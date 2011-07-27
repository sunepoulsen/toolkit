//-------------------------------------------------------------------------
/*!
    \file corepackagetestcase.cpp
    \brief
*/

//-------------------------------------------------------------------------

// Include Header File
#include "corepackagetestcase.h"

// Include Plugin Files
#include "scriptobjects.h"

// Include Toolkit Core Files
#include <toolkit/core/log.h>

// Include Toolkit Script Files
#include <toolkit/script/corepackage.h>
#include <toolkit/script/environment.h>
#include <toolkit/script/registrationfunction.h>
#include <toolkit/script/scriptexception.h>

//-------------------------------------------------------------------------
using namespace Toolkit::Core;
using namespace Toolkit::Script;
using namespace Toolkit::Test;

//-------------------------------------------------------------------------
CorePackageTestCase::CorePackageTestCase() :
    TestCase()
{
};

CorePackageTestCase::~CorePackageTestCase() {
};

void CorePackageTestCase::testQUrl() {
    QUrl url;

    url = "test";
    ASSERT_EQUAL( url.scheme(), "" );
    ASSERT_EQUAL( url.userName(), "" );
    ASSERT_EQUAL( url.password(), "" );
    ASSERT_EQUAL( url.host(), "" );
    ASSERT_EQUAL( url.port(), -1 );
    ASSERT_EQUAL( url.path(), "test" );
    ASSERT_EQUAL( url.hasQuery(), false );
    ASSERT_EQUAL( url.fragment(), "" );

    url = "core:///test";
    ASSERT_EQUAL( url.scheme(), "core" );
    ASSERT_EQUAL( url.userName(), "" );
    ASSERT_EQUAL( url.password(), "" );
    ASSERT_EQUAL( url.host(), "" );
    ASSERT_EQUAL( url.port(), -1 );
    ASSERT_EQUAL( url.path(), "/test" );
    ASSERT_EQUAL( url.hasQuery(), false );
    ASSERT_EQUAL( url.fragment(), "" );

    url = "*";
    ASSERT_EQUAL( url.scheme(), "" );
    ASSERT_EQUAL( url.userName(), "" );
    ASSERT_EQUAL( url.password(), "" );
    ASSERT_EQUAL( url.host(), "" );
    ASSERT_EQUAL( url.port(), -1 );
    ASSERT_EQUAL( url.path(), "*" );
    ASSERT_EQUAL( url.hasQuery(), false );
    ASSERT_EQUAL( url.fragment(), "" );

    url = "core:///*";
    ASSERT_EQUAL( url.scheme(), "core" );
    ASSERT_EQUAL( url.userName(), "" );
    ASSERT_EQUAL( url.password(), "" );
    ASSERT_EQUAL( url.host(), "" );
    ASSERT_EQUAL( url.port(), -1 );
    ASSERT_EQUAL( url.path(), "/*" );
    ASSERT_EQUAL( url.hasQuery(), false );
    ASSERT_EQUAL( url.fragment(), "" );

    url = "http://www.sunepoulsen.dk/projectlite/downloads/*.js";
    ASSERT_EQUAL( url.scheme(), "http" );
    ASSERT_EQUAL( url.userName(), "" );
    ASSERT_EQUAL( url.password(), "" );
    ASSERT_EQUAL( url.host(), "www.sunepoulsen.dk" );
    ASSERT_EQUAL( url.port(), -1 );
    ASSERT_EQUAL( url.path(), "/projectlite/downloads/*.js" );
    ASSERT_EQUAL( url.hasQuery(), false );
    ASSERT_EQUAL( url.fragment(), "" );
};

void CorePackageTestCase::testConstructors() {
    CorePackage package;

    ASSERT_EQUAL( package.getSchemeName(), "" );
    ASSERT_EQUAL( package.getNameSpace(), "" );
};

void CorePackageTestCase::testCheckPackage() {
    CorePackage package;

    ASSERT_EQUAL( package.checkPackage( QUrl( "Test" ) ), false );
    ASSERT_EQUAL( package.checkPackage( QUrl( "*" ) ), false );

    package.push_back( CorePackage::value_type( new RegistrationFunction( "test", QtScriptFunctions::arg ) ) );
    ASSERT_EQUAL( package.checkPackage( QUrl( "Test" ) ), false );
    ASSERT_EQUAL( package.checkPackage( QUrl( "test" ) ), true );
    ASSERT_EQUAL( package.checkPackage( QUrl( "*" ) ), true );
};

void CorePackageTestCase::testCheckPackageSchemaName() {
    CorePackage package;
    package.setSchemeName( "core" );

    package.push_back( CorePackage::value_type( new RegistrationFunction( "test", QtScriptFunctions::arg ) ) );
    ASSERT_EQUAL( package.checkPackage( QUrl( "test" ) ), false );
    ASSERT_EQUAL( package.checkPackage( QUrl( "*" ) ), false );
    ASSERT_EQUAL( package.checkPackage( QUrl( "core:///test" ) ), true );
    ASSERT_EQUAL( package.checkPackage( QUrl( "core:///*" ) ), true );
};

void CorePackageTestCase::testCheckPackageNameSpace() {
    CorePackage package( "Core" );

    package.push_back( CorePackage::value_type( new RegistrationFunction( "test", QtScriptFunctions::arg ) ) );
    ASSERT_EQUAL( package.checkPackage( QUrl( "test" ) ), false );
    ASSERT_EQUAL( package.checkPackage( QUrl( "*" ) ), false );
    ASSERT_EQUAL( package.checkPackage( QUrl( "Core.test" ) ), true );
    ASSERT_EQUAL( package.checkPackage( QUrl( "Core.*" ) ), true );
};

void CorePackageTestCase::testExtractPackages() {
    CorePackage package;
    AbstractPackage::url_container urls;

    package.push_back( CorePackage::value_type( new RegistrationFunction( "arg", QtScriptFunctions::arg ) ) );
    package.push_back( CorePackage::value_type( new RegistrationFunction( "test", QtScriptFunctions::arg ) ) );

    ASSERT_EQUAL( package.extractPackageNames( QUrl() ).empty(), true );

    urls = package.extractPackageNames( QUrl( "test" ) );
    ASSERT_REQUIRE_EQUAL( urls.size(), 1U );
    ASSERT_EQUAL( urls[0].toString(), "test" );

    urls = package.extractPackageNames( QUrl( "*" ) );
    ASSERT_REQUIRE_EQUAL( urls.size(), 2U );
    ASSERT_EQUAL( urls[0].toString(), "arg" );
    ASSERT_EQUAL( urls[1].toString(), "test" );
};

void CorePackageTestCase::testExtractPackagesSchemaName() {
    CorePackage package;
    package.setSchemeName( "core" );

    AbstractPackage::url_container urls;

    package.push_back( CorePackage::value_type( new RegistrationFunction( "arg", QtScriptFunctions::arg ) ) );
    package.push_back( CorePackage::value_type( new RegistrationFunction( "test", QtScriptFunctions::arg ) ) );

    urls = package.extractPackageNames( QUrl( "core:test" ) );
    ASSERT_REQUIRE_EQUAL( urls.size(), 1U );
    ASSERT_EQUAL( urls[0].toString(), "core:test" );

    urls = package.extractPackageNames( QUrl( "core:*" ) );
    ASSERT_REQUIRE_EQUAL( urls.size(), 2U );
    ASSERT_EQUAL( urls[0].toString(), "core:arg" );
    ASSERT_EQUAL( urls[1].toString(), "core:test" );

    ASSERT_EQUAL( package.extractPackageNames( QUrl( "test" ) ).empty(), true );
    ASSERT_EQUAL( package.extractPackageNames( QUrl( "*" ) ).empty(), true );
};

void CorePackageTestCase::testExtractPackagesNameSpace() {
    CorePackage package( "Core" );
    package.setSchemeName( "core" );

    AbstractPackage::url_container urls;

    package.push_back( CorePackage::value_type( new RegistrationFunction( "arg", QtScriptFunctions::arg ) ) );
    package.push_back( CorePackage::value_type( new RegistrationFunction( "test", QtScriptFunctions::arg ) ) );

    urls = package.extractPackageNames( QUrl( "core:Core.test" ) );
    ASSERT_REQUIRE_EQUAL( urls.size(), 1U );
    ASSERT_EQUAL( urls[0].toString(), "core:Core.test" );

    urls = package.extractPackageNames( QUrl( "core:Core.*" ) );
    ASSERT_REQUIRE_EQUAL( urls.size(), 2U );
    ASSERT_EQUAL( urls[0].toString(), "core:Core.arg" );
    ASSERT_EQUAL( urls[1].toString(), "core:Core.test" );

    ASSERT_EQUAL( package.extractPackageNames( QUrl( "core:test" ) ).empty(), true );
    ASSERT_EQUAL( package.extractPackageNames( QUrl( "*" ) ).empty(), true );
};

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
