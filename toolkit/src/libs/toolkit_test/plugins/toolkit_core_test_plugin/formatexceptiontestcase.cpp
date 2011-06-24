//-------------------------------------------------------------------------
/*!
    \file formatexceptiontestcase.cpp
    \brief
*/

//-------------------------------------------------------------------------

// Include Header File
#include "formatexceptiontestcase.h"

// Include Toolkit Core Files
#include <toolkit/core/sourceline.h>
#include <toolkit/core/formatexception.h>

//-------------------------------------------------------------------------
using namespace Toolkit::Core;
using namespace Toolkit::Test;

//-------------------------------------------------------------------------
FormatExceptionTestCase::FormatExceptionTestCase() :
    TestCase()
{
};

FormatExceptionTestCase::~FormatExceptionTestCase() {
};

void FormatExceptionTestCase::testConstructors() {
    SourceLine sl = SOURCELINE;

    FormatException t1( sl, "" );
    ASSERT_EQUAL( t1.getSourceLine().getFileName(), sl.getFileName() );
    ASSERT_EQUAL( t1.getSourceLine().getLineNumber(), sl.getLineNumber() );
    ASSERT_EQUAL( t1.getMessage(), "" );

    FormatException t2( sl, "Dette er en test!" );
    ASSERT_EQUAL( t2.getMessage(), "Dette er en test!" );

    FormatException t3( t2 );
    ASSERT_EQUAL( t3.getSourceLine().getFileName(), t2.getSourceLine().getFileName() );
    ASSERT_EQUAL( t3.getSourceLine().getLineNumber(), t2.getSourceLine().getLineNumber() );
    ASSERT_EQUAL( t3.getMessage(), "Dette er en test!" );
};

void FormatExceptionTestCase::testOpAssign() {
    SourceLine sl1 = SOURCELINE;
    SourceLine sl2 = SOURCELINE;

    FormatException t1( sl1, "t1" );
    FormatException t2( sl2, "t2" );

    t2 = t1;
    ASSERT_EQUAL( t2.getSourceLine().getFileName(), sl1.getFileName() );
    ASSERT_EQUAL( t2.getSourceLine().getLineNumber(), sl1.getLineNumber() );
    ASSERT_EQUAL( t2.getMessage(), "t1" );
};

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
