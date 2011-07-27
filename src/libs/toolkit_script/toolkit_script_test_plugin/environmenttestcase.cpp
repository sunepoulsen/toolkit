//-------------------------------------------------------------------------
/*!
    \file environmenttestcase.cpp
    \brief
*/

//-------------------------------------------------------------------------

// Include Header File
#include "environmenttestcase.h"

// Include Plugin Files
#include "scriptobjects.h"

// Include Toolkit Script Files
#include <toolkit/script/environment.h>
#include <toolkit/script/scriptexception.h>

// Include Toolkit Core Files
#include <toolkit/core/stringformat.h>

//-------------------------------------------------------------------------
using namespace Toolkit::Core;
using namespace Toolkit::Script;
using namespace Toolkit::Test;

//-------------------------------------------------------------------------
EnvironmentTestCase::EnvironmentTestCase() :
    TestCase()
{
};

EnvironmentTestCase::~EnvironmentTestCase() {
};

void EnvironmentTestCase::testConstructors() {
    Environment engine;

    ASSERT_EQUAL( engine.getOptions().getLocalContext(), true );
    ASSERT_EQUAL( engine.getOptions().getCodec().name(), QTextCodec::codecForLocale()->name() );
};

void EnvironmentTestCase::testEvaluateExpr() {
    Environment engine;

    ASSERT_EQUAL( engine.evaluate( "1+2" ).toNumber(), 3 );
    ASSERT_EQUAL( engine.evaluate( "\"זרו ֶ״ֵ\"" ).toString(), "זרו ֶ״ֵ" );
};

void EnvironmentTestCase::testEvaluateCallScriptFunction() {
    Environment engine;

    QString script = "function fun() { return arguments.length; }";

    ASSERT_EQUAL( engine.evaluate( script ).isValid(), true );
    ASSERT_EQUAL( engine.callFunction( "fun" ).toInteger(), 0 );
    ASSERT_EQUAL( engine.callFunction( "fun", 1 ).toInteger(), 1 );
    ASSERT_EQUAL( engine.callFunction( "fun", 1, 2 ).toInteger(), 2 );
    ASSERT_EQUAL( engine.callFunction( "fun", 1, 2, 3 ).toInteger(), 3 );
    ASSERT_EQUAL( engine.callFunction( "fun", 1, 2, 3, 4 ).toInteger(), 4 );
    ASSERT_EQUAL( engine.callFunction( "fun", 1, 2, 3, 4, 5 ).toInteger(), 5 );
    ASSERT_EQUAL( engine.callFunction( "fun", 1, 2, 3, 4, 5, 6 ).toInteger(), 6 );
    ASSERT_EQUAL( engine.callFunction( "fun", 1, 2, 3, 4, 5, 6, 7 ).toInteger(), 7 );
    ASSERT_EQUAL( engine.callFunction( "fun", 1, 2, 3, 4, 5, 6, 7, 8 ).toInteger(), 8 );
    ASSERT_EQUAL( engine.callFunction( "fun", 1, 2, 3, 4, 5, 6, 7, 8, 9 ).toInteger(), 9 );
    ASSERT_EQUAL( engine.callFunction( "fun", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 ).toInteger(), 10 );
};

void EnvironmentTestCase::testEvaluateCallRegFunction() {
    Environment engine;

    engine.registerFunction( "arg", QtScriptFunctions::arg );

    ASSERT_EQUAL( engine.callFunction( "arg" ).isUndefined(), true );
    ASSERT_EQUAL( engine.callFunction( "arg", 5 ).toNumber(), 5 );
    ASSERT_EXCEPTION( engine.callFunction( "arg", 5, engine.newArray() ), ScriptException );
};

void EnvironmentTestCase::testEvaluateCallRegObject() {
    Environment engine;

    QString script;
    script = "var obj = new QtScriptObject();"
             "obj.name = \"Navn\";"
             "obj.toString();";

    engine.registerClass<QtScriptObject>( "QtScriptObject" );
    ASSERT_EQUAL( engine.evaluate( script ).toString(), "Navn" );

    script = "var obj = new QtScriptObject( 5 );";
    ASSERT_EXCEPTION( engine.evaluate( script ), ScriptException );

    script = "var obj = QtScriptObject();";
    ASSERT_EXCEPTION( engine.evaluate( script ), ScriptException );

    script = "var a = new QtScriptObject();"
             "a.name = \"A\";"
             "var b = a;"
             "b.name = \"B\";"
             "b.name";
    ASSERT_EQUAL( engine.evaluate( script ).toString(), "B" );

    script = "var a = new QtScriptObject();"
             "a.name = \"A\";"
             "var b = a;"
             "b.name = \"B\";"
             "a.name";
    ASSERT_EQUAL( engine.evaluate( script ).toString(), "B" );
};

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
