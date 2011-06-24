//-------------------------------------------------------------------------
/*!
    \file abstractresourcetestcase.cpp
    \brief
*/

//-------------------------------------------------------------------------

// Include Header File
#include "abstractresourcetestcase.h"

// Include Toolkit Resource Files
#include <toolkit/resource/abstractresource.h>

//-------------------------------------------------------------------------
using namespace Toolkit::Resource;
using namespace Toolkit::Test;

//-------------------------------------------------------------------------
AbstractResourceTestCase::AbstractResourceTestCase() :
    TestCase()
{
};

AbstractResourceTestCase::~AbstractResourceTestCase() {
};

void AbstractResourceTestCase::testConstructors() {
    AbstractResource r1;
    ASSERT_TRUE( r1.getKey().isNull() );
    ASSERT_TRUE( r1.toVariant().isNull() );

    AbstractResource r2( "key" );
    ASSERT_EQUAL( r2.getKey(), "key" );
    ASSERT_TRUE( r1.toVariant().isNull() );

    AbstractResource r3( r2 );
    ASSERT_EQUAL( r3.getKey(), r2.getKey() );
    ASSERT_TRUE( r3.toVariant() == r2.toVariant() );
};

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */

