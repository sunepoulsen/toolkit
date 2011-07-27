//-------------------------------------------------------------------------------------------------------
/*!
    \file pluginmodel.h
    \brief
*/

//-------------------------------------------------------------------------------------------------------
#ifndef __TOOLKIT_TEST_UTR_PLUGINMODEL_H__
#define __TOOLKIT_TEST_UTR_PLUGINMODEL_H__

// Include UTR Files
#include "pluginitem.h"

// Include Toolkit Core Files
#include <toolkit/core/format.h>
#include <toolkit/core/modelcolumns.h>

// Include Toolkit Test Files
#include <toolkit/test/testregisterinterface.h>

// Include QT Files
#include <QAbstractTableModel>

// Include STD Files
#include <vector>

//-------------------------------------------------------------------------------------------------------
/*!
    \ingroup grp_TestExecutor
    \brief    
*/
class PluginModel : public QAbstractTableModel {
    Q_OBJECT
            
public:
    typedef std::vector<PluginItem::Pointer> container_type;
    typedef container_type::iterator iterator;
    typedef container_type::const_iterator const_iterator;
    typedef container_type::reference reference;
    typedef container_type::const_reference const_reference;
    typedef container_type::size_type size_type;
    typedef container_type::value_type value_type;

public:
    static const QString COL_NAME;
    static const QString COL_DESCRIPTION;
    static const QString COL_VERSION;
    static const QString COL_COUNT_TESTS;
    static const QString COL_COUNT_OK;
    static const QString COL_COUNT_WARNINGS;
    static const QString COL_COUNT_ERRORS;
    static const QString COL_ELAPSED;
        
public:
    //!\name Constructors & Destructor
    //@{
    PluginModel();
    PluginModel( const PluginModel& other );
    virtual ~PluginModel();
    //@}
    
    //!\name Properties
    //@{
    Toolkit::Core::ModelColumnContainer& getColumns();
    const Toolkit::Core::ModelColumnContainer& getColumns() const;
    void setColumns( const Toolkit::Core::ModelColumnContainer& newColumns );
    //@}

    //!\name Qt Model
    //@{
    virtual int columnCount( const QModelIndex& parent = QModelIndex() ) const;
    virtual int rowCount( const QModelIndex& parent = QModelIndex() ) const;
    virtual QModelIndex index( int row, int column, const QModelIndex& parent = QModelIndex() ) const;
    virtual QModelIndex parent( const QModelIndex& index ) const;
    virtual QVariant data( const QModelIndex& index, int role = Qt::DisplayRole ) const;
    virtual QVariant headerData( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const; 
    //@}
    
    //!\name Plugins
    //@{
    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;
    void clear();
    bool empty() const;
    void push_back( const value_type& v );
    size_type size() const;
    //@}
    
    //!\name Load plugins
    //@{
    bool addPlugin( const QString& fileName );
    bool addPlugins( const QString& wildcard );
    TestRegisterInterfacePtr loadPlugin( const QString& fileName ) const;
    //@}
    
    //!\name Operators
    //@{
    PluginModel& operator=( const PluginModel& other );
    //@}
    
private:
    //!\name Model Helpers
    //@{
    AbstractPluginItem* modelIndexData( const QModelIndex& index ) const;
    QModelIndex createModelIndex( int row, int column, AbstractPluginItem* data ) const;
    //@}

private:
    container_type m_Plugins;
    Toolkit::Core::ModelColumnContainer m_Columns;
};

#endif

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
