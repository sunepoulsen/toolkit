//---------------------------------------------------------------------------------------
/*!
    \file corepackage.h
    \brief
*/

//---------------------------------------------------------------------------------------
#ifndef __TOOLKIT_SCRIPT_COREPACKAGE_H__
#define __TOOLKIT_SCRIPT_COREPACKAGE_H__

// Include Toolkit Script Files
#include "abstractpackage.h"
#include "abstractregistrationobject.h"

// Include Qt Files
#include <QScriptValue>

// Include STD Files
#include <vector>

//---------------------------------------------------------------------------------------
namespace Toolkit {

    namespace Script {
        //---------------------------------------------------------------------------------------
        /*!
            \ingroup grp_Script
            \brief
        */
        class TOOLKIT_SCRIPT_API CorePackage : public AbstractPackage {
        public:
            typedef std::vector<AbstractRegistrationObject::Pointer> container_type;
            typedef container_type::iterator iterator;
            typedef container_type::const_iterator const_iterator;
            typedef container_type::value_type value_type;
            typedef container_type::size_type size_type;            

        public:
            //!\name Constructors & Destructor
            //@{
            CorePackage( const QString& ns = QString() );
            CorePackage( const CorePackage& other );
            virtual ~CorePackage();
            //@}

            //!\name Properties
            //@{
            const QString& getSchemeName() const;
            void setSchemeName( const QString& newSchemeName );
            const QString& getNameSpace() const;
            void setNameSpace( const QString& newNameSpace );
            //@}

            //!\name Items
            //@{
            iterator begin();
            const_iterator begin() const;
            iterator end();
            const_iterator end() const;
            void clear();
            bool empty() const;
            void push_back( const value_type& v );
            size_type size() const;
            //@}

            //!\name Operators
            //@{
            CorePackage& operator=( const CorePackage& other );
            //@}

        private:
            //!\name Package interface
            //@{
            virtual bool doCheckPackage( const QUrl& packageName ) const;
            virtual url_container doExtractPackageNames( const QUrl& packageName ) const;
            virtual void doLoadPackage( const QUrl& packageName, QScriptContext* ctx, Environment* eng ) const;
            //@}

            //!\name Helpers
            //@{
            QString fullPackageName( const_iterator it ) const;
            //@}

        private:
            QString m_SchemeName;
            QString m_NameSpace;
            container_type m_Items;
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
