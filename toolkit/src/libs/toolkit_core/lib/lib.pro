#====================================================================================
#
#                       NEW CONFIGURATION WITH PYTHON
#
#====================================================================================

PROJECT_NAME = toolkit_core

#====================================================================================
#                       Qt Configuration
#====================================================================================

QT = core

#====================================================================================
#			            Include Build Options
#====================================================================================

unix: INCLUDE_DIR = core
win32: INCLUDE_DIR = Core

include( ../../../toolkit.pri )

unix: PREFIX_INCLUDE = $${PREFIX_INCLUDE}/$${INCLUDE_DIR}
win32: PREFIX_INCLUDE = $${PREFIX_INCLUDE}\\$${INCLUDE_DIR}

include( $${PROJECT_ROOT}/buildfiles/lib.pri )

#====================================================================================
#			            Compiler Options
#====================================================================================

win32 {
    DEFINES += TOOLKIT_CORE_MAKE_DLL
}

#====================================================================================
#			            Sources
#====================================================================================

HEADERS += *.h
SOURCES += *.cpp

#====================================================================================
#			            Messages
#====================================================================================

message( "TARGET: " $${TARGET} )
