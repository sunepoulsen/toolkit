//-------------------------------------------------------------------------
/*!
    \file abstracttest.cpp
    \brief
*/

//-------------------------------------------------------------------------

// Include Header File
#include "abstracttest.h"

// Include QT Files
#include <QMetaMethod>
#include <QRegExp>
#include <QStringList>

// Include Toolkit Core Files
#include <toolkit/core/format.h>
#include <toolkit/core/log.h>

//-------------------------------------------------------------------------------------------------------
using namespace Toolkit::Core;
using namespace Toolkit::Test;

//-------------------------------------------------------------------------
const QRegExp AbstractTest::TESTNAME_METHOD_PATTERN( "(test[^\\s|\\(])\\s*\\(" );

//-------------------------------------------------------------------------
AbstractTest::AbstractTest() :
    QObject(),
    m_Id()
{
};

AbstractTest::AbstractTest( const QString& id ) :
    QObject(),
    m_Id( id )
{
};

AbstractTest::AbstractTest( const AbstractTest& other ) :
    QObject(),
    m_Id( other.m_Id )
{
};

AbstractTest::~AbstractTest() {
};

QString AbstractTest::getId() const {
    if( m_Id.isNull() ) {
        return metaObject()->className();
    };
    
    return m_Id;
};

void AbstractTest::setId( const QString& newId ) {
    m_Id = newId;
};

int AbstractTest::countTests() const {
    return doCountTests();
};

QStringList AbstractTest::registerTestCallers() const {
    return doRegisterTestCallers();
};

int AbstractTest::doCountTests() const {
    return registerTestCallers().count();
};

QStringList AbstractTest::doRegisterTestCallers() const {
    Log log( Log::LT_TRACE, Log::MOD_MAIN, StringFormat::format( "QStringList AbstractTest[%s]::doRegisterTestCallers() const", metaObject()->className() ) );
    
    QRegExp rx( TESTNAME_METHOD_PATTERN );
    const QMetaObject* metaObj = metaObject();
    QStringList resList;

    log.write( Log::LT_TRACE, "Number of meta methods: %i", metaObj->methodCount() );
    QMetaMethod metaMethod;
    for( int i = 0; i < metaObj->methodCount(); i++ ) {
        metaMethod = metaObj->method( i );

        QString s = QMetaObject::normalizedSignature( metaMethod.signature() );
        if( metaMethod.methodType() == QMetaMethod::Slot && s.startsWith( "test" ) ) {
            log.write( Log::LT_TRACE, "Found method [%i]: %s::%s - OK", i, metaObj->className(), metaMethod.signature() );
            resList << s.mid( 0, s.indexOf( '(' ) );
        }
        else {
            log.write( Log::LT_TRACE, "Found method [%i]: %s::%s - FAILED", i, metaObj->className(), metaMethod.signature() );
        };
    };

    return resList;
};

AbstractTest& AbstractTest::operator=( const AbstractTest& other ) {
    m_Id = other.m_Id;

    return *this;
};

//-------------------------------------------------------------------------
FindTestById::FindTestById( const QString& id ) :
    m_Id( id )
{
};

FindTestById::~FindTestById() {
};

bool FindTestById::operator()( const QSharedPointer<AbstractTest>& test ) const {
    if( test ) {
        return test->getId() == m_Id;
    };

    return false;
};

bool FindTestById::operator()( const AbstractTest* test ) const {
    if( test ) {
        return test->getId() == m_Id;
    };

    return false;
};

bool FindTestById::operator()( const AbstractTest& test ) const {
    return test.getId() == m_Id;
};

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
