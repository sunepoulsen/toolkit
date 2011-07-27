//-------------------------------------------------------------------------------------------------
/*!
    \file formatparamtestcase.cpp
    \brief
*/

//-------------------------------------------------------------------------------------------------

// Include Header File
#include "formatparamtestcase.h"

// Include Toolkit Core Files
#include <toolkit/core/formatparam.h>

//-------------------------------------------------------------------------------------------------
using namespace Toolkit::Core;

//-------------------------------------------------------------------------------------------------
FormatParamTestCase::FormatParamTestCase() :
    TestCase()
{
};

FormatParamTestCase::~FormatParamTestCase() {
};

/*!
    \brief Tests Toolkit::Core::FormatParam::PARAM_PATTERN
*/
void FormatParamTestCase::testRegExp() {
    QRegExp rx( FormatParam::PARAM_PATTERN );

    ASSERT_EQUAL( rx.indexIn( "%s" ), 0 );
    ASSERT_EQUAL( rx.cap(), "%s" );
    ASSERT_EQUAL( rx.indexIn( "%%s" ), 0 );
    ASSERT_EQUAL( rx.cap(), "%%" );
    ASSERT_EQUAL( rx.indexIn( "%%%s" ), 0 );
    ASSERT_EQUAL( rx.cap(), "%%" );
    ASSERT_EQUAL( rx.indexIn( "%%%%s" ), 0 );
    ASSERT_EQUAL( rx.cap(), "%%" );
    ASSERT_EQUAL( rx.indexIn( "%%%%%%%%%%%%%%%%%%%%%%%%s" ), 0 );
    ASSERT_EQUAL( rx.cap(), "%%" );
};

void FormatParamTestCase::testConstructor() {
    FormatParam fp1;

    ASSERT_EQUAL( fp1.getArgIndex(), -1 );
    ASSERT_EQUAL( fp1.getFlags(), "" );
    ASSERT_EQUAL( fp1.getWidth(), 0 );
    ASSERT_EQUAL( fp1.getPrecision(), -1 );
    ASSERT_EQUAL( fp1.getConversion(), 0 );

    FormatParam fp2( "%5$abcFGT50.17c" );
    ASSERT_EQUAL( fp2.getArgIndex(), 5 );
    ASSERT_EQUAL( fp2.getFlags(), "abcFGT" );
    ASSERT_EQUAL( fp2.getWidth(), 50 );
    ASSERT_EQUAL( fp2.getPrecision(), 17 );
    ASSERT_EQUAL( fp2.getConversion(), 'c' );

    FormatParam fp3( "Dette ser underligt ud!!!" );
    ASSERT_EQUAL( fp3.getArgIndex(), -1 );
    ASSERT_EQUAL( fp3.getFlags(), "" );
    ASSERT_EQUAL( fp3.getWidth(), 0 );
    ASSERT_EQUAL( fp3.getPrecision(), -1 );
    ASSERT_EQUAL( fp3.getConversion(), 0 );
};

void FormatParamTestCase::testRegExpConstructor() {
    FormatParam fp1 = createParam( "%5$abcFGT50.17c" );
    ASSERT_EQUAL( fp1.getArgIndex(), 5 );
    ASSERT_EQUAL( fp1.getFlags(), "abcFGT" );
    ASSERT_EQUAL( fp1.getWidth(), 50 );
    ASSERT_EQUAL( fp1.getPrecision(), 17 );
    ASSERT_EQUAL( fp1.getConversion(), 'c' );

    FormatParam fp2 = createParam( "Dette ser underligt ud!!!" );
    ASSERT_EQUAL( fp2.getArgIndex(), -1 );
    ASSERT_EQUAL( fp2.getFlags(), "" );
    ASSERT_EQUAL( fp2.getWidth(), 0 );
    ASSERT_EQUAL( fp2.getPrecision(), -1 );
    ASSERT_EQUAL( fp2.getConversion(), 0 );
};

void FormatParamTestCase::testCopyConstructor() {
    FormatParam fp1 = createParam( "%5$abcFGT50.17c" );
    FormatParam fp2( fp1 );

    ASSERT_EQUAL( fp1.getArgIndex(), fp2.getArgIndex() );
    ASSERT_EQUAL( fp1.getFlags(), fp2.getFlags() );
    ASSERT_EQUAL( fp1.getWidth(), fp2.getWidth() );
    ASSERT_EQUAL( fp1.getPrecision(), fp2.getPrecision() );
    ASSERT_EQUAL( fp1.getConversion(), fp2.getConversion() );
};

void FormatParamTestCase::testProperties() {
    FormatParam fp;

    fp.setArgIndex( -17 );
    ASSERT_EQUAL( fp.getArgIndex(), -17 );

    fp.setFlags( "gog" );
    ASSERT_EQUAL( fp.getFlags(), "gog" );

    fp.setWidth( -18 );
    ASSERT_EQUAL( fp.getWidth(), -18 );

    fp.setPrecision( -5 );
    ASSERT_EQUAL( fp.getPrecision(), -5 );

    fp.setConversion( QChar( 0x0021 ) );
    ASSERT_EQUAL( fp.getConversion(), QChar( 0x0021 ) );
};

void FormatParamTestCase::testToString() {
    ASSERT_EQUAL( FormatParam().toString(), "" );

    QString s;
    FormatParam fp;

    s = "%5$abcFGT50.17c";
    fp = createParam( s );
    ASSERT_EQUAL( fp.toString(), s );

    s = "%5$abcFGT50c";
    fp = createParam( s );
    ASSERT_EQUAL( fp.toString(), s );

    s = "%5$abcFGT.17c";
    fp = createParam( s );
    ASSERT_EQUAL( fp.toString(), s );

    s = "%5$abcFGTc";
    fp = createParam( s );
    ASSERT_EQUAL( fp.toString(), s );

    s = "%5$c";
    fp = createParam( s );
    ASSERT_EQUAL( fp.toString(), s );

    s = "%c";
    fp = createParam( s );
    ASSERT_EQUAL( fp.toString(), s );
};

void FormatParamTestCase::testFromString() {
    QString s;
    FormatParam fp;

    s = "%5$abcFGT50.17c";
    fp.fromString( s );
    ASSERT_EQUAL( fp.getArgIndex(), 5 );
    ASSERT_EQUAL( fp.getFlags(), "abcFGT" );
    ASSERT_EQUAL( fp.getWidth(), 50 );
    ASSERT_EQUAL( fp.getPrecision(), 17 );
    ASSERT_EQUAL( fp.getConversion(), 'c' );

    s = "%5$abcFGT50c";
    fp.fromString( s );
    ASSERT_EQUAL( fp.getArgIndex(), 5 );
    ASSERT_EQUAL( fp.getFlags(), "abcFGT" );
    ASSERT_EQUAL( fp.getWidth(), 50 );
    ASSERT_EQUAL( fp.getPrecision(), -1 );
    ASSERT_EQUAL( fp.getConversion(), 'c' );

    s = "%5$abcFGT.17c";
    fp.fromString( s );
    ASSERT_EQUAL( fp.getArgIndex(), 5 );
    ASSERT_EQUAL( fp.getFlags(), "abcFGT" );
    ASSERT_EQUAL( fp.getWidth(), 0 );
    ASSERT_EQUAL( fp.getPrecision(), 17 );
    ASSERT_EQUAL( fp.getConversion(), 'c' );

    s = "%5$abcFGTc";
    fp.fromString( s );
    ASSERT_EQUAL( fp.getArgIndex(), 5 );
    ASSERT_EQUAL( fp.getFlags(), "abcFGT" );
    ASSERT_EQUAL( fp.getWidth(), 0 );
    ASSERT_EQUAL( fp.getPrecision(), -1 );
    ASSERT_EQUAL( fp.getConversion(), 'c' );

    s = "%5$c";
    fp.fromString( s );
    ASSERT_EQUAL( fp.getArgIndex(), 5 );
    ASSERT_EQUAL( fp.getFlags(), "" );
    ASSERT_EQUAL( fp.getWidth(), 0 );
    ASSERT_EQUAL( fp.getPrecision(), -1 );
    ASSERT_EQUAL( fp.getConversion(), 'c' );

    s = "%c";
    fp.fromString( s );
    ASSERT_EQUAL( fp.getArgIndex(), -1 );
    ASSERT_EQUAL( fp.getFlags(), "" );
    ASSERT_EQUAL( fp.getWidth(), 0 );
    ASSERT_EQUAL( fp.getPrecision(), -1 );
    ASSERT_EQUAL( fp.getConversion(), 'c' );
};

void FormatParamTestCase::testOpAssign() {
    FormatParam fp1 = createParam( "%5$abcFGT50.17c" );
    FormatParam fp2 = fp1;

    ASSERT_EQUAL( fp1.getArgIndex(), fp2.getArgIndex() );
    ASSERT_EQUAL( fp1.getFlags(), fp2.getFlags() );
    ASSERT_EQUAL( fp1.getWidth(), fp2.getWidth() );
    ASSERT_EQUAL( fp1.getPrecision(), fp2.getPrecision() );
    ASSERT_EQUAL( fp1.getConversion(), fp2.getConversion() );
};

void FormatParamTestCase::testOpAssignString() {
    FormatParam fp;

    fp = "%5$abcFGT50.17c";
    ASSERT_EQUAL( fp.getArgIndex(), 5 );
    ASSERT_EQUAL( fp.getFlags(), "abcFGT" );
    ASSERT_EQUAL( fp.getWidth(), 50 );
    ASSERT_EQUAL( fp.getPrecision(), 17 );
    ASSERT_EQUAL( fp.getConversion(), 'c' );
};

FormatParam FormatParamTestCase::createParam( const QString& str ) {
    QRegExp rx( FormatParam::PARAM_PATTERN );

    if( rx.indexIn( str ) > -1 ) {
        return FormatParam( rx );
    }
    else {
        return FormatParam();
    };
};

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
