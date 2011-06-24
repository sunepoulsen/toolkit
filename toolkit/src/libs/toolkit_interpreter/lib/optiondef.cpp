//---------------------------------------------------------------------------------------
/*!
    \file optiondef.cpp
    \brief 
*/

//---------------------------------------------------------------------------------------

// Include Header File
#include "optiondef.h"

//---------------------------------------------------------------------------------------
using namespace Toolkit::Interpreter;

//---------------------------------------------------------------------------------------
OptionDef::OptionDef( const QString& id, const QString& shortName, const QString& longName, const QString& descr ) :
    m_Id( id ),
    m_ShortName( shortName ),
    m_LongName( longName ),
    m_Description( descr )
{
};

OptionDef::OptionDef( const OptionDef& other ) :
    m_Id( other.m_Id ),
    m_ShortName( other.m_ShortName ),
    m_LongName( other.m_LongName ),
    m_Description( other.m_Description )
{
};

OptionDef::~OptionDef() {
};

const QString& OptionDef::getId() const {
    return m_Id;
};

void OptionDef::setId( const QString& newId ) {
    m_Id = newId;
};

const QString& OptionDef::getShortName() const {
    return m_ShortName;
};

void OptionDef::setShortName( const QString& newShortName ) {
    m_ShortName = newShortName;
};

const QString& OptionDef::getLongName() const {
    return m_LongName;
};

void OptionDef::setLongName( const QString& newLongName ) {
    m_LongName = newLongName;
};

const QString& OptionDef::getDescripton() const {
    return m_Description;
};

void OptionDef::setDescription( const QString& newDescription ) {
    m_Description = newDescription;
};

bool OptionDef::getDefaultValue() const {
    return m_DefaultValue;
};

void OptionDef::setDefaultValue( bool newDefaultValue ) {
    m_DefaultValue = newDefaultValue;
};

OptionDef& OptionDef::operator=( const OptionDef& other ) {
    m_Id = other.m_Id;
    m_ShortName = other.m_ShortName;
    m_LongName = other.m_LongName;
    m_Description = other.m_Description;
    
    return *this;
};

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
