//-------------------------------------------------------------------------
/*!
    \file registrationclasstestcase.h
    \brief
*/

//-------------------------------------------------------------------------

// Include Header File
#include "registrationclasstestcase.h"

// Include Plugin Files
#include "scriptobjects.h"

// Include Toolkit Core Files
#include <toolkit/core/stringformat.h>

// Include Toolkit Script Files
#include <toolkit/script/environment.h>
#include <toolkit/script/registrationclass.h>
#include <toolkit/script/scriptexception.h>

// Include Qt Files
#include <QSharedPointer>

//-------------------------------------------------------------------------
using namespace Toolkit::Core;
using namespace Toolkit::Script;
using namespace Toolkit::Test;

//-------------------------------------------------------------------------
RegistrationClassTestCase::RegistrationClassTestCase() :
    TestCase()
{
};

RegistrationClassTestCase::~RegistrationClassTestCase() {
};

void RegistrationClassTestCase::testRegisterClass() {
    Environment engine;

    QSharedPointer<RegistrationClass> f( RegistrationClass::newClass<QtScriptObject>() );
    f->registerObject( engine.globalObject(), &engine );

    ASSERT_EQUAL( engine.globalObject().property( "QtScriptObject" ).isObject(), true );

    QString script;
    script = "var obj = new QtScriptObject();"
             "obj.name = \"Navn\";"
             "obj.toString();";
    ASSERT_EQUAL( engine.evaluate( script ).toString(), "Navn" );

    script = "var obj = new QtScriptObject( 5 );";
    ASSERT_EXCEPTION( engine.evaluate( script ), ScriptException );

    script = "var obj = QtScriptObject();";
    ASSERT_EXCEPTION( engine.evaluate( script ), ScriptException );
};

void RegistrationClassTestCase::testRegisterDynamicMethods() {
    Environment engine;

    QSharedPointer<RegistrationClass> f( RegistrationClass::newClass<QtScriptObject>() );
    f->getDynamicFunctions().push_back( RegistrationFunction( "arg", QtScriptFunctions::arg ) );
    f->registerObject( engine.globalObject(), &engine );

    QScriptValue v = engine.evaluate( "new QtScriptObject();" );
    ASSERT_REQUIRE_EQUAL( v.isObject(), true );

    ASSERT_EQUAL( engine.callFunction( v, "arg", 5 ).toInt32(), 5 );
};

void RegistrationClassTestCase::testRegisterStaticProperties() {
    Environment engine;

    QSharedPointer<RegistrationClass> f( RegistrationClass::newClass<QtScriptObject>() );
    f->getStaticProperties().insert( std::make_pair( "Engine", QScriptValue( "Qt" ) ) );
    f->registerObject( engine.globalObject(), &engine );

    ASSERT_EQUAL( engine.globalObject().property( "QtScriptObject" ).isObject(), true );
    ASSERT_EQUAL( engine.evaluate( "QtScriptObject.Engine;" ).toString(), "Qt" );

    engine.evaluate( "QtScriptObject.Engine = 17;" );
    ASSERT_EQUAL( engine.evaluate( "QtScriptObject.Engine;" ).toInt32(), 17 );
};

void RegistrationClassTestCase::testRegisterStaticMethods() {
    Environment engine;

    QSharedPointer<RegistrationClass> f( RegistrationClass::newClass<QtScriptObject>() );
    f->getStaticFunctions().push_back( RegistrationFunction( "arg", QtScriptFunctions::arg ) );
    f->registerObject( engine.globalObject(), &engine );

    ASSERT_EQUAL( engine.callFunction( engine.globalObject().property( "QtScriptObject" ), "arg", 5 ).toInt32(), 5 );
};

void RegistrationClassTestCase::testRegisterExtendDynamicMethods() {
    Environment engine;

    RegistrationClass f( "String" );
    f.getDynamicFunctions().push_back( RegistrationFunction( "arg", QtScriptFunctions::arg ) );
    f.registerObject( engine.globalObject(), &engine );

    QScriptValue v = engine.evaluate( "new String();" );
    ASSERT_REQUIRE_EQUAL( v.isObject(), true );

    ASSERT_EQUAL( engine.callFunction( v, "arg", 5 ).toInt32(), 5 );
};

void RegistrationClassTestCase::testRegisterExtendStaticMethods() {
    Environment engine;

    RegistrationClass f( "String" );
    f.getStaticFunctions().push_back( RegistrationFunction( "arg", QtScriptFunctions::arg ) );
    f.registerObject( engine.globalObject(), &engine );

    ASSERT_EQUAL( engine.callFunction( engine.globalObject().property( "String" ), "arg", 5 ).toInt32(), 5 );
};

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
