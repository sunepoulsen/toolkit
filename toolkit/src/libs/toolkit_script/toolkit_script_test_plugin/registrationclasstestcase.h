//-------------------------------------------------------------------------
/*!
    \file registrationclasstestcase.h
    \brief
*/

//-------------------------------------------------------------------------
#ifndef __TOOLKIT_SCRIPT_TEST_REGISTRATIONCLASSTESTCASE_H__
#define __TOOLKIT_SCRIPT_TEST_REGISTRATIONCLASSTESTCASE_H__

// Include Toolkit Test Files
#include <toolkit/test/testcase.h>

//-------------------------------------------------------------------------
/*!
    \brief Implements a test case to test the class Toolkit::Script::Environment
*/
class RegistrationClassTestCase : public Toolkit::Test::TestCase {
    Q_OBJECT

public:
    //!\name Constructors & Destructor
    //@{
    RegistrationClassTestCase();
    virtual ~RegistrationClassTestCase();
    //@}

public slots:
    //!\name Registrations
    //@{
    void testRegisterClass();
    void testRegisterDynamicMethods();
    void testRegisterStaticProperties();
    void testRegisterStaticMethods();
    void testRegisterExtendDynamicMethods();
    void testRegisterExtendStaticMethods();
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
