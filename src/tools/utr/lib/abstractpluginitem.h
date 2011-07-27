//-------------------------------------------------------------------------------------------------------
/*!
    \file abstractpluginitem.h
    \brief
*/

//-------------------------------------------------------------------------------------------------------
#ifndef __TOOLKIT_TEST_UTR_ABSTRACTPLUGINITEM_H__
#define __TOOLKIT_TEST_UTR_ABSTRACTPLUGINITEM_H__

// Include Toolkit Core Files
#include <toolkit/core/modelcolumns.h>

// Include Qt Files
#include <QSharedPointer>

// Include STD Files
#include <vector>

//-------------------------------------------------------------------------------------------------------
/*!
    \ingroup grp_TestExecutor
    \brief    
*/
class AbstractPluginItem {
public:
    typedef QSharedPointer<AbstractPluginItem> Pointer;

public:
    typedef std::vector<Pointer> container_type;
    typedef container_type::iterator iterator;
    typedef container_type::const_iterator const_iterator;
    typedef container_type::reference reference;
    typedef container_type::const_reference const_reference;
    typedef container_type::size_type size_type;
    typedef container_type::value_type value_type;

public:
    //\!name Constructors & Destructor
    //@{
    AbstractPluginItem( AbstractPluginItem* parent = NULL );
    virtual ~AbstractPluginItem();
    //@}

    //!\name Properties
    //@{
    AbstractPluginItem* getParent();
    const AbstractPluginItem* getParent() const;
    void setParent( AbstractPluginItem* newParent );
    //@}

    //!\name Sub items
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

    //!\name Model interface
    //@{
    QVariant modelData( Toolkit::Core::ModelColumnContainer::const_iterator colIt, int role = Qt::DisplayRole ) const;
    //@}

protected:
    //!\name Model interface
    //@{
    virtual QVariant doModelData( Toolkit::Core::ModelColumnContainer::const_iterator colIt, int role = Qt::DisplayRole ) const;
    //@}

private:
    AbstractPluginItem* m_Parent;
    container_type m_Items;

private:
    Q_DISABLE_COPY( AbstractPluginItem );
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
