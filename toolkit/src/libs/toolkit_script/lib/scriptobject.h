//---------------------------------------------------------------------------------------
/*!
    \file scriptobject.h
    \brief
*/

//---------------------------------------------------------------------------------------
#ifndef __TOOLKIT_SCRIPT_SCRIPTOBJECT_H__
#define __TOOLKIT_SCRIPT_SCRIPTOBJECT_H__

// Include Toolkit Script Files
#include "defines.h"

// Include Toolkit Core Files
#include <toolkit/core/exception.h>

// Include Qt Files
#include <QSharedPointer>

//---------------------------------------------------------------------------------------
namespace Toolkit {

    namespace Script {
        //---------------------------------------------------------------------------------------
        /*!
            \ingroup grp_Script
            \brief
        */
        template< typename T >
        class TOOLKIT_SCRIPT_API ScriptObject {
        public:
            enum ObjectOwnership {
                AppOwnership = 1,
                ScriptOwnership = 2
            };

        public:
            //!\name Constructors & Destructor
            //@{
            ScriptObject( T* data, ObjectOwnership ownership = ScriptOwnership, bool constObj = false );
            ScriptObject( const QSharedPointer<T>& data, bool constObj = false );
            virtual ~ScriptObject();
            //@}

            //!\name Properties
            //@{
            ObjectOwnership getOwnership() const {
                return m_Ownership;
            }

            void setOwnership( ObjectOwnership newOwnership );
            bool getConst() const;
            void setConst( bool newConst );
            //@}

            //!\name Data
            //@{
            const T* getConstData() const;
            const T* getData() const;
            T* getData( bool ignoreConst = false );
            void setData( T* newData, ObjectOwnership ownership = ScriptOwnership, bool ignoreConst = false );
            const QSharedPointer<T>& getConstSharedData() const;
            const QSharedPointer<T>& getSharedData() const;
            QSharedPointer<T>& getSharedData( bool ignoreConst = false );
            void setSharedData( const QSharedPointer<T>& newSharedData, bool ignoreConst = false );
            void setSharedData( T* newSharedData, bool ignoreConst = false );
            //@}

        private:
            //!\name Helpers
            //@{
            void detach();
            //@}

        private:
            //!\name Property members
            //@{
            ObjectOwnership m_Ownership;
            bool m_Const;
            //@}

            //!\name Data members
            //@{
            T* m_Data;
            QSharedPointer<T> m_SharedData;
            //@}
        };

        //---------------------------------------------------------------------------------------
        // Include implementation file of template functions.
        #include "scriptobject_imp.h"
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
