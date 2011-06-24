//-------------------------------------------------------------------------
/*!
    \file basicstringformattestcase.cpp
    \brief
*/

//-------------------------------------------------------------------------

// Include Header File
#include "basicstringformattestcase.h"

// Include Toolkit Core Files
#include <toolkit/core/stringformat.h>

//-------------------------------------------------------------------------
using namespace Toolkit::Core;
using namespace Toolkit::Test;

//-------------------------------------------------------------------------
BasicStringFormatTestCase::BasicStringFormatTestCase() :
    TestCase()
{
};

BasicStringFormatTestCase::~BasicStringFormatTestCase() {
};

void BasicStringFormatTestCase::testConstructors() {
    StringFormat f;
    ASSERT_TRUE( f.lastResult().isNull() );
};

/*!
    \brief Tests format() with 1 format parameter.
*/
void BasicStringFormatTestCase::testFormat01() {
    // Tests no format substitution
    ASSERT_EQUAL( StringFormat::format( "Test", "p1" ), "Test" );
    ASSERT_EQUAL( StringFormat::format( "%%s", "p1" ), "%s" );

    // Tests placement format substitution
    ASSERT_EQUAL( StringFormat::format( "%s", "p1" ), "p1" );
    ASSERT_EQUAL( StringFormat::format( "%s test", "p1" ), "p1 test" );
    ASSERT_EQUAL( StringFormat::format( "test %s", "p1" ), "test p1" );
    ASSERT_EQUAL( StringFormat::format( "test %s test", "p1" ), "test p1 test" );

    // Tests arg index format substitution
    ASSERT_EQUAL( StringFormat::format( "%1$s", "p1" ), "p1" );
    ASSERT_EQUAL( StringFormat::format( "%1$s test", "p1" ), "p1 test" );
    ASSERT_EQUAL( StringFormat::format( "test %1$s", "p1" ), "test p1" );
    ASSERT_EQUAL( StringFormat::format( "test %1$s test", "p1" ), "test p1 test" );

    // Tests wrong arg index in format.
    ASSERT_EQUAL( StringFormat::format( "%2$s", "p1" ), "%2$s" );
};

/*!
    \brief Tests format() with 2 format parameters.
*/
void BasicStringFormatTestCase::testFormat02() {
    // Tests no format substitution
    ASSERT_EQUAL( StringFormat::format( "Test", "p1", "p2" ), "Test" );
    ASSERT_EQUAL( StringFormat::format( "%%s", "p1", "p2" ), "%s" );
    ASSERT_EQUAL( StringFormat::format( "%s", "p1", "p2" ), "p1" );

    // Tests placement format substitution
    ASSERT_EQUAL( StringFormat::format( "%s %s test", "p1", "p2" ), "p1 p2 test" );
    ASSERT_EQUAL( StringFormat::format( "test %s %s", "p1", "p2" ), "test p1 p2" );
    ASSERT_EQUAL( StringFormat::format( "test %s %s test", "p1", "p2" ), "test p1 p2 test" );

    // Tests arg index format substitution
    ASSERT_EQUAL( StringFormat::format( "%1$s %s", "p1", "p2" ), "p1 p2" );
    ASSERT_EQUAL( StringFormat::format( "%2$s %1$s", "p1", "p2" ), "p2 p1" );
    ASSERT_EQUAL( StringFormat::format( "%1$s %s test", "p1", "p2" ), "p1 p2 test" );
    ASSERT_EQUAL( StringFormat::format( "test %1$s %s", "p1", "p2" ), "test p1 p2" );
    ASSERT_EQUAL( StringFormat::format( "test %1$s test %s", "p1", "p2" ), "test p1 test p2" );

    // Tests wrong arg index in format.
    ASSERT_EQUAL( StringFormat::format( "%2$s %s", "p1", "p2" ), "p2 p2" );
    ASSERT_EQUAL( StringFormat::format( "%3$s", "p1", "p2" ), "%3$s" );
};

/*!
    \brief Tests format() with 3 format parameters.
*/
void BasicStringFormatTestCase::testFormat03() {
    // Tests no format substitution
    ASSERT_EQUAL( StringFormat::format( "Test", "p1", "p2", "p3" ), "Test" );
    ASSERT_EQUAL( StringFormat::format( "%%s", "p1", "p2", "p3" ), "%s" );
    ASSERT_EQUAL( StringFormat::format( "%s", "p1", "p2", "p3" ), "p1" );

    // Tests placement format substitution
    ASSERT_EQUAL( StringFormat::format( "%s %s %s test", "p1", "p2", "p3" ), "p1 p2 p3 test" );
    ASSERT_EQUAL( StringFormat::format( "test %s %s %s", "p1", "p2", "p3" ), "test p1 p2 p3" );
    ASSERT_EQUAL( StringFormat::format( "test %s %s %s test", "p1", "p2", "p3" ), "test p1 p2 p3 test" );

    // Tests arg index format substitution
    ASSERT_EQUAL( StringFormat::format( "%1$s %s %s", "p1", "p2", "p3" ), "p1 p2 p3" );
    ASSERT_EQUAL( StringFormat::format( "%3$s %2$s %1$s", "p1", "p2", "p3" ), "p3 p2 p1" );
    ASSERT_EQUAL( StringFormat::format( "%1$s %s %s test", "p1", "p2", "p3" ), "p1 p2 p3 test" );
    ASSERT_EQUAL( StringFormat::format( "test %s %1$s %s", "p1", "p2", "p3" ), "test p1 p1 p3" );
    ASSERT_EQUAL( StringFormat::format( "test %2$s test %s test %s", "p1", "p2", "p3" ), "test p2 test p2 test p3" );

    // Tests wrong arg index in format.
    ASSERT_EQUAL( StringFormat::format( "%3$s %s", "p1", "p2", "p3" ), "p3 p2" );
    ASSERT_EQUAL( StringFormat::format( "%4$s", "p1", "p2", "p3" ), "%4$s" );
};

/*!
    \brief Tests format() with 4 format parameters.
*/
void BasicStringFormatTestCase::testFormat04() {
    // Tests no format substitution
    ASSERT_EQUAL( StringFormat::format( "Test", "p1", "p2", "p3", "p4" ), "Test" );
    ASSERT_EQUAL( StringFormat::format( "%%s", "p1", "p2", "p3", "p4" ), "%s" );
    ASSERT_EQUAL( StringFormat::format( "%s", "p1", "p2", "p3", "p4" ), "p1" );

    // Tests placement format substitution
    ASSERT_EQUAL( StringFormat::format( "%s %s %s %s test", "p1", "p2", "p3", "p4" ), "p1 p2 p3 p4 test" );
    ASSERT_EQUAL( StringFormat::format( "test %s %s %s %s", "p1", "p2", "p3", "p4" ), "test p1 p2 p3 p4" );
    ASSERT_EQUAL( StringFormat::format( "test %s %s %s %s test", "p1", "p2", "p3", "p4" ), "test p1 p2 p3 p4 test" );

    // Tests arg index format substitution
    ASSERT_EQUAL( StringFormat::format( "%1$s %s %s %s", "p1", "p2", "p3", "p4" ), "p1 p2 p3 p4" );
    ASSERT_EQUAL( StringFormat::format( "%4$s %3$s %2$s %1$s", "p1", "p2", "p3", "p4" ), "p4 p3 p2 p1" );
    ASSERT_EQUAL( StringFormat::format( "%1$s %s %s %s test", "p1", "p2", "p3", "p4" ), "p1 p2 p3 p4 test" );
    ASSERT_EQUAL( StringFormat::format( "test %s %1$s %s %s", "p1", "p2", "p3", "p4" ), "test p1 p1 p3 p4" );
    ASSERT_EQUAL( StringFormat::format( "test %2$s test %s test %s test %s", "p1", "p2", "p3", "p4" ), "test p2 test p2 test p3 test p4" );

    // Tests wrong arg index in format.
    ASSERT_EQUAL( StringFormat::format( "%4$s %s", "p1", "p2", "p3", "p4" ), "p4 p2" );
    ASSERT_EQUAL( StringFormat::format( "%5$s", "p1", "p2", "p3", "p4" ), "%5$s" );
};

/*!
    \brief Tests format() with 5 format parameters.
*/
void BasicStringFormatTestCase::testFormat05() {
    // Tests no format substitution
    ASSERT_EQUAL( StringFormat::format( "Test", "p1", "p2", "p3", "p4", "p5" ), "Test" );
    ASSERT_EQUAL( StringFormat::format( "%%s", "p1", "p2", "p3", "p4", "p5" ), "%s" );
    ASSERT_EQUAL( StringFormat::format( "%s", "p1", "p2", "p3", "p4", "p5" ), "p1" );

    // Tests placement format substitution
    ASSERT_EQUAL( StringFormat::format( "%s %s %s %s %s test", "p1", "p2", "p3", "p4", "p5" ), "p1 p2 p3 p4 p5 test" );
    ASSERT_EQUAL( StringFormat::format( "test %s %s %s %s %s", "p1", "p2", "p3", "p4", "p5" ), "test p1 p2 p3 p4 p5" );
    ASSERT_EQUAL( StringFormat::format( "test %s %s %s %s %s test", "p1", "p2", "p3", "p4", "p5" ), "test p1 p2 p3 p4 p5 test" );

    // Tests arg index format substitution
    ASSERT_EQUAL( StringFormat::format( "%1$s %s %s %s %s", "p1", "p2", "p3", "p4", "p5" ), "p1 p2 p3 p4 p5" );
    ASSERT_EQUAL( StringFormat::format( "%5$s %4$s %3$s %2$s %1$s", "p1", "p2", "p3", "p4", "p5" ), "p5 p4 p3 p2 p1" );
    ASSERT_EQUAL( StringFormat::format( "%1$s %s %s %s %s test", "p1", "p2", "p3", "p4", "p5" ), "p1 p2 p3 p4 p5 test" );
    ASSERT_EQUAL( StringFormat::format( "test %s %1$s %s %s %s", "p1", "p2", "p3", "p4", "p5" ), "test p1 p1 p3 p4 p5" );
    ASSERT_EQUAL( StringFormat::format( "test %2$s test %s test %s test %s test %s", "p1", "p2", "p3", "p4", "p5" ), "test p2 test p2 test p3 test p4 test p5" );

    // Tests wrong arg index in format.
    ASSERT_EQUAL( StringFormat::format( "%5$s %s", "p1", "p2", "p3", "p4", "p5" ), "p5 p2" );
    ASSERT_EQUAL( StringFormat::format( "%6$s", "p1", "p2", "p3", "p4", "p5" ), "%6$s" );
};

/*!
    \brief Tests format() with 6 format parameters.
*/
void BasicStringFormatTestCase::testFormat06() {
    // Tests no format substitution
    ASSERT_EQUAL( StringFormat::format( "Test", "p1", "p2", "p3", "p4", "p5", "p6" ), "Test" );
    ASSERT_EQUAL( StringFormat::format( "%%s", "p1", "p2", "p3", "p4", "p5", "p6" ), "%s" );
    ASSERT_EQUAL( StringFormat::format( "%s", "p1", "p2", "p3", "p4", "p5", "p6" ), "p1" );

    // Tests placement format substitution
    ASSERT_EQUAL( StringFormat::format( "%s %s %s %s %s %s test", "p1", "p2", "p3", "p4", "p5", "p6" ),
                  "p1 p2 p3 p4 p5 p6 test" );
    ASSERT_EQUAL( StringFormat::format( "test %s %s %s %s %s %s", "p1", "p2", "p3", "p4", "p5", "p6" ),
                  "test p1 p2 p3 p4 p5 p6" );
    ASSERT_EQUAL( StringFormat::format( "test %s %s %s %s %s %s test", "p1", "p2", "p3", "p4", "p5", "p6" ),
                  "test p1 p2 p3 p4 p5 p6 test" );

    // Tests arg index format substitution
    ASSERT_EQUAL( StringFormat::format( "%1$s %s %s %s %s %s", "p1", "p2", "p3", "p4", "p5", "p6" ),
                  "p1 p2 p3 p4 p5 p6" );
    ASSERT_EQUAL( StringFormat::format( "%6$s %5$s %4$s %3$s %2$s %1$s", "p1", "p2", "p3", "p4", "p5", "p6" ),
                  "p6 p5 p4 p3 p2 p1" );
    ASSERT_EQUAL( StringFormat::format( "%1$s %s %s %s %s %s test", "p1", "p2", "p3", "p4", "p5", "p6" ),
                  "p1 p2 p3 p4 p5 p6 test" );
    ASSERT_EQUAL( StringFormat::format( "test %s %1$s %s %s %s %s", "p1", "p2", "p3", "p4", "p5", "p6" ),
                  "test p1 p1 p3 p4 p5 p6" );
    ASSERT_EQUAL( StringFormat::format( "test %2$s test %s test %s test %s test %s test %s", "p1", "p2", "p3", "p4", "p5", "p6" ),
                  "test p2 test p2 test p3 test p4 test p5 test p6" );

    // Tests wrong arg index in format.
    ASSERT_EQUAL( StringFormat::format( "%6$s %s", "p1", "p2", "p3", "p4", "p5", "p6" ), "p6 p2" );
    ASSERT_EQUAL( StringFormat::format( "%7$s", "p1", "p2", "p3", "p4", "p5", "p6" ), "%7$s" );
};

/*!
    \brief Tests format() with 7 format parameters.
*/
void BasicStringFormatTestCase::testFormat07() {
    // Tests no format substitution
    ASSERT_EQUAL( StringFormat::format( "Test", "p1", "p2", "p3", "p4", "p5", "p6", "p7" ), "Test" );
    ASSERT_EQUAL( StringFormat::format( "%%s", "p1", "p2", "p3", "p4", "p5", "p6", "p7" ), "%s" );
    ASSERT_EQUAL( StringFormat::format( "%s", "p1", "p2", "p3", "p4", "p5", "p6", "p7" ), "p1" );

    // Tests placement format substitution
    ASSERT_EQUAL( StringFormat::format( "%s %s %s %s %s %s %s test", "p1", "p2", "p3", "p4", "p5", "p6", "p7" ),
                  "p1 p2 p3 p4 p5 p6 p7 test" );
    ASSERT_EQUAL( StringFormat::format( "test %s %s %s %s %s %s %s", "p1", "p2", "p3", "p4", "p5", "p6", "p7" ),
                  "test p1 p2 p3 p4 p5 p6 p7" );
    ASSERT_EQUAL( StringFormat::format( "test %s %s %s %s %s %s %s test", "p1", "p2", "p3", "p4", "p5", "p6", "p7" ),
                  "test p1 p2 p3 p4 p5 p6 p7 test" );

    // Tests arg index format substitution
    ASSERT_EQUAL( StringFormat::format( "%1$s %s %s %s %s %s %s", "p1", "p2", "p3", "p4", "p5", "p6", "p7" ),
                  "p1 p2 p3 p4 p5 p6 p7" );
    ASSERT_EQUAL( StringFormat::format( "%7$s %6$s %5$s %4$s %3$s %2$s %1$s", "p1", "p2", "p3", "p4", "p5", "p6", "p7" ),
                  "p7 p6 p5 p4 p3 p2 p1" );
    ASSERT_EQUAL( StringFormat::format( "%1$s %s %s %s %s %s %s test", "p1", "p2", "p3", "p4", "p5", "p6", "p7" ),
                  "p1 p2 p3 p4 p5 p6 p7 test" );
    ASSERT_EQUAL( StringFormat::format( "test %s %1$s %s %s %s %s %s", "p1", "p2", "p3", "p4", "p5", "p6", "p7" ),
                  "test p1 p1 p3 p4 p5 p6 p7" );
    ASSERT_EQUAL( StringFormat::format( "test %2$s test %s test %s test %s test %s test %s test %s", "p1", "p2", "p3", "p4", "p5", "p6", "p7" ),
                  "test p2 test p2 test p3 test p4 test p5 test p6 test p7" );

    // Tests wrong arg index in format.
    ASSERT_EQUAL( StringFormat::format( "%7$s %s", "p1", "p2", "p3", "p4", "p5", "p6", "p7" ), "p7 p2" );
    ASSERT_EQUAL( StringFormat::format( "%8$s", "p1", "p2", "p3", "p4", "p5", "p6", "p7" ), "%8$s" );
};

/*!
    \brief Tests format() with 8 format parameters.
*/
void BasicStringFormatTestCase::testFormat08() {
    // Tests no format substitution
    ASSERT_EQUAL( StringFormat::format( "Test", "p1", "p2", "p3", "p4", "p5", "p6", "p7", "p8" ), "Test" );
    ASSERT_EQUAL( StringFormat::format( "%%s", "p1", "p2", "p3", "p4", "p5", "p6", "p7", "p8" ), "%s" );
    ASSERT_EQUAL( StringFormat::format( "%s", "p1", "p2", "p3", "p4", "p5", "p6", "p7", "p8" ), "p1" );

    // Tests placement format substitution
    ASSERT_EQUAL( StringFormat::format( "%s %s %s %s %s %s %s %s test", "p1", "p2", "p3", "p4", "p5", "p6", "p7", "p8" ),
                  "p1 p2 p3 p4 p5 p6 p7 p8 test" );
    ASSERT_EQUAL( StringFormat::format( "test %s %s %s %s %s %s %s %s", "p1", "p2", "p3", "p4", "p5", "p6", "p7", "p8" ),
                  "test p1 p2 p3 p4 p5 p6 p7 p8" );
    ASSERT_EQUAL( StringFormat::format( "test %s %s %s %s %s %s %s %s test", "p1", "p2", "p3", "p4", "p5", "p6", "p7", "p8" ),
                  "test p1 p2 p3 p4 p5 p6 p7 p8 test" );

    // Tests arg index format substitution
    ASSERT_EQUAL( StringFormat::format( "%1$s %s %s %s %s %s %s %s", "p1", "p2", "p3", "p4", "p5", "p6", "p7", "p8" ),
                  "p1 p2 p3 p4 p5 p6 p7 p8" );
    ASSERT_EQUAL( StringFormat::format( "%8$s %7$s %6$s %5$s %4$s %3$s %2$s %1$s", "p1", "p2", "p3", "p4", "p5", "p6", "p7", "p8" ),
                  "p8 p7 p6 p5 p4 p3 p2 p1" );
    ASSERT_EQUAL( StringFormat::format( "%1$s %s %s %s %s %s %s %s test", "p1", "p2", "p3", "p4", "p5", "p6", "p7", "p8" ),
                  "p1 p2 p3 p4 p5 p6 p7 p8 test" );
    ASSERT_EQUAL( StringFormat::format( "test %s %1$s %s %s %s %s %s %s", "p1", "p2", "p3", "p4", "p5", "p6", "p7", "p8" ),
                  "test p1 p1 p3 p4 p5 p6 p7 p8" );
    ASSERT_EQUAL( StringFormat::format( "test %2$s test %s test %s test %s test %s test %s test %s test %s", "p1", "p2", "p3", "p4", "p5", "p6", "p7", "p8" ),
                  "test p2 test p2 test p3 test p4 test p5 test p6 test p7 test p8" );

    // Tests wrong arg index in format.
    ASSERT_EQUAL( StringFormat::format( "%8$s %s", "p1", "p2", "p3", "p4", "p5", "p6", "p7", "p8" ), "p8 p2" );
    ASSERT_EQUAL( StringFormat::format( "%9$s", "p1", "p2", "p3", "p4", "p5", "p6", "p7", "p8" ), "%9$s" );
};

/*!
    \brief Tests format() with 9 format parameters.
*/
void BasicStringFormatTestCase::testFormat09() {
    // Tests no format substitution
    ASSERT_EQUAL( StringFormat::format( "Test", "p1", "p2", "p3", "p4", "p5", "p6", "p7", "p8", "p9" ), "Test" );
    ASSERT_EQUAL( StringFormat::format( "%%s", "p1", "p2", "p3", "p4", "p5", "p6", "p7", "p8", "p9" ), "%s" );
    ASSERT_EQUAL( StringFormat::format( "%s", "p1", "p2", "p3", "p4", "p5", "p6", "p7", "p8", "p9" ), "p1" );

    // Tests placement format substitution
    ASSERT_EQUAL( StringFormat::format( "%s %s %s %s %s %s %s %s %s test", "p1", "p2", "p3", "p4", "p5", "p6", "p7", "p8", "p9" ),
                  "p1 p2 p3 p4 p5 p6 p7 p8 p9 test" );
    ASSERT_EQUAL( StringFormat::format( "test %s %s %s %s %s %s %s %s %s", "p1", "p2", "p3", "p4", "p5", "p6", "p7", "p8", "p9" ),
                  "test p1 p2 p3 p4 p5 p6 p7 p8 p9" );
    ASSERT_EQUAL( StringFormat::format( "test %s %s %s %s %s %s %s %s %s test", "p1", "p2", "p3", "p4", "p5", "p6", "p7", "p8", "p9" ),
                  "test p1 p2 p3 p4 p5 p6 p7 p8 p9 test" );

    // Tests arg index format substitution
    ASSERT_EQUAL( StringFormat::format( "%1$s %s %s %s %s %s %s %s %s", "p1", "p2", "p3", "p4", "p5", "p6", "p7", "p8", "p9" ),
                  "p1 p2 p3 p4 p5 p6 p7 p8 p9" );
    ASSERT_EQUAL( StringFormat::format( "%9$s %8$s %7$s %6$s %5$s %4$s %3$s %2$s %1$s", "p1", "p2", "p3", "p4", "p5", "p6", "p7", "p8", "p9" ),
                  "p9 p8 p7 p6 p5 p4 p3 p2 p1" );
    ASSERT_EQUAL( StringFormat::format( "%1$s %s %s %s %s %s %s %s %s test", "p1", "p2", "p3", "p4", "p5", "p6", "p7", "p8", "p9" ),
                  "p1 p2 p3 p4 p5 p6 p7 p8 p9 test" );
    ASSERT_EQUAL( StringFormat::format( "test %s %1$s %s %s %s %s %s %s %s", "p1", "p2", "p3", "p4", "p5", "p6", "p7", "p8", "p9" ),
                  "test p1 p1 p3 p4 p5 p6 p7 p8 p9" );
    ASSERT_EQUAL( StringFormat::format( "test %2$s test %s test %s test %s test %s test %s test %s test %s test %s", "p1", "p2", "p3", "p4", "p5", "p6", "p7", "p8", "p9" ),
                  "test p2 test p2 test p3 test p4 test p5 test p6 test p7 test p8 test p9" );

    // Tests wrong arg index in format.
    ASSERT_EQUAL( StringFormat::format( "%9$s %s", "p1", "p2", "p3", "p4", "p5", "p6", "p7", "p8", "p9" ), "p9 p2" );
    ASSERT_EQUAL( StringFormat::format( "%10$s", "p1", "p2", "p3", "p4", "p5", "p6", "p7", "p8", "p9" ), "%10$s" );
};

/*!
    \brief Tests format() with 10 format parameters.
*/
void BasicStringFormatTestCase::testFormat10() {
    // Tests no format substitution
    ASSERT_EQUAL( StringFormat::format( "Test", "p1", "p2", "p3", "p4", "p5", "p6", "p7", "p8", "p9", "p10" ), "Test" );
    ASSERT_EQUAL( StringFormat::format( "%%s", "p1", "p2", "p3", "p4", "p5", "p6", "p7", "p8", "p9", "p10" ), "%s" );
    ASSERT_EQUAL( StringFormat::format( "%s", "p1", "p2", "p3", "p4", "p5", "p6", "p7", "p8", "p9", "p10" ), "p1" );

    // Tests placement format substitution
    ASSERT_EQUAL( StringFormat::format( "%s %s %s %s %s %s %s %s %s %s test", "p1", "p2", "p3", "p4", "p5", "p6", "p7", "p8", "p9", "p10" ),
                  "p1 p2 p3 p4 p5 p6 p7 p8 p9 p10 test" );
    ASSERT_EQUAL( StringFormat::format( "test %s %s %s %s %s %s %s %s %s %s", "p1", "p2", "p3", "p4", "p5", "p6", "p7", "p8", "p9", "p10" ),
                  "test p1 p2 p3 p4 p5 p6 p7 p8 p9 p10" );
    ASSERT_EQUAL( StringFormat::format( "test %s %s %s %s %s %s %s %s %s %s test", "p1", "p2", "p3", "p4", "p5", "p6", "p7", "p8", "p9", "p10" ),
                  "test p1 p2 p3 p4 p5 p6 p7 p8 p9 p10 test" );

    // Tests arg index format substitution
    ASSERT_EQUAL( StringFormat::format( "%1$s %s %s %s %s %s %s %s %s %s", "p1", "p2", "p3", "p4", "p5", "p6", "p7", "p8", "p9", "p10" ),
                  "p1 p2 p3 p4 p5 p6 p7 p8 p9 p10" );
    ASSERT_EQUAL( StringFormat::format( "%10$s %9$s %8$s %7$s %6$s %5$s %4$s %3$s %2$s %1$s", "p1", "p2", "p3", "p4", "p5", "p6", "p7", "p8", "p9", "p10" ),
                  "p10 p9 p8 p7 p6 p5 p4 p3 p2 p1" );
    ASSERT_EQUAL( StringFormat::format( "%1$s %s %s %s %s %s %s %s %s %s test", "p1", "p2", "p3", "p4", "p5", "p6", "p7", "p8", "p9", "p10" ),
                  "p1 p2 p3 p4 p5 p6 p7 p8 p9 p10 test" );
    ASSERT_EQUAL( StringFormat::format( "test %s %1$s %s %s %s %s %s %s %s %s", "p1", "p2", "p3", "p4", "p5", "p6", "p7", "p8", "p9", "p10" ),
                  "test p1 p1 p3 p4 p5 p6 p7 p8 p9 p10" );
    ASSERT_EQUAL( StringFormat::format( "test %2$s test %s test %s test %s test %s test %s test %s test %s test %s test %s", "p1", "p2", "p3", "p4", "p5", "p6", "p7", "p8", "p9", "p10" ),
                  "test p2 test p2 test p3 test p4 test p5 test p6 test p7 test p8 test p9 test p10" );

    // Tests wrong arg index in format.
    ASSERT_EQUAL( StringFormat::format( "%10$s %s", "p1", "p2", "p3", "p4", "p5", "p6", "p7", "p8", "p9", "p10" ), "p10 p2" );
    ASSERT_EQUAL( StringFormat::format( "%11$s", "p1", "p2", "p3", "p4", "p5", "p6", "p7", "p8", "p9", "p10" ), "%11$s" );
};

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
