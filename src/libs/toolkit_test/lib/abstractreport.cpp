//-------------------------------------------------------------------------
/*!
    \file abstractreport.cpp
    \brief
*/

//-------------------------------------------------------------------------

// Include Header File
#include "abstractreport.h"

// Include UnitTests Files
#include "abstracttest.h"
#include "assert.h"

//-------------------------------------------------------------------------
using namespace Toolkit::Test;

//-------------------------------------------------------------------------
AbstractReport::AbstractReport() :
    m_Id()
{
};

AbstractReport::AbstractReport( const AbstractReport& other ) :
    m_Id( other.m_Id )
{
};

AbstractReport::~AbstractReport() {
};

const QString& AbstractReport::getId() const {
    return m_Id;
};

void AbstractReport::setId( const QString& newId ) {
    m_Id = newId;
};

void AbstractReport::beginReport() {
    doBeginReport();
};

void AbstractReport::endReport() {
    doEndReport();
};

void AbstractReport::beginTest( const AbstractTest* test ) {
    doBeginTest( test );
};

void AbstractReport::endTest( const AbstractTest* test ) {
    doEndTest( test );
};

void AbstractReport::beginExecuteTest( const AbstractTest* test, const QString& testId ) {
    doBeginExecuteTest( test, testId );
};

void AbstractReport::endExecuteTest( const AbstractTest* test, const QString& testId ) {
    doEndExecuteTest( test, testId );
};

bool AbstractReport::willWriteResultType( const TestResultType& resType ) const {
    return doWillWriteResultType( resType );
};

void AbstractReport::writeAssertEqual( const TestResult& testRes, const std::pair<QString, QString>& expr, const std::pair<QString, QString>& exprValue ) {
    doWriteAssertEqual( testRes, expr, exprValue );
};

void AbstractReport::writeAssertException( const TestResult& testRes, const QString& expName, const QString& expMessage ) {
    doWriteAssertException( testRes, expName, expMessage );
};

void AbstractReport::writeAssert( const TestResult& testRes ) {
    doWriteAssert( testRes );
};

void AbstractReport::clearResults() {
    m_Results.clear();
    
    m_Results.insert( std::make_pair( TestResultType::RT_OK, 0 ) );
    m_Results.insert( std::make_pair( TestResultType::RT_WARNING, 0 ) );
    m_Results.insert( std::make_pair( TestResultType::RT_REQUIRED, 0 ) );
    m_Results.insert( std::make_pair( TestResultType::RT_FAILURE, 0 ) );
    m_Results.insert( std::make_pair( TestResultType::RT_CRITICAL, 0 ) );
    m_Results.insert( std::make_pair( TestResultType::RT_FATAL, 0 ) );
};

void AbstractReport::addResult( const TestResultType& resType ) {
    m_Results[ resType.getResultType() ]++;
};

int AbstractReport::countResult( int key ) const {
    results_container_type::const_iterator it = m_Results.find(  key  );
    if( it != m_Results.end() ) {
        return it->second;
    };
    
    return 0;
};

int AbstractReport::countResultErrors() const {
    int i = 0;
    
    i += countResult( TestResultType::RT_REQUIRED );
    i += countResult( TestResultType::RT_FAILURE );
    i += countResult( TestResultType::RT_CRITICAL );
    i += countResult( TestResultType::RT_FATAL );
    
    return i;
};

AbstractReport& AbstractReport::operator=( const AbstractReport& other ) {
    m_Id = other.m_Id;
    m_Results = other.m_Results;

    return *this;
};

void AbstractReport::doBeginReport() {
};

void AbstractReport::doEndReport() {
};

void AbstractReport::doBeginTest( const AbstractTest* ) {
};

void AbstractReport::doEndTest( const AbstractTest* ) {
};

void AbstractReport::doBeginExecuteTest( const AbstractTest*, const QString& ) {
};

void AbstractReport::doEndExecuteTest( const AbstractTest*, const QString& ) {
};

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
