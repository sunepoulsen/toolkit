//-------------------------------------------------------------------------
/*!
    \file pluginimpl.h
    \brief
*/

//-------------------------------------------------------------------------
#ifndef __QSQLMANAGER_TEST_PLUGINIMPL_H__
#define __QSQLMANAGER_TEST_PLUGINIMPL_H__

// Include Toolkit Test Files
#include <toolkit/test/testregisterinterface.h>

// Include QT Files
#include <QtPlugin>

//-------------------------------------------------------------------------
/*!
    \brief
*/
class QSqlManagerPlugin : public QObject, TestRegisterInterface {
    Q_OBJECT
    Q_INTERFACES( TestRegisterInterface )

public:
    //!\name Plugin Interface
    //@{
    virtual QString pluginName() const;
    virtual QString pluginDescription() const;
    virtual QString pluginVersion() const;
    //@}

    //!\name Test Registration
    //@{
    virtual SuitePtr registerTests() const;
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

