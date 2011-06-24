//-------------------------------------------------------------------------
/*!
    \file errortestcase.cpp
    \brief
*/

//-------------------------------------------------------------------------

// Include Header File
#include "errortestcase.h"

// Include Toolkit Core Files
#include <toolkit/core/sourceline.h>
#include <toolkit/core/stringformat.h>
#include <toolkit/core/error.h>

//-------------------------------------------------------------------------
using namespace Toolkit::Core;
using namespace Toolkit::Test;

//-------------------------------------------------------------------------
ErrorTestCase::ErrorTestCase() :
    TestCase()
{
};

ErrorTestCase::~ErrorTestCase() {
};

void ErrorTestCase::testConstructors() {
    SourceLine sl = SOURCELINE;

    Error t1( sl, "" );
    ASSERT_EQUAL( t1.getSourceLine().getFileName(), sl.getFileName() );
    ASSERT_EQUAL( t1.getSourceLine().getLineNumber(), sl.getLineNumber() );
    ASSERT_EQUAL( t1.getMessage(), "" );

    Error t2( sl, "Dette er en test!" );
    ASSERT_EQUAL( t2.getMessage(), "Dette er en test!" );

    Error t3( t2 );
    ASSERT_EQUAL( t3.getSourceLine().getFileName(), t2.getSourceLine().getFileName() );
    ASSERT_EQUAL( t3.getSourceLine().getLineNumber(), t2.getSourceLine().getLineNumber() );
    ASSERT_EQUAL( t3.getMessage(), "Dette er en test!" );
};

void ErrorTestCase::testOpAssign() {
    SourceLine sl1 = SOURCELINE;
    SourceLine sl2 = SOURCELINE;

    Error t1( sl1, "t1" );
    Error t2( sl2, "t2" );

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
