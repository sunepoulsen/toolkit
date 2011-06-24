//---------------------------------------------------------------------------------------
/*!
    \file scriptobject_imp.h
    \brief
*/

//---------------------------------------------------------------------------------------
#ifndef __TOOLKIT_SCRIPT_SCRIPTOBJECT_IMP_H__
#define __TOOLKIT_SCRIPT_SCRIPTOBJECT_IMP_H__

//---------------------------------------------------------------------------------------
//      Implementation of template functions.
//---------------------------------------------------------------------------------------

template< typename T >
ScriptObject<T>::ScriptObject( T* data, ObjectOwnership ownership, bool constObj ) :
    m_Ownership( ownership ),
    m_Const( constObj ),
    m_Data( data ),
    m_SharedData()
{
};

template< typename T >
ScriptObject<T>::ScriptObject( const QSharedPointer<T>& data, bool constObj ) :
    m_Ownership( AppOwnership ),
    m_Const( constObj ),
    m_Data( NULL ),
    m_SharedData( data )
{
};

template< typename T >
ScriptObject<T>::~ScriptObject() {
    detach();
}

template< typename T >
void ScriptObject<T>::setOwnership( ObjectOwnership newOwnership ) {
    m_Ownership = newOwnership;
}

template< typename T >
bool ScriptObject<T>::getConst() const {
    return m_Const;
}

template< typename T >
void ScriptObject<T>::setConst( bool newConst ) {
    m_Const = newConst;
}

template< typename T >
const T* ScriptObject<T>::getConstData() const {
    if( m_Data ) {
        return m_Data;
    }

    return (const T*)( m_SharedData.data() );
}

template< typename T >
const T* ScriptObject<T>::getData() const {
    if( m_Data ) {
        return m_Data;
    }

    return (const T*)( m_SharedData.data() );
}

template< typename T >
T* ScriptObject<T>::getData( bool ignoreConst ) {
    if( !ignoreConst && getConst() ) {
        throw Toolkit::Core::Exception( SOURCELINE, "Try to access non-const member on const object." );
    }

    if( m_Data ) {
        return m_Data;
    }

    return m_SharedData.data();
}

template< typename T >
void ScriptObject<T>::setData( T* newData, ObjectOwnership newOwnership, bool ignoreConst ) {
    if( !ignoreConst && getConst() ) {
        throw Toolkit::Core::Exception( SOURCELINE, "Try to access non-const member on const object." );
    }
    detach();

    m_Data = newData;
    m_SharedData = QSharedPointer<T>();
    m_Ownership = newOwnership;
}

template< typename T >
const QSharedPointer<T>& ScriptObject<T>::getConstSharedData() const {
    return m_SharedData;
}

template< typename T >
const QSharedPointer<T>& ScriptObject<T>::getSharedData() const {
    return m_SharedData;
}

template< typename T >
QSharedPointer<T>& ScriptObject<T>::getSharedData( bool ignoreConst ) {
    if( !ignoreConst && getConst() ) {
        throw Toolkit::Core::Exception( SOURCELINE, "Try to access non-const member on const object." );
    }

    return m_SharedData;
}

template< typename T >
void ScriptObject<T>::setSharedData( const QSharedPointer<T>& newSharedData, bool ignoreConst ) {
    if( !ignoreConst && getConst() ) {
        throw Toolkit::Core::Exception( SOURCELINE, "Try to access non-const member on const object." );
    }
    detach();

    m_Data = NULL;
    m_SharedData = newSharedData;
    m_Ownership = AppOwnership;
}

template< typename T >
void ScriptObject<T>::setSharedData( T* newSharedData, bool ignoreConst ) {
    if( !ignoreConst && getConst() ) {
        throw Toolkit::Core::Exception( SOURCELINE, "Try to access non-const member on const object." );
    }

    detach();

    m_Data = NULL;
    m_SharedData = newSharedData;
    m_Ownership = AppOwnership;
}

template< typename T >
void ScriptObject<T>::detach() {
    if( m_Data && m_Ownership == ScriptOwnership ) {
        delete m_Data;
        m_Data = NULL;
    }
}

#endif

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
