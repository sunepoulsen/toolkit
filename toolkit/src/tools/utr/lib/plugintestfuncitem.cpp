//-------------------------------------------------------------------------------------------------------
/*!
    \file plugintestfuncitem.cpp
    \brief
*/

//-------------------------------------------------------------------------------------------------------

// Include Header File
#include "plugintestfuncitem.h"

// Include UTR Files
#include "pluginmodel.h"

//-------------------------------------------------------------------------------------------------------
using namespace Toolkit::Core;
using namespace Toolkit::Test;

//-------------------------------------------------------------------------------------------------------
PluginTestFuncItem::PluginTestFuncItem( Toolkit::Test::TestCasePtr testCase, const QString& funcName ) :
    AbstractPluginItem(),
    m_TestCase( testCase ),
    m_FuncName( funcName )
{
};

PluginTestFuncItem::~PluginTestFuncItem() {
};

TestCasePtr PluginTestFuncItem::testCase() const {
    return m_TestCase;
};

const QString& PluginTestFuncItem::getFuncName() const {
    return m_FuncName;
};

void PluginTestFuncItem::setFuncName( const QString& newFuncName ) {
    m_FuncName = newFuncName;
};

QVariant PluginTestFuncItem::doModelData( ModelColumnContainer::const_iterator colIt, int role ) const {
    if( role == Qt::DisplayRole ) {
        if( colIt->getId() == PluginModel::COL_NAME ) {
            return QVariant( m_FuncName );
        }
        else if( colIt->getId() == PluginModel::COL_COUNT_TESTS ) {
            return QVariant( 1 );
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
