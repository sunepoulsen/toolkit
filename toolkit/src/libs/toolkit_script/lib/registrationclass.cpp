//---------------------------------------------------------------------------------------
/*!
    \file registrationclass.cpp
    \brief
*/

//---------------------------------------------------------------------------------------

// Include Header File
#include "registrationclass.h"

// Include Toolkit Script Files
#include "environment.h"

// Include Toolkit Core Files
#include <toolkit/core/log.h>

//---------------------------------------------------------------------------------------
using namespace Toolkit::Core;
using namespace Toolkit::Script;

//---------------------------------------------------------------------------------------
const QString RegistrationClass::NAMESPACE_SEP( "::" );

//---------------------------------------------------------------------------------------
RegistrationClass::RegistrationClass( const QString& name ) :
    AbstractRegistrationObject( name ),
    m_Constructor( NULL ),
    m_MetaObject( NULL ),
    m_DynamicFunctions(),
    m_StaticProperties(),
    m_StaticFunctions()
{
};

RegistrationClass::RegistrationClass( const RegistrationClass& other ) :
    AbstractRegistrationObject( other ),
    m_Constructor( other.m_Constructor ),
    m_MetaObject( other.m_MetaObject ),
    m_DynamicFunctions( other.m_DynamicFunctions ),
    m_StaticProperties( other.m_StaticProperties ),
    m_StaticFunctions( other.m_StaticFunctions )
{
};
RegistrationClass::~RegistrationClass() {
};

QScriptEngine::FunctionSignature RegistrationClass::getConstructor() const {
    return m_Constructor;
};

void RegistrationClass::setConstructor( QScriptEngine::FunctionSignature newConstructor ) {
    m_Constructor = newConstructor;
};

const QMetaObject* RegistrationClass::getMetaObject() const {
    return m_MetaObject;
};

void RegistrationClass::setMetaObject( const QMetaObject* metaObject ) {
    m_MetaObject = metaObject;
};

RegistrationClass::functions_type& RegistrationClass::getDynamicFunctions() {
    return m_DynamicFunctions;
};

const RegistrationClass::functions_type& RegistrationClass::getDynamicFunctions() const {
    return m_DynamicFunctions;
};

void RegistrationClass::setDynamicFunctions( const functions_type& newDynamicFunctions ) {
    m_DynamicFunctions = newDynamicFunctions;
};

RegistrationClass::properties_type& RegistrationClass::getStaticProperties() {
    return m_StaticProperties;
};

const RegistrationClass::properties_type& RegistrationClass::getStaticProperties() const {
    return m_StaticProperties;
};

void RegistrationClass::setStaticProperties( const properties_type& newStaticProperties ) {
    m_StaticProperties = newStaticProperties;
};

RegistrationClass::functions_type& RegistrationClass::getStaticFunctions() {
    return m_StaticFunctions;
};

const RegistrationClass::functions_type& RegistrationClass::getStaticFunctions() const {
    return m_StaticFunctions;
};

void RegistrationClass::setStaticFunctions( const functions_type& newStaticFunctions ) {
    m_StaticFunctions = newStaticFunctions;
};

RegistrationClass& RegistrationClass::operator=( const RegistrationClass& other ) {
    AbstractRegistrationObject::operator=( other );
    m_Constructor = other.m_Constructor;
    m_MetaObject = other.m_MetaObject;
    m_DynamicFunctions = other.m_DynamicFunctions;
    m_StaticProperties = other.m_StaticProperties;
    m_StaticFunctions = other.m_StaticFunctions;

    return *this;
};

/*!
    \brief Converts a class name from a QMetaObject to a soutable name in a script.

    Class names from QObject's may contain namespace's. These namespaces are removed from
    the class name.

    For instance
    \code
    QString s = RegistrationClass::toClassName( "Toolkit::Core::Log" ); // s == "Log"
    \endcode

    \param className The class name to convert.

    \return The new class name.
*/
QString RegistrationClass::toClassName( const QString& className ) {
    int pos = className.lastIndexOf( NAMESPACE_SEP );

    if( pos > -1 ) {
        return className.mid( pos );
    };

    return className;
};

QScriptValue RegistrationClass::doRegisterObject( QScriptValue thisObj, Environment* eng ) const {
    Log log( Log::LT_TRACE, "", false );

    if( !eng ) {
        return QScriptValue();
    };

    // Register class
    QScriptValue classObj;
    if( m_MetaObject && m_Constructor ) {
        classObj = eng->registerClass( thisObj, getObjectName(), m_MetaObject, m_Constructor );
    }
    else {
        classObj = thisObj.property( getObjectName() );
    };

    // Register static properties on the class object
    for( properties_type::const_iterator it = m_StaticProperties.begin(); it != m_StaticProperties.end(); ++it ) {
        if( classObj.property( it->first ).isValid() ) {
            log.write( Log::LT_WARNING, "There already exists a property with name %s on the object %s", it->first, classObj.toString() );
        }
        else {
            classObj.setProperty( it->first, it->second );
        };
    };

    registerFunctions( m_DynamicFunctions, classObj.property( Environment::PROTOTYPE_PROPERTY_NAME ), eng );
    registerFunctions( m_StaticFunctions, classObj, eng );

    return classObj;
};

bool RegistrationClass::registerFunctions( const functions_type& funcs, QScriptValue thisObj, Environment* eng ) const {
    Log log( Log::LT_TRACE, "", false );

    if( !( thisObj.isValid() && eng ) ) {
        return false;
    };

    bool result = true;

    // Register static functions on the class object
    for( functions_type::const_iterator it = funcs.begin(); it != funcs.end(); ++it ) {
        if( thisObj.property( it->getObjectName() ).isValid() ) {
            log.write( Log::LT_WARNING, "There already exists a property with name %s on the object %s", it->getObjectName(), thisObj.toString() );
            result = false;
        }
        else {
            it->registerObject( thisObj, eng );
        };
    };

    return result;
};

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
