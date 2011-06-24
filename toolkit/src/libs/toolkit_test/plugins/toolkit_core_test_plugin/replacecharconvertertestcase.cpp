//-------------------------------------------------------------------------
/*!
    \file replacecharconvertertestcase.cpp
    \brief
*/

//-------------------------------------------------------------------------

// Include Header File
#include "replacecharconvertertestcase.h"

// Include Toolkit Core Files
#include <toolkit/core/replacecharconverter.h>

//-------------------------------------------------------------------------
using namespace Toolkit::Test;
using namespace Toolkit::Core;

//-------------------------------------------------------------------------

ReplaceCharConverterTestCase::ReplaceCharConverterTestCase() :
    TestCase()
{
};

ReplaceCharConverterTestCase::~ReplaceCharConverterTestCase() {
};

void ReplaceCharConverterTestCase::testConstructors() {
    ReplaceCharConverter c1;
    ASSERT_EQUAL( c1.getStartChar(), QChar() );
    ASSERT_EQUAL( c1.getReplaceValue(), "" );

    ReplaceCharConverter c2( '<', "&lt;" );
    ASSERT_EQUAL( c2.getStartChar(), QChar( '<' ) );
    ASSERT_EQUAL( c2.getReplaceValue(), "&lt;" );

    ReplaceCharConverter c3( c2 );
    ASSERT_EQUAL( c3.getStartChar(), QChar( '<' ) );
    ASSERT_EQUAL( c3.getReplaceValue(), "&lt;" );
};

void ReplaceCharConverterTestCase::testCanConvertFromUnicode() {
    ReplaceCharConverter c1( '<', "&lt;" );

    ASSERT_EQUAL( c1.canConvertFromUnicode( '<' ), true );
    ASSERT_EQUAL( c1.canConvertFromUnicode( QChar() ), false );
    ASSERT_EQUAL( c1.canConvertFromUnicode( '>' ), false );
};

void ReplaceCharConverterTestCase::testCanConvertToUnicode() {
    ReplaceCharConverter c1( '<', "&lt;" );

    QString s = c1.getReplaceValue();
    ASSERT_EQUAL( c1.canConvertToUnicode( s, 0 ), true );
    ASSERT_EQUAL( c1.canConvertToUnicode( s, 1 ), false );

    s = StringFormat::format( "a %s b", c1.getReplaceValue() );
    ASSERT_EQUAL( c1.canConvertToUnicode( s, s.indexOf( c1.getReplaceValue() ) ), true );
    ASSERT_EQUAL( c1.canConvertToUnicode( s, 0 ), false );
    ASSERT_EQUAL( c1.canConvertToUnicode( s, 1 ), false );
    ASSERT_EQUAL( c1.canConvertToUnicode( s, s.length() - c1.getReplaceValue().length() ), false );
};

void ReplaceCharConverterTestCase::testFromUnicode() {
    ReplaceCharConverter c1( '<', "&lt;" );

    ASSERT_EQUAL( c1.fromUnicode( QChar() ), "" );
    ASSERT_EQUAL( c1.fromUnicode( c1.getStartChar() ), c1.getReplaceValue() );
    ASSERT_EQUAL( c1.fromUnicode( '@' ), "" );
};

void ReplaceCharConverterTestCase::testToUnicode() {
    ReplaceCharConverter c1( '<', "&lt;" );
    QString fmt = "%s";
    int pos;

    pos = 0;
    ASSERT_EQUAL( c1.toUnicode( StringFormat::format( fmt, c1.getReplaceValue() ), pos ), c1.getStartChar() );
    ASSERT_EQUAL( pos, c1.getReplaceValue().length() );

    fmt = "&%s";
    pos = 0;
    ASSERT_EQUAL( c1.toUnicode( StringFormat::format( fmt, c1.getReplaceValue() ), pos ), QChar() );
    ASSERT_EQUAL( pos, 0 );

    fmt = "24 %s 32";
    pos = 3;
    ASSERT_EQUAL( c1.toUnicode( StringFormat::format( fmt, c1.getReplaceValue() ), pos ), c1.getStartChar() );
    ASSERT_EQUAL( pos, 3 + c1.getReplaceValue().length() );

    fmt = "24 %s";
    pos = 3;
    ASSERT_EQUAL( c1.toUnicode( StringFormat::format( fmt, c1.getReplaceValue() ), pos ), c1.getStartChar() );
    ASSERT_EQUAL( pos, 3 + c1.getReplaceValue().length() );
};

void ReplaceCharConverterTestCase::testOpAssign() {
    ReplaceCharConverter c1( '<', "&lt;" );

    ReplaceCharConverter c2 = c1;
    ASSERT_EQUAL( c2.getStartChar(), QChar( '<' ) );
    ASSERT_EQUAL( c2.getReplaceValue(), "&lt;" );
};

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */

