//---------------------------------------------------------------------------------------
/*!
    \file abstractresourcehandler.h
    \brief
*/

//---------------------------------------------------------------------------------------
#ifndef __TOOLKIT_RESOURCE_ABSTRACTRESOURCEHANDLER_H__
#define __TOOLKIT_RESOURCE_ABSTRACTRESOURCEHANDLER_H__

// Include Toolkit Resource Files
#include "defines.h"
#include "resourcebundle.h"

// Include Qt Files
#include <QLocale>

//---------------------------------------------------------------------------------------
namespace Toolkit {

    namespace Resource {
        //---------------------------------------------------------------------------------------
        /*!
            \ingroup grp_Resources
            \brief Abstract interface to read and write resources.

            This class declares the interface to read and write resources from a given source. The source
            can be IO devices, SQL-connections, etc.

            \par Responsabilities

            # Read resource from source.
            # Write resource to source.
            # Check if a given resource is supported by this handler.
        */
        class TOOLKIT_RESOURCE_API AbstractResourceHandler {
        public:
            //!\name Constructors & Destructor
            //@{
            AbstractResourceHandler( const QLocale& locale );
            AbstractResourceHandler( const AbstractResourceHandler& other );
            virtual ~AbstractResourceHandler();
            //@}

            //!\name Properties
            //@{
            const QLocale& getLocale() const;
            void setLocale( const QLocale& newLocale );
            //@}

            //!\name Bundles
            //@{
            ResourceBundle readBundle( const QString& id, const QString& rootPath = QString::null );
            void writeBundle( const ResourceBundle& bundle, const QString& rootPath = QString::null );
            //@}

            //!\name Operators
            //@{
            AbstractResourceHandler& operator=( const AbstractResourceHandler& other );
            //@}

        private:
            //!\name Bundles
            //@{
            virtual ResourceBundle doReadBundle( const QString& id, const QString& rootPath = QString::null ) = 0;
            virtual void doWriteBundle( const ResourceBundle& bundle, const QString& rootPath = QString::null ) = 0;
            //@}

        private:
            //!\name Properties
            //@{
            QLocale m_Locale;
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
