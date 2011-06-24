//---------------------------------------------------------------------------------------
/*!
    \file sqlfielddef.cpp
    \brief
*/

//---------------------------------------------------------------------------------------

// Include Header File
#include "sqlfielddef.h"

//---------------------------------------------------------------------------------------
using namespace Toolkit::Sql;

//---------------------------------------------------------------------------------------
SqlFieldDef::SqlFieldDef() {
}

SqlFieldDef::SqlFieldDef( const SqlFieldDef& ) {
}

SqlFieldDef::~SqlFieldDef() {
}

const QString& SqlFieldDef::getName() const {
    return m_Name;
}

void SqlFieldDef::setName( const QString& newName ) {
    m_Name = newName;
}

SqlFieldDef::FieldType SqlFieldDef::getFieldType() const {
    return m_Type;
}

void SqlFieldDef::setFieldType( FieldType newFieldType ) {
    m_Type = newFieldType;
}

int SqlFieldDef::getLength() const {
    return m_Length;
}

void SqlFieldDef::setLength( int newLength ) {
    m_Length = newLength;
}

int SqlFieldDef::getPrecision() const {
    return m_Precision;
}

void SqlFieldDef::setPrecision( int newPrecision ) {
    m_Precision = newPrecision;
}

QSqlField::RequiredStatus SqlFieldDef::getRequired() const {
    return m_Required;
}

void SqlFieldDef::setRequired( QSqlField::RequiredStatus newRequired ) {
    m_Required = newRequired;
}

const QVariant& SqlFieldDef::getDefaultValue() const {
    return m_DefaultValue;
}

void SqlFieldDef::setDefaultValue( const QVariant& newDefaultValue ) {
    m_DefaultValue = newDefaultValue;
}

SqlFieldDef& SqlFieldDef::operator=( const SqlFieldDef& ) {
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
