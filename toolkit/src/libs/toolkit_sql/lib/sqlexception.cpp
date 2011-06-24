//---------------------------------------------------------------------------------------
/*!
    \file sqlexception.cpp
    \brief
*/

//---------------------------------------------------------------------------------------

// Include Header File
#include "sqlexception.h"

// Include Qt Files
#include <QSqlDatabase>
#include <QSqlQuery>

//---------------------------------------------------------------------------------------
using namespace Toolkit::Core;
using namespace Toolkit::Sql;

//---------------------------------------------------------------------------------------
SqlException::SqlException( const Toolkit::Core::SourceLine& srcLine, const QString& message ) :
    Exception( srcLine, message ),
    m_SqlError(),
    m_SqlQuery()
{
}

SqlException::SqlException( const Toolkit::Core::SourceLine& srcLine, const QSqlDatabase& db ) :
    Exception( srcLine, db.lastError().databaseText() ),
    m_SqlError( db.lastError() ),
    m_SqlQuery()
{
}

SqlException::SqlException( const Toolkit::Core::SourceLine& srcLine, const QSqlQuery& query ) :
    Exception( srcLine, query.lastError().databaseText() ),
    m_SqlError( query.lastError() ),
    m_SqlQuery( query.executedQuery() )
{
}

SqlException::SqlException( const Toolkit::Core::SourceLine& srcLine, const QSqlError& sqlError ) :
    Exception( srcLine, sqlError.databaseText() ),
    m_SqlError( sqlError ),
    m_SqlQuery()
{
}

SqlException::SqlException( const SqlException& other ) :
    Exception( other ),
    m_SqlError( other.m_SqlError ),
    m_SqlQuery( other.m_SqlQuery )
{
}

SqlException::~SqlException() {
}

const QSqlError& SqlException::sqlError() const {
    return m_SqlError;
}

const QString& SqlException::sqlQuery() const {
    return m_SqlQuery;
}

SqlException& SqlException::operator=( const SqlException& other ) {
    Exception::operator=( other );
    m_SqlError = other.m_SqlError;
    m_SqlQuery = other.m_SqlQuery;

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
