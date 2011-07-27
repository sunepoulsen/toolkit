//----------------------------------------------------------------------------------------------
/*!
    \file blobdbtestcase.h
    \brief
*/

//----------------------------------------------------------------------------------------------
#ifndef __TOOLKIT_TEST_SQL_BLOBDBTESTCASE_H__
#define __TOOLKIT_TEST_SQL_BLOBDBTESTCASE_H__

// Include Toolkit Test Files
#include <toolkit/test/testcase.h>

// Include Qt Files
#include <QSqlDatabase>

//----------------------------------------------------------------------------------------------
/*!
    \brief
*/
class BlobDbTestCase : public Toolkit::Test::TestCase {
    Q_OBJECT

public:
    static int ROW_COUNT;
public:
    //!\name Constructors & Destructor
    //@{
    BlobDbTestCase();
    virtual ~BlobDbTestCase();
    //@}

public slots:
    //!\name Test Databases
    //@{
    void testDatabases();
    void testInsertSqlData();
    void testInsertBlobData();
    void testFetchSqlData();
    void testFetchBlobData();
    //@}

public slots:
    void testFileInfoList();

private:
    QByteArray packRecord( const QVariant& v );
    QVariant unpackRecord( const QByteArray& ba );

private:
    QSqlDatabase m_SqlDatabase;
    QSqlDatabase m_BlobDatabase;
};

#endif

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
