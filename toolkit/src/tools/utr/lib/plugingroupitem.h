//-------------------------------------------------------------------------------------------------------
/*!
    \file plugingroupitem.h
    \brief
*/

//-------------------------------------------------------------------------------------------------------
#ifndef __TOOLKIT_TEST_UTR_PLUGINGROUPITEM_H__
#define __TOOLKIT_TEST_UTR_PLUGINGROUPITEM_H__

// Include UTR Files
#include "abstractpluginitem.h"

// Include Toolkit Test Files
#include <toolkit/test/testregisterinterface.h>

//-------------------------------------------------------------------------------------------------------
/*!
    \ingroup grp_TestExecutor
    \brief    
*/
class PluginGroupItem : public AbstractPluginItem {
public:
    //!\name Constructors & Destructor
    //@{
    PluginGroupItem();
    PluginGroupItem( const QString& name, const QString& descr );
    virtual ~PluginGroupItem();
    //@}
    
    //!\name Properties
    //@{
    const QString& getName() const;
    void setName( const QString& newName );
    const QString& getDescription() const;
    void setDescription( const QString& newDescription );
    //@}
    
protected:
    //!\name Model interface
    //@{
    virtual QVariant doModelData( Toolkit::Core::ModelColumnContainer::const_iterator colIt, int role = Qt::DisplayRole ) const;
    //@}

private:
    //!\name Properties
    //@{
    QString m_Name;
    QString m_Description;
    //@}

private:
    Q_DISABLE_COPY( PluginGroupItem );
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
