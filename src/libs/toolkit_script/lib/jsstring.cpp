//---------------------------------------------------------------------------------------
/*!
    \file jsstring.cpp
    \brief
*/

//---------------------------------------------------------------------------------------

// Include Header File
#include "jsstring.h"

// include Toolkit Core Files
#include <toolkit/core/exception.h>
#include <toolkit/core/stringformat.h>

// include Qt Files
#include <QScriptEngine>

//---------------------------------------------------------------------------------------
using namespace Toolkit::Core;
using namespace Toolkit::Script;

//---------------------------------------------------------------------------------------
/*!
    \brief

    \param ctx
    \param eng

    \exception Exception

    \return
*/
QScriptValue JSString::format( QScriptContext* ctx, QScriptEngine* ) {
    if( ctx->isCalledAsConstructor() ) {
        throw Exception( SOURCELINE, "String.format() can not be called with a new operator." );
    };

    if( ctx->argumentCount() == 0 ) {
        return "";
    }

    QString format = ctx->argument( 0 ).toString();
    StringFormat formater;

    for( int i = 1; i < ctx->argumentCount(); i++ ) {
        QScriptValue arg = ctx->argument( i );

        if( arg.isString() ) {
            formater.printf( format, arg.toString() );
        }
        else if( arg.isBool() ) {
            formater.printf( format, arg.toBool() );
        }
        else if( arg.isBoolean() ) {
            formater.printf( format, arg.toBoolean() );
        }
        else if( arg.isDate() ) {
            formater.printf( format, arg.toDateTime() );
        }
        else if( arg.isNull() ) {
            formater.printf( format, QString() );
        }
        else if( arg.isNumber() ) {
            formater.printf( format, arg.toNumber() );
        }
        else if( arg.isRegExp() ) {
            formater.printf( format, arg.toRegExp().pattern() );
        }
        else if( arg.isVariant() ) {
            formater.printf( format, arg.toString() );
        }
        else {
            formater.printf( format, arg.toString() );
        }
    }
    
    return formater.lastResult();
}

/*!
    \brief

    \param ctx
    \param eng

    \exception Exception

    \return
*/
QScriptValue JSString::toInt( QScriptContext* ctx, QScriptEngine* ) {
    if( ctx->isCalledAsConstructor() ) {
        throw Exception( SOURCELINE, "String.toInt() can not be called with a new operator." );
    };

    if( ctx->argumentCount() > 1 ) {
        throw Exception( SOURCELINE, "Wrong number of arguments." );
    }

    bool ok;
    int base = 10;

    if( ctx->argumentCount() == 1 && ctx->argument( 0 ).isNumber() ) {
        base = ctx->argument( 0 ).toInt32();
    }

    int result = ctx->thisObject().toString().toInt( &ok, base );
    if( !ok ) {
        return QScriptValue::UndefinedValue;
    }

    return result;
}

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
