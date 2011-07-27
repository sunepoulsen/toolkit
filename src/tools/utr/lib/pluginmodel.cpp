//-------------------------------------------------------------------------------------------------------
/*!
    \file pluginmodel.cpp
    \brief
*/

//-------------------------------------------------------------------------------------------------------

// Include Header File
#include "pluginmodel.h"

// Include QT Files
#include <QDir>
#include <QPluginLoader>

// Include Toolkit Core Files
#include <toolkit/core/format.h>
#include <toolkit/core/log.h>

//-------------------------------------------------------------------------------------------------------
using namespace Toolkit::Core;

//-------------------------------------------------------------------------------------------------------
const QString PluginModel::COL_NAME( "${name}" );
const QString PluginModel::COL_DESCRIPTION( "${description}" );
const QString PluginModel::COL_VERSION( "${version}" );
const QString PluginModel::COL_COUNT_TESTS( "${count_tests}" );
const QString PluginModel::COL_COUNT_OK( "${count_ok}" );
const QString PluginModel::COL_COUNT_WARNINGS( "${count_warnings}" );
const QString PluginModel::COL_COUNT_ERRORS( "${count_errors}" );
const QString PluginModel::COL_ELAPSED( "${count_elapsed}" );

//-------------------------------------------------------------------------------------------------------
PluginModel::PluginModel() :
    QAbstractTableModel(),
    m_Plugins()
{
};

PluginModel::PluginModel( const PluginModel& other ) :
    QAbstractTableModel(),
    m_Plugins( other.m_Plugins )
{
};

PluginModel::~PluginModel() {
};

ModelColumnContainer& PluginModel::getColumns() {
    return m_Columns;
};

const ModelColumnContainer& PluginModel::getColumns() const {
    return m_Columns;
};

void PluginModel::setColumns( const ModelColumnContainer& newColumns ) {
    m_Columns = newColumns;
};

int PluginModel::columnCount( const QModelIndex& ) const {
    Log log( Log::LT_TRACE, Log::MOD_MAIN, "int PluginModel::columnCount( const QModelIndex& parent ) const" );
    return m_Columns.size();
};

int PluginModel::rowCount( const QModelIndex& parent ) const {
    Log log( Log::LT_TRACE, Log::MOD_MAIN, "int PluginModel::rowCount( const QModelIndex& parent ) const" );

    if( parent.isValid() ) {
        AbstractPluginItem* item = modelIndexData( parent );
        if( item ) {
            log.write( Log::LT_TRACE, "Returns item->size(): %i", item->size() );
            return item->size();
        };

        log.write( Log::LT_TRACE, "Returns 0" );
        return 0;
    };
    
    log.write( Log::LT_TRACE, "Returns size(): %i", size() );
    return size();
};

QModelIndex PluginModel::index( int row, int column, const QModelIndex& parent ) const {
    Log log( Log::LT_TRACE, Log::MOD_MAIN, "QModelIndex PluginModel::index( int row, int column, const QModelIndex& parent ) const" );

    if( row < 0 || column < 0 ) {
        log.write( Log::LT_TRACE, "Invalid row or column [%i, %i]", row, column );
        return QModelIndex();
    };

    if( !parent.isValid() ) {
        log.write( Log::LT_TRACE, "Invalid parent." );
        if( row < (int)( size() ) ) {
            return createModelIndex( row, column, ( begin() + row )->data() );
        }
    }

    AbstractPluginItem* item = modelIndexData( parent );
    if( item ) {
        log.write( Log::LT_TRACE, "Valid parent index [%i, %i, %s]",
                                  parent.row(), parent.column(), item->modelData( m_Columns.begin(), Qt::DisplayRole ).toString() );
        if( row < (int)( item->size() ) ) {
            return createModelIndex( row, column, ( item->begin() + row )->data() );
        }
    };

    return QModelIndex();
}

QModelIndex PluginModel::parent( const QModelIndex& index ) const {
    Log log( Log::LT_TRACE, Log::MOD_MAIN, "QModelIndex PluginModel::parent( const QModelIndex& index ) const" );

    if( !index.isValid() ) {
        return QModelIndex();
    };

    AbstractPluginItem* item = modelIndexData( index );
    if( item && item->getParent() ) {
        log.write( Log::LT_TRACE, "Find parent index for index [%i, %i, %s]",
                                  index.row(), index.column(), item->modelData( m_Columns.begin(), Qt::DisplayRole ).toString() );

        for( AbstractPluginItem::iterator it = item->getParent()->begin(); it != item->getParent()->end(); ++it ) {
            if( it->data() == item ) {
                log.write( Log::LT_TRACE, "Returns index as parent: [%i, %i, %s]",
                                          std::distance( item->getParent()->begin(), it ), 0,
                                          item->getParent()->modelData( m_Columns.begin(), Qt::DisplayRole ).toString() );
                return createModelIndex( std::distance( item->getParent()->begin(), it ), 0, item->getParent() );
            };
        }
    };

    log.write( Log::LT_TRACE, "Returns QModelIndex()" );
    return QModelIndex();
}

QVariant PluginModel::data( const QModelIndex& index, int role ) const {
    Log log( Log::LT_TRACE, Log::MOD_MAIN, "QVariant PluginModel::data( const QModelIndex& index, int role ) const" );

    if( !index.isValid() ) {
        return QVariant();
    };
    
    if( (size_type)(index.column()) >= m_Columns.size() ) {
        return QVariant();        
    };

    log.write( Log::LT_TRACE, "Getting internal pointer of index." );
    AbstractPluginItem* item = modelIndexData( index );
    if( item ) {
        log.write( Log::LT_TRACE, "Returns model data for index [%i, %i]", index.row(), index.column() );
        return item->modelData( m_Columns.begin() + index.column(), role );
    };

    log.write( Log::LT_TRACE, "Return QVariant()" );
    return QVariant();
};

QVariant PluginModel::headerData( int section, Qt::Orientation, int role ) const {
    Log log( Log::LT_TRACE, Log::MOD_MAIN, "QVariant PluginModel::headerData( int section, Qt::Orientation, int role ) const" );

    return m_Columns.headerData( section, role );
};

PluginModel::iterator PluginModel::begin() {
    return m_Plugins.begin();
};

PluginModel::const_iterator PluginModel::begin() const {
    return m_Plugins.begin();
};

PluginModel::iterator PluginModel::end() {
    return m_Plugins.end();
};

PluginModel::const_iterator PluginModel::end() const {
    return m_Plugins.end();
};

void PluginModel::clear() {
    m_Plugins.clear();
};

bool PluginModel::empty() const {
    return m_Plugins.empty();
};

void PluginModel::push_back( const value_type& v ) {
    m_Plugins.push_back( v );
};

PluginModel::size_type PluginModel::size() const {
    return m_Plugins.size();
};

bool PluginModel::addPlugin( const QString& fileName ) {
    TestRegisterInterfacePtr p = loadPlugin( fileName );
    
    if( !p.isNull() ) {
        PluginItem::Pointer newItem( new PluginItem() );
        
        newItem->setPlugin( p );
        push_back( newItem );
        return true;
    };
    
    return false;
};

bool PluginModel::addPlugins( const QString& wildcard ) {
    Log log( Log::LT_TRACE, Log::MOD_MAIN, "bool PluginModel::addPlugins( const QString& wildcard )" );
    
    QDir curDir = QDir::current();
    QStringList pluginNames = curDir.entryList( QStringList( wildcard ), QDir::Files | QDir::Readable, QDir::Name );
    
    log.write( Log::LT_TRACE, "curDir: %s", curDir.path() );
    log.write( Log::LT_TRACE, "wildcard: %s", wildcard );
    log.write( Log::LT_TRACE, "Plugin Names: \n%s", pluginNames.join( "\n" ) );
    
    if( pluginNames.isEmpty() ) {
        return false;
    };
    
    bool result = false;
    for( QStringList::const_iterator it = pluginNames.begin(); it != pluginNames.end(); ++it ) {
        log.beginGroup( Log::LT_TRACE, StringFormat::format( "Loading plugin: %s", *it ) );
        if( addPlugin( curDir.absoluteFilePath( *it ) ) ) {
            log.write( Log::LT_TRACE, "Load successful!" );
            result = true;
        }
        else {
            log.write( Log::LT_TRACE, "Load failed!" );
        };
        log.endGroup();
    };
    
    return result;
};

TestRegisterInterfacePtr PluginModel::loadPlugin( const QString& fileName ) const {
    Log log( Log::LT_TRACE, Log::MOD_MAIN, "bool PluginModel::addPlugins( const QString& wildcard )", false );

    QPluginLoader pluginLoader( fileName );
    QObject* plugin = pluginLoader.instance();
    if( plugin ) {
        TestRegisterInterface* pluginInterface = qobject_cast<TestRegisterInterface*>( plugin );
        if( pluginInterface ) {
            return TestRegisterInterfacePtr( pluginInterface );
        }
        else {
            log.write( Log::LT_DEBUG, "Plugin load error: Root component is not a valid TestRegisterInterface interface." );
        };
    }
    else {
        log.write( Log::LT_DEBUG, "Plugin load error: %s", pluginLoader.errorString() );
    };
    
    return TestRegisterInterfacePtr();
};

PluginModel& PluginModel::operator=( const PluginModel& other ) {
    m_Plugins = other.m_Plugins;
    
    return *this;
};

AbstractPluginItem* PluginModel::modelIndexData( const QModelIndex& index ) const {
    Log log( Log::LT_TRACE, Log::MOD_MAIN, "AbstractPluginItem* PluginModel::modelIndexData( const QModelIndex& index ) const" );
    log.write( Log::LT_TRACE, "Index [%i, %i]", index.row(), index.column() );

    if( !index.isValid() ) {
        log.write( Log::LT_TRACE, "Invalid index. Returns NULL" );
        return NULL;
    };

    AbstractPluginItem* item = reinterpret_cast<AbstractPluginItem*>( index.internalPointer() );
    log.write( Log::LT_TRACE, "Trying to write item to log." );
    log.write( Log::LT_TRACE, "Returns item: %s", item->modelData( m_Columns.begin(), Qt::DisplayRole ).toString() );

    return item;
}

QModelIndex PluginModel::createModelIndex( int row, int column, AbstractPluginItem* data ) const {
    Log log( Log::LT_TRACE, Log::MOD_MAIN, "QModelIndex PluginModel::createModelIndex( int row, int column, AbstractPluginItem* data ) const" );

    if( data ) {
        log.write( Log::LT_TRACE, "Trying to write index to log." );
        log.write( Log::LT_TRACE, "Create index: [%i, %i, %s]",
                   row, column, data->modelData( m_Columns.begin(), Qt::DisplayRole ).toString() );
    }
    else {
        log.write( Log::LT_TRACE, "Create index: [%i, %i, NULL]", row, column );
    }

    return createIndex( row, column, data );
}

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
