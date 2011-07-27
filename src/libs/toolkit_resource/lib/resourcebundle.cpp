//---------------------------------------------------------------------------------------
/*!
    \file resourcebundle.cpp
    \brief
*/

//---------------------------------------------------------------------------------------

// Include Header File
#include "resourcebundle.h"

// Include Qt Files
#include <QMenuBar>
#include <QStringList>

//---------------------------------------------------------------------------------------
using namespace Toolkit::Resource;

//---------------------------------------------------------------------------------------
const QString ResourceBundle::PATH_SEP( "::" );

//---------------------------------------------------------------------------------------
ResourceBundle::ResourceBundle( const QString& id ) :
    m_Id( id ),
    m_Resources( new GroupResource() )
{
};

ResourceBundle::ResourceBundle( const ResourceBundle& other ) :
    m_Id( other.m_Id ),
    m_Resources( other.m_Resources )
{
};

ResourceBundle::~ResourceBundle() {
};

const QString& ResourceBundle::getId() const {
    return m_Id;
};

void ResourceBundle::setId( const QString& newId ) {
    m_Id = newId;
};

const GroupResource::Pointer& ResourceBundle::getResources() const {
    return m_Resources;
};

void ResourceBundle::setResources( GroupResource::Pointer& newResources ) {
    m_Resources = newResources;
};

QString ResourceBundle::getString( const QString& keyPath, const QString& defValue ) const {
    const AbstractResource::Pointer res = findResource( keyPath );
    if( res ) {
        return res->toString();
    };

    return defValue;
};

QMenu* ResourceBundle::getMenu( const QString& ) const {
    return NULL;
};

QMenuBar* ResourceBundle::getMenuBar( const QString& ) const {
    return NULL;
};

const AbstractResource::Pointer ResourceBundle::findResource( const QString& keyPath ) const {
    return findResource( m_Resources, keyPath );
};

const AbstractResource::Pointer ResourceBundle::findResource( const GroupResource::Pointer& root, const QString& keyPath ) const {
    return findResource( root, keyPath.split( PATH_SEP ) );
};

const AbstractResource::Pointer ResourceBundle::findResource( const GroupResource::Pointer& root, const QStringList& keyPath, int index ) const {
    if( index >= keyPath.size() ) {
        return AbstractResource::Pointer();
    };    

    if( !root || root->empty() ) {
        return AbstractResource::Pointer();
    };

    for( GroupResource::const_iterator it = root->begin(); it != root->end(); ++it ) {
        if( (*it) && (*it)->getKey() == keyPath[ index ] ) {
            if( index == keyPath.size() - 1 ) {
                return *it;
            }
            else if( it->dynamicCast<GroupResource>() ) {
                return findResource( it->dynamicCast<GroupResource>(), keyPath, index + 1 );
            };
        };
    };

    return AbstractResource::Pointer();
};

ResourceBundle& ResourceBundle::operator=( const ResourceBundle& other ) {
    m_Resources = other.m_Resources;

    return *this;
};

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */

