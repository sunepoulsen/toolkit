#====================================================================================
#
#                       Toolkit UTR Core Configuration
#
#====================================================================================

PROJECT_NAME = toolkit_utrcore

#====================================================================================
#                       Qt Configuration
#====================================================================================

QT = core gui xml testlib

#====================================================================================
#			            Include Build Options
#====================================================================================

unix: INCLUDE_DIR = utrcore
win32: INCLUDE_DIR = UtrCore

include( ../../../toolkit.pri )

unix: PREFIX_INCLUDE = $${PREFIX_INCLUDE}/$${INCLUDE_DIR}
win32: PREFIX_INCLUDE = $${PREFIX_INCLUDE}\\$${INCLUDE_DIR}

include( $${QBUILDTOOLS_LIB}/lib.pri )

#====================================================================================
#			            Dependencies
#====================================================================================

include( $${PROJECT_ROOT}/toolkit_test.pri )
include( $${PROJECT_ROOT}/toolkit_core.pri )

#====================================================================================
#			            Compiler Options
#====================================================================================

win32 {
    DEFINES += TOOLKIT_UTRCORE_MAKE_DLL
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

