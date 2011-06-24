//-------------------------------------------------------------------------------------------------
/*!
    \file genericmodel.cpp
    \brief
*/

//-------------------------------------------------------------------------------------------------

// include Header File
#include "genericmodel.h"

//-------------------------------------------------------------------------------------------------
using namespace Toolkit::Core;

//-------------------------------------------------------------------------------------------------
GenericModel::GenericModel( QObject* parent, ModelItem* root ) :
    QAbstractItemModel( parent ),
    m_Root( root ),
    m_Columns()
{
}

GenericModel::~GenericModel() {
    delete m_Root;
}

const ModelItem* GenericModel::getRoot() const {
    return m_Root;
}

ModelItem* GenericModel::getRoot() {
    return m_Root;
}

void GenericModel::setRoot( ModelItem* newModelItem ) {
    delete m_Root;
    m_Root = newModelItem;

    emit reset();
}

const ModelColumnContainer& GenericModel::getColumns() const {
    return m_Columns;
}

ModelColumnContainer& GenericModel::getColumns() {
    return m_Columns;
}

void GenericModel::setColumns( const ModelColumnContainer& newColumns ) {
    m_Columns = newColumns;
}

int GenericModel::rowCount( const QModelIndex& ) const {
    return static_cast<int>( m_Root->size() );
}

int GenericModel::columnCount( const QModelIndex& ) const {
    return static_cast<int>( m_Columns.size() );
}

QModelIndex GenericModel::index( int row, int column, const QModelIndex& ) const {
    return createIndex( row, column );
}

QModelIndex GenericModel::parent( const QModelIndex& ) const {
    return QModelIndex();
}

bool GenericModel::canFetchMore( const QModelIndex& ) const {
    return m_Root->canFetchMore();
}

void GenericModel::fetchMore( const QModelIndex& ) {
    m_Root->fetchMore();
}

bool GenericModel::hasChildren( const QModelIndex& ) const {
    return !m_Root->empty();
}

Qt::ItemFlags GenericModel::flags( const QModelIndex& index ) const {
    ModelColumnContainer::const_iterator col = findColumn( index );
    if( col != m_Columns.end() ) {
        ModelItem::const_iterator item = findItem( m_Root, index );
        if( item != m_Root->end() ) {
            return (*item)->flags( *col );
        }
    }

    return Qt::ItemFlags();
};

QVariant GenericModel::data( const QModelIndex& index, int role ) const {
    ModelColumnContainer::const_iterator col = findColumn( index );

    if( col == m_Columns.end() ) {
        return QVariant();
    };

    ModelItem::const_iterator item = findItem( m_Root, index );
    if( item == m_Root->end() ) {
        return QVariant();
    }

    switch( role ) {
    case Qt::DisplayRole:               return (*item)->getValue( *col );
    case Qt::DecorationRole:            return (*item)->getDecoration( *col );
    case Qt::EditRole:                  return (*item)->getEditValue( *col );
    case Qt::ToolTipRole:               return (*item)->getToolTip( *col );
    case Qt::StatusTipRole:             return (*item)->getStatusTip( *col );
    case Qt::WhatsThisRole:             return (*item)->getWhatsThis( *col );
    case Qt::SizeHintRole:              return (*item)->getSizeHint( *col );
    case Qt::FontRole:                  return (*item)->getFont( *col );
    case Qt::TextAlignmentRole:         return (*item)->getTextAlignment( *col );
    case Qt::BackgroundRole:            return (*item)->getBackground( *col );
    case Qt::ForegroundRole:            return (*item)->getForeground( *col );
    case Qt::CheckStateRole:            return (*item)->getCheckState( *col );
    case Qt::AccessibleTextRole:        return (*item)->getAccessibleText( *col );
    case Qt::AccessibleDescriptionRole: return (*item)->getAccessibleDescription( *col );

    default:
        return QVariant();
    }

    return QVariant();
}

bool GenericModel::setData( const QModelIndex& index, const QVariant& newValue, int role ) {
    ModelColumnContainer::const_iterator col = findColumn( index );

    if( col == m_Columns.end() ) {
        return false;
    };

    ModelItem::const_iterator item = findItem( m_Root, index );
    if( item == m_Root->end() ) {
        return false;
    }

    bool result;
    switch( role ) {
    case Qt::DisplayRole:
        result = (*item)->setValue( *col, newValue );
        break;

    case Qt::DecorationRole:
        result = (*item)->setDecoration( *col, newValue );
        break;

    case Qt::EditRole:
        result = (*item)->setEditValue( *col, newValue );
        break;

    case Qt::ToolTipRole:
        result = (*item)->setToolTip( *col, newValue );
        break;

    case Qt::StatusTipRole:
        result = (*item)->setStatusTip( *col, newValue );
        break;

    case Qt::WhatsThisRole:
        result = (*item)->setWhatsThis( *col, newValue );
        break;

    case Qt::SizeHintRole:
        result = (*item)->setSizeHint( *col, newValue );
        break;

    case Qt::FontRole:
        result = (*item)->setFont( *col, newValue );
        break;

    case Qt::TextAlignmentRole:
        result = (*item)->setTextAlignment( *col, newValue );
        break;

    case Qt::BackgroundRole:
        result = (*item)->setBackground( *col, newValue );
        break;

    case Qt::ForegroundRole:
        result = (*item)->setForeground( *col, newValue );
        break;

    case Qt::CheckStateRole:
        result = (*item)->setCheckState( *col, newValue );
        break;

    case Qt::AccessibleTextRole:
        result = (*item)->setAccessibleText( *col, newValue );
        break;

    case Qt::AccessibleDescriptionRole:
        result = (*item)->setAccessibleDescription( *col, newValue );
        break;

    default:
        return false;
    }

    if( result ) {
        emit dataChanged( index, index );
    }

    return false;
}

QVariant GenericModel::headerData( int section, Qt::Orientation, int role ) const {
    return m_Columns.headerData( section, role );
}

void GenericModel::sort( int, Qt::SortOrder ) {
}

ModelColumnContainer::const_iterator GenericModel::findColumn( const QModelIndex& index ) const {
    if( index.column() < static_cast<int>( m_Columns.size() ) ) {
        return m_Columns.begin() + index.column();
    }

    return m_Columns.end();
}

ModelItem::const_iterator GenericModel::findItem( const ModelItem* modelItem, const QModelIndex& index ) const {
    if( !modelItem ) {
        return modelItem->end();
    }

    if( index.row() < static_cast<int>( modelItem->size() ) ) {
        return modelItem->begin() + index.row();
    }

    return modelItem->end();
}

ModelItem::iterator GenericModel::findItem( ModelItem* modelItem, const QModelIndex& index ) {
    if( !modelItem ) {
        return modelItem->end();
    }

    if( index.row() < static_cast<int>( modelItem->size() ) ) {
        return modelItem->begin() + index.row();
    }

    return modelItem->end();
}

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
