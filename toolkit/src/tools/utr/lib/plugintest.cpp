//-------------------------------------------------------------------------------------------------------
/*!
    \file plugintest.cpp
    \brief
*/

//-------------------------------------------------------------------------------------------------------

// Include Header File
#include "plugintest.h"

// Include UTR Files
#include "pluginmodel.h"

//-------------------------------------------------------------------------------------------------------
using namespace Toolkit::Core;
using namespace Toolkit::Test;

//-------------------------------------------------------------------------------------------------------
PluginTest::PluginTest( AbstractPluginItem* parent, Toolkit::Test::TestSuite::value_type test ) :
    AbstractPluginItem( parent ),
    m_Test( test )
{
    if( !m_Test.isNull() ) {
        setupTest();
    };
}

PluginTest::~PluginTest() {
}

TestSuite::value_type PluginTest::getTest() {
    return m_Test;
}

const TestSuite::value_type PluginTest::getTest() const {
    return m_Test;
}

void PluginTest::setTest( TestSuite::value_type newTest ) {
    m_Test = newTest;
    setupTest();
}

QVariant PluginTest::doModelData( ModelColumnContainer::const_iterator colIt, int role ) const {
    if( role == Qt::DisplayRole ) {
        if( colIt->getId() == PluginModel::COL_NAME ) {
            return QVariant( getTest()->getId() );
        }
        else if( colIt->getId() == PluginModel::COL_COUNT_TESTS ) {
            return QVariant( getTest()->countTests() );
        };
    };

    if( role == Qt::TextAlignmentRole ) {
        return QVariant( colIt->getAlignment() );
    };

    return AbstractPluginItem::doModelData( colIt, role );
}

void PluginTest::setupTest() {
    clear();

    QSharedPointer<TestSuite> suite = m_Test.dynamicCast<TestSuite>();
    if( suite ) {
        for( TestSuite::iterator it = suite->begin(); it != suite->end(); ++it ) {
            push_back( Pointer( new PluginTest( this, *it ) ) );
        }
    }
}

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
