//---------------------------------------------------------------------------------------
/*!
    \file packagehandler.cpp
    \brief
*/

//---------------------------------------------------------------------------------------

// Include Header File
#include "packagehandler.h"

// Include Toolkit Script Files
#include "environment.h"

// Include Toolkit Core Files
#include <toolkit/core/stringformat.h>

//---------------------------------------------------------------------------------------
using namespace Toolkit::Core;
using namespace Toolkit::Script;

//---------------------------------------------------------------------------------------
const QString PackageHandler::IMPORT_FUNCNAME( "import" );
const QString PackageHandler::SETUP_NAMESPACE_FUNCNAME( "setupNameSpace" );

//---------------------------------------------------------------------------------------
PackageHandler::PackageHandler() :
    QObject(),
    m_Packages()
{
};

PackageHandler::PackageHandler( const PackageHandler& other ) :
    QObject(),
    m_Packages( other.m_Packages )
{
};

PackageHandler::~PackageHandler() {
};

PackageHandler::iterator PackageHandler::begin() {
    return m_Packages.begin();
};

PackageHandler::const_iterator PackageHandler::begin() const {
    return m_Packages.begin();
};

PackageHandler::iterator PackageHandler::end() {
    return m_Packages.end();
};

PackageHandler::const_iterator PackageHandler::end() const {
    return m_Packages.end();
};

void PackageHandler::clear() {
    m_Packages.clear();
};

bool PackageHandler::empty() const {
    return m_Packages.empty();
};

void PackageHandler::push_back( const value_type& v ) {
    m_Packages.push_back( v );
};

PackageHandler::size_type PackageHandler::size() const {
    return m_Packages.size();
};

bool PackageHandler::checkPackage( const QUrl& packageName ) const {
    return doCheckPackage( packageName );
};

bool PackageHandler::importPackage( const QUrl& packageName, QScriptContext* ctx, Environment* eng ) const {
    return doImportPackage( packageName, ctx, eng );
};

PackageHandler& PackageHandler::operator=( const PackageHandler& other ) {
    m_Packages = other.m_Packages;

    return *this;
};

bool PackageHandler::doCheckPackage( const QUrl& packageName ) const {
    if( empty() ) {
        return false;
    };

    for( const_iterator it = begin(); it != end(); ++it ) {
        if( (*it)->checkPackage( packageName ) ) {
            return true;
        };
    };

    return false;
};

bool PackageHandler::doImportPackage( const QUrl& packageName, QScriptContext* ctx, Environment* eng ) const {
    if( empty() ) {
        return false;
    };

    bool result = false;
    for( const_iterator it = begin(); it != end(); ++it ) {
        if( (*it)->checkPackage( packageName ) ) {
            AbstractPackage::url_container list = (*it)->extractPackageNames( packageName );
            for( AbstractPackage::url_container::const_iterator listIt = list.begin(); listIt != list.end(); ++listIt ) {
                (*it)->loadPackage( *listIt, ctx, eng );
                result = true;
            };
        };
    };

    return result;
};

QScriptValue PackageHandler::jsImport( QScriptContext* ctx, QScriptEngine* eng ) {
    if( ctx->isCalledAsConstructor() ) {
        return ctx->throwError( StringFormat::format( "The function %s can not be called as a constructor", IMPORT_FUNCNAME ) );
    };

    if( ctx->argumentCount() != 1 ) {
        return ctx->throwError( StringFormat::format( "Wrong number of arguments in call of function %s", IMPORT_FUNCNAME ) );
    };

    if( !ctx->argument( 0 ).isString() ) {
        return ctx->throwError( "Wrong argument type. String was expected." );
    };

    if( !ctx->thisObject().property( IMPORT_FUNCNAME ).isFunction() ) {
        return ctx->throwError( StringFormat::format( "The function %s does not exist on the object %s",
                                                      IMPORT_FUNCNAME, ctx->thisObject().toString() ) );
    };

    PackageHandler* handler = dynamic_cast<PackageHandler*>( ctx->thisObject().property( IMPORT_FUNCNAME ).data().toQObject() );
    if( !handler ) {
        return ctx->throwError( StringFormat::format( "No PackageHandler is associated with the object %s",
                                                      ctx->thisObject().property( IMPORT_FUNCNAME ).toString() ) );
    };

    Environment* envir = dynamic_cast<Environment*>( eng );
    if( !envir ) {
        return ctx->throwError( "This script engine is not a Toolkit::Script::Environment" );
    };

    QUrl url( ctx->argument( 0 ).toString() );
    if( !handler->checkPackage( url ) ) {
        return ctx->throwError( StringFormat::format( "The package %s does not exist.", url.toString() ) );
    };

    if( !handler->importPackage( url, ctx, envir ) ) {
        return ctx->throwError( StringFormat::format( "Error in loading package %s", url.toString() ) );
    };

    return QScriptValue();
};

QScriptValue PackageHandler::jsSetupNameSpace( QScriptContext* ctx, QScriptEngine* ) {
    if( ctx->isCalledAsConstructor() ) {
        return ctx->throwError( StringFormat::format( "The function %s can not be called as a constructor", SETUP_NAMESPACE_FUNCNAME ) );
    };

    if( ctx->argumentCount() != 1 ) {
        return ctx->throwError( StringFormat::format( "Wrong number of arguments in call of function %s", SETUP_NAMESPACE_FUNCNAME ) );
    };

    if( !ctx->argument( 0 ).isString() ) {
        return ctx->throwError( "Wrong argument type. String was expected." );
    };

    return ctx->throwError( StringFormat::format( "The function %s is not implementated yet!", SETUP_NAMESPACE_FUNCNAME ) );
};

QScriptValue PackageHandler::registerFunctions( Environment* eng ) {
    if( !eng ) {
        return QScriptValue();
    };

    QScriptValue funObj = eng->registerFunction( IMPORT_FUNCNAME, jsImport );
    funObj.setData( eng->newQObject( this ) );
    eng->registerFunction( SETUP_NAMESPACE_FUNCNAME, jsSetupNameSpace );

    return funObj;
};

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
