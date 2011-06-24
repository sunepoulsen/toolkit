//---------------------------------------------------------------------------------------
/*!
    \file xmlresourcehandler.cpp
    \brief
*/

//---------------------------------------------------------------------------------------

// Include Header File
#include "xmlresourcehandler.h"

// Include Toolkit Resource Files
#include "genericresource.h"

// Include Toolkit Core Files
#include <toolkit/core/stringformat.h>

// Include Qt Files
#include <QColor>
#include <QIcon>
#include <QImage>
#include <QPixmap>

//---------------------------------------------------------------------------------------
using namespace Toolkit::Core;
using namespace Toolkit::Resource;

//---------------------------------------------------------------------------------------
const QString XMLResourceHandler::FILENAME_PATTERN( "%s/%s_%s.xml" );
const QString XMLResourceHandler::GROUP_TAG( "group" );
const QString XMLResourceHandler::STRING_TAG( "string" );
const QString XMLResourceHandler::INT_TAG( "int" );
const QString XMLResourceHandler::HEX_TAG( "hex" );
const QString XMLResourceHandler::FILE_TAG( "file" );
const QString XMLResourceHandler::COLOR_TAG( "color" );
const QString XMLResourceHandler::ICON_TAG( "icon" );
const QString XMLResourceHandler::IMAGE_TAG( "image" );
const QString XMLResourceHandler::PIXMAP_TAG( "pixmap" );
const QString XMLResourceHandler::KEY_ATTR( "key" );
const QString XMLResourceHandler::VALUE_ATTR( "value" );

//---------------------------------------------------------------------------------------
XMLResourceHandler::XMLResourceHandler( const QLocale& locale, const QString& root ) :
    AbstractResourceHandler( locale ),
    m_Root( root )
{
};

XMLResourceHandler::XMLResourceHandler( const XMLResourceHandler& other ) :
    AbstractResourceHandler( other ),
    m_Root( other.m_Root )
{
};

XMLResourceHandler::~XMLResourceHandler() {
};

XMLResourceHandler& XMLResourceHandler::operator=( const XMLResourceHandler& other ) {
    AbstractResourceHandler::operator=( other );
    m_Root = other.m_Root;

    return *this;
};

QString XMLResourceHandler::createFileName( const QString& id ) const {
    return StringFormat::format( FILENAME_PATTERN, m_Root, id, getLocale().name() );
};

ResourceBundle XMLResourceHandler::loadFile( const QString& fileName ) const {
    ResourceBundle bundle;
    QFile file( fileName );

    if( file.open( QIODevice::ReadOnly ) ) {
        bundle = loadData( file.readAll() );
        file.close();
    }
    else {
        throw ResourceException( SOURCELINE, StringFormat::format( "Unable to open file %s", fileName ) );
    };

    return bundle;
};

ResourceBundle XMLResourceHandler::loadData( const QByteArray& bytes ) const {
    QDomDocument doc;

    QString errorMsg;
    int errorLine;
    int errorColumn;

    if( doc.setContent( bytes, false, &errorMsg, &errorLine, &errorColumn ) ) {
        return loadDocument( doc );
    };

    throw ResourceException( SOURCELINE, StringFormat::format( "Parse error in XML at %i:%i\n%s", errorLine, errorColumn, errorMsg ) );
};

ResourceBundle XMLResourceHandler::loadDocument( QDomDocument doc ) const {
    ResourceBundle bundle;

    for( int i = 0; i < doc.documentElement().childNodes().count(); i++ ) {
        QDomNode node = doc.documentElement().childNodes().item( i );

        if( node.isComment() ) {
            continue;
        }
        else if( node.isElement() ) {
            res_type v = loadResource( bundle, node );
            if( v ) {
                bundle.getResources()->push_back( v );
            };
        };
    };

    return bundle;
};

XMLResourceHandler::res_type XMLResourceHandler::loadResource( const ResourceBundle& bundle, QDomNode node ) const {
    if( !node.isElement() ) {
        return res_type();
    };

    QDomElement elem = node.toElement();
    if( elem.tagName() == GROUP_TAG ) {
        return loadGroup( bundle, elem );
    }
    else if( elem.tagName() == STRING_TAG ) {
        return loadString( bundle, elem );
    }
    else if( elem.tagName() == INT_TAG ) {
        return loadNumber( bundle, elem, 10 );
    }
    else if( elem.tagName() == HEX_TAG ) {
        return loadNumber( bundle, elem, 16 );
    }
    else if( elem.tagName() == FILE_TAG ) {
        return loadFile( bundle, elem );
    }
    else if( elem.tagName() == COLOR_TAG ) {
        return loadColor( bundle, elem );
    }
    else if( elem.tagName() == ICON_TAG ) {
        return loadIcon( bundle, elem );
    }
    else if( elem.tagName() == IMAGE_TAG ) {
        return loadImage( bundle, elem );
    }
    else if( elem.tagName() == PIXMAP_TAG ) {
        return loadPixmap( bundle, elem );
    }
    else {
        throw ResourceException( SOURCELINE, StringFormat::format( "Unknown tag %s at line %i", elem.tagName(), elem.lineNumber() ) );
    };
};

ResourceBundle XMLResourceHandler::doReadBundle( const QString& id, const QString& ) {
    return loadFile( createFileName( id ) );
};

void XMLResourceHandler::doWriteBundle( const ResourceBundle&, const QString& ) {
    throw ResourceException( SOURCELINE, "doWriteBundle is not implementated yet!" );
};

XMLResourceHandler::res_type XMLResourceHandler::loadGroup( const ResourceBundle& bundle, QDomElement elem ) const {
    GroupResource* group = new GroupResource( elem.attribute( KEY_ATTR ) );

    for( int i = 0; i < elem.childNodes().count(); i++ ) {
        res_type v = loadResource( bundle, elem.childNodes().item( i ) );
        if( v ) {
            group->push_back( v );
        };
    };

    return res_type( group );
}

XMLResourceHandler::res_type XMLResourceHandler::loadString( const ResourceBundle&, QDomElement elem ) const {
    return res_type( new GenericResource( elem.attribute( KEY_ATTR ), QVariant( elem.attribute( VALUE_ATTR ) ) ) );
}

XMLResourceHandler::res_type XMLResourceHandler::loadNumber( const ResourceBundle&, QDomElement elem, int base ) const {
    bool ok;
    int i = elem.attribute( VALUE_ATTR ).toInt( &ok, base );

    if( ok ) {
        return res_type( new GenericResource( elem.attribute( KEY_ATTR ), QVariant( i ) ) );
    };

    throw ResourceException( SOURCELINE, StringFormat::format( "%s from resource %s is not a number of base %i",
                                                               elem.attribute( VALUE_ATTR ), elem.attribute( KEY_ATTR ), base ) );
}

XMLResourceHandler::res_type XMLResourceHandler::loadFile( const ResourceBundle&, QDomElement elem ) const {
    QString fileName = elem.attribute( VALUE_ATTR );
    if( fileName.isEmpty() ) {
        throw ResourceException( SOURCELINE, "File resource has an empty name." );
    }

    QFile file( fileName );
    if( file.open( QIODevice::ReadOnly ) ) {
        res_type result = res_type( new GenericResource( elem.attribute( KEY_ATTR ), QVariant( file.readAll() ) ) );
        file.close();

        return result;
    }

    throw ResourceException( SOURCELINE, StringFormat::format( "Unable to load file resource %s", fileName ) );
}

XMLResourceHandler::res_type XMLResourceHandler::loadColor( const ResourceBundle&, QDomElement elem ) const {
    return res_type( new GenericResource( elem.attribute( KEY_ATTR ), QVariant( QColor( elem.attribute( VALUE_ATTR ) ) ) ) );
}

XMLResourceHandler::res_type XMLResourceHandler::loadIcon( const ResourceBundle&, QDomElement elem ) const {
    return res_type( new GenericResource( elem.attribute( KEY_ATTR ), QVariant( QIcon( elem.attribute( VALUE_ATTR ) ) ) ) );
}

XMLResourceHandler::res_type XMLResourceHandler::loadImage( const ResourceBundle&, QDomElement elem ) const {
    return res_type( new GenericResource( elem.attribute( KEY_ATTR ), QVariant( QImage( elem.attribute( VALUE_ATTR ) ) ) ) );
}

XMLResourceHandler::res_type XMLResourceHandler::loadPixmap( const ResourceBundle&, QDomElement elem ) const {
    return res_type( new GenericResource( elem.attribute( KEY_ATTR ), QVariant( QPixmap( elem.attribute( VALUE_ATTR ) ) ) ) );
}

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
