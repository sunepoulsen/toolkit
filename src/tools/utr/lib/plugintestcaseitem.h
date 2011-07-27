//-------------------------------------------------------------------------------------------------------
/*!
    \file plugintestcaseitem.h
    \brief
*/

//-------------------------------------------------------------------------------------------------------
#ifndef __TOOLKIT_TEST_UTR_PLUGINTESTCASEITEM_H__
#define __TOOLKIT_TEST_UTR_PLUGINTESTCASEITEM_H__

// Include UTR Files
#include "abstractpluginitem.h"

// Include Toolkit Test Files
#include <toolkit/test/testcase.h>

//-------------------------------------------------------------------------------------------------------
/*!
    \ingroup grp_TestExecutor
    \brief    
*/
class PluginTestCaseItem : public AbstractPluginItem {
public:
    //!\name Constructors & Destructor
    //@{
    PluginTestCaseItem( Toolkit::Test::TestCasePtr testCase );
    virtual ~PluginTestCaseItem();
    //@}

    //!\name Properties
    //@{
    Toolkit::Test::TestCasePtr testCase() const;
    //@}
    
protected:
    //!\name Model interface
    //@{
    virtual QVariant doModelData( Toolkit::Core::ModelColumnContainer::const_iterator colIt, int role = Qt::DisplayRole ) const;
    //@}
    
private:
    Toolkit::Test::TestCasePtr m_TestCase;

private:
    Q_DISABLE_COPY( PluginTestCaseItem );
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
