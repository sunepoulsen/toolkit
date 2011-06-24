//-------------------------------------------------------------------------------------------------------
/*!
    \file executor.h
    \brief
*/

//-------------------------------------------------------------------------------------------------------
#ifndef __TOOLKIT_TEST_UTR_EXECUTOR_H__
#define __TOOLKIT_TEST_UTR_EXECUTOR_H__

// Include UTR Files
#include "pluginmodel.h"

// Include Toolkit Core Files
#include <toolkit/core/format.h>

// Include QT Files
#include <QApplication>
#include <QFile>
#include <QStringList>

//-------------------------------------------------------------------------------------------------------
/*!
    \ingroup grp_TestExecutor
    \brief   
*/
class Executor : public QObject {
    Q_OBJECT
            
public:
    static QString PROGRAM_FILENAME;
    static QString VERSION_STR;
    static QString LOG_FILENAME;
    static QString PLUGIN_WILDCARD_DEBUG;
    static QString PLUGIN_WILDCARD_RELEASE;
    
public:
    //!\name Constructors & Destructor
    //@{
    Executor( int argc, char* argv[] );
    virtual ~Executor();
    //@}
    
    //!\name Execution
    //@{
    int run();
    //@}
    
private slots:
    void quit();
    
private:
    //!\name Helpers
    //@{
    void setOptions( int argc, char* argv[] );
    void setupColumns();
    void loadPlugins();
    //@}
        
private:
    //!\name Members
    //@{
    QApplication m_App;
    QStringList m_Options;
    PluginModel m_PluginModel;
    //@}    
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
