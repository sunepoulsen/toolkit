//-------------------------------------------------------------------------------------------------------
/*!
    \file main.cpp
    \brief
*/

//-------------------------------------------------------------------------------------------------------

// Include QSqlManager Files
#include <toolkit/qsqlmanagercore/mainwindow.h>

// Include Toolkit Core Files
#include <toolkit/core/format.h>
#include <toolkit/core/library.h>
#include <toolkit/core/log.h>
#include <toolkit/core/stringformat.h>

// Include Qt Files
#include <QApplication>

//-------------------------------------------------------------------------------------------------------
#ifdef DEBUG
QString LOG_FILENAME( "qsqlmanagerd.log" );
#else
QString LOG_FILENAME( "qsqlmanager.log" );
#endif

//-------------------------------------------------------------------------------------------------------
using namespace Toolkit::Core;
using namespace QSqlManager::Core;

//-------------------------------------------------------------------------------------------------------
/*!
    \ingroup grp_TestExecutor
    \brief Main function of the \e utr tool.
    
    \param argc The numer of parsed arguments at the command line.
    \param argv An array of each argument as a char*.
*/
int main( int argc, char* argv[] ) {
    QApplication app( argc, argv, true );
    app.setApplicationName( "QtSqlManager" );

    Log::pushHandler( NULL, LogHandler( LogDevice( LOG_FILENAME ), LogHandler::OPT_ALL, LogHandler::LT_TRACE ) );
    Log::installQtMessageHandler();

    Log log( Log::LT_INFO, Log::MOD_MAIN, StringFormat::format( "%s version %s", app.applicationName(), TOOLKIT_VERSION_STR ) );

    MainWindow* mainWidget = new MainWindow();
    mainWidget->showMaximized();

    app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );

    int appRes = app.exec();

    return appRes;
};

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */

