//-------------------------------------------------------------------------
/*!
    \file abstractoperationtestcase.cpp
    \brief
*/

//-------------------------------------------------------------------------

// Include Header File
#include "abstractoperationtestcase.h"

// Include Toolkit Sql Files
#include <toolkit/sql/abstractoperation.h>

//-------------------------------------------------------------------------
using namespace Toolkit::Sql;
using namespace Toolkit::Test;

//-------------------------------------------------------------------------
AbstractOperationTestCase::AbstractOperationTestCase() :
    TestCase()
{
};

AbstractOperationTestCase::~AbstractOperationTestCase() {
};

void AbstractOperationTestCase::testConstructors() {
    AbstractOperation op;

    ASSERT_TRUE( op.getName().isEmpty() );
    ASSERT_TRUE( op.getDescription().isEmpty() );
    ASSERT_FALSE( op.getDatabase().isValid() );
};

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
