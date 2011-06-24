//-------------------------------------------------------------------------
/*!
    \file jsqchartestcase.cpp
    \brief
*/

//-------------------------------------------------------------------------

// Include Header File
#include "jsqchartestcase.h"

// Include Toolkit Core Files
#include <toolkit/core/log.h>

// Include Toolkit Script Files
#include <toolkit/script/environment.h>
#include <toolkit/script/packagefactory.h>

//-------------------------------------------------------------------------
using namespace Toolkit::Core;
using namespace Toolkit::Script;
using namespace Toolkit::Test;

//-------------------------------------------------------------------------
JSQCharTestCase::JSQCharTestCase() :
    TestCase()
{
};

JSQCharTestCase::~JSQCharTestCase() {
};

void JSQCharTestCase::testCategoryScriptProperties() {
    Environment engine;

    AbstractPackage::Pointer package = PackageFactory::newPackage( "" );
    ASSERT_REQUIRE_TRUE( package != NULL );

    package->loadPackage( PackageFactory::QCHAR_CLASS_NAME, engine.currentContext(), &engine );
    ASSERT_EQUAL( engine.evaluate( "QChar.Mark_NonSpacing;" ).toInt32(), QChar::Mark_NonSpacing );
};

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
