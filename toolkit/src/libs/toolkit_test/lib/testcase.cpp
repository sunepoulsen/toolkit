//-------------------------------------------------------------------------
/*!
    \file testcase.cpp
    \brief
*/

//-------------------------------------------------------------------------

// Include Header File
#include "testcase.h"

// Include STD Files
#include <algorithm>

//-------------------------------------------------------------------------
using namespace Toolkit::Test;

//-------------------------------------------------------------------------
TestCase::TestCase() :
    AbstractTest(),
    m_Assert()
{
};

TestCase::TestCase( const TestCase& other ) :
    AbstractTest( other ),
    m_Assert( other.m_Assert )
{
};

TestCase::~TestCase() {
};

Assert& TestCase::getAssert() {
    return m_Assert;
};

const Assert& TestCase::getAssert() const {
    return m_Assert;
};

void TestCase::setAssert( const Assert& newAssert ) {
    m_Assert = newAssert;
};

void TestCase::beforeExecuteClass() {
    doBeforeExecuteClass();
};

void TestCase::afterExecuteClass() {
    doAfterExecuteClass();
};

void TestCase::beforeExecute() {
    doBeforeExecute();
};

void TestCase::afterExecute() {
    doAfterExecute();
};

TestCase& TestCase::operator=( const TestCase& other ) {
    AbstractTest::operator=( other );
    m_Assert = other.m_Assert;

    return *this;
};

void TestCase::doBeforeExecuteClass() {
};

void TestCase::doAfterExecuteClass() {
};

void TestCase::doBeforeExecute() {
};

void TestCase::doAfterExecute() {
};

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
