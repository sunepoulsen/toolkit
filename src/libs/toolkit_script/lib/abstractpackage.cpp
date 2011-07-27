//---------------------------------------------------------------------------------------
/*!
    \file abstractpackage.cpp
    \brief
*/

//---------------------------------------------------------------------------------------

// Include Header File
#include "abstractpackage.h"

// Include Toolkit Script Files
#include "environment.h"

//---------------------------------------------------------------------------------------
using namespace Toolkit::Script;

//---------------------------------------------------------------------------------------
/*!
    \brief Empty constructor.
*/
AbstractPackage::AbstractPackage() :
    QObject()
{
};

/*!
    \brief Empty copy constructor.

    \param other Abstract package to make a copy of.
*/
AbstractPackage::AbstractPackage( const AbstractPackage& ) :
    QObject()
{
};

/*!
    \brief Empty destructor.
*/
AbstractPackage::~AbstractPackage() {
};

/*!
    \brief Checks if the packages in \e packageName is supported by this class.

    If the package name is supported the script engine will try to extract the packages name and
    load in turn.

    \param packageName The package name.

    \retval true  The package name is supported.
    \retval false The package name is not supported.
*/
bool AbstractPackage::checkPackage( const QUrl& packageName ) const {
    return doCheckPackage( packageName );
};

/*!
    \brief Extract each package name from a single package name.

    This member has the responsability to extract a package name containing wildcards to single unique package names.
    This may happen if \e packageName equals \e "Toolkit.Core.*" or \e "http://www.sunepoulsen.dk/downloads/toolkit.core.*"

    \param packageName The package name to extract from.

    \return
        A prioritized string list of unique package names.

    \note
        If where exists some dependencies between the packages, dependencies should appear before the depended package name.
*/
AbstractPackage::url_container AbstractPackage::extractPackageNames( const QUrl& packageName ) const {
    return doExtractPackageNames( packageName );
};

/*!
    \brief Loads a package into the script engine.

    \param packageName The name of the package to load.
    \param ctx         The current context in the script engine.
    \param eng         The current script engine.
*/
void AbstractPackage::loadPackage( const QUrl& packageName, QScriptContext* ctx, Environment* eng ) const {
    doLoadPackage( packageName, ctx, eng );
};

/*!
    \brief Empty assignment operator.

    \param other An AbstractPackage to assign.

    \return
        A reference to this instance.
*/
AbstractPackage& AbstractPackage::operator=( const AbstractPackage& ) {
    return *this;
};

/*!
    \brief Sets up a "namespace" with a script object as its base.

    This method is provided for the doLoadPackage() to make it easier to construct
    namespaces to avoid package pollution of the global object.

    \param ns      The namespace names separated with dots.
    \param baseObj The base object. This is normally the global object of the script engine.

    \return
        The object of the "namespace".

    \par Example
    \code
    setupPackage( "Toolkit.Core", engine->globalObject() );
    \endcode
    This will produce a property on the global object with the name "Toolkit". The "Toolkit" property will
    be an Object with a "Core" property. The "Core" property is returned. If a property already exists, it will
    simply be used and \b not \b created.
*/
QScriptValue AbstractPackage::setupPackage( const QString& ns, QScriptValue baseObj ) {
    QStringList names = ns.split( "." );

    QScriptValue obj = baseObj;
    QScriptEngine* eng = baseObj.engine();
    while( !names.isEmpty() ) {
        QString name = names.front();
        QScriptValue v = obj.property( name );
        if( !v.isValid() ) {
            QScriptValue newObj = eng->newObject();
            obj.setProperty( name, newObj );

            obj = newObj;
        }
        else {
            obj = v;
        };
        names.removeFirst();
    };

    return obj;
};

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
