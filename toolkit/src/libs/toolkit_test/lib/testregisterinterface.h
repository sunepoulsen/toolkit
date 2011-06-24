//-------------------------------------------------------------------------
/*!
    \file testregisterinterface.h
    \brief
*/

//-------------------------------------------------------------------------
#ifndef __TOOLKIT_TEST_TESTREGISTERINTERFACE_H__
#define __TOOLKIT_TEST_TESTREGISTERINTERFACE_H__

// Include Toolkit Test Files
#include <toolkit/test/testsuite.h>

// Include QT Files
#include <QSharedPointer>
#include <QtPlugin>

//-------------------------------------------------------------------------
/*!
    \ingroup grp_Test
    \brief
*/
class TOOLKIT_TEST_API TestRegisterInterface {
public:
    //!\name Types
    //@{
    typedef Toolkit::Test::TestSuite Suite;
    typedef QSharedPointer<Suite> SuitePtr;
    //@}
    
public:
    //!\name Constructors & Destructor
    //@{
    virtual ~TestRegisterInterface();
    //@}

    //!\name Plugin Interface
    //@{
    virtual QString pluginName() const = 0;
    virtual QString pluginDescription() const = 0;
    virtual QString pluginVersion() const = 0;
    //@}
    
    //!\name Test Registration
    //@{
    virtual SuitePtr registerTests() const = 0;
    //@}
};

typedef QSharedPointer<TestRegisterInterface> TestRegisterInterfacePtr;

Q_DECLARE_INTERFACE( TestRegisterInterface, "com.stp.Toolkit_Test.TestRegisterInterface/1.0" )

#endif

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
