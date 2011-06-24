//---------------------------------------------------------------------------------------
/*!
    \file scriptexception.h
    \brief
*/

//---------------------------------------------------------------------------------------
#ifndef __TOOLKIT_SCRIPT_SCRIPTEXCEPTION_H__
#define __TOOLKIT_SCRIPT_SCRIPTEXCEPTION_H__

// Include Toolkit Script Files
#include "defines.h"

// Include Toolkit Core Files
#include <toolkit/core/exception.h>

// Include Qt Files
#include <QScriptValue>

//---------------------------------------------------------------------------------------
namespace Toolkit {

    namespace Script {
        //---------------------------------------------------------------------------------------
        /*!
            \ingroup grp_Exceptions
        */
        class TOOLKIT_SCRIPT_API ScriptException : public Toolkit::Core::Exception {
        public:
            //!\name Constructors & Destructor
            //@{
            ScriptException( const QScriptValue& scriptExp );
            ScriptException( const ScriptException& other );
            virtual ~ScriptException();
            //@}

            //!\name Operators
            //@{
            ScriptException& operator=( const ScriptException& other );
            //@}

        private:
            QScriptValue m_Exception;
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
