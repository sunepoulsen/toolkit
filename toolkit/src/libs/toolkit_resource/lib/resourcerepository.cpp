//---------------------------------------------------------------------------------------
/*!
    \file resourcerepository.cpp
    \brief
*/

//---------------------------------------------------------------------------------------

// Include Header File
#include "resourcerepository.h"

// Include Toolkit Core Files
#include <toolkit/core/exception.h>

//---------------------------------------------------------------------------------------
using namespace Toolkit::Core;
using namespace Toolkit::Resource;

//---------------------------------------------------------------------------------------
ResourceRepository::ResourceRepository( const QLocale& locale ) :
    m_Locale( locale ),
    m_Cache()
{
};

ResourceRepository::ResourceRepository( const ResourceRepository& other ) :
    m_Locale( other.m_Locale ),
    m_Cache( other.m_Cache )
{
};

ResourceRepository::~ResourceRepository() {
};

const QLocale& ResourceRepository::getLocale() const {
    return m_Locale;
};

void ResourceRepository::setLocale( const QLocale& newLocale ) {
    m_Locale = newLocale;
};

/*!
    \brief Clears the cache of loaded resources.

    \note
        Any existing loaded resources is now invalid and will have to be loaded again.
*/
void ResourceRepository::clear() {
    m_Cache.clear();
};

/*!
    \brief Loads a resource bundle based on the name \e id.

    \param id The id of the resources to load.

    \return
        Returns a reference into the cache for the new ResourceBundle after it has been loaded.
        If the \e id already exists in the cache, a read-only reference is just returned.
*/
ResourceRepository::const_reference ResourceRepository::loadResources( const key_type& ) const {
    throw Exception( SOURCELINE, "ResourceRepository::loadResources( const key_type& id ) const is not implementated yet!" );
};

/*!
    \brief Loads a resource bundle based on the name \e id and the QLocale of this repository.

    Use this method to load locale specific resources.

    \param id The id of the resources to load.

    \return
        Returns a reference into the cache for the new ResourceBundle after it has been loaded.
        If the \e id already exists in the cache, a read-only reference is just returned.
*/
ResourceRepository::const_reference ResourceRepository::loadBundle( const key_type& ) const {
    throw Exception( SOURCELINE, "ResourceRepository::loadBundle( const key_type& id ) const is not implementated yet!" );
};

ResourceRepository& ResourceRepository::operator=( const ResourceRepository& other ) {
    m_Locale = other.m_Locale;

    return *this;
};

ResourceRepository::data_type& ResourceRepository::operator[]( const key_type& key ) {
    return m_Cache[ key ];
};

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
