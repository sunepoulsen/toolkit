//-------------------------------------------------------------------------
/*!
    \file assert.cpp
    \brief
*/

//-------------------------------------------------------------------------

// Include Header File
#include "assert.h"

// Include Toolkit Test Files
#include "abstractreport.h"
#include "assertrequireexception.h"
#include "assertcriticalexception.h"
#include "assertfatalexception.h"

//-------------------------------------------------------------------------
using namespace Toolkit::Core;
using namespace Toolkit::Test;

//-------------------------------------------------------------------------
Assert::Assert() :
    QObject(),
    m_Report( NULL )
{
};

Assert::Assert( const Assert& other ) :
    QObject(),
    m_Report( other.m_Report )
{
};

Assert::~Assert() {
};

AbstractReport* Assert::getReport() {
    return m_Report;
};

const AbstractReport* Assert::getReport() const {
    return m_Report;
};

void Assert::setReport( AbstractReport* newReport ) {
    m_Report = newReport;
};

void Assert::assertException( const Toolkit::Core::SourceLine& srcLine, int assertType, const QString& message, const TestResultType& resType, const QString& expName, const QString& expMessage ) const {
    TestResult testRes;

    testRes.setAssertType( assertType );
    testRes.setSourceLine( srcLine );
    testRes.setResultType( TestResultType( resType ) );
    testRes.setMessage( message );
    
    m_Report->addResult( testRes.getResultType() );
    if( m_Report->willWriteResultType( testRes.getResultType() ) ) {
        m_Report->writeAssertException( testRes, expName, expMessage );
    };

    throwAssertException( srcLine, testRes.getResultType().getResultType(), message );
};

void Assert::assertFail( const Toolkit::Core::SourceLine& srcLine, const TestResultType& res, const QString& message ) const {
    TestResult testRes;

    testRes.setAssertType( TestResult::ASSERT_FAIL );
    testRes.setSourceLine( srcLine );
    testRes.setResultType( TestResultType( res ) );
    testRes.setMessage( message );
    
    m_Report->addResult( testRes.getResultType() );
    if( m_Report->willWriteResultType( testRes.getResultType() ) ) {
        m_Report->writeAssert( testRes );
    };

    throwAssertException( srcLine, testRes.getResultType().getResultType(), message );
};

Assert& Assert::operator=( const Assert& other ) {
    m_Report = other.m_Report;

    return *this;
};

void Assert::throwAssertException( const Toolkit::Core::SourceLine& srcLine, const TestResultType& res, const QString& message ) const {
    if( res.getResultType() == TestResultType::RT_REQUIRED ) {
        throw AssertRequireException( srcLine, message );
    }
    else if( res.getResultType() == TestResultType::RT_CRITICAL ) {
        throw AssertCriticalException( srcLine, message );
    }
    else if( res.getResultType() == TestResultType::RT_FATAL ) {
        throw AssertFatalException( srcLine, message );
    };
};

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
