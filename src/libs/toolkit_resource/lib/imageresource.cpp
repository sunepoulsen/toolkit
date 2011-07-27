//---------------------------------------------------------------------------------------
/*!
    \file imageresource.cpp
    \brief
*/

//---------------------------------------------------------------------------------------

// Include Header File
#include "imageresource.h"

//---------------------------------------------------------------------------------------
using namespace Toolkit::Resource;

//---------------------------------------------------------------------------------------
ImageResource::ImageResource( const QString& key ) :
    GenericResource( key ),
    m_FileName()
{
};

ImageResource::ImageResource( const ImageResource& other ) :
    GenericResource( other ),
    m_FileName( other.m_FileName )
{
};

ImageResource::~ImageResource() {
};

const QString& ImageResource::getFileName() const {
    return m_FileName;
};

void ImageResource::setFileName( const QString& newFileName ) {
    m_FileName = newFileName;
};

ImageResource& ImageResource::operator=( const ImageResource& other ) {
    GenericResource::operator=( other );
    m_FileName = other.m_FileName;

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
