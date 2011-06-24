//---------------------------------------------------------------------------------------
/*!
    \file sqlquery.cpp
    \brief
*/

//---------------------------------------------------------------------------------------

// Include Header File
#include "sqlquery.h"

// Include Toolkit Sql Files
#include "sqldatabase.h"

//---------------------------------------------------------------------------------------
using namespace Toolkit::Sql;

//---------------------------------------------------------------------------------------
SqlQuery::SqlQuery() :
    QObject(),
    m_Query()
{
}

SqlQuery::SqlQuery( const SqlQuery& other ) :
    QObject(),
    m_Query( other.m_Query )
{
}

SqlQuery::~SqlQuery() {
}

SqlQuery& SqlQuery::operator=( const SqlQuery& other ) {
    m_Query = other.m_Query;

    return *this;
}

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
