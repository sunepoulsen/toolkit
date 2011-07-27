//-------------------------------------------------------------------------
/*!
    \file testresult.cpp
    \brief
*/

//-------------------------------------------------------------------------

// Include Header File
#include "testresult.h"

//-------------------------------------------------------------------------
using namespace Toolkit::Core;
using namespace Toolkit::Test;

//-------------------------------------------------------------------------
const int TestResult::ASSERT_EQUAL( 1 );
const int TestResult::ASSERT_NOT_EQUAL( 2 );
const int TestResult::ASSERT_EXCEPTION( 3 );
const int TestResult::ASSERT_WRONG_EXCEPTION( 4 );
const int TestResult::ASSERT_TRUE( 5 );
const int TestResult::ASSERT_FALSE( 6 );
const int TestResult::ASSERT_FAIL( 7 );

//-------------------------------------------------------------------------
TestResult::TestResult() :
    m_AssertType(),
    m_ResultType(),
    m_SourceLine(),
    m_Message()
{
};

TestResult::TestResult( const TestResult& other ) :
    m_AssertType( other.m_AssertType ),
    m_ResultType( other.m_ResultType ),
    m_SourceLine( other.m_SourceLine ),
    m_Message( other.m_Message )
{
};

TestResult::~TestResult() {
};

int TestResult::getAssertType() const {
    return m_AssertType;
};

void TestResult::setAssertType( const int newAssertType ) {
    m_AssertType = newAssertType;
};

const TestResultType& TestResult::getResultType() const {
    return m_ResultType;
};

void TestResult::setResultType( const TestResultType& newResultType ) {
    m_ResultType = newResultType;
};

const SourceLine& TestResult::getSourceLine() const {
    return m_SourceLine;
};

void TestResult::setSourceLine( const SourceLine& newSourceLine ) {
    m_SourceLine = newSourceLine;
};

const QString& TestResult::getMessage() const {
    return m_Message;
};

void TestResult::setMessage( const QString& newMessage ) {
    m_Message = newMessage;
};

QString TestResult::toAssertTypeString() const {
    switch( getAssertType() ) {
    case ASSERT_EQUAL:     return "ASSERT_EQUAL";
    case ASSERT_NOT_EQUAL: return "ASSERT_NOT_EQUAL";
    case ASSERT_EXCEPTION: return "ASSERT_EXCEPTION";
    case ASSERT_TRUE:      return "ASSERT_TRUE";
    case ASSERT_FALSE:     return "ASSERT_FALSE";
    case ASSERT_FAIL:      return "ASSERT_FAIL";
    };
    
    return "CUSTOM";
};

TestResult& TestResult::operator=( const TestResult& other ) {
    m_AssertType = other.m_AssertType;
    m_ResultType = other.m_ResultType;
    m_SourceLine = other.m_SourceLine;
    m_Message = other.m_Message;

    return *this;
};

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
