#====================================================================================
#
#                       Toolkit Sql Test Plugin Configuration
#
#====================================================================================

PROJECT_NAME = toolkit_sql_test_plugin

#====================================================================================
#			            Include Build Options
#====================================================================================

include( ../../../toolkit.pri )
include( $${PROJECT_ROOT}/buildfiles/plugin.pri )

#====================================================================================
#			            Dependencies
#====================================================================================

include( $${PROJECT_ROOT}/toolkit_sql.pri )
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
