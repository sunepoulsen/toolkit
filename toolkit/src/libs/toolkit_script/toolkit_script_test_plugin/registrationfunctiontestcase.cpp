//-------------------------------------------------------------------------
/*!
    \file registrationfunctiontestcase.h
    \brief
*/

//-------------------------------------------------------------------------

// Include Header File
#include "registrationfunctiontestcase.h"

// Include Plugin Files
#include "scriptobjects.h"

// Include Toolkit Script Files
#include <toolkit/script/environment.h>
#include <toolkit/script/registrationfunction.h>
#include <toolkit/script/scriptexception.h>

//-------------------------------------------------------------------------
using namespace Toolkit::Script;
using namespace Toolkit::Test;

//-------------------------------------------------------------------------
RegistrationFunctionTestCase::RegistrationFunctionTestCase() :
    TestCase()
{
};

RegistrationFunctionTestCase::~RegistrationFunctionTestCase() {
};

void RegistrationFunctionTestCase::testRegister() {
    Environment engine;

    RegistrationFunction f( "arg", QtScriptFunctions::arg );
    f.registerObject( engine.globalObject(), &engine );

    ASSERT_EQUAL( engine.globalObject().property( "arg" ).isFunction(), true );
    ASSERT_EQUAL( engine.callFunction( "arg", 5 ).toInt32(), 5 );
};

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
