//-------------------------------------------------------------------------------------------------------
/*!
    \file plugintestsuiteitem.h
    \brief
*/

//-------------------------------------------------------------------------------------------------------
#ifndef __TOOLKIT_TEST_UTR_PLUGINTESTSUITEITEM_H__
#define __TOOLKIT_TEST_UTR_PLUGINTESTSUITEITEM_H__

// Include UTR Files
#include "abstractpluginitem.h"

// Include Toolkit Test Files
#include <toolkit/test/testsuite.h>

//-------------------------------------------------------------------------------------------------------
/*!
    \ingroup grp_TestExecutor
    \brief    
*/
class PluginTestSuiteItem : public AbstractPluginItem {
public:
	//!\name Constructors & Destructor
	//@{
	PluginTestSuiteItem( Toolkit::Test::TestSuitePtr suite );
	virtual ~PluginTestSuiteItem();
	//@}

    //!\name Properties
    //@{
    Toolkit::Test::TestSuitePtr suite() const;
    //@}
    
protected:
	//!\name Model interface
	//@{
	virtual QVariant doModelData( Toolkit::Core::ModelColumnContainer::const_iterator colIt, int role = Qt::DisplayRole ) const;
	//@}
    
private:
    Toolkit::Test::TestSuitePtr m_Suite;    

private:
    Q_DISABLE_COPY( PluginTestSuiteItem );
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
