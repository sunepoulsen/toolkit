//-------------------------------------------------------------------------
/*!
    \file defaultassertwriter.h
    \brief
*/

//-------------------------------------------------------------------------

// Include Header File
#include "defaultassertwriter.h"

// Include Toolkit Core Files
#include <toolkit/core/stringformat.h>

// Include QT Files
#include <QVariant>

//-------------------------------------------------------------------------
using namespace Toolkit::Core;
using namespace Toolkit::Test;

//-------------------------------------------------------------------------
const QString DefaultAssertWriter::FORMAT_BOOL( "%ps" );
const QString DefaultAssertWriter::FORMAT_CHAR( "%c" );
const QString DefaultAssertWriter::FORMAT_NON_PRINT_CHAR( "@%u-4h" );
const QString DefaultAssertWriter::FORMAT_QBYTEARRAY( "{ Len = %i, Bytes = %s }" );
const QString DefaultAssertWriter::FORMAT_QVARIANT( "{ Type = %s, Data = %ds }" );

//-------------------------------------------------------------------------
DefaultAssertWriter::DefaultAssertWriter() {
};

DefaultAssertWriter::~DefaultAssertWriter() {
};

void DefaultAssertWriter::writeAssert( AbstractReport* report, const TestResult& testRes,
                                       const std::pair<QString, QString>& expr, const std::pair<QChar, QChar>& exprValue )
{
    QString fmt1 = FORMAT_CHAR;
    QString fmt2 = FORMAT_CHAR;

    if( ! ( exprValue.first.isPrint() && exprValue.first.toLatin1() ) ) {
        fmt1 = FORMAT_NON_PRINT_CHAR;
    };
    if( ! ( exprValue.second.isPrint() && exprValue.second.toLatin1() ) ) {
        fmt2 = FORMAT_NON_PRINT_CHAR;
    };

    report->writeAssertEqual( testRes, expr,
                              std::make_pair( StringFormat::format( fmt1, exprValue.first ),
                                              StringFormat::format( fmt2, exprValue.second ) ) );
};

void DefaultAssertWriter::writeAssert( AbstractReport* report, const TestResult& testRes,
                                       const std::pair<QString, QString>& expr, const std::pair<const char*, const char*>& exprValue )
{
    report->writeAssertEqual( testRes, expr, std::make_pair( QString( exprValue.first ), QString( exprValue.second ) ) );
};

void DefaultAssertWriter::writeAssert( AbstractReport* report, const TestResult& testRes, 
                                       const std::pair<QString, QString>& expr, const std::pair<QString, QString>& exprValue ) 
{
    report->writeAssertEqual( testRes, expr, exprValue );
};

void DefaultAssertWriter::writeAssert( AbstractReport* report, const TestResult& testRes, 
                                       const std::pair<QString, QString>& expr, const std::pair<const char*, std::string>& exprValue )
{
    report->writeAssertEqual( testRes, expr, std::make_pair( QString( exprValue.first ), QString::fromStdString( exprValue.second ) ) );
};

void DefaultAssertWriter::writeAssert( AbstractReport* report, const TestResult& testRes, 
                                       const std::pair<QString, QString>& expr, const std::pair<std::string, const char*>& exprValue ) 
{
    report->writeAssertEqual( testRes, expr, std::make_pair( QString::fromStdString( exprValue.first ), QString( exprValue.second ) ) );
};

void DefaultAssertWriter::writeAssert( AbstractReport* report, const TestResult& testRes, 
                                       const std::pair<QString, QString>& expr, const std::pair<std::string, std::string>& exprValue )
{
    report->writeAssertEqual( testRes, expr, std::make_pair( QString::fromStdString( exprValue.first ), QString::fromStdString( exprValue.second ) ) );
};

void DefaultAssertWriter::writeAssert( AbstractReport* report, const TestResult& testRes, 
                                       const std::pair<QString, QString>& expr, const std::pair<bool, bool>& exprValue )
{
    report->writeAssertEqual( testRes, expr, std::make_pair( StringFormat::format( FORMAT_BOOL, exprValue.first ), StringFormat::format( FORMAT_BOOL, exprValue.second ) ) );
};

void DefaultAssertWriter::writeAssert( AbstractReport* report, const TestResult& testRes, 
                                       const std::pair<QString, QString>& expr, const std::pair<const char*, QByteArray>& exprValue )
{
    QByteArray array( exprValue.first );
    
    report->writeAssertEqual( testRes, expr, std::make_pair( StringFormat::format( FORMAT_QBYTEARRAY, array.size(), QString( array ) ),
                                                             StringFormat::format( FORMAT_QBYTEARRAY, exprValue.second.size(), QString( exprValue.second ) ) ) );
};

void DefaultAssertWriter::writeAssert( AbstractReport* report, const TestResult& testRes, 
                                       const std::pair<QString, QString>& expr, const std::pair<QByteArray, const char*>& exprValue )
{
    QByteArray array( exprValue.second );
    
    report->writeAssertEqual( testRes, expr, std::make_pair( StringFormat::format( FORMAT_QBYTEARRAY, exprValue.first.size(), QString( exprValue.first ) ),
                                                             StringFormat::format( FORMAT_QBYTEARRAY, array.size(), QString( array ) ) ) );
};

void DefaultAssertWriter::writeAssert( AbstractReport* report, const TestResult& testRes, 
                                       const std::pair<QString, QString>& expr, const std::pair<QByteArray, QByteArray>& exprValue )
{
    report->writeAssertEqual( testRes, expr, std::make_pair( StringFormat::format( FORMAT_QBYTEARRAY, exprValue.first.size(), QString( exprValue.first ) ),
                                                             StringFormat::format( FORMAT_QBYTEARRAY, exprValue.second.size(), QString( exprValue.second ) ) ) );
};

void DefaultAssertWriter::writeAssert( AbstractReport* report, const TestResult& testRes, 
                                       const std::pair<QString, QString>& expr, const std::pair<QDate, QDate>& exprValue )
{
    report->writeAssertEqual( testRes, expr, std::make_pair( exprValue.first.toString(), exprValue.second.toString() ) );
};

void DefaultAssertWriter::writeAssert( AbstractReport* report, const TestResult& testRes, 
                                       const std::pair<QString, QString>& expr, const std::pair<QTime, QTime>& exprValue )
{
    report->writeAssertEqual( testRes, expr, std::make_pair( exprValue.first.toString(), exprValue.second.toString() ) );
};

void DefaultAssertWriter::writeAssert( AbstractReport* report, const TestResult& testRes, 
                                       const std::pair<QString, QString>& expr, const std::pair<QDateTime, QDateTime>& exprValue )
{
    report->writeAssertEqual( testRes, expr, std::make_pair( exprValue.first.toString(), exprValue.second.toString() ) );
};

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
