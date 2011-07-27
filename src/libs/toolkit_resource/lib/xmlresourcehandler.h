//---------------------------------------------------------------------------------------
/*!
    \file xmlresourcehandler.h
    \brief
*/

//---------------------------------------------------------------------------------------
#ifndef __TOOLKIT_RESOURCE_XMLRESOURCEHANDLER_H__
#define __TOOLKIT_RESOURCE_XMLRESOURCEHANDLER_H__

// Include Toolkit Resource Files
#include "abstractresourcehandler.h"
#include "abstractresource.h"

// Include Qt Files
#include <QDir>
#include <QDomDocument>

//---------------------------------------------------------------------------------------
namespace Toolkit {

    namespace Resource {
        //---------------------------------------------------------------------------------------
        /*!
            \ingroup grp_Resources
            \brief Implements a resource handler to store resources in XML-files.
        */
        class TOOLKIT_RESOURCE_API XMLResourceHandler : public AbstractResourceHandler {
        public:
            typedef AbstractResource::Pointer res_type;

        public:
            //!\name Constants
            //@{
            static const QString FILENAME_PATTERN;
            static const QString LINK_PATTERN;
            //@}

            //!\name Tag names
            //@{
            static const QString GROUP_TAG;
            static const QString STRING_TAG;
            static const QString INT_TAG;
            static const QString HEX_TAG;
            static const QString FILE_TAG;
            static const QString COLOR_TAG;
            static const QString ICON_TAG;
            static const QString IMAGE_TAG;
            static const QString PIXMAP_TAG;
            //@}

            //!\name Attribute names
            //@{
            static const QString KEY_ATTR;
            static const QString VALUE_ATTR;
            //@}

        public:
            //!\name Constructors & Destructor
            //@{
            XMLResourceHandler( const QLocale& locale, const QString& root = QString() );
            XMLResourceHandler( const XMLResourceHandler& other );
            virtual ~XMLResourceHandler();
            //@}

            //!\name Operators
            //@{
            XMLResourceHandler& operator=( const XMLResourceHandler& other );
            //@}

        private:
            //!\name File Helpers
            //@{
            QString createFileName( const QString& id ) const;
            ResourceBundle loadFile( const QString& fileName ) const;
            ResourceBundle loadData( const QByteArray& bytes ) const;
            //@}

            //!\name XML Helpers
            //@{
            ResourceBundle loadDocument( QDomDocument doc ) const;
            res_type loadResource( const ResourceBundle& bundle, QDomNode node ) const;
            //@}

        private:
            //!\name Bundles
            //@{
            virtual ResourceBundle doReadBundle( const QString& id, const QString& rootPath = QString::null );
            virtual void doWriteBundle( const ResourceBundle& bundle, const QString& rootPath = QString::null );
            //@}

            //!\name Load Helpers
            //@{
            res_type loadGroup( const ResourceBundle& bundle, QDomElement elem ) const;
            res_type loadString( const ResourceBundle& bundle, QDomElement elem ) const;
            res_type loadNumber( const ResourceBundle& bundle, QDomElement elem, int base = 10 ) const;
            res_type loadFile( const ResourceBundle& bundle, QDomElement elem ) const;
            res_type loadColor( const ResourceBundle& bundle, QDomElement elem ) const;
            res_type loadIcon( const ResourceBundle& bundle, QDomElement elem ) const;
            res_type loadImage( const ResourceBundle& bundle, QDomElement elem ) const;
            res_type loadPixmap( const ResourceBundle& bundle, QDomElement elem ) const;
            //@}

        private:
            //!\name Properties
            //@{
            QString m_Root;
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
