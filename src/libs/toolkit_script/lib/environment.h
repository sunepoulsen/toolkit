//---------------------------------------------------------------------------------------
/*!
    \file environment.h
    \brief
*/

//---------------------------------------------------------------------------------------
#ifndef __TOOLKIT_SCRIPT_ENVIRONMENT_H__
#define __TOOLKIT_SCRIPT_ENVIRONMENT_H__

// Include Toolkit Script Files
#include "defines.h"
#include "environmentoptions.h"

// Include Toolkit Core Files
#include <toolkit/core/throwable.h>

// Include Qt Files
#include <QScriptEngine>
#include <QStringList>

//---------------------------------------------------------------------------------------
namespace Toolkit {

    namespace Script {
        //---------------------------------------------------------------------------------------
        /*!
            \ingroup grp_Script
            \brief
        */
        class TOOLKIT_SCRIPT_API Environment : public QScriptEngine {
        public:
            static const QString PROTOTYPE_PROPERTY_NAME;

        public:
            //!\name Constructors & Destructor
            //@{
            Environment();
            virtual ~Environment();
            //@}

            //!\name Script properties
            //@{
            const EnvironmentOptions& getOptions() const;
            EnvironmentOptions& getOptions();
            void setOptions( const EnvironmentOptions& newOptions );
            //@}

            //!\name Evaluation
            //@{
            QScriptValue evaluate( const QString& script, const QString& scriptName = QString(), int lineNumber = 1 );
            QScriptValue evaluateScript( const QByteArray& script, const QString& scriptName, const QTextCodec* codec = NULL, int lineNumber = 1 );
            QScriptValue evaluateScript( QIODevice& script, const QString& scriptName, const QTextCodec* codec = NULL, int lineNumber = 1 );
            //@}

            //!\name Functions
            //@{
            QScriptValue callFunction( const QString& funcName, const QScriptValueList& args );
            QScriptValue callFunction( const QScriptValue& thisObj, const QString& funcName, const QScriptValueList& args );
            QScriptValue callFunction( const QString& funcName,
                                       const QScriptValue& arg1 = QScriptValue(), const QScriptValue& arg2 = QScriptValue(),
                                       const QScriptValue& arg3 = QScriptValue(), const QScriptValue& arg4 = QScriptValue(),
                                       const QScriptValue& arg5 = QScriptValue(), const QScriptValue& arg6 = QScriptValue(),
                                       const QScriptValue& arg7 = QScriptValue(), const QScriptValue& arg8 = QScriptValue(),
                                       const QScriptValue& arg9 = QScriptValue(), const QScriptValue& arg10 = QScriptValue() );
            QScriptValue callFunction( const QScriptValue& thisObj, const QString& funcName,
                                       const QScriptValue& arg1 = QScriptValue(), const QScriptValue& arg2 = QScriptValue(),
                                       const QScriptValue& arg3 = QScriptValue(), const QScriptValue& arg4 = QScriptValue(),
                                       const QScriptValue& arg5 = QScriptValue(), const QScriptValue& arg6 = QScriptValue(),
                                       const QScriptValue& arg7 = QScriptValue(), const QScriptValue& arg8 = QScriptValue(),
                                       const QScriptValue& arg9 = QScriptValue(), const QScriptValue& arg10 = QScriptValue() );
            //@}

            //!\name Registrations
            //@{
            QScriptValue registerFunction( const QString& funcName, QScriptEngine::FunctionSignature func,
                                           const QScriptValue::PropertyFlags& flags = QScriptValue::KeepExistingFlags );
            QScriptValue registerFunction( QScriptValue thisObj, const QString& funcName, QScriptEngine::FunctionSignature func,
                                           const QScriptValue::PropertyFlags& flags = QScriptValue::KeepExistingFlags );

            template< typename QObjectT >
            QScriptValue registerClass( const QString& className ) {
                return registerClass<QObjectT>( globalObject(), className );
            };
            template< typename QObjectT >
            QScriptValue registerClass( QScriptValue thisObj, const QString& className ) {
                return registerClass( thisObj, className, &QObjectT::staticMetaObject, QObjectT::constructor );
            };

            QScriptValue registerClass( const QString& className, const QMetaObject* metaObject, QScriptEngine::FunctionSignature func );
            QScriptValue registerClass( QScriptValue thisObj, const QString& className, const QMetaObject* metaObject, QScriptEngine::FunctionSignature func );
            //@}

            //!\name Helpers
            //@{
            QByteArray codecName( const QTextCodec* codec ) const;
            //@}

        private:
            static QScriptValue EngineFunc( QScriptContext* ctx, QScriptEngine* eng, void* arg );

        private:
            //!\name Script properties
            //@{
            EnvironmentOptions m_Options;
            QStringList m_ScriptCache;
            //@}
        };

    };

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
