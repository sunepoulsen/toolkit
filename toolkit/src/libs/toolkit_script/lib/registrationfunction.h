//---------------------------------------------------------------------------------------
/*!
    \file registrationfunction.h
    \brief
*/

//---------------------------------------------------------------------------------------
#ifndef __TOOLKIT_SCRIPT_REGISTRATIONFUNCTION_H__
#define __TOOLKIT_SCRIPT_REGISTRATIONFUNCTION_H__

// Include Toolkit Script Files
#include "abstractregistrationobject.h"

// Include Qt Files
#include <QScriptEngine>

//---------------------------------------------------------------------------------------
namespace Toolkit {

    namespace Script {
        //---------------------------------------------------------------------------------------
        /*!
            \ingroup grp_Script
            \brief Implements a registration object to registrate a script function in a script engine.
        */
        class TOOLKIT_SCRIPT_API RegistrationFunction : public AbstractRegistrationObject {
        public:
            //!\name Constructors & Destructor
            //@{
            RegistrationFunction( const QString& name = QString(),
                                  QScriptEngine::FunctionSignature func = NULL,
                                  const QScriptValue::PropertyFlags& flags = QScriptValue::KeepExistingFlags );
            RegistrationFunction( const RegistrationFunction& other );
            virtual ~RegistrationFunction();
            //@}

            //!\name Properties
            //@{
            QScriptEngine::FunctionSignature getFunction() const;
            void setFunction( QScriptEngine::FunctionSignature newFunction );
            QScriptValue::PropertyFlags getFlags() const;
            void setFlags( QScriptValue::PropertyFlags newFlags );
            //@}

            //!\name Operators
            //@{
            RegistrationFunction& operator=( const RegistrationFunction& other );
            //@}

        private:
            //!\name Registration
            //@{
            virtual QScriptValue doRegisterObject( QScriptValue thisObj, Environment* eng ) const;
            //@}

        private:
            //!\name Properties
            //@{
            QScriptEngine::FunctionSignature m_Function;
            QScriptValue::PropertyFlags m_Flags;
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
