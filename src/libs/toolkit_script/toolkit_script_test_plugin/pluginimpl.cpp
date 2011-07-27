//-------------------------------------------------------------------------
/*!
    \file plugininterface.cpp
    \brief
*/

//-------------------------------------------------------------------------

// Include Header File
#include "pluginimpl.h"

// Include Plugin Files
#include "corepackagetestcase.h"
#include "environmenttestcase.h"
#include "registrationclasstestcase.h"
#include "registrationfunctiontestcase.h"
#include "jsqchartestcase.h"

// Include Toolkit Core Files
#include <toolkit/core/library.h>

//-------------------------------------------------------------------------
QString ToolkitScriptPlugin::pluginName() const {
    return "Toolkit Script Plugin";
};

QString ToolkitScriptPlugin::pluginDescription() const {
    return "Tests the Toolkit Script Library";
};

QString ToolkitScriptPlugin::pluginVersion() const {
    return TOOLKIT_VERSION_STR;
};

TestRegisterInterface::SuitePtr ToolkitScriptPlugin::registerTests() const {
    SuitePtr res( new Suite( pluginName() + " test suite" ) );
        
    res->addTest( Suite::item_type( new EnvironmentTestCase() ) );
    res->addTest( Suite::item_type( new RegistrationFunctionTestCase() ) );
    res->addTest( Suite::item_type( new RegistrationClassTestCase() ) );
    res->addTest( Suite::item_type( new CorePackageTestCase() ) );

    // Adding new script engine objects
    res->addTest( Suite::item_type( new JSQCharTestCase() ) );

    return res;
};

Q_EXPORT_PLUGIN2(toolkitscriptplugin, ToolkitScriptPlugin);

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */

