#====================================================================================
#			            Qt Template
#====================================================================================

TEMPLATE = app
QT = core gui xml

CONFIG += warn_on qt thread dll

ROOT_PATH = ../../../..
TARGET = qsqlmanager

# ====== Dependencies ======
DEP_LIBS += toolkit_qsqlmanagercore
DEP_LIBS += toolkit_resource
DEP_LIBS += toolkit_gui
DEP_LIBS += toolkit_test
DEP_LIBS += toolkit_core

#====================================================================================
#			            Include QMake Options
#====================================================================================

include( $$ROOT_PATH/src/app.pri )

#====================================================================================
#			            Sources
#====================================================================================

SOURCES += *.cpp

