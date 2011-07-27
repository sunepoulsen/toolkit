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

#include <QLineEdit>

//-------------------------------------------------------------------------
QString ToolkitGuiPlugin::pluginName() const {
    return "Toolkit Gui Plugin";
};

QString ToolkitGuiPlugin::pluginDescription() const {
    return "Tests the Toolkit Gui Library";
};

QString ToolkitGuiPlugin::pluginVersion() const {
    return TOOLKIT_VERSION_STR;
};

TestRegisterInterface::SuitePtr ToolkitGuiPlugin::registerTests() const {
    SuitePtr res( new Suite( pluginName() + " test suite" ) );

    QLineEdit* le = new QLineEdit();
    le->setText( "Test" );
    delete le;

    return res;
};

Q_EXPORT_PLUGIN2(toolkitguiplugin, ToolkitGuiPlugin);

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */

