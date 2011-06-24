//---------------------------------------------------------------------------------------
/*!
    \file log.cpp
    \brief 
*/

//---------------------------------------------------------------------------------------

// Include Header File
#include "log.h"

// Include STD Files
#include <stdlib.h>

//---------------------------------------------------------------------------------------
using namespace Toolkit::Core;

//---------------------------------------------------------------------------------------
Log::container_type Log::m_Handlers;

//---------------------------------------------------------------------------------------
Log::Log( LogLevel logLevel, const QString& msg, bool createGroup ) :
    m_Module( MOD_MAIN ),
    m_Handler( currentHandler() ),
    m_CreateGroup( createGroup )
{
    init( logLevel, msg );
};

Log::Log( LogLevel logLevel, ModuleType module, const QString& msg, bool createGroup ) :
    m_Module( module ),
    m_Handler( currentHandler() ),
    m_CreateGroup( createGroup )
{
    init( logLevel, msg );
};

Log::~Log() {
    destroy();
};

void Log::write( LogLevel logLevel, const QString& msg ) {
    if( m_Handler != m_Handlers.end() ) {
        m_Handler->second.write( (LogHandler::LogLevel)logLevel, (LogHandler::ModuleType)m_Module, msg );
    };
};

void Log::beginGroup( LogLevel logLevel, const QString& msg ) {
    if( m_Handler != m_Handlers.end() ) {
        m_Handler->second.beginGroup( (LogHandler::LogLevel)logLevel, (LogHandler::ModuleType)m_Module, msg );
    };
};

void Log::endGroup() {
    if( m_Handler != m_Handlers.end() ) {
        m_Handler->second.endGroup();
    };
};

void Log::init( LogLevel logLevel, const QString& msg ) {
    if( m_CreateGroup ) {
        beginGroup( logLevel, msg );
    };
};

void Log::destroy() {
    if( m_CreateGroup ) {
        endGroup();
    };
};

Log::iterator Log::currentHandler( QThread* thread ) {
    iterator it = m_Handlers.find( thread );

    if( it == m_Handlers.end() ) {
        return m_Handlers.find( NULL );
    };

    return it;
};

void Log::clearHandlers() {
    m_Handlers.clear();
};

void Log::pushHandler( const key_type& key, const data_type& data ) {
    m_Handlers.insert( std::make_pair( key, data ) );
};

Log::size_type Log::sizeHandlers() {
    return m_Handlers.size();
};

void Log::installQtMessageHandler() {
    qInstallMsgHandler( QtMessageHandler );
};

//---------------------------------------------------------------------------------------
void Toolkit::Core::QtMessageHandler( QtMsgType msgType, const char* msg ) {
    Log log( Log::LT_INFO, Log::MOD_QT, "", false );

    switch( msgType ) {
    case QtDebugMsg:
        log.write( Log::LT_DEBUG, msg );
        break;
    
    case QtWarningMsg:
        log.write( Log::LT_WARNING, msg );
        break;
    
    case QtCriticalMsg:
        log.write( Log::LT_ERROR, msg );
        break;
    
    case QtFatalMsg:
        log.write( Log::LT_FATAL, msg );
        abort();
    }
}
