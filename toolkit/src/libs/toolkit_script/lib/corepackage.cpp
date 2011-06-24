//---------------------------------------------------------------------------------------
/*!
    \file corepackage.cpp
    \brief
*/

//---------------------------------------------------------------------------------------

// Include Header File
#include "corepackage.h"

// include Toolkit Core Files
#include <toolkit/core/log.h>

// Include Toolkit Script Files
#include "environment.h"

//---------------------------------------------------------------------------------------
using namespace Toolkit::Core;
using namespace Toolkit::Script;

//---------------------------------------------------------------------------------------
/*!
    \brief Constructs a CorePackage with a namespace.

    \param ns The name space.
*/
CorePackage::CorePackage( const QString& ns ) :
    AbstractPackage(),
    m_SchemeName(),
    m_NameSpace( ns ),
    m_Items()
{
};

/*!
    \brief Copy constructor.

    \param other CorePackage to make a copy of.
*/
CorePackage::CorePackage( const CorePackage& other ) :
    AbstractPackage( other ),
    m_SchemeName( other.m_SchemeName ),
    m_NameSpace( other.m_NameSpace ),
    m_Items( other.m_Items )
{
};

/*!
    \brief Empty destructor.
*/
CorePackage::~CorePackage() {
};

const QString& CorePackage::getSchemeName() const {
    return m_SchemeName;
};

void CorePackage::setSchemeName( const QString& newSchemeName ) {
    m_SchemeName = newSchemeName;
};

const QString& CorePackage::getNameSpace() const {
    return m_NameSpace;
};

void CorePackage::setNameSpace( const QString& newNameSpace ) {
    m_NameSpace = newNameSpace;
};

CorePackage::iterator CorePackage::begin() {
    return m_Items.begin();
};

CorePackage::const_iterator CorePackage::begin() const {
    return m_Items.begin();
};

CorePackage::iterator CorePackage::end() {
    return m_Items.end();
};

CorePackage::const_iterator CorePackage::end() const {
    return m_Items.end();
};

void CorePackage::clear() {
    m_Items.clear();
};

bool CorePackage::empty() const {
    return m_Items.empty();
};

void CorePackage::push_back( const value_type& v ) {
    m_Items.push_back( v );
};

CorePackage::size_type CorePackage::size() const {
    return m_Items.size();
};

CorePackage& CorePackage::operator=( const CorePackage& other ) {
    AbstractPackage::operator=( other );
    m_SchemeName = other.m_SchemeName;
    m_NameSpace = other.m_NameSpace;
    m_Items = other.m_Items;

    return *this;
};

bool CorePackage::doCheckPackage( const QUrl& packageName ) const {
    if( !getSchemeName().isEmpty() && getSchemeName() != packageName.scheme() ) {
        return false;
    };

    if( !packageName.path().startsWith( getNameSpace() ) ) {
        return false;
    };

    QRegExp rx( packageName.path() );
    if( rx.pattern().startsWith( "/" ) ) {
        rx.setPattern( rx.pattern().mid( 1 ) );
    };
    rx.setPatternSyntax( QRegExp::Wildcard );

    for( const_iterator it = begin(); it != end(); ++it ) {
        if( rx.exactMatch( fullPackageName( it ) ) ) {
            return true;
        };
    };

    return false;
};

CorePackage::url_container CorePackage::doExtractPackageNames( const QUrl& packageName ) const {
    url_container list;

    if( packageName.path().isEmpty() ) {
        return list;
    };

    if( !getSchemeName().isEmpty() && getSchemeName() != packageName.scheme() ) {
        return list;
    };

    if( !packageName.path().startsWith( getNameSpace() ) ) {
        return list;
    };

    QRegExp rx( packageName.path() );
    if( rx.pattern().startsWith( "/" ) ) {
        rx.setPattern( rx.pattern().mid( 1 ) );
    };
    rx.setPatternSyntax( QRegExp::Wildcard );

    for( const_iterator it = begin(); it != end(); ++it ) {
        if( rx.indexIn( fullPackageName( it ) ) > -1 ) {
            QUrl newUrl( packageName );

            newUrl.setPath( fullPackageName( it ) );
            list.push_back( newUrl );
        };
    };

    return list;
};

void CorePackage::doLoadPackage( const QUrl& packageName, QScriptContext*, Environment* eng ) const {
    for( const_iterator it = begin(); it != end(); ++it ) {
        if( fullPackageName( it ) == packageName.path() ) {
            QScriptValue obj = eng->globalObject();
            if( !getNameSpace().isEmpty() ) {
                obj = setupPackage( getNameSpace(), obj );
            };

            (*it)->registerObject( obj, eng );
            return;
        };
    };
};

QString CorePackage::fullPackageName( const_iterator it ) const {
    if( getNameSpace().isEmpty() ) {
        return (*it)->getObjectName();
    };

    return getNameSpace() + "." + (*it)->getObjectName();
};

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
