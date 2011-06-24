//-------------------------------------------------------------------------
/*!
    \file qttestcase.cpp
    \brief
*/

//-------------------------------------------------------------------------

// Include Header File
#include "qttestcase.h"

// Include Toolkit Test Files
#include <toolkit/test/testcase.h>

// Include Qt Files
#include <QDir>
#include <QRegExp>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QUrl>

//-------------------------------------------------------------------------
using namespace Toolkit::Core;
using namespace Toolkit::Test;

//-------------------------------------------------------------------------
const QString QtTestCase::SQLITE_DRIVER_NAME( "QSQLITE" );
const QString QtTestCase::CODEC_LATIN1_NAME( "latin1" );
const QString QtTestCase::CODEC_ISO88591_NAME( "ISO 8859-1" );
const QString QtTestCase::CODEC_UTF8_NAME( "UTF-8" );
const QString QtTestCase::CODEC_UTF16_NAME( "UTF-16" );

//-------------------------------------------------------------------------
QtTestCase::QtTestCase() :
    TestCase()
{
}

QtTestCase::~QtTestCase() {
}

void QtTestCase::testCodecNames() {
    ASSERT_WARNING_TRUE_MESSAGE( StringFormat::format( "Qt does not have a text codec for %s", CODEC_LATIN1_NAME ),
                                 QTextCodec::codecForName( CODEC_LATIN1_NAME.toLatin1().data() ) );
    ASSERT_WARNING_TRUE_MESSAGE( StringFormat::format( "Qt does not have a text codec for %s", CODEC_ISO88591_NAME ),
                                 QTextCodec::codecForName( CODEC_ISO88591_NAME.toLatin1().data() ) );
    ASSERT_WARNING_TRUE_MESSAGE( StringFormat::format( "Qt does not have a text codec for %s", CODEC_UTF8_NAME ),
                                 QTextCodec::codecForName( CODEC_UTF8_NAME.toLatin1().data() ) );
    ASSERT_WARNING_TRUE_MESSAGE( StringFormat::format( "Qt does not have a text codec for %s", CODEC_UTF16_NAME ),
                                 QTextCodec::codecForName( CODEC_UTF16_NAME.toLatin1().data() ) );
}

void QtTestCase::testQDir() {
    ASSERT_TRUE( QDir::current().root().path().endsWith( QDir::separator() ) );
    ASSERT_FALSE( QDir::current().path().endsWith( QDir::separator() ) );
}

void QtTestCase::testRegExpWildcards() {
    QRegExp rx;
    rx.setPatternSyntax( QRegExp::Wildcard );

    rx.setPattern( "" );
    ASSERT_EQUAL( rx.indexIn( "" ), 0 );
    ASSERT_EQUAL( rx.indexIn( "Test" ), 0 );
}

void QtTestCase::testQUrl() {
    QUrl url;

    url = "Toolkit.Core";
    ASSERT_EQUAL( url.scheme(), "" );
    ASSERT_EQUAL( url.userName(), "" );
    ASSERT_EQUAL( url.password(), "" );
    ASSERT_EQUAL( url.host(), "" );
    ASSERT_EQUAL( url.port(), -1 );
    ASSERT_EQUAL( url.path(), "Toolkit.Core" );
    ASSERT_EQUAL( url.hasQuery(), false );
    ASSERT_EQUAL( url.fragment(), "" );

    url = "Toolkit.Core.*";
    ASSERT_EQUAL( url.scheme(), "" );
    ASSERT_EQUAL( url.userName(), "" );
    ASSERT_EQUAL( url.password(), "" );
    ASSERT_EQUAL( url.host(), "" );
    ASSERT_EQUAL( url.port(), -1 );
    ASSERT_EQUAL( url.path(), "Toolkit.Core.*" );
    ASSERT_EQUAL( url.hasQuery(), false );
    ASSERT_EQUAL( url.fragment(), "" );
}

void QtTestCase::testDatabaseDrivers() {
    ASSERT_WARNING_TRUE_MESSAGE( "Qt does not include the SQLITE database driver", QSqlDatabase::isDriverAvailable( SQLITE_DRIVER_NAME ) );

    QSqlDatabase sqlite = QSqlDatabase::addDatabase( SQLITE_DRIVER_NAME );
    ASSERT_WARNING_EQUAL( sqlite.driver()->hasFeature( QSqlDriver::SimpleLocking ), true );
    QSqlDatabase::removeDatabase( sqlite.connectionName() );
}

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
