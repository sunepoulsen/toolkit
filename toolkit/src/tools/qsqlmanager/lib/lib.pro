#====================================================================================
#			            Qt Template
#====================================================================================

TEMPLATE = lib
QT = core gui xml

CONFIG += warn_on qt thread dll

ROOT_PATH = ../../../..
DEST_INCLUDE_DIR = qsqlmanagercore

# ====== Dependencies ======
DEP_LIBS += toolkit_core
DEP_LIBS += toolkit_resource
DEP_LIBS += toolkit_gui
DEP_LIBS += toolkit_test

#====================================================================================
#			            Include QMake Options
#====================================================================================

include( $$ROOT_PATH/src/lib.pri )

#====================================================================================
#			            Sources
#====================================================================================

HEADERS += *.h
SOURCES += *.cpp

#====================================================================================
#			            Resources
#====================================================================================

RESOURCES += resources/qsqlmanager.qrc