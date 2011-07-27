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
QString QSqlManagerPlugin::pluginName() const {
    return "QSqlManager Plugin";
};

QString QSqlManagerPlugin::pluginDescription() const {
    return "Tests the QSqlManager Tool";
};

QString QSqlManagerPlugin::pluginVersion() const {
    return TOOLKIT_VERSION_STR;
};

TestRegisterInterface::SuitePtr QSqlManagerPlugin::registerTests() const {
    SuitePtr res( new Suite( pluginName() + " test suite" ) );
    
    return res;
};

Q_EXPORT_PLUGIN2(qsqlmanagerplugin, QSqlManagerPlugin);

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */

