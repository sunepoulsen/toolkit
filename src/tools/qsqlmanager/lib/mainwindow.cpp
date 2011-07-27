//-------------------------------------------------------------------------------------------------------
/*!
    \file mainwindow.cpp
    \brief
*/

//-------------------------------------------------------------------------------------------------------

// Include Header File
#include "mainwindow.h"

// Include Toolkit Core Files
#include <toolkit/core/log.h>

// Include Toolkit Resource Files
#include <toolkit/resource/menuresource.h>
#include <toolkit/resource/xmlresourcehandler.h>

// Include Qt Files
#include <QFile>

//-------------------------------------------------------------------------------------------------------
using namespace QSqlManager::Core;
using namespace Toolkit::Core;
using namespace Toolkit::Resource;

//-------------------------------------------------------------------------------------------------------
QString MainWindow::WINDOW_TITLE( "title" );

//-------------------------------------------------------------------------------------------------------
MainWindow::MainWindow() :
    QMainWindow()
{
    Log log( Log::LT_TRACE, Log::MOD_MAIN, "MainWindow::MainWindow()" );

    try {
        ResourceBundle bundle = XMLResourceHandler( QLocale::system(), ":" ).readBundle( "mainwindow" );

        setWindowTitle( bundle.getString( WINDOW_TITLE ) );
    }
    catch( Exception& e ) {
        log.write( Log::LT_WARNING, "Resource error: %s", e.getMessage() );
    };

    QFile file( ":/mainwindow_en_DK.xml" );
    if( file.open( QIODevice::ReadOnly) ) {
        log.write( Log::LT_TRACE, "File content:\n%s", file.readAll() );
        file.close();
    }
    else {
        log.write( Log::LT_TRACE, "Unable to open file: %s", file.fileName() );
    }
};

MainWindow::~MainWindow() {
};

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
