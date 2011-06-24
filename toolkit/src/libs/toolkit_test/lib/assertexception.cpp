//---------------------------------------------------------------------------------------
/*!
    \file assertexception.cpp
    \brief 
*/

//---------------------------------------------------------------------------------------

// Include Header File
#include "assertexception.h"

//-------------------------------------------------------------
using namespace Toolkit::Core;
using namespace Toolkit::Test;

//-------------------------------------------------------------
AssertException::AssertException( const SourceLine& srcLine, const QString& message ) :
    Exception( srcLine, message ),
    m_TestResult()
{
};

AssertException::AssertException( const AssertException& other ) :
    Exception( other ),
    m_TestResult( other.m_TestResult )
{
};
    
AssertException::~AssertException() {
};

const TestResult& AssertException::getTestResult() const {
    return m_TestResult;
};

void AssertException::setTestResult( const TestResult& newTestResult ) {
    m_TestResult = newTestResult;
};

AssertException& AssertException::operator=( const AssertException& other ) {
    Exception::operator=( other );
    m_TestResult = other.m_TestResult;
    
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
