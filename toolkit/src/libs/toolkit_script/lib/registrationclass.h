//---------------------------------------------------------------------------------------
/*!
    \file registrationclass.h
    \brief
*/

//---------------------------------------------------------------------------------------
#ifndef __TOOLKIT_SCRIPT_REGISTRATIONCLASS_H__
#define __TOOLKIT_SCRIPT_REGISTRATIONCLASS_H__

// Include Toolkit Script Files
#include "registrationfunction.h"

// Include STD Files
#include <map>
#include <vector>

//---------------------------------------------------------------------------------------
namespace Toolkit {

    namespace Script {
        //---------------------------------------------------------------------------------------
        /*!
            \ingroup grp_Script
            \brief Implements a registration object to registrate a script "class" in a script engine.
        */
        class TOOLKIT_SCRIPT_API RegistrationClass : public AbstractRegistrationObject {
        public:
            typedef std::vector<RegistrationFunction> functions_type;
            typedef std::map<QString, QScriptValue> properties_type;

        public:
            static const QString NAMESPACE_SEP;

        public:
            //!\name Constructors & Destructor
            //@{
            RegistrationClass( const QString& name = QString() );
            RegistrationClass( const RegistrationClass& other );
            virtual ~RegistrationClass();
            //@}

            //!\name Properties
            //@{
            QScriptEngine::FunctionSignature getConstructor() const;
            void setConstructor( QScriptEngine::FunctionSignature newConstructor );
            const QMetaObject* getMetaObject() const;
            void setMetaObject( const QMetaObject* metaObject );
            //@}

            //!\name Static contents
            //@{
            functions_type& getDynamicFunctions();
            const functions_type& getDynamicFunctions() const;
            void setDynamicFunctions( const functions_type& newDynamicFunctions );
            properties_type& getStaticProperties();
            const properties_type& getStaticProperties() const;
            void setStaticProperties( const properties_type& newStaticProperties );
            functions_type& getStaticFunctions();
            const functions_type& getStaticFunctions() const;
            void setStaticFunctions( const functions_type& newStaticFunctions );
            //@}

            //!\name QObject interface
            //@{
            template< typename QObjectT >
            void setClass( const QString& className = QString() ) {
                m_Constructor = QObjectT::constructor;
                m_MetaObject = &QObjectT::staticMetaObject;

                if( className.isEmpty() && m_MetaObject ) {
                    setObjectName( toClassName( m_MetaObject->className() ) );
                }
                else {
                    setObjectName( className );
                };
            };

            template< typename QObjectT >
            static RegistrationClass* newClass( const QString& className = QString() ) {
                RegistrationClass* result = new RegistrationClass( className );
                result->setClass< QObjectT >( className );

                return result;
            };
            //@}

            //!\name Operators
            //@{
            RegistrationClass& operator=( const RegistrationClass& other );
            //@}

        public:
            //!\name Helpers
            //@{
            static QString toClassName( const QString& className );
            //@}

            //!\name Registration
            //@{
            virtual QScriptValue doRegisterObject( QScriptValue thisObj, Environment* eng ) const;
            //@}

        private:
            //!\name Helpers
            //@{
            bool registerFunctions( const functions_type& funcs, QScriptValue thisObj, Environment* eng ) const;
            //@}

        private:
            //!\name Properties
            //@{
            QScriptEngine::FunctionSignature m_Constructor;
            const QMetaObject* m_MetaObject;
            //@}

            //!\name Static contents
            //@{
            /*!
                \brief Vector of dynamic functions to be registered on the class object.

                This is mainly used for methods that is not registered on the m_MetaObject. For instance methods
                that takes a variabel number of arguments.
            */
            functions_type m_DynamicFunctions;

            /*!
                \brief Map of static properties to be registered on the class object.
            */
            properties_type m_StaticProperties;

            /*!
                \brief Vector of static functions to be registered on the class object.
            */
            functions_type m_StaticFunctions;
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
