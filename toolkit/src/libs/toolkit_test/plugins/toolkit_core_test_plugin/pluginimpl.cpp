//-------------------------------------------------------------------------
/*!
    \file plugininterface.cpp
    \brief
*/

//-------------------------------------------------------------------------

// Include Header File
#include "pluginimpl.h"

// Include Plugin Files
#include "basicdeviceformattestcase.h"
#include "basicstringformattestcase.h"
#include "defaultargumentformatertestcase.h"
#include "errortestcase.h"
#include "exceptiontestcase.h"
#include "filefactorytestcase.h"
#include "formatexceptiontestcase.h"
#include "formatparamtestcase.h"
#include "replacecharconvertertestcase.h"
#include "qttestcase.h"
#include "sourcelinetestcase.h"
#include "throwabletestcase.h"

// Include Toolkit Core Files
#include <toolkit/core/library.h>
#include <toolkit/core/log.h>

//-------------------------------------------------------------------------
using namespace Toolkit::Core;

//-------------------------------------------------------------------------
QString ToolkitCorePlugin::pluginName() const {
    return "Toolkit Core Plugin";
};

QString ToolkitCorePlugin::pluginDescription() const {
    return "Tests the Toolkit Core Library";
};

QString ToolkitCorePlugin::pluginVersion() const {
    return TOOLKIT_VERSION_STR;
};

TestRegisterInterface::SuitePtr ToolkitCorePlugin::registerTests() const {
    SuitePtr res( new Suite( pluginName() + " test suite" ) );
    Suite* suiteModule = NULL;

    // Create suite Qt and OS tests
    suiteModule = new Suite( "Qt & operating system" );
    suiteModule->addTest( Suite::item_type( new QtTestCase() ) );
    suiteModule->addTest( Suite::item_type( new FileFactoryTestCase() ) );
    res->addTest( Suite::item_type( suiteModule ) );

    // Create suite for the Exceptions module.
    suiteModule = new Suite( "Exceptions" );
    suiteModule->addTest( Suite::item_type( new SourceLineTestCase() ) );
    suiteModule->addTest( Suite::item_type( new ThrowableTestCase() ) );
    suiteModule->addTest( Suite::item_type( new ErrorTestCase() ) );
    suiteModule->addTest( Suite::item_type( new ExceptionTestCase() ) );
    suiteModule->addTest( Suite::item_type( new FormatExceptionTestCase() ) );
    res->addTest( Suite::item_type( suiteModule ) );

    // Create suite for the Formats module.
    suiteModule = new Suite( "Formats" );
    suiteModule->addTest( Suite::item_type( new FormatParamTestCase() ) );
    suiteModule->addTest( Suite::item_type( new DefaultArgumentFormaterTestCase() ) );
    suiteModule->addTest( Suite::item_type( new BasicStringFormatTestCase() ) );
    suiteModule->addTest( Suite::item_type( new BasicDeviceFormatTestCase() ) );
    res->addTest( Suite::item_type( suiteModule ) );

    // Create suite for the Text Converter module.
    suiteModule = new Suite( "Text converters" );
    suiteModule->addTest( Suite::item_type( new ReplaceCharConverterTestCase() ) );
    res->addTest( Suite::item_type( suiteModule ) );

    return res;
};

Q_EXPORT_PLUGIN2(toolkitcoreplugin, ToolkitCorePlugin);

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */

