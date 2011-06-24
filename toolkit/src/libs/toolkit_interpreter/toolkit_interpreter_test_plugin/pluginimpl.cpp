//-------------------------------------------------------------------------
/*!
    \file plugininterface.cpp
    \brief
*/

//-------------------------------------------------------------------------

// Include Header File
#include "pluginimpl.h"

// Include Toolkit Core Files
#include <toolkit/core/library.h>

//-------------------------------------------------------------------------
QString ToolkitInterpreterPlugin::pluginName() const {
    return "Toolkit Interpreter Plugin";
};

QString ToolkitInterpreterPlugin::pluginDescription() const {
    return "Tests the Toolkit Interpreter Library";
};

QString ToolkitInterpreterPlugin::pluginVersion() const {
    return TOOLKIT_VERSION_STR;
};

TestRegisterInterface::SuitePtr ToolkitInterpreterPlugin::registerTests() const {
    SuitePtr res( new Suite( pluginName() + " test suite" ) );
    
    return res;
};

Q_EXPORT_PLUGIN2(toolkitinterpreterplugin, ToolkitInterpreterPlugin);

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */

