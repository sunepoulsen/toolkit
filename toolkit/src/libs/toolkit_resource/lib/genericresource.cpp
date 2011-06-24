//---------------------------------------------------------------------------------------
/*!
    \file genericresource.cpp
    \brief
*/

//---------------------------------------------------------------------------------------

// Include Header File
#include "genericresource.h"

//---------------------------------------------------------------------------------------
using namespace Toolkit::Resource;

//---------------------------------------------------------------------------------------
GenericResource::GenericResource( const QString& key, const QVariant& value ) :
    AbstractResource( key ),
    m_Data( value )
{
};

GenericResource::GenericResource( const GenericResource& other ) :
    AbstractResource( other ),
    m_Data( other.m_Data )
{
};

GenericResource::~GenericResource() {
};

const QVariant& GenericResource::getData() const {
    return m_Data;
};

void GenericResource::setData( const QVariant& newData ) {
    m_Data = newData;
};

GenericResource& GenericResource::operator=( const GenericResource& other ) {
    AbstractResource::operator=( other );
    m_Data = other.m_Data;

    return *this;
};

const QVariant& GenericResource::doToVariant() const {
    return getData();
};

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
