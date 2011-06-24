//---------------------------------------------------------------------------------------
/*!
    \file abstractoperation.cpp
    \brief 
*/

//---------------------------------------------------------------------------------------

// Include Header File
#include "abstractoperation.h"

//---------------------------------------------------------------------------------------
using namespace Toolkit::Sql;

//---------------------------------------------------------------------------------------
AbstractOperation::AbstractOperation() :
    QObject(),
    m_Name(),
    m_Description(),
    m_Database()
{
};

AbstractOperation::~AbstractOperation() {
};

const QString& AbstractOperation::getName() const {
    return m_Name;
};

void AbstractOperation::setName( const QString& newName ) {
    m_Name = newName;
};

const QString& AbstractOperation::getDescription() const {
    return m_Description;
};

void AbstractOperation::setDescription( const QString& newDescription ) {
    m_Description = newDescription;
};

const QSqlDatabase& AbstractOperation::getDatabase() const {
    return m_Database;
};

void AbstractOperation::setDatabase( const QSqlDatabase& newDatabase ) {
    m_Database = newDatabase;
};

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
