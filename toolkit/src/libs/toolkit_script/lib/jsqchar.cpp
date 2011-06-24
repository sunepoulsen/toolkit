//---------------------------------------------------------------------------------------
/*!
    \file jsqchar.h
    \brief
*/

//---------------------------------------------------------------------------------------

// Include Header File
#include "jsqchar.h"

// Include Qt Files
#include <QScriptEngine>

//---------------------------------------------------------------------------------------
using namespace Toolkit::Script;

//---------------------------------------------------------------------------------------
QScriptValue JSQChar::constructor( QScriptContext* ctx, QScriptEngine* eng ) {
    if( !ctx->isCalledAsConstructor() ) {
        return ctx->throwError( "MarcSubField must be called as a constructor with the new operand." );
    };

    switch( ctx->argumentCount() ) {
    case 0:
        return eng->newQObject( ctx->thisObject(), new JSQChar(), QScriptEngine::ScriptOwnership );

    case 1:
        {
            QScriptValue arg = ctx->argument( 0 );

            if( arg.isNumber() ) {
                return eng->newQObject( ctx->thisObject(), new JSQChar( QSharedPointer<QChar>( new QChar( arg.toInt32() ) ) ), QScriptEngine::ScriptOwnership );
            }
            else {
                return ctx->throwError( "Wrong data type of argument." );
            }
        }

    default:
        return ctx->throwError( "Wrong number of arguments." );
    }

}

JSQChar::JSQChar() :
    QObject(),
    ScriptObject<QChar>( QSharedPointer<QChar>( new QChar() ) ),
    QScriptable()
{
}

JSQChar::JSQChar( QChar* data, ObjectOwnership ownership ) :
    QObject(),
    ScriptObject<QChar>( data, ownership ),
    QScriptable()
{
}

JSQChar::JSQChar( const QSharedPointer<QChar>& data ) :
    QObject(),
    ScriptObject<QChar>( data ),
    QScriptable()
{
}

JSQChar::~JSQChar() {
}

uint JSQChar::category() const {
    if( !getData() ) {
        context()->throwError( "No internal data to operate on!" );
        return 0;
    }

    return getData()->category();
}

uint JSQChar::cell() const {
    if( !getData() ) {
        context()->throwError( "No internal data to operate on!" );
        return 0;
    }

    return getData()->cell();
}

QString JSQChar::decomposition() const {
    if( !getData() ) {
        context()->throwError( "No internal data to operate on!" );
        return "";
    }

    return getData()->decomposition();
}

uint JSQChar::decompositionTag() const {
    if( !getData() ) {
        context()->throwError( "No internal data to operate on!" );
        return 0;
    }

    return getData()->decompositionTag();
}

int JSQChar::digitValue() const {
    if( !getData() ) {
        context()->throwError( "No internal data to operate on!" );
        return -1;
    }

    return getData()->digitValue();
}

uint JSQChar::direction() const {
    if( !getData() ) {
        context()->throwError( "No internal data to operate on!" );
        return 0;
    }

    return getData()->direction();
}

bool JSQChar::hasMirrored() const {
    if( !getData() ) {
        context()->throwError( "No internal data to operate on!" );
        return false;
    }

    return getData()->hasMirrored();
}

bool JSQChar::isAscii() const {
    if( !getData() ) {
        context()->throwError( "No internal data to operate on!" );
        return false;
    }

    return getData()->toAscii() != 0;
}

bool JSQChar::isDigit() const {
    if( !getData() ) {
        context()->throwError( "No internal data to operate on!" );
        return false;
    }

    return getData()->isDigit();
}

bool JSQChar::isHighSurrogate() const {
    if( !getData() ) {
        context()->throwError( "No internal data to operate on!" );
        return false;
    }

    return getData()->isHighSurrogate();
}

bool JSQChar::isLatin1() const {
    if( !getData() ) {
        context()->throwError( "No internal data to operate on!" );
        return false;
    }

    return getData()->toLatin1() != 0;
}

bool JSQChar::isLetter() const {
    if( !getData() ) {
        context()->throwError( "No internal data to operate on!" );
        return false;
    }

    return getData()->isLetter();
}

bool JSQChar::isLetterOrNumber() const {
    if( !getData() ) {
        context()->throwError( "No internal data to operate on!" );
        return false;
    }

    return getData()->isLetterOrNumber();
}

bool JSQChar::isLowSurrogate() const {
    if( !getData() ) {
        context()->throwError( "No internal data to operate on!" );
        return false;
    }

    return getData()->isLowSurrogate();
}

bool JSQChar::isLower() const {
    if( !getData() ) {
        context()->throwError( "No internal data to operate on!" );
        return false;
    }

    return getData()->isLower();
}

bool JSQChar::isMark() const {
    if( !getData() ) {
        context()->throwError( "No internal data to operate on!" );
        return false;
    }

    return getData()->isMark();
}

bool JSQChar::isNull() const {
    if( !getData() ) {
        context()->throwError( "No internal data to operate on!" );
        return false;
    }

    return getData()->isNull();
}

bool JSQChar::isNumber() const {
    if( !getData() ) {
        context()->throwError( "No internal data to operate on!" );
        return false;
    }

    return getData()->isNumber();
}

bool JSQChar::isPrint() const {
    if( !getData() ) {
        context()->throwError( "No internal data to operate on!" );
        return false;
    }

    return getData()->isPrint();
}

bool JSQChar::isPunct() const {
    if( !getData() ) {
        context()->throwError( "No internal data to operate on!" );
        return false;
    }

    return getData()->isPunct();
}

bool JSQChar::isSpace() const {
    if( !getData() ) {
        context()->throwError( "No internal data to operate on!" );
        return false;
    }

    return getData()->isSpace();
}

bool JSQChar::isSymbol() const {
    if( !getData() ) {
        context()->throwError( "No internal data to operate on!" );
        return false;
    }

    return getData()->isSymbol();
}

bool JSQChar::isTitleCase() const {
    if( !getData() ) {
        context()->throwError( "No internal data to operate on!" );
        return false;
    }

    return getData()->isTitleCase();
}

bool JSQChar::isUpper() const {
    if( !getData() ) {
        context()->throwError( "No internal data to operate on!" );
        return false;
    }

    return getData()->isUpper();
}

uint JSQChar::joining() const {
    if( !getData() ) {
        context()->throwError( "No internal data to operate on!" );
        return 0;
    }

    return getData()->joining();
}

QObject* JSQChar::mirroredChar() const {
    if( !getData() ) {
        context()->throwError( "No internal data to operate on!" );
        return NULL;
    }

    return new JSQChar( QSharedPointer<QChar>( new QChar( getData()->mirroredChar() ) ) );
}

uint JSQChar::row() const {
    if( !getData() ) {
        context()->throwError( "No internal data to operate on!" );
        return 0;
    }

    return getData()->row();
}

QObject* JSQChar::toCaseFolded() const {
    if( !getData() ) {
        context()->throwError( "No internal data to operate on!" );
        return NULL;
    }

    return new JSQChar( QSharedPointer<QChar>( new QChar( getData()->toCaseFolded() ) ) );
}

QObject* JSQChar::toLower() const {
    if( !getData() ) {
        context()->throwError( "No internal data to operate on!" );
        return NULL;
    }

    return new JSQChar( QSharedPointer<QChar>( new QChar( getData()->toLower() ) ) );
}

QString JSQChar::toString() const {
    if( !getData() ) {
        context()->throwError( "No internal data to operate on!" );
        return NULL;
    }

    return QString( *getData() );
}

QObject* JSQChar::toTitleCase() const {
    if( !getData() ) {
        context()->throwError( "No internal data to operate on!" );
        return NULL;
    }

    return new JSQChar( QSharedPointer<QChar>( new QChar( getData()->toTitleCase() ) ) );
}

QObject* JSQChar::toUpper() const {
    if( !getData() ) {
        context()->throwError( "No internal data to operate on!" );
        return NULL;
    }

    return new JSQChar( QSharedPointer<QChar>( new QChar( getData()->toUpper() ) ) );
}

ushort JSQChar::unicode() const {
    if( !getData() ) {
        context()->throwError( "No internal data to operate on!" );
        return 0;
    }

    return getData()->unicode();
}

uint JSQChar::unicodeVersion() const {
    if( !getData() ) {
        context()->throwError( "No internal data to operate on!" );
        return 0;
    }

    return getData()->unicodeVersion();
}


/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
