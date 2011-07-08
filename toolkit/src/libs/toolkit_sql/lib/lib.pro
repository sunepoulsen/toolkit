#====================================================================================
#
#                       Toolkit Sql Configuration
#
#====================================================================================

PROJECT_NAME = toolkit_sql

#====================================================================================
#                       Qt Configuration
#====================================================================================

QT = core sql

#====================================================================================
#			            Include Build Options
#====================================================================================

unix: INCLUDE_DIR = sql
win32: INCLUDE_DIR = Sql

include( ../../../toolkit.pri )

unix: PREFIX_INCLUDE = $${PREFIX_INCLUDE}/$${INCLUDE_DIR}
win32: PREFIX_INCLUDE = $${PREFIX_INCLUDE}\\$${INCLUDE_DIR}

include( $${QBUILDTOOLS_LIB}/lib.pri )

#====================================================================================
#			            Dependencies
#====================================================================================

include( $${PROJECT_ROOT}/toolkit_core.pri )

#====================================================================================
#			            Compiler Options
#====================================================================================

win32 {
    DEFINES += TOOLKIT_SQL_MAKE_DLL
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
