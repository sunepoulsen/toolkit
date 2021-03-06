#====================================================================================
#
#                       Toolkit UTR Core Test Plugin Configuration
#
#====================================================================================

PROJECT_NAME = toolkit_utrcore_test_plugin

#====================================================================================
#			            Include Build Options
#====================================================================================

include( ../../../toolkit.pri )
include( $${QBUILDTOOLS_LIB}/plugin.pri )

#====================================================================================
#			            Dependencies
#====================================================================================

include( $${PROJECT_ROOT}/toolkit_utrcore.pri )
include( $${PROJECT_ROOT}/toolkit_test.pri )
include( $${PROJECT_ROOT}/toolkit_core.pri )

#====================================================================================
#			            Sources
#====================================================================================

HEADERS += *.h
SOURCES += *.cpp

#====================================================================================
#			            Messages
#====================================================================================

message( "TARGET: " $${TARGET} )
