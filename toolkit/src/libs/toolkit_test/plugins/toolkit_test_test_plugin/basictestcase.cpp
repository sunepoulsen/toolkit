//-------------------------------------------------------------------------
/*!
    \file basictestcase.cpp
    \brief
*/

//-------------------------------------------------------------------------

// Include Header File
#include "basictestcase.h"

// Include Toolkit Core Files
#include <toolkit/core/log.h>

// Include Toolkit Test Files
#include <toolkit/test/defaultassertwriter.h>

#include <math.h>

//-------------------------------------------------------------------------
using namespace Toolkit::Core;
using namespace Toolkit::Test;

//-------------------------------------------------------------------------
BasicTestCase::BasicTestCase() :
    TestCase()
{
};

BasicTestCase::~BasicTestCase() {
};

void BasicTestCase::testAssertEqualImplChars() {
    Log log( Log::LT_INFO, Log::MOD_MAIN, "void BasicTestCase::testAssertEqualImplChars()" );
    
    ASSERT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, "", "" );
    ASSERT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, "Linux", "Linux" );
};

void BasicTestCase::testAssertEqualImplStrings() {
    Log log( Log::LT_INFO, Log::MOD_MAIN, "void BasicTestCase::testAssertEqualImplQString()" );
    
    QString s = "";
    ASSERT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, s, s );
    
    s = "Linux";
    ASSERT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, s, s );
    ASSERT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, s, "Linux" );
    ASSERT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, "Linux", s );
    ASSERT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, s.toStdString(), "Linux" );
    ASSERT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, "Linux", s.toStdString() );
    ASSERT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, s.toStdString(), s.toStdString() );
};

void BasicTestCase::testAssertEqualImplBools() {
    ASSERT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, true, true );
    ASSERT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, false, false );
};

void BasicTestCase::testAssertEqualImplInts() {
    ASSERT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, int( 1 ), int( 1 ) );
    ASSERT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, int( 1 ), long( 1 ) );
    ASSERT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, int( 1 ), qlonglong( 1 ) );
    
    ASSERT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, uint( 1 ), uint( 1 ) );
    ASSERT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, uint( 1 ), ulong( 1 ) );
    ASSERT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, uint( 1 ), qulonglong( 1 ) );    
    
    ASSERT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, long( 1 ), long( 1 ) );
    ASSERT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, long( 1 ), int( 1 ) );
    ASSERT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, long( 1 ), qlonglong( 1 ) );
    
    ASSERT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, ulong( 1 ), ulong( 1 ) );    
    ASSERT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, ulong( 1 ), uint( 1 ) );    
    ASSERT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, ulong( 1 ), qulonglong( 1 ) );    

    ASSERT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, qlonglong( 1 ), qlonglong( 1 ) );
    ASSERT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, qlonglong( 1 ), long( 1 ) );
    ASSERT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, qlonglong( 1 ), int( 1 ) );
    
    ASSERT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, qulonglong( 1 ), qulonglong( 1 ) );    
    ASSERT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, qulonglong( 1 ), uint( 1 ) );    
    ASSERT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, qulonglong( 1 ), ulong( 1 ) );    
    
    ASSERT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, double( 1.5 ), double( 1.5 ) );    
    ASSERT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, double( 2.0 ), int( 2 ) );
};

void BasicTestCase::testAssertEqualImplArrays() {
    const char* c1 = "Linux";
    QByteArray b1 = "Linux";
    QByteArray b2 = b1;
    QString s( b1 );

    ASSERT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, b1, b2 );
    ASSERT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, b1, c1 );
    ASSERT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, c1, b2 );
    ASSERT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, b1, s.toLatin1() );
    ASSERT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, s.toLatin1(), b2 );
};

void BasicTestCase::testAssertEqualImplDateTimes() {
    QDate d = QDate::currentDate();
    ASSERT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, d, d );
    
    QTime t = QTime::currentTime();
    ASSERT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, t, t );

    QDateTime dt = QDateTime::currentDateTime();
    ASSERT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, dt, dt );
};

void BasicTestCase::testAssertNotEqualImplChars() {
    ASSERT_NOT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, "", "(null)" );
    ASSERT_NOT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, "Linux", "LINUX" );
};

void BasicTestCase::testAssertNotEqualImplStrings() {
    QString s1 = "Unix";
    QString s2 = "Mac";
    ASSERT_NOT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, s1, s2 );
    
    ASSERT_NOT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, s1, s2 );
    ASSERT_NOT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, s1, "Linux" );
    ASSERT_NOT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, "Linux", s2 );
    ASSERT_NOT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, s1.toStdString(), "Linux" );
    ASSERT_NOT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, "Linux", s2.toStdString() );
    ASSERT_NOT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, s1.toStdString(), s2.toStdString() );
};

void BasicTestCase::testAssertNotEqualImplBools() {
    ASSERT_NOT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, true, false );
    ASSERT_NOT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, false, true );
};

void BasicTestCase::testAssertNotEqualImplInts() {
    ASSERT_NOT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, int( 1 ), int( 2 ) );
    ASSERT_NOT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, int( 1 ), long( 2 ) );
    ASSERT_NOT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, int( 1 ), qlonglong( 2 ) );
    
    ASSERT_NOT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, uint( 1 ), uint( 2 ) );
    ASSERT_NOT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, uint( 1 ), ulong( 2 ) );
    ASSERT_NOT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, uint( 1 ), qulonglong( 2 ) );    
    
    ASSERT_NOT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, long( 1 ), long( 2 ) );
    ASSERT_NOT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, long( 1 ), int( 2 ) );
    ASSERT_NOT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, long( 1 ), qlonglong( 2 ) );
    
    ASSERT_NOT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, ulong( 1 ), ulong( 2 ) );    
    ASSERT_NOT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, ulong( 1 ), uint( 2 ) );    
    ASSERT_NOT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, ulong( 1 ), qulonglong( 2 ) );    

    ASSERT_NOT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, qlonglong( 1 ), qlonglong( 2 ) );
    ASSERT_NOT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, qlonglong( 1 ), long( 2 ) );
    ASSERT_NOT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, qlonglong( 1 ), int( 2 ) );
    
    ASSERT_NOT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, qulonglong( 1 ), qulonglong( 2 ) );    
    ASSERT_NOT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, qulonglong( 1 ), uint( 2 ) );    
    ASSERT_NOT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, qulonglong( 1 ), ulong( 2 ) );    
    
    ASSERT_NOT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, double( 1.5 ), double( 1.7 ) );    
    ASSERT_NOT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, double( 2.0 ), int( 4 ) );
};

void BasicTestCase::testAssertNotEqualImplArrays() {
    const char* c1 = "c1";
    QByteArray b1 = "b1";
    QByteArray b2 = "b2";
    QString s( "s" );

    ASSERT_NOT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, b1, b2 );
    ASSERT_NOT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, b1, c1 );
    ASSERT_NOT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, c1, b2 );
    ASSERT_NOT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, b1, s.toLatin1() );
    ASSERT_NOT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, s.toLatin1(), b2 );
};

void BasicTestCase::testAssertNotEqualImplDateTimes() {
    QDate d = QDate::currentDate();
    ASSERT_NOT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, d, d.addDays( 1 ) );
    
    QTime t = QTime::currentTime();
    ASSERT_NOT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, t, t.addSecs( 1 ) );

    QDateTime dt = QDateTime::currentDateTime();
    ASSERT_NOT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, dt, dt.addDays( 1 ) );
};

void BasicTestCase::testAssertTrue() {
    ASSERT_TRUE_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, true );
};

void BasicTestCase::testAssertFalse() {
    ASSERT_FALSE_IMPL( DefaultAssertWriter(), TestResultType::RT_FAILURE, false );
};

void BasicTestCase::testAssertFail() {
    return;
    
    ASSERT_FAIL_IMPL( TestResultType::RT_FAILURE, "ASSERT_FAIL with message" );
};

void BasicTestCase::testAssertRequired() {
    return;
    
    ASSERT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_REQUIRED, 1, 2 );
    ASSERT_FAIL_IMPL( TestResultType::RT_FAILURE, "This assert should never run!" );
};

void BasicTestCase::testAssertCriticals() {
    return;
    
    ASSERT_EQUAL_IMPL( DefaultAssertWriter(), TestResultType::RT_CRITICAL, 1, 2 );
    ASSERT_FAIL_IMPL( TestResultType::RT_FAILURE, "This assert should never run!" );
};

void BasicTestCase::testAssertFatal() {
    return;
    
    ASSERT_FAIL_IMPL( TestResultType::RT_FAILURE, "This assert should never run!" );
};

//-------------------------------------------------------------------------
MacroTestCase::MacroTestCase() :
    TestCase()
{
};

MacroTestCase::~MacroTestCase() {
};

void MacroTestCase::testAssertFailureMacros() {
    ASSERT_EQUAL( 1, 1 );
    ASSERT_EQUAL_MESSAGE( "ASSERT_EQUAL_MESSAGE", 1, 1 );

    ASSERT_NOT_EQUAL( 1, 2 );
    ASSERT_NOT_EQUAL_MESSAGE( "ASSERT_EQUAL_MESSAGE", 1, 2 );
    
    ASSERT_TRUE( true );
    ASSERT_FALSE( false );
    
    ASSERT_OK( "ASSERT_OK" );
    
    ASSERT_EXCEPTION( StringFormat::format( "%s", 5 ), FormatException );
    ASSERT_NO_EXCEPTION( StringFormat::format( "%i", 5 ) );    
};

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
