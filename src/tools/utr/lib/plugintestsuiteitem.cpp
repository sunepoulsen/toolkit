//-------------------------------------------------------------------------------------------------------
/*!
    \file plugintestsuiteitem.cpp
    \brief
*/

//-------------------------------------------------------------------------------------------------------

// Include Header File
#include "plugintestsuiteitem.h"

//-------------------------------------------------------------------------------------------------------
using namespace Toolkit::Core;
using namespace Toolkit::Test;

//-------------------------------------------------------------------------------------------------------
PluginTestSuiteItem::PluginTestSuiteItem( Toolkit::Test::TestSuitePtr suite ) :
	AbstractPluginItem(),
    m_Suite( suite )
{
};

PluginTestSuiteItem::~PluginTestSuiteItem() {
};

TestSuitePtr PluginTestSuiteItem::suite() const {
    return m_Suite;
};

QVariant PluginTestSuiteItem::doModelData( ModelColumnContainer::const_iterator colIt, int role ) const {
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
