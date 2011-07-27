//-------------------------------------------------------------------------------------------------------
/*!
    \file pluginitem.h
    \brief
*/

//-------------------------------------------------------------------------------------------------------
#ifndef __TOOLKIT_TEST_UTR_PLUGINITEM_H__
#define __TOOLKIT_TEST_UTR_PLUGINITEM_H__

// Include UTR Files
#include "abstractpluginitem.h"

// Include Toolkit Test Files
#include <toolkit/test/testregisterinterface.h>

//-------------------------------------------------------------------------------------------------------
/*!
    \ingroup grp_TestExecutor
    \brief    
*/
class PluginItem : public AbstractPluginItem {
public:
    typedef QSharedPointer<PluginItem> Pointer;

public:
    //!\name Constructors & Destructor
    //@{
    PluginItem();
    virtual ~PluginItem();
    //@}
    
    //!\name Properties
    //@{
    TestRegisterInterfacePtr getPlugin();
    const TestRegisterInterfacePtr getPlugin() const;
    void setPlugin( TestRegisterInterfacePtr newPlugin );
    TestRegisterInterface::SuitePtr& getSuite();
    const TestRegisterInterface::SuitePtr& getSuite() const;
    int countTests() const;
    //@}
    
protected:
    //!\name Model interface
    //@{
    virtual QVariant doModelData( Toolkit::Core::ModelColumnContainer::const_iterator colIt, int role = Qt::DisplayRole ) const;
    //@}

private:
    //!\name Properties
    //@{
    TestRegisterInterfacePtr m_Plugin;
    TestRegisterInterface::SuitePtr m_Suite;
    int m_CountTests;
    //@}

private:
    Q_DISABLE_COPY( PluginItem );
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
