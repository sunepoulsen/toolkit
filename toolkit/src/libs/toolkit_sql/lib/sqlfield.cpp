//---------------------------------------------------------------------------------------
/*!
    \file sqlfield.h
    \brief
*/

//---------------------------------------------------------------------------------------

// Include Header File
#include "sqlfield.h"

//---------------------------------------------------------------------------------------
using namespace Toolkit::Sql;

//---------------------------------------------------------------------------------------
SqlField::SqlField( FieldType fieldType, const QString& fieldName, QVariant::Type valueType ) :
    m_FieldType( fieldType ),
    m_Name( fieldName ),
    m_IsReadOnly( false ),
    m_Length( -1 ),
    m_Precision( -1 ),
    m_Required( QSqlField::Optional ),
    m_DefaultValue( valueType ),
    m_AutoValue( false ),
    m_IsGenerated( false ),
    m_ValueType( valueType ),
    m_Value( valueType )
{
    if( m_FieldType == FT_JSDOC ) {
        m_DefaultValue = QVariant( QVariant::Map );
        m_ValueType = QVariant::Map;
        m_Value = QVariant( QVariant::Map );
    }
}

SqlField::SqlField( const QSqlField& other ) :
    m_FieldType( FT_GENERIC ),
    m_Name(),
    m_IsReadOnly( false ),
    m_Length( -1 ),
    m_Precision( -1 ),
    m_Required( QSqlField::Optional ),
    m_DefaultValue(),
    m_AutoValue( false ),
    m_IsGenerated( false ),
    m_ValueType( QVariant::Invalid ),
    m_Value()
{
    operator=( other );
}

SqlField::SqlField( const SqlField& other ) :
    m_FieldType( other.m_FieldType ),
    m_Name( other.m_Name ),
    m_IsReadOnly( other.m_IsReadOnly ),
    m_Length( other.m_Length ),
    m_Precision( other.m_Precision ),
    m_Required( other.m_Required ),
    m_DefaultValue( other.m_DefaultValue ),
    m_AutoValue( other.m_AutoValue ),
    m_IsGenerated( other.m_IsGenerated ),
    m_ValueType( other.m_ValueType ),
    m_Value( other.m_Value )
{
}

SqlField::~SqlField() {
}

SqlField::FieldType SqlField::getFieldType() const {
    return m_FieldType;
}

void SqlField::setFieldType( FieldType newFieldType ) {
    m_FieldType = newFieldType;
}

const QString& SqlField::getName() const {
    return m_Name;
}

void SqlField::setName( const QString& newName ) {
    m_Name = newName;
}

bool SqlField::getReadOnly() const {
    return m_IsReadOnly;
}

void SqlField::setReadOnly( bool newReadOnly ) {
    m_IsReadOnly = newReadOnly;
}

int SqlField::getLength() const {
    return m_Length;
}

void SqlField::setLength( int newLength ) {
    m_Length = newLength;
}

int SqlField::getPrecision() const {
    return m_Precision;
}

void SqlField::setPrecision( int newPrecision ) {
    m_Precision = newPrecision;
}

QSqlField::RequiredStatus SqlField::getRequired() const {
    return m_Required;
}
void SqlField::setRequired( QSqlField::RequiredStatus newRequired ) {
    m_Required = newRequired;
}

const QVariant& SqlField::getDefaultValue() const {
    return m_DefaultValue;
}

void SqlField::setDefaultValue( const QVariant& newDefaultValue ) {
    m_DefaultValue = newDefaultValue;
}

bool SqlField::getAutoValue() const {
    return m_AutoValue;
}

void SqlField::setAutoValue( bool newAutoValue ) {
    m_AutoValue = newAutoValue;
}

bool SqlField::getGenerated() const {
    return m_IsGenerated;
}

void SqlField::setGenerated( bool newGenerated ) {
    m_IsGenerated = newGenerated;
}

QVariant::Type SqlField::getValueType() const {
    return m_ValueType;
}
void SqlField::setValueType( QVariant::Type newValueType ) {
    m_ValueType = newValueType;
}

const QVariant& SqlField::getValue() const {
    return m_Value;
}

void SqlField::setValue( const QVariant& newValue ) {
    m_Value = newValue;
}

bool SqlField::hasField( const QString& fieldName ) const {
    if( m_FieldType != FT_JSDOC ) {
        return false;
    }

    jsdoc_type jsdoc = getValue().toMap();
    return jsdoc.find( fieldName ) != jsdoc.end();
}

SqlField& SqlField::operator=( const SqlField& other ) {
    m_FieldType = other.m_FieldType;
    m_Name = other.m_Name;
    m_IsReadOnly = other.m_IsReadOnly;
    m_Length = other.m_Length;
    m_Precision = other.m_Precision;
    m_Required = other.m_Required;
    m_DefaultValue = other.m_DefaultValue;
    m_AutoValue = other.m_AutoValue;
    m_IsGenerated = other.m_IsGenerated;
    m_ValueType = other.m_ValueType;
    m_Value = other.m_Value;

    return *this;
}

SqlField& SqlField::operator=( const QSqlField& other ) {
    m_FieldType = FT_GENERIC;
    m_Name = other.name();
    m_IsReadOnly = other.isReadOnly();
    m_Length = other.length();
    m_Precision = other.precision();
    m_Required = other.requiredStatus();
    m_DefaultValue = other.defaultValue();
    m_AutoValue = other.isAutoValue();
    m_IsGenerated = other.isGenerated();
    m_ValueType = other.type();
    m_Value = other.value();

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
