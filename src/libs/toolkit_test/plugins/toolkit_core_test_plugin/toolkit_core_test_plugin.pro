#====================================================================================
#
#                       Toolkit Core Test Plugin Configuration
#
#====================================================================================

PROJECT_NAME = toolkit_core_test_plugin

#====================================================================================
#                       Qt Configuration
#====================================================================================

QT = sql

#====================================================================================
#			            Include Build Options
#====================================================================================

include( ../../../../toolkit.pri )
include( $${QBUILDTOOLS_LIB}/plugin.pri )

#====================================================================================
#			            Dependencies
#====================================================================================

include( $${PROJECT_ROOT}/toolkit_core.pri )
include( $${PROJECT_ROOT}/toolkit_test.pri )

#====================================================================================
#			            Sources
#====================================================================================

HEADERS += *.h
SOURCES += *.cpp

#====================================================================================
#			            Messages
#====================================================================================

message( "TARGET: " $${TARGET} )