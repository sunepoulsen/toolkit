//---------------------------------------------------------------------------------------
/*!
    \file abstractregistrationobject.cpp
    \brief
*/

//---------------------------------------------------------------------------------------

// Include Header File
#include "abstractregistrationobject.h"

//---------------------------------------------------------------------------------------
using namespace Toolkit::Script;

//---------------------------------------------------------------------------------------
AbstractRegistrationObject::AbstractRegistrationObject( const QString& name ) :
    m_ObjectName( name )
{
};

AbstractRegistrationObject::AbstractRegistrationObject( const AbstractRegistrationObject& other ) :
    m_ObjectName( other.m_ObjectName )
{
};

AbstractRegistrationObject::~AbstractRegistrationObject() {
};

const QString& AbstractRegistrationObject::getObjectName() const {
    return m_ObjectName;
};

void AbstractRegistrationObject::setObjectName( const QString& newObjectName ) {
    m_ObjectName = newObjectName;
};

QScriptValue AbstractRegistrationObject::registerObject( QScriptValue thisObj, Environment* eng ) const {
    return doRegisterObject( thisObj, eng );
};

AbstractRegistrationObject& AbstractRegistrationObject::operator=( const AbstractRegistrationObject& other ) {
    m_ObjectName = other.m_ObjectName;

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

