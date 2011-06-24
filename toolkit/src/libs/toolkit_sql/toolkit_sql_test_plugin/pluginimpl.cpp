//-------------------------------------------------------------------------
/*!
    \file plugininterface.cpp
    \brief
*/

//-------------------------------------------------------------------------

// Include Header File
#include "pluginimpl.h"

// Include Toolkit Sql Test Plugin Files
#include "abstractoperationtestcase.h"
#include "blobdbtestcase.h"

// Include Toolkit Core Files
#include <toolkit/core/library.h>

//-------------------------------------------------------------------------
QString ToolkitSqlPlugin::pluginName() const {
    return "Toolkit Sql Plugin";
};

QString ToolkitSqlPlugin::pluginDescription() const {
    return "Tests the Toolkit Sql Library";
};

QString ToolkitSqlPlugin::pluginVersion() const {
    return TOOLKIT_VERSION_STR;
};

TestRegisterInterface::SuitePtr ToolkitSqlPlugin::registerTests() const {
    SuitePtr res( new Suite( pluginName() + " test suite" ) );
    Suite* suiteModule = NULL;

    // Create suite Qt and OS tests
    suiteModule = new Suite( "Database operations" );
    suiteModule->addTest( Suite::item_type( new AbstractOperationTestCase() ) );
    //suiteModule->addTest( Suite::item_type( new BlobDbTestCase() ) );
    res->addTest( Suite::item_type( suiteModule ) );

    return res;
};

Q_EXPORT_PLUGIN2(toolkitsqlplugin, ToolkitSqlPlugin);

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */

