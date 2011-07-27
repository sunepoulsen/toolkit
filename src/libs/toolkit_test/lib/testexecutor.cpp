//-------------------------------------------------------------------------
/*!
    \file testexecutor.cpp
    \brief
*/

//-------------------------------------------------------------------------

// Include Header File
#include "testexecutor.h"

// Include Toolkit Test Files
#include "assertrequireexception.h"
#include "assertcriticalexception.h"
#include "assertfatalexception.h"

// Include Toolkit Core Files
#include <toolkit/core/log.h>

// Include QT Files
#include <QStringList>

//-------------------------------------------------------------------------
using namespace Toolkit::Core;
using namespace Toolkit::Test;

//-------------------------------------------------------------------------
TestExecutor::TestExecutor() :
    m_Tests(),
    m_Assert(),
    m_Report()
{
};

TestExecutor::TestExecutor( const AbstractReportPtr& report ) :
    m_Tests(),
    m_Assert(),
    m_Report( report )
{
};

TestExecutor::TestExecutor( const TestExecutor& other ) :
    m_Tests( other.m_Tests ),
    m_Assert( other.m_Assert ),
    m_Report( other.m_Report )
{
};

TestExecutor::~TestExecutor() {
};

Assert& TestExecutor::getAssert() {
    return m_Assert;
};

const Assert& TestExecutor::getAssert() const {
    return m_Assert;
};

void TestExecutor::setAssert( const Assert& newAssert ) {
    m_Assert = newAssert;
};

AbstractReportPtr& TestExecutor::getReport() {
    return m_Report;
};

const AbstractReportPtr& TestExecutor::getReport() const {
    return m_Report;
};

void TestExecutor::setReport( const AbstractReportPtr& newReport ) {
    m_Report = newReport;
};

TestExecutor::iterator TestExecutor::begin() {
    return m_Tests.begin();
};

TestExecutor::const_iterator TestExecutor::begin() const {
    return m_Tests.begin();
};

TestExecutor::iterator TestExecutor::end() {
    return m_Tests.end();
};

TestExecutor::const_iterator TestExecutor::end() const {
    return m_Tests.end();
};

void TestExecutor::addTest( const value_type& v ) {
    m_Tests.addTest( v );
};

void TestExecutor::clear() {
    m_Tests.clear();
};

void TestExecutor::erase( iterator pos ) {
    m_Tests.erase( pos );
};

void TestExecutor::erase( iterator __begin, iterator __end ) {
    m_Tests.erase( __begin, __end );
};

TestExecutor::iterator TestExecutor::findTest( const QString& id ) {
    return m_Tests.findTest( id );
};

TestExecutor::const_iterator TestExecutor::findTest( const QString& id ) const {
    return m_Tests.findTest( id );
};

TestExecutor::size_type TestExecutor::size() const {
    return m_Tests.size();
};

void TestExecutor::execute() {
    Log log( Log::LT_INFO, Log::MOD_MAIN, "void TestExecutor::execute()" );
    
    m_Assert.setReport( m_Report.data() );
    
    DeviceFormat::write( stdout, "Executes %i test(s).\n\n", m_Tests.countTests() );
    m_Report->beginReport();
    for( iterator it = begin(); it != end(); ++it ) {
        executeTest( it );
    };
    m_Report->endReport();
};

void TestExecutor::executeTest( iterator it ) {
    Log log( Log::LT_INFO, Log::MOD_MAIN, "void TestExecutor::executeTest()" );
    log.write( Log::LT_INFO, "(*it)->getId(): %ds", (*it)->getId() );
    
    TestSuite* suite = dynamic_cast<TestSuite*>( it->data() );
    if( suite ) {
        executeTestSuite( *suite );
        return;
    };

    TestCase* testCase = dynamic_cast<TestCase*>( it->data() );
    if( testCase ) {
        executeTestCase( *testCase );
        return;
    };
};

void TestExecutor::executeTestSuite( TestSuite& suite ) {
    Log log( Log::LT_INFO, Log::MOD_MAIN, "void TestExecutor::executeTestSuite()" );
    log.write( Log::LT_TRACE, "Id: %s", suite.getId() );
    
    try {
        m_Report->beginTest( &suite );
        for( iterator it = suite.begin(); it != suite.end(); ++it ) {
            executeTest( it );
        };
        m_Report->endTest( &suite );
    }
    catch( AssertFatalException& e ) {
        log.write( Log::LT_ERROR, "Fatal exception in TestSuite %s: %s", suite.getId(), e.getMessage() );
    };
};

void TestExecutor::executeTestCase( TestCase& testCase ) {
    Log log( Log::LT_INFO, Log::MOD_MAIN, StringFormat::format( "void TestExecutor::executeTestCase( %s )", testCase.getId() ) );
    
    testCase.setAssert( m_Assert );
    testCase.beforeExecuteClass();
    
    try {
        m_Report->beginTest( &testCase );
        
        QStringList testFuncs = testCase.registerTestCallers();
        for( QStringList::const_iterator it = testFuncs.begin(); it != testFuncs.end(); ++it ) {
            testCase.beforeExecute();
            
            log.beginGroup( Log::LT_TRACE, StringFormat::format( "Run test %s::%s", testCase.getId(), *it ) );
            try {
                m_Report->beginExecuteTest( &testCase, it->toAscii() );
                QMetaObject::invokeMethod( &testCase, it->toAscii(), Qt::DirectConnection );
                m_Report->endExecuteTest( &testCase, it->toAscii() );
            }
            catch( AssertRequireException& e ) {
                log.write( Log::LT_ERROR, "Required exception in test function %s::%s: %s", testCase.getId(), *it, e.getMessage() );
            };
            log.endGroup();

            testCase.afterExecute();        
        };
    
        m_Report->endTest( &testCase );
    }
    catch( AssertCriticalException& e ) {
        log.write( Log::LT_ERROR, "Critical exception in test case %s: %s", testCase.getId(), e.getMessage() );
    };
    
    testCase.afterExecuteClass();
};

TestExecutor& TestExecutor::operator=( const TestExecutor& other ) {
    m_Tests = other.m_Tests;
    
    return *this;
};

TestExecutor::reference TestExecutor::operator[]( size_type n ) {
    return m_Tests[ n ];
};

TestExecutor::const_reference TestExecutor::operator[]( size_type n ) const {
    return m_Tests[ n ];
};

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
