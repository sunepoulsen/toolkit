//-------------------------------------------------------------------------------------------------------
/*!
    \file plugingroupitem.cpp
    \brief
*/

//-------------------------------------------------------------------------------------------------------

// Include Header File
#include "plugingroupitem.h"

// Include UTR Files
#include "pluginmodel.h"

//-------------------------------------------------------------------------------------------------------
PluginGroupItem::PluginGroupItem() :
    AbstractPluginItem(),
    m_Name(),
    m_Description()
{
};

PluginGroupItem::PluginGroupItem( const QString& name, const QString& descr ) :
    AbstractPluginItem(),
    m_Name( name ),
    m_Description( descr )
{
};

PluginGroupItem::~PluginGroupItem() {
};

const QString& PluginGroupItem::getName() const {
    return m_Name;
};

void PluginGroupItem::setName( const QString& newName ) {
    m_Name = newName;
};

const QString& PluginGroupItem::getDescription() const {
    return m_Description;
};

void PluginGroupItem::setDescription( const QString& newDescription ) {
    m_Description = newDescription;
};

QVariant PluginGroupItem::doModelData( Toolkit::Core::ModelColumnContainer::const_iterator colIt, int role ) const {
    if( role == Qt::DisplayRole ) {
        if( colIt->getId() == PluginModel::COL_NAME ) {
            return QVariant( getName() );
        }
        else if( colIt->getId() == PluginModel::COL_DESCRIPTION ) {
            return QVariant( getDescription() );
        };
    };
    
    if( role == Qt::TextAlignmentRole ) {
        return QVariant( colIt->getAlignment() );
    };

    return AbstractPluginItem::doModelData( colIt, role );    
};

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
