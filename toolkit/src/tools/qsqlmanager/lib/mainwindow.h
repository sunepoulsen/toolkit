//-------------------------------------------------------------------------------------------------------
/*!
    \file mainwindow.h
    \brief
*/

//-------------------------------------------------------------------------------------------------------
#ifndef __TOOLKIT_QSQLMANAGER_CORE_MAINWINDOW_H__
#define __TOOLKIT_QSQLMANAGER_CORE_MAINWINDOW_H__

// Include QT Files
#include <QMainWindow>

//-------------------------------------------------------------------------------------------------------
namespace QSqlManager {

    //-------------------------------------------------------------------------------------------------------
    namespace Core {

        //-------------------------------------------------------------------------------------------------------
        /*!
            \brief    
        */
        class MainWindow : public QMainWindow {
        public:
            //!\name Constants
            //@{
            static QString WINDOW_TITLE;
            //@}
            
        public:
            //!\name Constructors & Destructor
            //@{
            MainWindow();
            virtual ~MainWindow();
            //@}            
        };
    };
};

#endif

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */

