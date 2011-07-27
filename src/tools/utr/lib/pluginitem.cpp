//-------------------------------------------------------------------------------------------------------
/*!
    \file pluginitem.cpp
    \brief
*/

//-------------------------------------------------------------------------------------------------------

// Include Header File
#include "pluginitem.h"

// Include UTR Files
#include "pluginmodel.h"
#include "plugintest.h"

// Include Toolkit Test Files
#include <toolkit/test/testcase.h>

//-------------------------------------------------------------------------------------------------------
using namespace Toolkit::Core;
using namespace Toolkit::Test;

//-------------------------------------------------------------------------------------------------------
PluginItem::PluginItem() :
    AbstractPluginItem(),
    m_Plugin(),
    m_Suite(),
    m_CountTests( -1 )
{
};

PluginItem::~PluginItem() {
};

TestRegisterInterfacePtr PluginItem::getPlugin() {
    return m_Plugin;
};

const TestRegisterInterfacePtr PluginItem::getPlugin() const {
    return m_Plugin;
};

void PluginItem::setPlugin( TestRegisterInterfacePtr newPlugin ) {
    m_Plugin = newPlugin;
    
    if( !m_Plugin.isNull() ) {
        m_Suite = m_Plugin->registerTests();

        for( TestSuite::iterator it = m_Suite->begin(); it != m_Suite->end(); ++it ) {
            push_back( AbstractPluginItem::Pointer( new PluginTest( this, *it ) ) );
        }
        
        m_CountTests = 0;
        if( !m_Suite.isNull() ) {
            m_CountTests = m_Suite->countTests();
        };
    };
};

TestRegisterInterface::SuitePtr& PluginItem::getSuite() {
    return m_Suite;
};

const TestRegisterInterface::SuitePtr& PluginItem::getSuite() const {
    return m_Suite;
};

int PluginItem::countTests() const {
    return m_CountTests;
};

QVariant PluginItem::doModelData( ModelColumnContainer::const_iterator colIt, int role ) const {
    if( role == Qt::DisplayRole ) {
        if( colIt->getId() == PluginModel::COL_NAME ) {
            return QVariant( getPlugin()->pluginName() );
        }
        else if( colIt->getId() == PluginModel::COL_DESCRIPTION ) {
            return QVariant( getPlugin()->pluginDescription() );
        }
        else if( colIt->getId() == PluginModel::COL_VERSION ) {
            return QVariant( getPlugin()->pluginVersion() );
        }
        else if( colIt->getId() == PluginModel::COL_COUNT_TESTS ) {
            return QVariant( countTests() );
        }
        else if( colIt->getId() == PluginModel::COL_COUNT_OK ) {
            return "";
        }
        else if( colIt->getId() == PluginModel::COL_COUNT_WARNINGS ) {
            return "";
        }
        else if( colIt->getId() == PluginModel::COL_COUNT_ERRORS ) {
            return "";
        };
    };
    
    if( role == Qt::TextAlignmentRole ) {
        return QVariant( colIt->getAlignment() );
    };

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
