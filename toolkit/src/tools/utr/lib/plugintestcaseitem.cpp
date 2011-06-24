//-------------------------------------------------------------------------------------------------------
/*!
    \file plugintestcaseitem.cpp
    \brief
*/

//-------------------------------------------------------------------------------------------------------

// Include Header File
#include "plugintestcaseitem.h"

//-------------------------------------------------------------------------------------------------------
using namespace Toolkit::Core;
using namespace Toolkit::Test;

//-------------------------------------------------------------------------------------------------------
PluginTestCaseItem::PluginTestCaseItem( TestCasePtr testCase ) :
    AbstractPluginItem(),
    m_TestCase( testCase )
{
};

PluginTestCaseItem::~PluginTestCaseItem() {
};

TestCasePtr PluginTestCaseItem::testCase() const {
    return m_TestCase;
};

QVariant PluginTestCaseItem::doModelData( ModelColumnContainer::const_iterator colIt, int role ) const {
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
