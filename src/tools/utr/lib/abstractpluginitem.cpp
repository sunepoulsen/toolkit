//-------------------------------------------------------------------------------------------------------
/*!
    \file abstractpluginitem.cpp
    \brief
*/

//-------------------------------------------------------------------------------------------------------

// Include Header File
#include "abstractpluginitem.h"

//-------------------------------------------------------------------------------------------------------
using namespace Toolkit::Core;

//-------------------------------------------------------------------------------------------------------
AbstractPluginItem::AbstractPluginItem( AbstractPluginItem* parent ) :
    m_Parent( parent ),
    m_Items()
{
};

AbstractPluginItem::~AbstractPluginItem() {
};

AbstractPluginItem* AbstractPluginItem::getParent() {
    return m_Parent;
}

const AbstractPluginItem* AbstractPluginItem::getParent() const {
    return m_Parent;
}

void AbstractPluginItem::setParent( AbstractPluginItem* newParent ) {
    m_Parent = newParent;
}

AbstractPluginItem::iterator AbstractPluginItem::begin() {
    return m_Items.begin();
};

AbstractPluginItem::const_iterator AbstractPluginItem::begin() const {
    return m_Items.begin();
};

AbstractPluginItem::iterator AbstractPluginItem::end() {
    return m_Items.end();
};

AbstractPluginItem::const_iterator AbstractPluginItem::end() const {
    return m_Items.end();
};

void AbstractPluginItem::clear() {
    m_Items.clear();
};

bool AbstractPluginItem::empty() const {
    return m_Items.empty();
};

void AbstractPluginItem::push_back( const value_type& v ) {
    v->setParent( this );
    m_Items.push_back( v );
};

AbstractPluginItem::size_type AbstractPluginItem::size() const {
    return m_Items.size();
};

QVariant AbstractPluginItem::modelData( Toolkit::Core::ModelColumnContainer::const_iterator colIt, int role ) const {
    return doModelData( colIt, role );
};

QVariant AbstractPluginItem::doModelData( ModelColumnContainer::const_iterator, int ) const {
    return QVariant();
};

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
