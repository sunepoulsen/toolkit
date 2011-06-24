//---------------------------------------------------------------------------------------
/*!
    \file abstractregistrationobject.h
    \brief
*/

//---------------------------------------------------------------------------------------
#ifndef __TOOLKIT_SCRIPT_ABSTRACTREGISTRATIONOBJECT_H__
#define __TOOLKIT_SCRIPT_ABSTRACTREGISTRATIONOBJECT_H__

// Include Toolkit Script Files
#include "defines.h"

// Include Qt Files
#include <QScriptValue>
#include <QSharedPointer>

//---------------------------------------------------------------------------------------
namespace Toolkit {

    namespace Script {
        //---------------------------------------------------------------------------------------
        class Environment;

        //---------------------------------------------------------------------------------------
        /*!
            \ingroup grp_Script
            \brief
        */
        class TOOLKIT_SCRIPT_API AbstractRegistrationObject {
        public:
            typedef QSharedPointer<AbstractRegistrationObject> Pointer;

        public:
            //!\name Constructors & Destructor
            //@{
            AbstractRegistrationObject( const QString& name = QString() );
            AbstractRegistrationObject( const AbstractRegistrationObject& other );
            virtual ~AbstractRegistrationObject();
            //@}

            //!\name Properties
            //@{
            const QString& getObjectName() const;
            void setObjectName( const QString& newObjectName );
            //@}

            //!\name Registration
            //@{
            QScriptValue registerObject( QScriptValue thisObj, Environment* eng ) const;
            //@}

            //!\name Operators
            //@{
            AbstractRegistrationObject& operator=( const AbstractRegistrationObject& other );
            //@}

        private:
            //!\name Registration
            //@{
            virtual QScriptValue doRegisterObject( QScriptValue thisObj, Environment* eng ) const = 0;
            //@}

        private:
            //!\name Properties
            //@{
            QString m_ObjectName;
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
