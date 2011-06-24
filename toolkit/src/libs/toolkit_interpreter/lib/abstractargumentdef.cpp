//---------------------------------------------------------------------------------------
/*!
    \file abstractargumentdef.cpp
    \brief 
*/

//---------------------------------------------------------------------------------------

// Include Header File
#include "abstractargumentdef.h"

//---------------------------------------------------------------------------------------
using namespace Toolkit::Interpreter;

//---------------------------------------------------------------------------------------
AbstractArgumentDef::AbstractArgumentDef( const QString& name, const QString& descr ) :
    m_Name( name ),
    m_Description( descr ),
    m_Required( false )
{
};

AbstractArgumentDef::AbstractArgumentDef( const AbstractArgumentDef& other ) :
    m_Name( other.m_Name ),
    m_Description( other.m_Description ),
    m_Required( other.m_Required )
{
};

AbstractArgumentDef::~AbstractArgumentDef() {
};

const QString& AbstractArgumentDef::getName() const {
    return m_Name;
};

void AbstractArgumentDef::setName( const QString& newName ) {
    m_Name = newName;
};

const QString& AbstractArgumentDef::getDescripton() const {
    return m_Description;
};

void AbstractArgumentDef::setDescription( const QString& newDescription ) {
    m_Description = newDescription;
};

bool AbstractArgumentDef::getRequired() const {
    return m_Required;
};

void AbstractArgumentDef::setRequired( bool newRequired ) {
    m_Required = newRequired;
};

bool AbstractArgumentDef::isRequired() const {
    return getRequired();
};

AbstractArgumentDef& AbstractArgumentDef::operator=( const AbstractArgumentDef& other ) {
    m_Name = other.m_Name;
    m_Description = other.m_Description;
    m_Required = other.m_Required;
    
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
