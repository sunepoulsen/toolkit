//-----------------------------------------------------------------------------
/*!
    \file datamodel.h
    \brief
*/

//-----------------------------------------------------------------------------

// Include Header File
#include "datamodel.h"

//-----------------------------------------------------------------------------
using namespace Toolkit::Core;

//-----------------------------------------------------------------------------
DataModel::DataModel( QObject* parent ) :
    QAbstractTableModel( parent ),
    m_Columns()
{
}

DataModel::DataModel( const DataModel* other, QObject* parent ) :
    QAbstractTableModel( parent ),
    m_Columns()
{
    if( other ) {
        m_Columns = other->getColumns();
    };
}

DataModel::~DataModel() {
}

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
