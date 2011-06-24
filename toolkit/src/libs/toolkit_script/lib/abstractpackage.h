//---------------------------------------------------------------------------------------
/*!
    \file abstractpackage.h
    \brief
*/

//---------------------------------------------------------------------------------------
#ifndef __TOOLKIT_SCRIPT_ABSTRACTPACKAGE_H__
#define __TOOLKIT_SCRIPT_ABSTRACTPACKAGE_H__

// Include Toolkit Script Files
#include "defines.h"

// Include Qt Files
#include <QScriptEngine>
#include <QSharedPointer>
#include <QUrl>

// Include STD Files
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
        class TOOLKIT_SCRIPT_API AbstractPackage : public QObject {
        public:
            typedef QSharedPointer<AbstractPackage> Pointer;
            typedef std::vector<QUrl> url_container;

        public:
            //!\name Constructors & Destructor
            //@{
            AbstractPackage();
            AbstractPackage( const AbstractPackage& other );
            virtual ~AbstractPackage();
            //@}

            //!\name Package interface
            //@{
            bool checkPackage( const QUrl& packageName ) const;
            url_container extractPackageNames( const QUrl& packageName ) const;
            void loadPackage( const QUrl& packageName, QScriptContext* ctx, Environment* eng ) const;
            //@}

            //!\name Operators
            //@{
            AbstractPackage& operator=( const AbstractPackage& other );
            //@}

            //!\name Helper functions
            //@{
            static QScriptValue setupPackage( const QString& ns, QScriptValue baseObj );
            //@}

        private:
            //!\name Package interface
            //@{
            /*!
                \copydoc checkPackage
            */
            virtual bool doCheckPackage( const QUrl& packageName ) const = 0;

            /*!
                \copydoc extractPackageNames
            */
            virtual url_container doExtractPackageNames( const QUrl& packageName ) const = 0;

            /*!
                \copydoc loadPackage
            */
            virtual void doLoadPackage( const QUrl& packageName, QScriptContext* ctx, Environment* eng ) const = 0;
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
