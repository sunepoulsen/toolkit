//---------------------------------------------------------------------------------------
/*!
    \file jsstring.h
    \brief
*/

//---------------------------------------------------------------------------------------
#ifndef __TOOLKIT_SCRIPT_JSSTRING_H__
#define __TOOLKIT_SCRIPT_JSSTRING_H__

// Include Toolkit Script Files
#include "defines.h"

#include "scriptobject.h"

// Include Qt Files
#include <QObject>
#include <QScriptable>

//---------------------------------------------------------------------------------------
namespace Toolkit {

    namespace Script {
        //---------------------------------------------------------------------------------------
        /*!
            \ingroup grp_ScriptApi
            \brief
        */
        class TOOLKIT_SCRIPT_API JSString {
        public:
            //!\name Statis String methods
            //@{
            static QScriptValue format( QScriptContext* ctx, QScriptEngine* eng );
            //@}

            //!\name String prototype methods
            //@{
            static QScriptValue toInt( QScriptContext* ctx, QScriptEngine* eng );
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
