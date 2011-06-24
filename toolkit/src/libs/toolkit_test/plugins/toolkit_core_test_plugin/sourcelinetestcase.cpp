//-------------------------------------------------------------------------
/*!
    \file sourcelinetestcase.cpp
    \brief
*/

//-------------------------------------------------------------------------

// Include Header File
#include "sourcelinetestcase.h"

// Include Toolkit Core Files
#include <toolkit/core/sourceline.h>

// Include STD Files
#include <limits>

//-------------------------------------------------------------------------
using namespace Toolkit::Core;

//-------------------------------------------------------------------------
typedef std::numeric_limits<Toolkit::Core::SourceLine::size_type> size_limit;

//-------------------------------------------------------------------------
SourceLineTestCase::SourceLineTestCase() :
    TestCase()
{
};

SourceLineTestCase::~SourceLineTestCase() {
};

void SourceLineTestCase::testConstructors() {
    SourceLine s1;
    
    ASSERT_EQUAL( s1.getFileName(), "" );
    ASSERT_EQUAL( s1.getLineNumber(), 0U );
};

void SourceLineTestCase::testMacro() {
    SourceLine s1 = SOURCELINE;
    
    ASSERT_EQUAL( s1.getFileName(), __FILE__ );
    ASSERT_EQUAL( s1.getLineNumber(), __LINE__ - 3U );
};

void SourceLineTestCase::testFileName() {
    SourceLine s1;
    QString s;
    
    s = "(empty)";
    s1.setFileName( s );
    ASSERT_EQUAL( s1.getFileName(), s );
    
    s = "/\\;:- ";
    s1.setFileName( s );
    ASSERT_EQUAL( s1.getFileName(), s );

    s = __FILE__;
    s1.setFileName( s );
    ASSERT_EQUAL( s1.getFileName(), s );
};

void SourceLineTestCase::testLineNumber() {
    SourceLine s1;
    SourceLine::size_type n;
    
    n = 15;
    s1.setLineNumber( n );
    ASSERT_EQUAL( s1.getLineNumber(), n );    

    n = size_limit::min();
    s1.setLineNumber( n );
    ASSERT_EQUAL( s1.getLineNumber(), n );    

    n = size_limit::max();
    s1.setLineNumber( n );
    ASSERT_EQUAL( s1.getLineNumber(), n );    
};

void SourceLineTestCase::testOpAssign() {
    SourceLine s1 = SOURCELINE;
    SourceLine s2;
    
    ASSERT_NOT_EQUAL( s1.getFileName(), s2.getFileName() );
    ASSERT_NOT_EQUAL( s1.getLineNumber(), s2.getLineNumber() );
    
    s2 = s1;
    ASSERT_EQUAL( s1.getFileName(), s2.getFileName() );
    ASSERT_EQUAL( s1.getLineNumber(), s2.getLineNumber() );
};

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
