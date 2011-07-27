//----------------------------------------------------------------------------------------------
/*!
    \file blobdbtestcase.cpp
    \brief
*/

//----------------------------------------------------------------------------------------------

// Include Header File
#include "blobdbtestcase.h"

// Include Toolkit Core Files
#include <toolkit/core/log.h>
#include <toolkit/core/exception.h>
#include <toolkit/core/profiler.h>
#include <toolkit/core/stringformat.h>

// Include Qt Files
#include <QDataStream>
#include <QSqlError>
#include <QSqlQuery>
#include <QStringList>
#include <QVariant>
#include <QDir>

//----------------------------------------------------------------------------------------------
using namespace Toolkit::Core;
using namespace Toolkit::Test;

//----------------------------------------------------------------------------------------------
int BlobDbTestCase::ROW_COUNT( 10 );

//----------------------------------------------------------------------------------------------
BlobDbTestCase::BlobDbTestCase() :
    TestCase(),
    m_SqlDatabase( QSqlDatabase::addDatabase( "QSQLITE", "SqlDb" ) ),
    m_BlobDatabase( QSqlDatabase::addDatabase( "QSQLITE", "BlobDb" ) )
{
    Log log( Log::LT_TRACE, Log::MOD_MAIN, "BlobDbTestCase::BlobDbTestCase()" );

    m_SqlDatabase.setDatabaseName( ":memory:" );
    if( !m_SqlDatabase.open() ) {
        log.write( Log::LT_TRACE, "SqlDatabase open error: %s", m_SqlDatabase.lastError().databaseText() );
    }

    m_BlobDatabase.setDatabaseName( ":memory:" );
    if( !m_BlobDatabase.open() ) {
        log.write( Log::LT_TRACE, "BlobDatabase open error: %s", m_BlobDatabase.lastError().databaseText() );
    }
}

BlobDbTestCase::~BlobDbTestCase() {
    m_SqlDatabase.close();
    m_BlobDatabase.close();
}

void BlobDbTestCase::testDatabases() {
    ASSERT_TRUE( m_SqlDatabase.isOpen() );
    ASSERT_TRUE( m_BlobDatabase.isOpen() );

    QSqlQuery q = m_SqlDatabase.exec(
            "CREATE TABLE data ("
            "id INTEGER PRIMARY KEY AUTOINCREMENT, "
            "data1 TEXT, "
            "data2 TEXT, "
            "data3 TEXT, "
            "data4 TEXT, "
            "data5 TEXT, "
            "data6 TEXT, "
            "data7 TEXT, "
            "data8 TEXT, "
            "data9 TEXT, "
            "data10 TEXT "
            ")"
        );

    if( m_SqlDatabase.lastError().isValid() ) {
        ASSERT_WARNING_FAIL( "Tabellen data kunne ikke oprettes i basen SqlDatabase." );
    }

    q = m_BlobDatabase.exec(
            "CREATE TABLE data ("
            "id INTEGER PRIMARY KEY AUTOINCREMENT, "
            "data BLOB "
            ")"
        );

    if( m_BlobDatabase.lastError().isValid() ) {
        ASSERT_WARNING_FAIL( "Tabellen data kunne ikke oprettes i basen SqlDatabase." );
    }
}

void BlobDbTestCase::testInsertSqlData() {
    Profiler profiler( ROW_COUNT );

    for( int i = 0; i < ROW_COUNT; i++ ) {
        profiler.start();

        m_SqlDatabase.transaction();

        QSqlQuery q( m_SqlDatabase );
        q.prepare(
                "INSERT INTO data ( data1, data2, data3, data4, data5, data6, data7, data8, data9, data10 ) "
                "VALUES ( :1, :2, :3, :4, :5, :6, :7, :8, :9, :10 )"
                   );
        q.bindValue( 0, "v1" );
        q.bindValue( 1, "v2" );
        q.bindValue( 2, "v3" );
        q.bindValue( 3, "v4" );
        q.bindValue( 4, "v5" );
        q.bindValue( 5, "v6" );
        q.bindValue( 6, "v7" );
        q.bindValue( 7, "v8" );
        q.bindValue( 8, "v9" );
        q.bindValue( 9, "v10" );
        if( !q.exec() ) {
            ASSERT_WARNING_FAIL( StringFormat::format( "Query error: %s", q.lastError().databaseText() ) );
            m_SqlDatabase.rollback();
        }
        else {
            m_SqlDatabase.commit();
        };

        profiler.stop();
    }

    ASSERT_WARNING_FAIL( StringFormat::format( "testInsertSqlData Profiler: Antal = %i", profiler.count() ) );
    ASSERT_WARNING_FAIL( StringFormat::format( "testInsertSqlData Profiler: Min = %i ms", profiler.min() ) );
    ASSERT_WARNING_FAIL( StringFormat::format( "testInsertSqlData Profiler: Max = %i ms", profiler.max() ) );
    ASSERT_WARNING_FAIL( StringFormat::format( "testInsertSqlData Profiler: Sum = %i ms", profiler.sum() ) );
    ASSERT_WARNING_FAIL( StringFormat::format( "testInsertSqlData Profiler: Gennemsnit = %g ms", profiler.avg() ) );
    ASSERT_WARNING_FAIL( "" );
}

void BlobDbTestCase::testInsertBlobData() {
    Profiler profiler( ROW_COUNT );

    QVariant v( QVariant::Map );

    v.toMap()[ "data1" ] = "v1";
    v.toMap()[ "data2" ] = "v2";
    v.toMap()[ "data3" ] = "v3";
    v.toMap()[ "data4" ] = "v4";
    v.toMap()[ "data5" ] = "v5";
    v.toMap()[ "data6" ] = "v6";
    v.toMap()[ "data7" ] = "v7";
    v.toMap()[ "data8" ] = "v8";
    v.toMap()[ "data9" ] = "v9";
    v.toMap()[ "data10" ] = "v10";

    for( int i = 0; i < ROW_COUNT; i++ ) {
        profiler.start();

        m_BlobDatabase.transaction();

        QSqlQuery q( m_BlobDatabase );
        q.prepare(
                "INSERT INTO data ( data ) "
                "VALUES ( :1 )"
                   );

        q.bindValue( 0, packRecord( v ) );
        if( !q.exec() ) {
            ASSERT_WARNING_FAIL( StringFormat::format( "Query error: %s", q.lastError().databaseText() ) );
            m_BlobDatabase.rollback();
        }
        else {
            m_BlobDatabase.commit();
        };

        profiler.stop();
    }

    ASSERT_WARNING_FAIL( StringFormat::format( "testInsertBlobData Profiler: Antal = %i", profiler.count() ) );
    ASSERT_WARNING_FAIL( StringFormat::format( "testInsertBlobData Profiler: Min = %i ms", profiler.min() ) );
    ASSERT_WARNING_FAIL( StringFormat::format( "testInsertBlobData Profiler: Max = %i ms", profiler.max() ) );
    ASSERT_WARNING_FAIL( StringFormat::format( "testInsertBlobData Profiler: Sum = %i ms", profiler.sum() ) );
    ASSERT_WARNING_FAIL( StringFormat::format( "testInsertBlobData Profiler: Gennemsnit = %g ms", profiler.avg() ) );
    ASSERT_WARNING_FAIL( "" );
}

void BlobDbTestCase::testFetchSqlData() {
    Profiler profiler( ROW_COUNT );

    QSqlQuery q( m_SqlDatabase );
    q.exec( "SELECT * FROM data" );

    QVariant v;
    while( true ) {
        profiler.start();

        if( !q.next() ) {
            profiler.stop();
            break;
        }

        for( int i = 1; i < 11; i++ ) {
            v = q.value( i );
        }

        profiler.stop();
    }

    ASSERT_WARNING_FAIL( StringFormat::format( "testFetchSqlData Profiler: Antal = %i", profiler.count() ) );
    ASSERT_WARNING_FAIL( StringFormat::format( "testFetchSqlData Profiler: Min = %i ms", profiler.min() ) );
    ASSERT_WARNING_FAIL( StringFormat::format( "testFetchSqlData Profiler: Max = %i ms", profiler.max() ) );
    ASSERT_WARNING_FAIL( StringFormat::format( "testFetchSqlData Profiler: Sum = %i ms", profiler.sum() ) );
    ASSERT_WARNING_FAIL( StringFormat::format( "testFetchSqlData Profiler: Gennemsnit = %g ms", profiler.avg() ) );
    ASSERT_WARNING_FAIL( "" );
}

void BlobDbTestCase::testFetchBlobData() {
    Profiler profiler( ROW_COUNT );

    QSqlQuery q( m_BlobDatabase );
    q.exec( "SELECT * FROM data" );

    QVariant v;
    while( true ) {
        profiler.start();

        if( !q.next() ) {
            profiler.stop();
            break;
        }

        QVariant bv = unpackRecord( q.value( 1 ).toByteArray() );
        QMap<QString, QVariant> map = bv.toMap();
        for( QMap<QString, QVariant>::const_iterator it = map.begin(); it != map.end(); ++it ) {
            v = it.value();
        }

        profiler.stop();
    }

    ASSERT_WARNING_FAIL( StringFormat::format( "testFetchBlobData Profiler: Antal = %i", profiler.count() ) );
    ASSERT_WARNING_FAIL( StringFormat::format( "testFetchBlobData Profiler: Min = %i ms", profiler.min() ) );
    ASSERT_WARNING_FAIL( StringFormat::format( "testFetchBlobData Profiler: Max = %i ms", profiler.max() ) );
    ASSERT_WARNING_FAIL( StringFormat::format( "testFetchBlobData Profiler: Sum = %i ms", profiler.sum() ) );
    ASSERT_WARNING_FAIL( StringFormat::format( "testFetchBlobData Profiler: Gennemsnit = %g ms", profiler.avg() ) );
    ASSERT_WARNING_FAIL( "" );
}

void BlobDbTestCase::testFileInfoList() {
    int max = 10;
    QStringList list = ( QStringList() << "*.*" << "*.mpeg" << "*.f4v" << "*.doc" );

    for( QStringList::const_iterator it = list.begin(); it != list.end(); ++it ) {
        Profiler profiler( max );

        for( int i = 0; i < max; i++ ) {
            profiler.start();

            QDir dir( "/usr/local/archives/total" );
            dir.entryInfoList( QStringList() << *it );

            profiler.stop();
        }

        ASSERT_WARNING_FAIL( StringFormat::format( "testFileInfoList Profiler (%s): Antal = %i", *it, profiler.count() ) );
        ASSERT_WARNING_FAIL( StringFormat::format( "testFileInfoList Profiler (%s): Min = %i ms", *it, profiler.min() ) );
        ASSERT_WARNING_FAIL( StringFormat::format( "testFileInfoList Profiler (%s): Max = %i ms", *it, profiler.max() ) );
        ASSERT_WARNING_FAIL( StringFormat::format( "testFileInfoList Profiler (%s): Sum = %i ms", *it, profiler.sum() ) );
        ASSERT_WARNING_FAIL( StringFormat::format( "testFileInfoList Profiler (%s): Gennemsnit = %g ms", *it, profiler.avg() ) );
        ASSERT_WARNING_FAIL( "" );
    };
}

QByteArray BlobDbTestCase::packRecord( const QVariant& v ) {
    QByteArray ba;
    QDataStream stream( &ba, QIODevice::WriteOnly );

    stream << v;

    return ba;
}

QVariant BlobDbTestCase::unpackRecord( const QByteArray& ba ) {
    QVariant v;
    QDataStream stream( ba );

    stream >> v;
    return v;
}

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
