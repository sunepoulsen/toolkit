//-------------------------------------------------------------------------
/*!
    \file filefactorytestcase.cpp
    \brief
*/

//-------------------------------------------------------------------------

// Include Header File
#include "filefactorytestcase.h"

// Include Toolkit Core Files
#include <toolkit/core/filefactory.h>

// Include Qt Files
#include <QTemporaryFile>

//-------------------------------------------------------------------------
using namespace Toolkit::Core;
using namespace Toolkit::Test;

//-------------------------------------------------------------------------
FileFactoryTestCase::FileFactoryTestCase() :
    TestCase()
{
};

FileFactoryTestCase::~FileFactoryTestCase() {
};

void FileFactoryTestCase::testReadFile() {
    QTemporaryFile tempFile;
    QByteArray bytes( "File Bytes!!!" );

    ASSERT_REQUIRE_TRUE( tempFile.open() );
    ASSERT_REQUIRE_NOT_EQUAL( tempFile.write( bytes ), 0 );
    tempFile.close();

    ASSERT_EQUAL( FileFactory::readFile( "Dette fil skal ikke findes!!!" ), QByteArray() );
    ASSERT_EQUAL( FileFactory::readFile( tempFile.fileName() ), bytes );
};

void FileFactoryTestCase::testWriteFile() {
    QTemporaryFile tempFile;
    QByteArray bytes( "File Bytes!!!" );

    ASSERT_REQUIRE_TRUE( tempFile.open() );
    tempFile.close();

    ASSERT_EQUAL( FileFactory::writeFile( "", "bytes" ), false );

    ASSERT_EQUAL( FileFactory::writeFile( tempFile.fileName(), bytes ), true );
    ASSERT_EQUAL( FileFactory::readFile( tempFile.fileName() ), bytes );
};

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */

