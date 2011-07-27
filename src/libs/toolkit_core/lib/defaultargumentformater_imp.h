//-------------------------------------------------------------------------------------------------
/*!
    \file defaultargumentformater_imp.h
    \brief
*/

//-------------------------------------------------------------------------------------------------
#ifndef __TOOLKIT_CORE_DEFAULTARGUMENTFORMATER_IMP_H__
#define __TOOLKIT_CORE_DEFAULTARGUMENTFORMATER_IMP_H__

//-------------------------------------------------------------------------------------------------
//              Implementation of template functions.
//-------------------------------------------------------------------------------------------------

template< typename floatType >
QString DefaultArgumentFormater::formatFloat( const QLocale& locale, const FormatParam& param, floatType d ) const {
    if( !checkConversion( DOUBLE_CONVS, param.getConversion() ) ) {
        throw FormatException( SOURCELINE, QString( "The conversion %1 is not supported on the argument" ).arg( param.getConversion() ) );
    };

    QString res = locale.toString( d, param.getConversion().toAscii(), param.getPrecision() );

    if( !param.hasFlag( FLAG_GROUP_SEP ) ) {
        res.replace( locale.groupSeparator(), "" );
    };

    if( d < 0.0 && param.hasFlag( FLAG_PARENTES ) ) {
        res = "(" + res.replace( locale.negativeSign(), "" ) + ")";
    };

    // Justify result
    res = justifyCases( param, res );
    return justifyWidth( locale, param, res );
};

template< typename intType >
QString DefaultArgumentFormater::formatInteger( const QLocale& locale, const FormatParam& param, intType i ) const {
    int base;

    if( param.hasConversion( CONV_INT ) ) {
        base = 10;
    }
    else if( param.hasConversion( CONV_BOOL ) ) {
        base = 2;
    }
    else if( param.hasConversion( CONV_OCTAL ) ) {
        base = 8;
    }
    else if( param.hasConversion( CONV_HEX ) ) {
        base = 16;
    }
    else {
        throw FormatException( SOURCELINE, QString( "The conversion %1 is not supported on integer arguments" ).arg( param.getConversion() ) );
    };

    QString res;

    if( param.hasConversion( CONV_INT ) ) {
        res = locale.toString( i );
    }
    else {
        res = QString::number( i, base );
    };

    if( !param.hasFlag( FLAG_GROUP_SEP ) ) {
        res.replace( locale.groupSeparator(), "" );
    };

    // If we compare i < 0, we will get a compiler warning if intType is unsigned.
    // We fix this by testing if res contains a negative sign.
    if( res.contains( locale.negativeSign() ) && param.hasFlag( FLAG_PARENTES ) ) {
        res = "(" + res.replace( locale.negativeSign(), "" ) + ")";
    };

    // Justify result
    res = justifyCases( param, res );
    return justifyWidth( locale, param, res );
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

