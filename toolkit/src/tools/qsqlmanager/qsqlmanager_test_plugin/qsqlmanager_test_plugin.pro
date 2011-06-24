#====================================================================================
#			            Qt Template
#====================================================================================

TEMPLATE = lib
QT = core

CONFIG += warn_on qt thread dll plugin

ROOT_PATH = ../../../..
TARGET = qsqlmanager_test_plugin

# ====== Dependencies ======
DEP_LIBS += toolkit_core
DEP_LIBS += toolkit_qsqlmanagercore
DEP_LIBS += toolkit_test

#====================================================================================
#			            Include QMake Options
#====================================================================================

include( $$ROOT_PATH/src/plugin.pri )

#====================================================================================
#			            Sources
#====================================================================================

HEADERS += *.h
SOURCES += *.cpp
