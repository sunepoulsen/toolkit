//-------------------------------------------------------------------------
/*!
    \file testsuite.cpp
    \brief
*/

//-------------------------------------------------------------------------

// Include Header File
#include "testsuite.h"

// Include QT Files
#include <QStringList>

// Include STD Files
#include <algorithm>

//-------------------------------------------------------------------------
using namespace Toolkit::Test;

//-------------------------------------------------------------------------
TestSuite::TestSuite() :
    AbstractTest(),
    m_Tests()
{
};

TestSuite::TestSuite( const QString& id ) :
    AbstractTest( id ),
    m_Tests()
{
};

TestSuite::TestSuite( const TestSuite& other ) :
    AbstractTest( other ),
    m_Tests( other.m_Tests )
{
};

TestSuite::~TestSuite() {
};

TestSuite::iterator TestSuite::begin() {
    return m_Tests.begin();
};

TestSuite::const_iterator TestSuite::begin() const {
    return m_Tests.begin();
};

TestSuite::iterator TestSuite::end() {
    return m_Tests.end();
};

TestSuite::const_iterator TestSuite::end() const {
    return m_Tests.end();
};

void TestSuite::addTest( const value_type& v ) {
    m_Tests.push_back( v );
};

void TestSuite::clear() {
    m_Tests.clear();
};

void TestSuite::erase( iterator pos ) {
    m_Tests.erase( pos );
};

void TestSuite::erase( iterator __begin, iterator __end ) {
    m_Tests.erase( __begin, __end );
};

TestSuite::iterator TestSuite::findTest( const QString& id ) {
    return std::find_if( begin(), end(), FindTestById( id ) );
};

TestSuite::const_iterator TestSuite::findTest( const QString& id ) const {
    return std::find_if( begin(), end(), FindTestById( id ) );
};

TestSuite::size_type TestSuite::size() const {
    return m_Tests.size();
};

TestSuite& TestSuite::operator=( const TestSuite& other ) {
    AbstractTest::operator=( other );
    m_Tests = other.m_Tests;

    return *this;
};

TestSuite::reference TestSuite::operator[]( size_type n ) {
    return m_Tests[ n ];
};

TestSuite::const_reference TestSuite::operator[]( size_type n ) const {
    return m_Tests[ n ];
};

int TestSuite::doCountTests() const {
    int result = 0;
    
    for( const_iterator it = begin(); it != end(); ++it ) {
        result += (*it)->countTests();
    };
    
    result += registerTestCallers().count();
    
    return result;
};

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
