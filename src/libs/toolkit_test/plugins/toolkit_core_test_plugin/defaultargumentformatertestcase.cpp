//-------------------------------------------------------------------------------------------------
/*!
    \file defaultargumentformatertestcase.cpp
    \brief
*/

//-------------------------------------------------------------------------------------------------

// Include Header File
#include "defaultargumentformatertestcase.h"

// Include Toolkit Core Files
#include <toolkit/core/defaultargumentformater.h>

//-------------------------------------------------------------------------------------------------
using namespace Toolkit::Core;

//-------------------------------------------------------------------------------------------------
DefaultArgumentFormaterTestCase::DefaultArgumentFormaterTestCase() :
    TestCase()
{
};

DefaultArgumentFormaterTestCase::~DefaultArgumentFormaterTestCase() {
};

void DefaultArgumentFormaterTestCase::testConstants() {
    ASSERT_EQUAL( DefaultArgumentFormater::CONV_STRING, 's' );
    ASSERT_EQUAL( DefaultArgumentFormater::CONV_BOOL, 'b' );
    ASSERT_EQUAL( DefaultArgumentFormater::CONV_INT, 'i' );
    ASSERT_EQUAL( DefaultArgumentFormater::CONV_DECIMAL, 'd' );
    ASSERT_EQUAL( DefaultArgumentFormater::CONV_HEX, 'h' );
    ASSERT_EQUAL( DefaultArgumentFormater::CONV_OCTAL, 'o' );
    ASSERT_EQUAL( DefaultArgumentFormater::CONV_DOUBLE, 'g' );
    ASSERT_EQUAL( DefaultArgumentFormater::CONV_FLOAT, 'f' );
    ASSERT_EQUAL( DefaultArgumentFormater::CONV_EXP, 'e' );
    ASSERT_EQUAL( DefaultArgumentFormater::CONV_DATETIME, 't' );

    ASSERT_EQUAL( DefaultArgumentFormater::QCHAR_CONVS, "sdh" );
    ASSERT_EQUAL( DefaultArgumentFormater::QSTRING_CONVS, "s" );
    ASSERT_EQUAL( DefaultArgumentFormater::BOOL_CONVS, "si" );
    ASSERT_EQUAL( DefaultArgumentFormater::DOUBLE_CONVS, "gfe" );
    ASSERT_EQUAL( DefaultArgumentFormater::DATETIME_CONVS, "t" );

    ASSERT_EQUAL( DefaultArgumentFormater::FLAG_DEBUG, 'd' );
    ASSERT_EQUAL( DefaultArgumentFormater::FLAG_FILL_ZEROS, 'n' );
    ASSERT_EQUAL( DefaultArgumentFormater::FLAG_GROUP_SEP, 'g' );
    ASSERT_EQUAL( DefaultArgumentFormater::FLAG_LOWERCASE, 'l' );
    ASSERT_EQUAL( DefaultArgumentFormater::FLAG_PARENTES, 'p' );
    ASSERT_EQUAL( DefaultArgumentFormater::FLAG_TRUNCATE, 't' );
    ASSERT_EQUAL( DefaultArgumentFormater::FLAG_UPPERCASE, 'u' );

    ASSERT_EQUAL( DefaultArgumentFormater::NULL_VALUE, "(null)" );
    ASSERT_EQUAL( DefaultArgumentFormater::EMPTY_VALUE, "(empty)" );
    ASSERT_EQUAL( DefaultArgumentFormater::TRUE_VALUE, "1" );
    ASSERT_EQUAL( DefaultArgumentFormater::FALSE_VALUE, "0" );
    ASSERT_EQUAL( DefaultArgumentFormater::TRUE_NAME_VALUE, "true" );
    ASSERT_EQUAL( DefaultArgumentFormater::FALSE_NAME_VALUE, "false" );
    ASSERT_EQUAL( DefaultArgumentFormater::DATE_FORMAT, "dd/MM-yy" );
    ASSERT_EQUAL( DefaultArgumentFormater::TIME_FORMAT, "hh:mm" );
    ASSERT_EQUAL( DefaultArgumentFormater::DATETIME_FORMAT, DefaultArgumentFormater::DATE_FORMAT + " " + DefaultArgumentFormater::TIME_FORMAT );
};

void DefaultArgumentFormaterTestCase::testChar() {
    DefaultArgumentFormater fm;
    QString fmt;
    QLocale locale = QLocale::system();

    fmt = "%ut17s";
    ASSERT_EQUAL( fm.format( locale, FormatParam( fmt ), 'c' ), fm.format( locale, FormatParam( fmt ), QChar( 'c' ) )  );
};

void DefaultArgumentFormaterTestCase::testQChar() {
    QLocale locale = QLocale::system();
    DefaultArgumentFormater fm;

    ASSERT_EQUAL( fm.format( locale, FormatParam( "%s" ), QChar() ), QString( QChar() ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%ds" ), QChar() ), DefaultArgumentFormater::NULL_VALUE  );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%s" ), 'c' ), "c"  );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%1s" ), 'c' ), fm.justifyWidth( locale, FormatParam( "%1s" ), "c" ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%3s" ), 'c' ), fm.justifyWidth( locale, FormatParam( "%3s" ), "c" ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%n3s" ), 'c' ), fm.justifyWidth( locale, FormatParam( "%n3s" ), "c" ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%-3s" ), 'c' ), fm.justifyWidth( locale, FormatParam( "%-3s" ), "c" ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%n-3s" ), 'c' ), fm.justifyWidth( locale, FormatParam( "%n-3s" ), "c" ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%us" ), 'c' ), fm.justifyCases( FormatParam( "%us" ), "c" ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%ls" ), 'Q' ), fm.justifyCases( FormatParam( "%ls" ), "Q" ) );

    ASSERT_EQUAL( fm.format( locale, FormatParam( "%d" ), 'Q' ), QString::number( QChar( 'Q' ).unicode() )  );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%h" ), 'Q' ), QString::number( QChar( 'Q' ).unicode(), 16 )  );

    ASSERT_NO_EXCEPTION( fm.format( locale, FormatParam( "%s" ), 'Q' ) );
    ASSERT_NO_EXCEPTION( fm.format( locale, FormatParam( "%d" ), 'Q' ) );
    ASSERT_NO_EXCEPTION( fm.format( locale, FormatParam( "%h" ), 'Q' ) );
    ASSERT_EXCEPTION( fm.format( locale, FormatParam( "%g" ), 'Q' ), FormatException );
};

void DefaultArgumentFormaterTestCase::testCString() {
    DefaultArgumentFormater fm;
    QString fmt;
    QString s;
    QLocale locale = QLocale::system();

    fmt = "%ut17s";
    s = "Petersen";
    ASSERT_EQUAL( fm.format( locale, FormatParam( fmt ), s.toAscii().constData() ), fm.format( locale, FormatParam( fmt ), s )  );
};

void DefaultArgumentFormaterTestCase::testStdString() {
    DefaultArgumentFormater fm;
    QString fmt;
    QString s;
    QLocale locale = QLocale::system();

    fmt = "%ut17s";
    s = "Petersen";
    ASSERT_EQUAL( fm.format( locale, FormatParam( fmt ), s.toStdString() ), fm.format( locale, FormatParam( fmt ), s )  );
};

void DefaultArgumentFormaterTestCase::testQString() {
    QLocale locale = QLocale::system();
    DefaultArgumentFormater fm;
    QString fmt;
    QString s;

    ASSERT_EQUAL( fm.format( locale, FormatParam( "%s" ), QString() ), "" );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%ds" ), QString() ), DefaultArgumentFormater::NULL_VALUE );
    s = "";
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%ds" ), s ), DefaultArgumentFormater::EMPTY_VALUE );

    s = "Pineapple";
    fmt = "%us";
    ASSERT_EQUAL( fm.format( locale, FormatParam( fmt ), s ), fm.justifyCases( FormatParam( fmt ), s ) );
    fmt = "%ls";
    ASSERT_EQUAL( fm.format( locale, FormatParam( fmt ), s ), fm.justifyCases( FormatParam( fmt ), s ) );
    fmt = "%15s";
    ASSERT_EQUAL( fm.format( locale, FormatParam( fmt ), s ), fm.justifyWidth( locale, FormatParam( fmt ), s ) );
    fmt = "%-15s";
    ASSERT_EQUAL( fm.format( locale, FormatParam( fmt ), s ), fm.justifyWidth( locale, FormatParam( fmt ), s ) );
    fmt = "%2s";
    ASSERT_EQUAL( fm.format( locale, FormatParam( fmt ), s ), fm.justifyWidth( locale, FormatParam( fmt ), s ) );
    fmt = "%-2s";
    ASSERT_EQUAL( fm.format( locale, FormatParam( fmt ), s ), fm.justifyWidth( locale, FormatParam( fmt ), s ) );
    fmt = "%t2s";
    ASSERT_EQUAL( fm.format( locale, FormatParam( fmt ), s ), fm.justifyWidth( locale, FormatParam( fmt ), s ) );
    fmt = "%t-2s";
    ASSERT_EQUAL( fm.format( locale, FormatParam( fmt ), s ), fm.justifyWidth( locale, FormatParam( fmt ), s ) );

    ASSERT_NO_EXCEPTION( fm.format( locale, FormatParam( "%s" ), "Q" ) );
    ASSERT_EXCEPTION( fm.format( locale, FormatParam( "%g" ), "Q" ), FormatException );
};

void DefaultArgumentFormaterTestCase::testBool() {
    QLocale locale = QLocale::system();
    DefaultArgumentFormater fm;
    QString fmt;
    bool b;

    ASSERT_EQUAL( fm.format( locale, FormatParam( "%s" ), true ), DefaultArgumentFormater::TRUE_NAME_VALUE );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%s" ), false ), DefaultArgumentFormater::FALSE_NAME_VALUE );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%i" ), true ), DefaultArgumentFormater::TRUE_VALUE );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%i" ), false ), DefaultArgumentFormater::FALSE_VALUE );

    b = true;
    fmt = "%us";
    ASSERT_EQUAL( fm.format( locale, FormatParam( fmt ), b ), fm.justifyCases( FormatParam( fmt ), DefaultArgumentFormater::TRUE_NAME_VALUE ) );
    fmt = "%ls";
    ASSERT_EQUAL( fm.format( locale, FormatParam( fmt ), b ), fm.justifyCases( FormatParam( fmt ), DefaultArgumentFormater::TRUE_NAME_VALUE ) );
    fmt = "%15s";
    ASSERT_EQUAL( fm.format( locale, FormatParam( fmt ), b ), fm.justifyWidth( locale, FormatParam( fmt ), DefaultArgumentFormater::TRUE_NAME_VALUE ) );
    fmt = "%-15s";
    ASSERT_EQUAL( fm.format( locale, FormatParam( fmt ), b ), fm.justifyWidth( locale, FormatParam( fmt ), DefaultArgumentFormater::TRUE_NAME_VALUE ) );
    fmt = "%2s";
    ASSERT_EQUAL( fm.format( locale, FormatParam( fmt ), b ), fm.justifyWidth( locale, FormatParam( fmt ), DefaultArgumentFormater::TRUE_NAME_VALUE ) );
    fmt = "%-2s";
    ASSERT_EQUAL( fm.format( locale, FormatParam( fmt ), b ), fm.justifyWidth( locale, FormatParam( fmt ), DefaultArgumentFormater::TRUE_NAME_VALUE ) );
    fmt = "%t2s";
    ASSERT_EQUAL( fm.format( locale, FormatParam( fmt ), b ), fm.justifyWidth( locale, FormatParam( fmt ), DefaultArgumentFormater::TRUE_NAME_VALUE ) );
    fmt = "%t-2s";
    ASSERT_EQUAL( fm.format( locale, FormatParam( fmt ), b ), fm.justifyWidth( locale, FormatParam( fmt ), DefaultArgumentFormater::TRUE_NAME_VALUE ) );

    ASSERT_NO_EXCEPTION( fm.format( locale, FormatParam( "%s" ), true ) );
    ASSERT_NO_EXCEPTION( fm.format( locale, FormatParam( "%i" ), false ) );
    ASSERT_EXCEPTION( fm.format( locale, FormatParam( "%g" ), false ), FormatException );
};

void DefaultArgumentFormaterTestCase::testDouble() {
    QLocale locale = QLocale::system();
    DefaultArgumentFormater fm;
    QString fmt;
    double d;

    fmt = "%gg";
    d = 12345678.90123456;
    ASSERT_EQUAL( fm.format( locale, FormatParam( fmt ), d ), fm.formatFloat( locale, FormatParam( fmt ), d )  );
};

void DefaultArgumentFormaterTestCase::testFloat() {
    QLocale locale = QLocale::system();
    DefaultArgumentFormater fm;
    QString fmt;
    float d;

    fmt = "%gg";
    d = 12345678.90123456;
    ASSERT_EQUAL( fm.format( locale, FormatParam( fmt ), d ), fm.formatFloat( locale, FormatParam( fmt ), d )  );
};

void DefaultArgumentFormaterTestCase::testInt() {
    QLocale locale = QLocale::system();
    DefaultArgumentFormater fm;
    QString fmt;
    int i;

    fmt = "%gi";
    i = 12345678;
    ASSERT_EQUAL( fm.format( locale, FormatParam( fmt ), i ), fm.formatInteger( locale, FormatParam( fmt ), i )  );
};

void DefaultArgumentFormaterTestCase::testUInt() {
    QLocale locale = QLocale::system();
    DefaultArgumentFormater fm;
    QString fmt;
    uint i;

    fmt = "%gi";
    i = 12345678;
    ASSERT_EQUAL( fm.format( locale, FormatParam( fmt ), i ), fm.formatInteger( locale, FormatParam( fmt ), i )  );
};

void DefaultArgumentFormaterTestCase::testShort() {
    QLocale locale = QLocale::system();
    DefaultArgumentFormater fm;
    QString fmt;
    short i;

    fmt = "%gi";
    i = 123;
    ASSERT_EQUAL( fm.format( locale, FormatParam( fmt ), i ), fm.formatInteger( locale, FormatParam( fmt ), i )  );
};

void DefaultArgumentFormaterTestCase::testUShort() {
    QLocale locale = QLocale::system();
    DefaultArgumentFormater fm;
    QString fmt;
    ushort i;

    fmt = "%gi";
    i = 123;
    ASSERT_EQUAL( fm.format( locale, FormatParam( fmt ), i ), fm.formatInteger( locale, FormatParam( fmt ), i )  );
};

void DefaultArgumentFormaterTestCase::testQLongLong() {
    QLocale locale = QLocale::system();
    DefaultArgumentFormater fm;
    QString fmt;
    qlonglong i;

    fmt = "%gi";
    i = 12345678;
    ASSERT_EQUAL( fm.format( locale, FormatParam( fmt ), i ), fm.formatInteger( locale, FormatParam( fmt ), i )  );
};

void DefaultArgumentFormaterTestCase::testQULongLong() {
    QLocale locale = QLocale::system();
    DefaultArgumentFormater fm;
    QString fmt;
    qulonglong i;

    fmt = "%gi";
    i = 12345678;
    ASSERT_EQUAL( fm.format( locale, FormatParam( fmt ), i ), fm.formatInteger( locale, FormatParam( fmt ), i )  );
};

void DefaultArgumentFormaterTestCase::testQBitArray() {
    QLocale locale = QLocale::system();
    DefaultArgumentFormater fm;
    QBitArray ba;

    ASSERT_EQUAL( fm.format( locale, FormatParam( "%s" ), ba ), "" );

    ba.fill( true, 1 );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%s" ), ba ), fm.format( locale, FormatParam( "%s" ), ba.at( 0 ) ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%i" ), ba ), fm.format( locale, FormatParam( "%i" ), ba.at( 0 ) ) );

    ba.fill( true, 2 );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%s" ), ba ),
                  fm.format( locale, FormatParam( "%s" ), ba.at( 0 ) ) + ", " + fm.format( locale, FormatParam( "%s" ), ba.at( 1 ) )
                );

    // Test exceptions
    ASSERT_NO_EXCEPTION( fm.format( locale, FormatParam( "%s" ), ba ) );
    ASSERT_NO_EXCEPTION( fm.format( locale, FormatParam( "%i" ), ba ) );
    ASSERT_EXCEPTION( fm.format( locale, FormatParam( "%q" ), ba ), FormatException );
};

void DefaultArgumentFormaterTestCase::testQByteArray() {
    QLocale locale = QLocale::system();
    DefaultArgumentFormater fm;
    QString fmt;
    QByteArray s;

    ASSERT_EQUAL( fm.format( locale, FormatParam( "%s" ), QByteArray() ), "" );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%ds" ), QByteArray() ), DefaultArgumentFormater::NULL_VALUE );
    s = "";
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%ds" ), s ), DefaultArgumentFormater::EMPTY_VALUE );

    s = "Pineapple";
    fmt = "%us";
    ASSERT_EQUAL( fm.format( locale, FormatParam( fmt ), s ), fm.justifyCases( FormatParam( fmt ), s ) );
    fmt = "%ls";
    ASSERT_EQUAL( fm.format( locale, FormatParam( fmt ), s ), fm.justifyCases( FormatParam( fmt ), s ) );
    fmt = "%15s";
    ASSERT_EQUAL( fm.format( locale, FormatParam( fmt ), s ), fm.justifyWidth( locale, FormatParam( fmt ), s ) );
    fmt = "%-15s";
    ASSERT_EQUAL( fm.format( locale, FormatParam( fmt ), s ), fm.justifyWidth( locale, FormatParam( fmt ), s ) );
    fmt = "%2s";
    ASSERT_EQUAL( fm.format( locale, FormatParam( fmt ), s ), fm.justifyWidth( locale, FormatParam( fmt ), s ) );
    fmt = "%-2s";
    ASSERT_EQUAL( fm.format( locale, FormatParam( fmt ), s ), fm.justifyWidth( locale, FormatParam( fmt ), s ) );
    fmt = "%t2s";
    ASSERT_EQUAL( fm.format( locale, FormatParam( fmt ), s ), fm.justifyWidth( locale, FormatParam( fmt ), s ) );
    fmt = "%t-2s";
    ASSERT_EQUAL( fm.format( locale, FormatParam( fmt ), s ), fm.justifyWidth( locale, FormatParam( fmt ), s ) );

    ASSERT_NO_EXCEPTION( fm.format( locale, FormatParam( "%s" ), QByteArray( "Q" ) ) );
    ASSERT_EXCEPTION( fm.format( locale, FormatParam( "%g" ), QByteArray( "Q" ) ), FormatException );
};

void DefaultArgumentFormaterTestCase::testQDate() {
    QLocale locale = QLocale::system();
    DefaultArgumentFormater fm;
    QString fmt;
    QDate d = QDate::currentDate();

    ASSERT_EQUAL( fm.format( locale, FormatParam( "%t" ), d ), d.toString( DefaultArgumentFormater::DATE_FORMAT ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%dt" ), d ), d.toString( "d" ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%ddt" ), d ), d.toString( "dd" ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%dddt" ), d ), d.toString( "ddd" ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%ddddt" ), d ), d.toString( "dddd" ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%Mt" ), d ), d.toString( "M" ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%MMt" ), d ), d.toString( "MM" ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%MMMt" ), d ), d.toString( "MMM" ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%MMMMt" ), d ), d.toString( "MMMM" ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%yyt" ), d ), d.toString( "yy" ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%yyyyt" ), d ), d.toString( "yyyy" ) );

    ASSERT_NO_EXCEPTION( fm.format( locale, FormatParam( "%t" ), QDate() ) );
    ASSERT_EXCEPTION( fm.format( locale, FormatParam( "%s" ), QDate() ), FormatException );
};

void DefaultArgumentFormaterTestCase::testQTime() {
    QLocale locale = QLocale::system();
    DefaultArgumentFormater fm;
    QString fmt;
    QTime t = QTime::currentTime();

    ASSERT_EQUAL( fm.format( locale, FormatParam( "%t" ), t ), t.toString( DefaultArgumentFormater::TIME_FORMAT ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%ht" ), t ), t.toString( "h" ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%hht" ), t ), t.toString( "hh" ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%mt" ), t ), t.toString( "m" ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%mmt" ), t ), t.toString( "mm" ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%st" ), t ), t.toString( "s" ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%sst" ), t ), t.toString( "ss" ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%zt" ), t ), t.toString( "z" ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%zzzt" ), t ), t.toString( "zzz" ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%APt" ), t ), t.toString( "AP" ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%apt" ), t ), t.toString( "ap" ) );

    ASSERT_NO_EXCEPTION( fm.format( locale, FormatParam( "%t" ), QTime() ) );
    ASSERT_EXCEPTION( fm.format( locale, FormatParam( "%s" ), QTime() ), FormatException );
};

void DefaultArgumentFormaterTestCase::testQDateTime() {
    QLocale locale = QLocale::system();
    DefaultArgumentFormater fm;
    QString fmt;
    QDateTime dt = QDateTime::currentDateTime();

    ASSERT_EQUAL( fm.format( locale, FormatParam( "%t" ), dt ), dt.toString( DefaultArgumentFormater::DATETIME_FORMAT ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%dt" ), dt ), dt.toString( "d" ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%ddt" ), dt ), dt.toString( "dd" ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%dddt" ), dt ), dt.toString( "ddd" ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%ddddt" ), dt ), dt.toString( "dddd" ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%Mt" ), dt ), dt.toString( "M" ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%MMt" ), dt ), dt.toString( "MM" ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%MMMt" ), dt ), dt.toString( "MMM" ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%MMMMt" ), dt ), dt.toString( "MMMM" ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%yyt" ), dt ), dt.toString( "yy" ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%yyyyt" ), dt ), dt.toString( "yyyy" ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%ht" ), dt ), dt.toString( "h" ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%hht" ), dt ), dt.toString( "hh" ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%mt" ), dt ), dt.toString( "m" ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%mmt" ), dt ), dt.toString( "mm" ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%st" ), dt ), dt.toString( "s" ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%sst" ), dt ), dt.toString( "ss" ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%zt" ), dt ), dt.toString( "z" ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%zzzt" ), dt ), dt.toString( "zzz" ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%APt" ), dt ), dt.toString( "AP" ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%apt" ), dt ), dt.toString( "ap" ) );

    ASSERT_NO_EXCEPTION( fm.format( locale, FormatParam( "%t" ), QDateTime() ) );
    ASSERT_EXCEPTION( fm.format( locale, FormatParam( "%s" ), QDateTime() ), FormatException );
};

void DefaultArgumentFormaterTestCase::testFormatFloats() {
    QLocale locale = QLocale::system();
    DefaultArgumentFormater fm;
    QString fmt;
    double d;

    locale.setNumberOptions( QLocale::OmitGroupSeparator );
    d = 0.0;
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%g" ), d ), locale.toString( d ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%f" ), d ), locale.toString( d, 'f' ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%e" ), d ), locale.toString( d, 'e' ) );
    d = 12345678.90123456;
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%g" ), d ), locale.toString( d ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%f" ), d ), locale.toString( d, 'f' ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%e" ), d ), locale.toString( d, 'e' ) );
    d = -12345678.90123456;
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%g" ), d ), locale.toString( d ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%f" ), d ), locale.toString( d, 'f' ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%e" ), d ), locale.toString( d, 'e' ) );

    // Test group seperator
    locale.setNumberOptions( 0 );
    d = 12345678.90123456;
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%gg" ), d ), locale.toString( d ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%gf" ), d ), locale.toString( d, 'f' ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%ge" ), d ), locale.toString( d, 'e' ) );
    d = -12345678.90123456;
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%gg" ), d ), locale.toString( d ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%gf" ), d ), locale.toString( d, 'f' ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%ge" ), d ), locale.toString( d, 'e' ) );

    // Test parentes
    d = 12345678.90123456;
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%pgg" ), d ), locale.toString( d ) );
    d = -12345678.90123456;
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%pgg" ), d ), "(" + locale.toString( -d ) + ")" );

    // Test decimal points
    d = 12345678.90123456;
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%g.0g" ), d ), locale.toString( d, 'g', 0 ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%g.2g" ), d ), locale.toString( d, 'g', 2 ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%g.8g" ), d ), locale.toString( d, 'g', 8 ) );

    // Test widths
    fmt = "%2g";
    ASSERT_EQUAL( fm.format( locale, FormatParam( fmt ), d ), fm.justifyWidth( locale, FormatParam( fmt ), locale.toString( d ) ) );
    fmt = "%-2g";
    ASSERT_EQUAL( fm.format( locale, FormatParam( fmt ), d ), fm.justifyWidth( locale, FormatParam( fmt ), locale.toString( d ) ) );
    fmt = "%17g";
    ASSERT_EQUAL( fm.format( locale, FormatParam( fmt ), d ), fm.justifyWidth( locale, FormatParam( fmt ), locale.toString( d ) ) );
    fmt = "%-17g";
    ASSERT_EQUAL( fm.format( locale, FormatParam( fmt ), d ), fm.justifyWidth( locale, FormatParam( fmt ), locale.toString( d ) ) );

    // Test exceptions
    ASSERT_NO_EXCEPTION( fm.format( locale, FormatParam( "%g" ), d ) );
    ASSERT_NO_EXCEPTION( fm.format( locale, FormatParam( "%f" ), d ) );
    ASSERT_NO_EXCEPTION( fm.format( locale, FormatParam( "%e" ), d ) );
    ASSERT_EXCEPTION( fm.format( locale, FormatParam( "%q" ), d ), FormatException );
};

void DefaultArgumentFormaterTestCase::testFormatIntegers() {
    QLocale locale = QLocale::system();
    DefaultArgumentFormater fm;
    QString fmt;
    int i;

    locale.setNumberOptions( QLocale::OmitGroupSeparator );
    i = 0;
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%i" ), i ), locale.toString( i ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%b" ), i ), QString::number( i, 2 ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%o" ), i ), QString::number( i, 8 ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%h" ), i ), QString::number( i, 16 ) );
    i = 12345;
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%i" ), i ), locale.toString( i ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%b" ), i ), QString::number( i, 2 ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%o" ), i ), QString::number( i, 8 ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%h" ), i ), QString::number( i, 16 ) );
    i = -12345;
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%i" ), i ), locale.toString( i ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%b" ), i ), QString::number( i, 2 ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%o" ), i ), QString::number( i, 8 ) );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%h" ), i ), QString::number( i, 16 ) );

    // Test group seperator
    locale.setNumberOptions( 0 );
    i = 12345;
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%gi" ), i ), locale.toString( i ) );
    i = -12345;
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%gi" ), i ), locale.toString( i ) );

    // Test negative numbers
    i = -12345;
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%pgi" ), i ), "(" + locale.toString( -i ) + ")" );

    // Test justitying and widths
    i = 12345;
    fmt = "%g2i";
    ASSERT_EQUAL( fm.format( locale, FormatParam( fmt ), i ), fm.justifyWidth( locale, FormatParam( fmt ), locale.toString( i ) ) );
    fmt = "%g17i";
    ASSERT_EQUAL( fm.format( locale, FormatParam( fmt ), i ), fm.justifyWidth( locale, FormatParam( fmt ), locale.toString( i ) ) );
    fmt = "%g-17i";
    ASSERT_EQUAL( fm.format( locale, FormatParam( fmt ), i ), fm.justifyWidth( locale, FormatParam( fmt ), locale.toString( i ) ) );
    fmt = "%gn-17i";
    ASSERT_EQUAL( fm.format( locale, FormatParam( fmt ), i ), fm.justifyWidth( locale, FormatParam( fmt ), locale.toString( i ) ) );

    ASSERT_EQUAL( fm.format( locale, FormatParam( "%ln-4h" ), 0x01AF ), "01af" );
    ASSERT_EQUAL( fm.format( locale, FormatParam( "%un-4h" ), 0x01AF ), "01AF" );

    // Test exceptions
    ASSERT_NO_EXCEPTION( fm.format( locale, FormatParam( "%i" ), i ) );
    ASSERT_NO_EXCEPTION( fm.format( locale, FormatParam( "%b" ), i ) );
    ASSERT_NO_EXCEPTION( fm.format( locale, FormatParam( "%o" ), i ) );
    ASSERT_NO_EXCEPTION( fm.format( locale, FormatParam( "%h" ), i ) );
    ASSERT_EXCEPTION( fm.format( locale, FormatParam( "%q" ), i ), FormatException );
};

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
