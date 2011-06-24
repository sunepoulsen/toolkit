//---------------------------------------------------------------------------------------
/*!
    \file sqldatabase.cpp
    \brief
*/

//---------------------------------------------------------------------------------------

// Include Header File
#include "sqldatabase.h"

//---------------------------------------------------------------------------------------
using namespace Toolkit::Sql;

//---------------------------------------------------------------------------------------
SqlDatabase::SqlDatabase() :
    QObject(),
    m_Database()
{
}

SqlDatabase::SqlDatabase( const SqlDatabase& other ) :
    QObject(),
    m_Database( other.m_Database )
{
}

SqlDatabase::~SqlDatabase() {
}

QSqlDatabase& SqlDatabase::getDatabase() {
    return m_Database;
}

const QSqlDatabase& SqlDatabase::getDatabase() const {
    return m_Database;
}

SqlDatabase& SqlDatabase::operator=( const SqlDatabase& other ) {
    m_Database = other.m_Database;

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
