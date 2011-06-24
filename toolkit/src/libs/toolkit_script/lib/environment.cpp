//---------------------------------------------------------------------------------------
/*!
    \file environment.h
    \brief
*/

//---------------------------------------------------------------------------------------

// Include Header File
#include "environment.h"

// Include Toolkit Script Files
#include "corepackage.h"
#include "scriptexception.h"

// Include Toolkit Core Files
#include <toolkit/core/log.h>

// Include Qt Files
#include <QTextStream>

//---------------------------------------------------------------------------------------
using namespace Toolkit::Core;
using namespace Toolkit::Script;

//---------------------------------------------------------------------------------------
const QString Environment::PROTOTYPE_PROPERTY_NAME( "prototype" );

//---------------------------------------------------------------------------------------
Environment::Environment() :
    QScriptEngine(),
    m_Options(),
    m_ScriptCache()
{
};

Environment::~Environment() {
};

const EnvironmentOptions& Environment::getOptions() const {
    return m_Options;
};

EnvironmentOptions& Environment::getOptions() {
    return m_Options;
};

void Environment::setOptions( const EnvironmentOptions& newOptions ) {
    m_Options = newOptions;
};

/*!
    \brief Evaluates the script in \e script.

    \e scriptName is the name of the script. For instance the file name of the file containing the script. If a script
    with the same script name has been evaluated then this script *is not* evaluated. In this case we return an invalid
    QScriptValue.

    \param script     The script to evaluate.
    \param scriptName The name of the script.
    \param lineNumber The base line number of the script. Used to report evaluation and execution errors.

    \exception ScriptException Throwed in case of syntax or evaluation errors in the script.
*/
QScriptValue Environment::evaluate( const QString& script, const QString& scriptName, int lineNumber ) {
    if( !scriptName.isEmpty() && m_ScriptCache.contains( scriptName ) ) {
        return QScriptValue();
    };

    QScriptValue res = QScriptEngine::evaluate( script, scriptName, lineNumber );
    if( hasUncaughtException() ) {
        QString s = uncaughtException().toString();
        if( !scriptName.isEmpty() ) {
            s = StringFormat::format( "%s:%i: %s", scriptName, uncaughtExceptionLineNumber(), uncaughtException().toString() );
        };

        throw ScriptException( s );
    };

    return res;
};

QScriptValue Environment::evaluateScript( const QByteArray& script, const QString& scriptName, const QTextCodec* codec, int lineNumber ) {
    QTextStream stream( script );
    stream.setCodec( codecName( codec ) );

    return evaluate( stream.readAll(), scriptName, lineNumber );
};

QScriptValue Environment::evaluateScript( QIODevice& script, const QString& scriptName, const QTextCodec* codec, int lineNumber ) {
    bool doCloseDevice = !script.isOpen();

    if( !script.isOpen() && !script.open( QIODevice::ReadOnly ) ) {
        return QScriptValue();
    };

    QTextStream stream( &script );
    stream.setCodec( codecName( codec ) );

    QScriptValue res = evaluate( stream.readAll(), scriptName, lineNumber );        
    if( doCloseDevice ) {
        script.close();
    };

    return res;
};

QScriptValue Environment::callFunction( const QString& funcName, const QScriptValueList& args ) {
    return callFunction( globalObject(), funcName, args );
};

QScriptValue Environment::callFunction( const QScriptValue& thisObj, const QString& funcName, const QScriptValueList& args ) {
    Log log( Log::LT_TRACE, Log::MOD_MAIN, "QScriptValue Environment::callFunction( const QScriptValue& thisObj, const QString& funcName, const QScriptValueList& args )" );
    log.write( Log::LT_TRACE, "thisObj: %s", thisObj.toString() );
    log.write( Log::LT_TRACE, "funcName: %s", funcName );

    if( m_Options.getLocalContext() ) {
        log.write( Log::LT_DEBUG, "Push new context" );
        pushContext();
    };

    QScriptValue funcObj = thisObj.property( funcName );
    if( !funcObj.isFunction() ) {
        log.write( Log::LT_TRACE, "The thisObj.property['%s'] is not a function!", funcName );
        log.write( Log::LT_TRACE, "thisObj.property['%s']: %s", funcName, funcObj.toString() );
        return QScriptValue();
    };

    QScriptValue res = funcObj.call( thisObj, args );
    log.write( Log::LT_TRACE, "Script returned: %s", res.toString() );

    QScriptValue scriptExp;
    if( hasUncaughtException() ) {
        log.write( Log::LT_ERROR, "Uncaught exception: %s", uncaughtException().toString() );
        scriptExp = uncaughtException();
    };

    if( m_Options.getLocalContext() ) {
        log.write( Log::LT_DEBUG, "Pop old context" );
        popContext();
    };

    if( scriptExp.isValid() ) {
        log.write( Log::LT_ERROR, "Throw exception!" );
        throw ScriptException( scriptExp );
    };

    return res;
};

QScriptValue Environment::callFunction( const QString& funcName,
                                        const QScriptValue& arg1, const QScriptValue& arg2, const QScriptValue& arg3,
                                        const QScriptValue& arg4, const QScriptValue& arg5, const QScriptValue& arg6,
                                        const QScriptValue& arg7, const QScriptValue& arg8, const QScriptValue& arg9, const QScriptValue& arg10 )
{
    return callFunction( globalObject(), funcName, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10 );
};

QScriptValue Environment::callFunction( const QScriptValue& thisObj, const QString& funcName,
                                        const QScriptValue& arg1, const QScriptValue& arg2, const QScriptValue& arg3,
                                        const QScriptValue& arg4, const QScriptValue& arg5, const QScriptValue& arg6,
                                        const QScriptValue& arg7, const QScriptValue& arg8, const QScriptValue& arg9, const QScriptValue& arg10 )
{
    QScriptValueList args;

    if( arg1.isValid() ) {
        args << arg1;
    };
    if( arg2.isValid() ) {
        args << arg2;
    };
    if( arg3.isValid() ) {
        args << arg3;
    };
    if( arg4.isValid() ) {
        args << arg4;
    };
    if( arg5.isValid() ) {
        args << arg5;
    };
    if( arg6.isValid() ) {
        args << arg6;
    };
    if( arg7.isValid() ) {
        args << arg7;
    };
    if( arg8.isValid() ) {
        args << arg8;
    };
    if( arg9.isValid() ) {
        args << arg9;
    };
    if( arg10.isValid() ) {
        args << arg10;
    };

    return callFunction( thisObj, funcName, args );
};

/*!
    \brief Registers a new function on the global object in the engine.

    \param funcName The name of the new function.
    \param func     The function to execute.
    \param flags    Property flags to assign the new function.

    \return
        The script object of the new function. On errors an invalid QScriptValue is returned.
*/
QScriptValue Environment::registerFunction( const QString& funcName, QScriptEngine::FunctionSignature func, const QScriptValue::PropertyFlags& flags ) {
    return registerFunction( globalObject(), funcName, func, flags );
};

/*!
    \brief Registers a new function on an object in the engine.

    \param thisObj  The object in the engine to register the new function on.
    \param funcName The name of the new function.
    \param func     The function to execute.
    \param flags    Property flags to assign the new function.

    \return
        The script object of the new function. On errors an invalid QScriptValue is returned.
*/
QScriptValue Environment::registerFunction( QScriptValue thisObj, const QString& funcName,
                                            QScriptEngine::FunctionSignature func, const QScriptValue::PropertyFlags& flags )
{
    if( !thisObj.isValid() ) {
        return QScriptValue();
    };

    QScriptValue funcObj = newFunction( EngineFunc, (void*)( func ) );
    thisObj.setProperty( funcName, funcObj, flags );

    return funcObj;
};

/*!
    \brief Registers a new "class" in the engine on the global object.

    \param className  The name of the new "class".
    \param metaObject The QMetaObject of the QObject class to register class methods in the engine.
    \param func       The constructor function to create new instances of the "class".

    \return
        The script object of the new "class" (that is the created metaObject in the engine). On errors an invalid QScriptValue is returned.
*/
QScriptValue Environment::registerClass( const QString& className, const QMetaObject* metaObject, QScriptEngine::FunctionSignature func ) {
    return registerClass( globalObject(), className, metaObject, func );
};

/*!
    \brief Registers a new "class" in the engine.

    \param thisObj    The object in the engine to register the new "class" on.
    \param className  The name of the new "class".
    \param metaObject The QMetaObject of the QObject class to register class methods in the engine.
    \param func       The constructor function to create new instances of the "class".

    \return
        The script object of the new "class" (that is the created metaObject in the engine). On errors an invalid QScriptValue is returned.
*/
QScriptValue Environment::registerClass( QScriptValue thisObj, const QString& className,
                                         const QMetaObject* metaObject, QScriptEngine::FunctionSignature func )
{
    if( !thisObj.isValid() ) {
        return QScriptValue();
    };

    if( !metaObject ) {
        return QScriptValue();
    };

    QScriptValue conFunc = newFunction( EngineFunc, (void*)( func ) );
    QScriptValue metaObj = newQMetaObject( metaObject, conFunc );
    thisObj.setProperty( className, metaObj );

    return metaObj;
};

/*!
    \brief Returns the name of a QTextCodec.

    If \e codec is NULL, when the name of the options codec (from getOptions()) is returned.

    This function is used by evaluateScript() to load the script with the right codec.

    \param codec The codec to use.

    \return
        The name of the used codec.
*/
QByteArray Environment::codecName( const QTextCodec* codec ) const {
    if( codec ) {
        return codec->name();
    };

    return m_Options.getCodec().name();
};

QScriptValue Environment::EngineFunc( QScriptContext* ctx, QScriptEngine* eng, void* arg ) {
    try {
        QScriptEngine::FunctionSignature func = (QScriptEngine::FunctionSignature)( arg );
        return func( ctx, eng );
    }
    catch( Toolkit::Core::Throwable& e ) {
        return ctx->throwError( e.getMessage() );
    };
}

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
