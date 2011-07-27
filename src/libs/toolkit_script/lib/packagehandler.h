//---------------------------------------------------------------------------------------
/*!
    \file packagehandler.h
    \brief
*/

//---------------------------------------------------------------------------------------
#ifndef __TOOLKIT_SCRIPT_PACKAGEHANDLER_H__
#define __TOOLKIT_SCRIPT_PACKAGEHANDLER_H__

// Include Toolkit Script Files
#include "abstractpackage.h"

// Include Std Files
#include <vector>

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
        class TOOLKIT_SCRIPT_API PackageHandler : public QObject {
        public:
            typedef std::vector<AbstractPackage::Pointer> container_type;
            typedef container_type::iterator iterator;
            typedef container_type::const_iterator const_iterator;
            typedef container_type::value_type value_type;
            typedef container_type::size_type size_type;

            //!\name Script constants
            //@{
            static const QString IMPORT_FUNCNAME;
            static const QString SETUP_NAMESPACE_FUNCNAME;
            //@}

        public:
            //!\name Constructors & Destructor
            //@{
            PackageHandler();
            PackageHandler( const PackageHandler& other );
            virtual ~PackageHandler();
            //@}

            //!\name Packages
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

            //!\name Package interface
            //@{
            bool checkPackage( const QUrl& packageName ) const;
            bool importPackage( const QUrl& packageName, QScriptContext* ctx, Environment* eng ) const;
            //@}

            //!\name Operators
            //@{
            PackageHandler& operator=( const PackageHandler& other );
            //@}

        private:
            //!\name Package interface
            //@{
            virtual bool doCheckPackage( const QUrl& packageName ) const;
            virtual bool doImportPackage( const QUrl& packageName, QScriptContext* ctx, Environment* eng ) const;
            //@}

        public:
            //!\name JavaScript interface
            //@{
            static QScriptValue jsImport( QScriptContext* ctx, QScriptEngine* eng );
            static QScriptValue jsSetupNameSpace( QScriptContext* ctx, QScriptEngine* eng );
            QScriptValue registerFunctions( Environment* eng );
            //@}

        private:
            container_type m_Packages;
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
