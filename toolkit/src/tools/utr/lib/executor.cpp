//-------------------------------------------------------------------------------------------------------
/*!
    \file executor.cpp
    \brief
*/

//-------------------------------------------------------------------------------------------------------

// Include Header File
#include "executor.h"

// Include Utr Core Files
#include "logreport.h"

// Include Toolkit Core Files
#include <toolkit/core/library.h>
#include <toolkit/core/log.h>
#include <toolkit/core/throwable.h>

// Include Toolkit Core Files
#include <toolkit/test/testexecutor.h>

// Include Qt Files
#include <QSharedPointer>

//-------------------------------------------------------------------------------------------------------
using namespace Toolkit::Core;
using namespace Toolkit::Test;

//-------------------------------------------------------------------------------------------------------
#ifdef WIN32
	QString Executor::PROGRAM_FILENAME( "utr.exe" );
#else
	QString Executor::PROGRAM_FILENAME( "utr" );
#endif

QString Executor::VERSION_STR( "0.1.0" );
QString Executor::LOG_FILENAME( "utr.log" );

#ifdef WIN32
	QString Executor::PLUGIN_WILDCARD_DEBUG( "*plugind.dll" );
	QString Executor::PLUGIN_WILDCARD_RELEASE( "*plugin.dll" );
#else
	QString Executor::PLUGIN_WILDCARD_DEBUG( "*plugind.so" );
	QString Executor::PLUGIN_WILDCARD_RELEASE( "*plugin.so" );
#endif

//-------------------------------------------------------------------------------------------------------
Executor::Executor( int argc, char* argv[] ) :
    m_App( argc, argv ),
    m_Options(),
    m_PluginModel()
{   
    Log::pushHandler( NULL, LogHandler( LogDevice( LOG_FILENAME ), LogHandler::OPT_ALL, LogHandler::LT_TRACE ) );
    Log::installQtMessageHandler();
    
    try {
        setupColumns();
        setOptions( argc, argv );
    }
    catch( Throwable& e ) {
        Log log( Log::LT_ERROR, Log::MOD_MAIN, "Executor::Executor( int argc, char* argv[] )" );
        log.write( Log::LT_ERROR, "%s", e.debugString() );
    };
};

Executor::~Executor() {
};

int Executor::run() {
    Log log( Log::LT_INFO, Log::MOD_MAIN, "int Executor::run()" );
    log.write( Log::LT_INFO, "Application dir: %s", m_App.applicationDirPath() );
    log.write( Log::LT_INFO, "Library path: %s", m_App.libraryPaths().join( ":" ) );

    loadPlugins();
    
    LogReport* report = new LogReport();
    report->setPrintTests( m_Options.contains( "-t" ) );
    report->setPrintStatistics( m_Options.contains( "-s" ) );

    TestExecutor executor;
    executor.setReport( AbstractReportPtr( report ) );

    for( PluginModel::iterator it = m_PluginModel.begin(); it != m_PluginModel.end(); ++it ) {
        executor.addTest( TestSuite::item_type( new TestSuite( *(it->data()->getSuite()) ) ) );
    };

    executor.execute();
    
    if( report->countResultErrors() > 0 ) {
        return -1;
    }

    return 0;
};

void Executor::quit() {
    m_App.quit();
};

void Executor::setOptions( int argc, char* argv[] ) {
    Log log( Log::LT_INFO, Log::MOD_MAIN, "void Executor::setOptions( int argc, char* argv[] )" );
    
    m_Options.clear();
    
    for( int i = 0; i < argc; i++ ) {
        log.write( Log::LT_INFO, "Param %-2s: %s", StringFormat::format( "%i", i ), argv[ i ] );
        m_Options << argv[ i ];
    };
};

void Executor::setupColumns() {
	m_PluginModel.getColumns().clear();

	m_PluginModel.getColumns().push_back( ModelColumn( PluginModel::COL_NAME, "Name" ) ); 
	m_PluginModel.getColumns().push_back( ModelColumn( PluginModel::COL_DESCRIPTION, "Description" ) );
	m_PluginModel.getColumns().push_back( ModelColumn( PluginModel::COL_VERSION, "Version" ) );
	m_PluginModel.getColumns().push_back( ModelColumn( PluginModel::COL_COUNT_TESTS, "Tests", Qt::AlignRight | Qt::AlignVCenter ) );
	m_PluginModel.getColumns().push_back( ModelColumn( PluginModel::COL_COUNT_OK, "OK", Qt::AlignRight | Qt::AlignVCenter ) );
	m_PluginModel.getColumns().push_back( ModelColumn( PluginModel::COL_COUNT_WARNINGS, "Warnings", Qt::AlignRight | Qt::AlignVCenter ) );
	m_PluginModel.getColumns().push_back( ModelColumn( PluginModel::COL_COUNT_ERRORS, "Errors", Qt::AlignRight | Qt::AlignVCenter ) );
	m_PluginModel.getColumns().push_back( ModelColumn( PluginModel::COL_ELAPSED, "Time", Qt::AlignRight | Qt::AlignVCenter ) );
};

void Executor::loadPlugins() {
    Log log( Log::LT_TRACE, Log::MOD_MAIN, "void Executor::loadPlugins()" );
    
    if( m_Options.isEmpty() ) {
        return;
    };
    
    QString wildcard = PLUGIN_WILDCARD_DEBUG;
    if( m_Options.front().endsWith( PROGRAM_FILENAME ) ) {
        wildcard = PLUGIN_WILDCARD_RELEASE;
    };
    
    m_PluginModel.addPlugins( wildcard );
};

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
