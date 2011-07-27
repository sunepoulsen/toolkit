//-------------------------------------------------------------------------
/*!
    \file plugininterface.cpp
    \brief
*/

//-------------------------------------------------------------------------

// Include Header File
#include "pluginimpl.h"

// Include Plugin Files
#include "basictestcase.h"

// Include Toolkit Core Files
#include <toolkit/core/library.h>

//-------------------------------------------------------------------------
QString ToolkitTestPlugin::pluginName() const {
    return "Toolkit Test Plugin";
};

QString ToolkitTestPlugin::pluginDescription() const {
    return "Tests the Toolkit Test Library";
};

QString ToolkitTestPlugin::pluginVersion() const {
    return TOOLKIT_VERSION_STR;
};

TestRegisterInterface::SuitePtr ToolkitTestPlugin::registerTests() const {
    SuitePtr res( new Suite( pluginName() + " test suite" ) );
    
    res->addTest( Suite::item_type( new BasicTestCase() ) );
    res->addTest( Suite::item_type( new MacroTestCase() ) );
    
    return res;
};

Q_EXPORT_PLUGIN2(toolkittestplugin, ToolkitTestPlugin);

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
