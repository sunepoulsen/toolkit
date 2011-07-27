#====================================================================================
#
#                       Toolkit UTR Core Configuration
#
#====================================================================================

PROJECT_NAME = utr

#====================================================================================
#                       Qt Configuration
#====================================================================================

QT = core xml

#====================================================================================
#			            Include Build Options
#====================================================================================

include( ../../../toolkit.pri )
include( $${QBUILDTOOLS_LIB}/app.pri )

#====================================================================================
#			            Dependencies
#====================================================================================

include( $${PROJECT_ROOT}/toolkit_utrcore.pri )
include( $${PROJECT_ROOT}/toolkit_test.pri )
include( $${PROJECT_ROOT}/toolkit_core.pri )

#====================================================================================
#			            Sources
#====================================================================================

SOURCES += *.cpp

#====================================================================================
#			            Messages
#====================================================================================

message( "TARGET: " $${TARGET} )
