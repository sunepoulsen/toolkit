//-------------------------------------------------------------------------
/*!
    \file testresulttype.cpp
    \brief
*/

//-------------------------------------------------------------------------

// Include Header File
#include "testresulttype.h"

//-------------------------------------------------------------------------
using namespace Toolkit::Test;

//-------------------------------------------------------------------------
TestResultType::TestResultType() :
    m_ResultType( RT_OK )
{
};

TestResultType::TestResultType( ResultType resType ) :
    m_ResultType( resType )
{
};

TestResultType::TestResultType( const TestResultType& other ) :
    m_ResultType( other.m_ResultType )
{
};

TestResultType::~TestResultType() {
};

TestResultType::ResultType TestResultType::getResultType() const {
    return m_ResultType;
};

void TestResultType::setResultType( ResultType newResultType ) {
    m_ResultType = newResultType;
};

QString TestResultType::toString() const {
    switch( m_ResultType ) {
    case RT_OK:       return "OK";
    case RT_WARNING:  return "WARNING";
    case RT_REQUIRED: return "REQUIRED";
    case RT_FAILURE:  return "FAILURE";
    case RT_CRITICAL: return "CRITICAL";
    case RT_FATAL:    return "FATAL";
    };
    
    return "UNKNOWN";
};

TestResultType& TestResultType::operator=( const TestResultType& other ) {
    m_ResultType = other.m_ResultType;

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
