//-------------------------------------------------------------------------
/*!
    \file plugininterface.cpp
    \brief
*/

//-------------------------------------------------------------------------

// Include Header File
#include "pluginimpl.h"

// Include Plugin Files
#include "abstractresourcetestcase.h"
#include "genericresourcetestcase.h"
#include "groupresourcetestcase.h"
#include "resourcebundletestcase.h"
#include "resourcerepositorytestcase.h"

// Include Toolkit Core Files
#include <toolkit/core/library.h>

//-------------------------------------------------------------------------
QString ToolkitResourcePlugin::pluginName() const {
    return "Toolkit Resource Plugin";
};

QString ToolkitResourcePlugin::pluginDescription() const {
    return "Tests the Toolkit Resource Library";
};

QString ToolkitResourcePlugin::pluginVersion() const {
    return TOOLKIT_VERSION_STR;
};

TestRegisterInterface::SuitePtr ToolkitResourcePlugin::registerTests() const {
    SuitePtr res( new Suite( pluginName() + " test suite" ) );
    Suite* suiteModule = NULL;

    // Create suite for tests of resource types.
    suiteModule = new Suite( "Resource types" );
    suiteModule->addTest( Suite::item_type( new AbstractResourceTestCase() ) );
    suiteModule->addTest( Suite::item_type( new GenericResourceTestCase() ) );
    suiteModule->addTest( Suite::item_type( new GroupResourceTestCase() ) );
    res->addTest( Suite::item_type( suiteModule ) );

    // Create suite for tests of resource repositories.
    suiteModule = new Suite( "Resource repositories" );
    suiteModule->addTest( Suite::item_type( new ResourceBundleTestCase() ) );
    suiteModule->addTest( Suite::item_type( new ResourceRepositoryTestCase() ) );
    res->addTest( Suite::item_type( suiteModule ) );

    return res;
};

Q_EXPORT_PLUGIN2(toolkitresourceplugin, ToolkitResourcePlugin);

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */

