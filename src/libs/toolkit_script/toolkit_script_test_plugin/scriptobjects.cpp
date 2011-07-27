//-------------------------------------------------------------------------
/*!
    \file scriptobjects.cpp
    \brief
*/

//-------------------------------------------------------------------------

// Include Header File
#include "scriptobjects.h"

// Include Toolkit Core Files
#include <toolkit/core/log.h>

//-------------------------------------------------------------------------
using namespace Toolkit::Core;

//-------------------------------------------------------------------------
QScriptValue QtScriptFunctions::arg( QScriptContext* ctx, QScriptEngine* ) {
    if( ctx->argumentCount() > 1 ) {
        return ctx->throwError( "Wrong number of arguments. Zero or one is expected." );
    };

    return ctx->argument( 0 );
};

//-------------------------------------------------------------------------
QScriptValue QtScriptObject::constructor( QScriptContext* ctx, QScriptEngine* eng ) {
    if( ctx->argumentCount() != 0 ) {
        throw Exception( SOURCELINE, "Wrong number of arguments. No arguments expected!" );
        //return ctx->throwError( "Wrong number of arguments. No arguments expected!" );
    };

    if( !ctx->isCalledAsConstructor() ) {
        throw Exception( SOURCELINE, "QtScriptObject must be called as a constructor with the new operand." );
        //return ctx->throwError( "QtScriptObject must be called as a constructor with the new operand." );
    };

    return eng->newQObject( ctx->thisObject(), new QtScriptObject(), QScriptEngine::ScriptOwnership );
};

QtScriptObject::QtScriptObject() :
    QObject(),
    m_Name(),
    m_Number( 0 )
{
};

QtScriptObject::~QtScriptObject() {
};

const QString& QtScriptObject::getName() const {
    return m_Name;
};

void QtScriptObject::setName( const QString& newName ) {
    Log log( Log::LT_TRACE, "void QtScriptObject::setName( const QString& newName )" );
    log.write( Log::LT_TRACE, "newName = %s", newName );

    m_Name = newName;
};

QString QtScriptObject::toString() const {
    return m_Name;
};

int QtScriptObject::getNumber() const {
    return m_Number;
};

void QtScriptObject::setNumber( int newNumber ) {
    m_Number = newNumber;
};

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
