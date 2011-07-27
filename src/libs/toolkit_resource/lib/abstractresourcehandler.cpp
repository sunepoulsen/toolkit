//---------------------------------------------------------------------------------------
/*!
    \file abstractresourcehandler.cpp
    \brief
*/

//---------------------------------------------------------------------------------------

// Include Header File
#include "abstractresourcehandler.h"

//---------------------------------------------------------------------------------------
using namespace Toolkit::Resource;

//---------------------------------------------------------------------------------------
AbstractResourceHandler::AbstractResourceHandler( const QLocale& locale ) :
    m_Locale( locale )
{
};

AbstractResourceHandler::AbstractResourceHandler( const AbstractResourceHandler& other ) :
    m_Locale( other.m_Locale )
{
};

AbstractResourceHandler::~AbstractResourceHandler() {
};

const QLocale& AbstractResourceHandler::getLocale() const {
    return m_Locale;
};

void AbstractResourceHandler::setLocale( const QLocale& newLocale ) {
    m_Locale = newLocale;
};

ResourceBundle AbstractResourceHandler::readBundle( const QString& id, const QString& rootPath ) {
    return doReadBundle( id, rootPath );
};

void AbstractResourceHandler::writeBundle( const ResourceBundle& bundle, const QString& rootPath ) {
    doWriteBundle( bundle, rootPath );
};

AbstractResourceHandler& AbstractResourceHandler::operator=( const AbstractResourceHandler& other ) {
    m_Locale = other.m_Locale;

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
