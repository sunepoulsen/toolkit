//-------------------------------------------------------------------------------------------------
/*!
    \file defaultargumentformater.cpp
    \brief
*/

//-------------------------------------------------------------------------------------------------

// Include Header File
#include "defaultargumentformater.h"

// Include Toolkit Core Files
#include "formatexception.h"

//-------------------------------------------------------------------------------------------------
using namespace Toolkit::Core;

//-------------------------------------------------------------------------------------------------

// Convertion constants
const QChar DefaultArgumentFormater::CONV_STRING( 's' );
const QChar DefaultArgumentFormater::CONV_BOOL( 'b' );
const QChar DefaultArgumentFormater::CONV_INT( 'i' );
const QChar DefaultArgumentFormater::CONV_DECIMAL( 'd' );
const QChar DefaultArgumentFormater::CONV_HEX( 'h' );
const QChar DefaultArgumentFormater::CONV_OCTAL( 'o' );
const QChar DefaultArgumentFormater::CONV_DOUBLE( 'g' );
const QChar DefaultArgumentFormater::CONV_FLOAT( 'f' );
const QChar DefaultArgumentFormater::CONV_EXP( 'e' );
const QChar DefaultArgumentFormater::CONV_DATETIME( 't' );

const QString DefaultArgumentFormater::QCHAR_CONVS(
    QString() + CONV_STRING + CONV_DECIMAL + CONV_HEX
);
const QString DefaultArgumentFormater::QSTRING_CONVS( CONV_STRING );
const QString DefaultArgumentFormater::BOOL_CONVS(
        QString() + CONV_STRING + CONV_INT
);
const QString DefaultArgumentFormater::DOUBLE_CONVS(
        QString() + CONV_DOUBLE + CONV_FLOAT + CONV_EXP
);
const QString DefaultArgumentFormater::DATETIME_CONVS( CONV_DATETIME );

// Flags constants
const QChar DefaultArgumentFormater::FLAG_DEBUG( 'd' );
const QChar DefaultArgumentFormater::FLAG_FILL_ZEROS( 'n' );
const QChar DefaultArgumentFormater::FLAG_GROUP_SEP( 'g' );
const QChar DefaultArgumentFormater::FLAG_LOWERCASE( 'l' );
const QChar DefaultArgumentFormater::FLAG_PARENTES( 'p' );
const QChar DefaultArgumentFormater::FLAG_TRUNCATE( 't' );
const QChar DefaultArgumentFormater::FLAG_UPPERCASE( 'u' );

// Value constants
const QString DefaultArgumentFormater::NULL_VALUE( "(null)" );
const QString DefaultArgumentFormater::EMPTY_VALUE( "(empty)" );
const QString DefaultArgumentFormater::TRUE_VALUE( QString::number( (int)( true ) ) );
const QString DefaultArgumentFormater::FALSE_VALUE( QString::number( (int)( false ) ) );
const QString DefaultArgumentFormater::TRUE_NAME_VALUE( "true" );
const QString DefaultArgumentFormater::FALSE_NAME_VALUE( "false" );
const QString DefaultArgumentFormater::DATE_FORMAT( "dd/MM-yy" );
const QString DefaultArgumentFormater::TIME_FORMAT( "hh:mm" );
const QString DefaultArgumentFormater::DATETIME_FORMAT( DATE_FORMAT + " " + TIME_FORMAT );

//-------------------------------------------------------------------------------------------------
DefaultArgumentFormater::DefaultArgumentFormater() {
};

DefaultArgumentFormater::~DefaultArgumentFormater() {
};

/*!
    \brief Converts a const char to a QString.
*/
QString DefaultArgumentFormater::format( const QLocale& locale, const FormatParam& param, const char ch ) const {
    return format( locale, param, QChar( ch ) );
};

/*!
    \brief Converts a QChar to a QString based on the format parameter \e param.

    \par Supported Conversions
    <dl>
        <dt>s</dt>
        <dd>
            Converts the char.
            <p/>
            <b>Flags:</b> Any.
        </dd>
        <dt>d</dt>
        <dd>
            Converts the char to its internal unicode value and displays it in decimals.
            <p/>
            <b>Flags:</b> Any.
        </dd>
        <dt>h</dt>
        <dd>
            Converts the char to its internal unicode value and displays it in hex.
            <p/>
            <b>Flags:</b> Any.
        </dd>
    </dl>

    \par Supported Flags
    <dl>
        <dt>None</dt>
        <dd>
            The char is simply converted as it is.
        </dd>

        <dt>u</td>
        <dd>The char is converted to upper cases. \e u has precedens over \e l.</dd>

        <dt>l</td>
        <dd>The char is converted to lower cases.</dd>

        <dt>n</dt>
        <dd>
            Uses 0's in stead of spaces to fill extra spaces, then justifying for the width.
        </dd>

        <dt>d</dt>
        <dd>
            The char is converted to "(null)" if it is null.
        </dd>
    </dl>
    \par
    Any unsupported flags are ignored!

    \param locale The locale to use. This parameter is ignored in this implementation.
    \param param  The format parameter to use.
    \param ch     The char to convert.

    \exception FormatException In case of an unsupported conversion.
*/
QString DefaultArgumentFormater::format( const QLocale& locale, const FormatParam& param, const QChar& ch ) const {
    if( !checkConversion( QCHAR_CONVS, param.getConversion() ) ) {
        throw FormatException( SOURCELINE, QString( "The conversion %1 is not supported on QChar arguments" ).arg( param.getConversion() ) );
    };

    QString res;

    if( param.hasConversion( CONV_STRING ) ) {
        res = ch;
    }
    else if( param.hasConversion( CONV_DECIMAL ) ) {
        res = QString::number( ch.unicode() );
    }
    else if( param.hasConversion( CONV_HEX ) ) {
        res = QString::number( ch.unicode(), 16 );
    };

    res = justifyCases( param, res );

    if( param.hasFlag( FLAG_DEBUG ) && ch.isNull() ) {
        res = NULL_VALUE;
    };

    if( res.isEmpty() ) {
        res = ch;
    };

    // Justify result
    return justifyWidth( locale, param, res );
};

/*!
    \brief Formats a const char* based on the format parameter \e param.

    \par Supported Conversions
    <dl>
        <dt>s</dt>
        <dd>
            Converts the passed string.
            <p/>
            <b>Flags:</b> Any.
        </dd>
    </dl>

    \par Supported Flags
    <dl>
        <dt>None</dt>
        <dd>
            The string is simply converted as it is.
        </dd>

        <dt>u</td>
        <dd>The char is converted to upper cases. \e u has precedens over \e l.</dd>

        <dt>l</td>
        <dd>The char is converted to lower cases.</dd>

        <dt>t</dt>
        <dd>
            In case of a specified \e width, the string is truncated to \e width if it
            is larger than \e width.
        </dd>

        <dt>d</dt>
        <dd>
            The string is converted to "(empty)" is it is empty or "(null)" if it is null.
        </dd>
    </dl>
    \par
    Any unsupported flags are ignored!

    \param locale The locale to use. This parameter is ignored in this implementation.
    \param param  The format parameter to use.
    \param ch     The char to convert.

    \exception FormatException In case of an unsupported conversion.
*/
QString DefaultArgumentFormater::format( const QLocale& locale, const FormatParam& param, const char* str ) const {
    return format( locale, param, QString( str ) );
};

/*!
    \brief Formats a std::string based on the format parameter \e param.

    \par Supported Conversions
    <dl>
        <dt>s</dt>
        <dd>
            Converts the passed string.
            <p/>
            <b>Flags:</b> Any.
        </dd>
    </dl>

    \par Supported Flags
    <dl>
        <dt>None</dt>
        <dd>
            The string is simply converted as it is.
        </dd>

        <dt>u</td>
        <dd>The char is converted to upper cases. \e u has precedens over \e l.</dd>

        <dt>l</td>
        <dd>The char is converted to lower cases.</dd>

        <dt>t</dt>
        <dd>
            In case of a specified \e width, the string is truncated to \e width if it
            is larger than \e width.
        </dd>

        <dt>d</dt>
        <dd>
            The string is converted to "(empty)" is it is empty or "(null)" if it is null.
        </dd>
    </dl>
    \par
    Any unsupported flags are ignored!

    \param locale The locale to use. This parameter is ignored in this implementation.
    \param param  The format parameter to use.
    \param ch     The char to convert.

    \exception FormatException In case of an unsupported conversion.
*/
QString DefaultArgumentFormater::format( const QLocale& locale, const FormatParam& param, const std::string& str ) const {
    return format( locale, param, QString::fromStdString( str ) );
};

/*!
    \brief Formats a QString based on the format parameter \e param.

    \par Supported Conversions
    <dl>
        <dt>s</dt>
        <dd>
            Converts the passed string.
            <p/>
            <b>Flags:</b> Any.
        </dd>
    </dl>

    \par Supported Flags
    <dl>
        <dt>None</dt>
        <dd>
            The string is simply converted as it is.
        </dd>

        <dt>u</td>
        <dd>The char is converted to upper cases. \e u has precedens over \e l.</dd>

        <dt>l</td>
        <dd>The char is converted to lower cases.</dd>

        <dt>t</dt>
        <dd>
            In case of a specified \e width, the string is truncated to \e width if it
            is larger than \e width.
        </dd>

        <dt>d</dt>
        <dd>
            The string is converted to "(empty)" is it is empty or "(null)" if it is null.
        </dd>
    </dl>
    \par
    Any unsupported flags are ignored!

    \param locale The locale to use. This parameter is ignored in this implementation.
    \param param  The format parameter to use.
    \param ch     The char to convert.

    \exception FormatException In case of an unsupported conversion.
*/
QString DefaultArgumentFormater::format( const QLocale& locale, const FormatParam& param, const QString& str ) const {
    if( !checkConversion( QSTRING_CONVS, param.getConversion() ) ) {
        throw FormatException( SOURCELINE, QString( "The conversion %1 is not supported on QString arguments" ).arg( param.getConversion() ) );
    };

    QString res;

    if( param.hasFlag( FLAG_DEBUG ) ) {
        if( str.isNull() ) {
            res = NULL_VALUE;
        }
        else if( str.isEmpty() ) {
            res = EMPTY_VALUE;
        };
    };

    if( res.isEmpty() ) {
        res = str;
    };

    // Justify result
    res = justifyCases( param, res );
    return justifyWidth( locale, param, res );
};

/*!
    \brief Formats a bool based on the format parameter \e param.

    \par Supported Conversions
    <dl>
        <dt>s</dt>
        <dd>
            Converts the bool as the names \e true or \e false.
            <p/>
            <b>Flags:</b> Any.
        </dd>

        <dt>i</dt>
        <dd>
            Converts the bool as \e 0 or \e 1
            <p/>
            <b>Flags:</b> \e p
        </dd>
    </dl>

    \par Supported Flags
    <dl>
        <dt>None</dt>
        <dd>
            The string is simply converted as it is.
        </dd>

        <dt>p</dt>
        <dd>
            Puts the result in parentes. Like "(true)" or "(0)".
        </dd>

        <dt>u</td>
        <dd>The result is converted to upper cases. \e u has precedens over \e l.</dd>

        <dt>l</td>
        <dd>The result is converted to lower cases.</dd>

        <dt>t</dt>
        <dd>
            In case of a specified \e width, the result is truncated to \e width if it
            is larger than \e width.
        </dd>
    </dl>
    \par
    Any unsupported flags are ignored!

    \param locale The locale to use. This parameter is ignored in this implementation.
    \param param  The format parameter to use.
    \param ch     The char to convert.

    \exception FormatException In case of an unsupported conversion.
*/
QString DefaultArgumentFormater::format( const QLocale& locale, const FormatParam& param, bool b ) const {
    if( !checkConversion( BOOL_CONVS, param.getConversion() ) ) {
        throw FormatException( SOURCELINE, QString( "The conversion %1 is not supported on bool arguments" ).arg( param.getConversion() ) );
    };

    QString res;

    if( param.hasConversion( CONV_STRING ) ) {
        res = b ? TRUE_NAME_VALUE : FALSE_NAME_VALUE;
    }
    else if( param.hasConversion( CONV_INT ) ) {
        res = QString::number( b );
    };

    if( param.hasFlag( FLAG_PARENTES ) ) {
        res = "(" + res + ")";
    };

    // Justify result
    res = justifyCases( param, res );
    return justifyWidth( locale, param, res );
};

/*!
    \brief Formats a double based on the format parameter \e param.

    For supported conversions and flags see formatFloat()

    \param locale The locale to use. This parameter is ignored in this implementation.
    \param param  The format parameter to use.
    \param d      The double to format.

    \exception FormatException In case of an unsupported conversion.
*/
QString DefaultArgumentFormater::format( const QLocale& locale, const FormatParam& param, double d ) const {
    return formatFloat( locale, param, d );
};

/*!
    \brief Formats a double based on the format parameter \e param.

    For supported conversions and flags see formatFloat()

    \param locale The locale to use. This parameter is ignored in this implementation.
    \param param  The format parameter to use.
    \param f      The float to convert.

    \exception FormatException In case of an unsupported conversion.
*/
QString DefaultArgumentFormater::format( const QLocale& locale, const FormatParam& param, float f ) const {
    return formatFloat( locale, param, f );
};

/*!
    \brief Formats an integer based on the format parameter \e param.

    For supported conversions and flags see formatInteger()

    \param locale The locale to use. This parameter is ignored in this implementation.
    \param param  The format parameter to use.
    \param i      The integer to convert.

    \exception FormatException In case of an unsupported conversion.
*/
QString DefaultArgumentFormater::format( const QLocale& locale, const FormatParam& param, int i ) const {
    return formatInteger( locale, param, i );
};

/*!
    \brief Formats an integer based on the format parameter \e param.

    For supported conversions and flags see formatInteger()

    \param locale The locale to use. This parameter is ignored in this implementation.
    \param param  The format parameter to use.
    \param i      The integer to convert.

    \exception FormatException In case of an unsupported conversion.
*/
QString DefaultArgumentFormater::format( const QLocale& locale, const FormatParam& param, uint i ) const {
    return formatInteger( locale, param, i );
};

QString DefaultArgumentFormater::format( const QLocale& locale, const FormatParam& param, long i ) const {
    return format( locale, param, (qlonglong)( i ) );
};

QString DefaultArgumentFormater::format( const QLocale& locale, const FormatParam& param, ulong i ) const {
    return format( locale, param, (qulonglong)( i ) );
};

/*!
    \brief Formats an integer based on the format parameter \e param.

    For supported conversions and flags see formatInteger()

    \param locale The locale to use. This parameter is ignored in this implementation.
    \param param  The format parameter to use.
    \param i      The integer to convert.

    \exception FormatException In case of an unsupported conversion.
*/
QString DefaultArgumentFormater::format( const QLocale& locale, const FormatParam& param, short i ) const {
    return formatInteger( locale, param, i );
};

/*!
    \brief Formats an integer based on the format parameter \e param.

    For supported conversions and flags see formatInteger()

    \param locale The locale to use. This parameter is ignored in this implementation.
    \param param  The format parameter to use.
    \param i      The integer to convert.

    \exception FormatException In case of an unsupported conversion.
*/
QString DefaultArgumentFormater::format( const QLocale& locale, const FormatParam& param, ushort i ) const {
    return formatInteger( locale, param, i );
};

/*!
    \brief Formats an integer based on the format parameter \e param.

    For supported conversions and flags see formatInteger()

    \param locale The locale to use. This parameter is ignored in this implementation.
    \param param  The format parameter to use.
    \param i      The integer to convert.

    \exception FormatException In case of an unsupported conversion.
*/
QString DefaultArgumentFormater::format( const QLocale& locale, const FormatParam& param, qlonglong i ) const {
    return formatInteger( locale, param, i );
};

/*!
    \brief Formats an integer based on the format parameter \e param.

    For supported conversions and flags see formatInteger()

    \param locale The locale to use. This parameter is ignored in this implementation.
    \param param  The format parameter to use.
    \param i      The integer to convert.

    \exception FormatException In case of an unsupported conversion.
*/
QString DefaultArgumentFormater::format( const QLocale& locale, const FormatParam& param, qulonglong i ) const {
    return formatInteger( locale, param, i );
};

/*!
    \brief Formats a QBitArray based on the format parameter \e param.

    A QBitArray is formated as a list of booleans. The parameter \e param has the same meaning as for bools.
    Each element is separated with commas.

    \param locale The locale to use. This parameter is ignored in this implementation.
    \param param  The format parameter to use.
    \param i      The integer to convert.

    \exception FormatException In case of an unsupported conversion.
*/
QString DefaultArgumentFormater::format( const QLocale& locale, const FormatParam& param, const QBitArray& ba ) const {
    if( !checkConversion( BOOL_CONVS, param.getConversion() ) ) {
        throw FormatException( SOURCELINE, QString( "The conversion %1 is not supported on QBitArray arguments" ).arg( param.getConversion() ) );
    };

    QString res;

    for( int i = 0; i < ba.size(); i++ ) {
        if( i != 0 ) {
            res += ", ";
        };

        res += format( locale, param, ba.at( i ) );
    };

    // Justify result
    return justifyCases( param, res );
};

/*!
    \brief Formats a QByteArray based on the format parameter \e param.

    It can be formated in the same way as a QString.

    \param locale The locale to use. This parameter is ignored in this implementation.
    \param param  The format parameter to use.
    \param i      The integer to convert.

    \exception FormatException In case of an unsupported conversion.
*/
QString DefaultArgumentFormater::format( const QLocale& locale, const FormatParam& param, const QByteArray& ba ) const {
    if( !checkConversion( QSTRING_CONVS, param.getConversion() ) ) {
        throw FormatException( SOURCELINE, QString( "The conversion %1 is not supported on QByteArray arguments" ).arg( param.getConversion() ) );
    };

    QString res;

    if( param.hasFlag( FLAG_DEBUG ) ) {
        if( ba.isNull() ) {
            res = NULL_VALUE;
        }
        else if( ba.isEmpty() ) {
            res = EMPTY_VALUE;
        };
    };

    if( res.isEmpty() ) {
        res = ba;
    };

    // Justify result
    res = justifyCases( param, res );
    return justifyWidth( locale, param, res );
};

QString DefaultArgumentFormater::format( const QLocale& locale, const FormatParam& param, const QDate& date ) const {
    if( !checkConversion( DATETIME_CONVS, param.getConversion() ) ) {
        throw FormatException( SOURCELINE, QString( "The conversion %1 is not supported on QDate arguments" ).arg( param.getConversion() ) );
    };

    QString fmt = param.getFlags();

    if( fmt.isEmpty() ) {
        fmt = DATE_FORMAT;
    };

    QString res = locale.toString( date, fmt );

    // Justify result
    res = justifyCases( param, res );
    return justifyWidth( locale, param, res );
};

QString DefaultArgumentFormater::format( const QLocale& locale, const FormatParam& param, const QTime& time ) const {
    if( !checkConversion( DATETIME_CONVS, param.getConversion() ) ) {
        throw FormatException( SOURCELINE, QString( "The conversion %1 is not supported on QTime arguments" ).arg( param.getConversion() ) );
    };

    QString fmt = param.getFlags();

    if( fmt.isEmpty() ) {
        fmt = TIME_FORMAT;
    };

    QString res = locale.toString( time, fmt );

    // Justify result
    res = justifyCases( param, res );
    return justifyWidth( locale, param, res );
};

QString DefaultArgumentFormater::format( const QLocale& locale, const FormatParam& param, const QDateTime& dateTime ) const {
    if( !checkConversion( DATETIME_CONVS, param.getConversion() ) ) {
        throw FormatException( SOURCELINE, QString( "The conversion %1 is not supported on QTime arguments" ).arg( param.getConversion() ) );
    };

    QString fmt = param.getFlags();

    if( fmt.isEmpty() ) {
        fmt = DATETIME_FORMAT;
    };

    QString res = locale.toString( dateTime, fmt );

    // Justify result
    res = justifyCases( param, res );
    return justifyWidth( locale, param, res );
};

bool DefaultArgumentFormater::checkConversion( const QString& convs, const QChar& conv ) const {
    return convs.contains( conv, Qt::CaseInsensitive );
};

QString DefaultArgumentFormater::justifyCases( const FormatParam& param, const QString& str ) const {
    if( param.hasFlag( FLAG_UPPERCASE ) ) {
        return str.toUpper();
    }
    else if( param.hasFlag( FLAG_LOWERCASE ) ) {
        return str.toLower();
    };

    return str;
};

QString DefaultArgumentFormater::justifyWidth( const QLocale& locale, const FormatParam& param, const QString& str ) const {
    // param.getWidth() is unspecified.
    if( param.getWidth() == 0 ) {
        return str;
    };

    QChar fillChar = ' ';
    if( param.hasFlag( FLAG_FILL_ZEROS ) ) {
        fillChar = locale.zeroDigit();
    };

    // param.getWidth() is negative ==> The string is right justified.
    if( param.getWidth() < 0 ) {
        return str.rightJustified( -param.getWidth(), fillChar, param.hasFlag( FLAG_TRUNCATE ) );
    };

    // param.getWidth() is positive ==> The string is left justified.
    return str.leftJustified( param.getWidth(), fillChar, param.hasFlag( FLAG_TRUNCATE ) );
};

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
