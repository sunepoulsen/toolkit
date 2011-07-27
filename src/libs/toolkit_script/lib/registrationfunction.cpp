//---------------------------------------------------------------------------------------
/*!
    \file registrationfunction.cpp
    \brief
*/

//---------------------------------------------------------------------------------------

// Include Header File
#include "registrationfunction.h"

// Include Toolkit Script Files
#include "environment.h"


//---------------------------------------------------------------------------------------
using namespace Toolkit::Script;

//---------------------------------------------------------------------------------------
RegistrationFunction::RegistrationFunction( const QString& name, QScriptEngine::FunctionSignature func, const QScriptValue::PropertyFlags& flags ) :
    AbstractRegistrationObject( name ),
    m_Function( func ),
    m_Flags( flags )
{
};

RegistrationFunction::RegistrationFunction( const RegistrationFunction& other ) :
    AbstractRegistrationObject( other ),
    m_Function( other.m_Function ),
    m_Flags( other.m_Flags )
{
};

RegistrationFunction::~RegistrationFunction() {
};

QScriptEngine::FunctionSignature RegistrationFunction::getFunction() const {
    return m_Function;
};

void RegistrationFunction::setFunction( QScriptEngine::FunctionSignature newFunction ) {
    m_Function = newFunction;
};

QScriptValue::PropertyFlags RegistrationFunction::getFlags() const {
    return m_Flags;
};

void RegistrationFunction::setFlags( QScriptValue::PropertyFlags newFlags ) {
    m_Flags = newFlags;
};

RegistrationFunction& RegistrationFunction::operator=( const RegistrationFunction& other ) {
    AbstractRegistrationObject::operator=( other );
    m_Function = other.m_Function;
    m_Flags = other.m_Flags;

    return *this;
};

QScriptValue RegistrationFunction::doRegisterObject( QScriptValue thisObj, Environment* eng ) const {
    if( !eng ) {
        return QScriptValue();
    };

    return eng->registerFunction( thisObj, getObjectName(), m_Function, m_Flags );
};

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
