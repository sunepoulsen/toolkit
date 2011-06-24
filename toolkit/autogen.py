#!/usr/bin/env python

# =========================================================================================
#                       Imports
# =========================================================================================

import sys
import os.path

## Magic to add buildfiles/modules to search path
sys.path.append( os.path.join(os.path.dirname(os.path.realpath(sys.argv[0])), "../buildfiles/tools/modules" ) )

from autogenfactory import AutogenFactory
from fileaction import FileAction

# =========================================================================================
#                       Main function
# =========================================================================================

def main( args ):    
    VERSION = "0.5.1"

    fact = AutogenFactory( "Toolkit configuration tool", VERSION )
    fact.appendAction( fact.newFileAction( "src/toolkit.pri.in", "src/toolkit.pri" ) )
    fact.appendAction( fact.newUseLibAction( "../buildfiles/use-lib.pri.in", "toolkit_core.pri", "toolkit_core", "core" ) )
    fact.appendAction( fact.newUseLibAction( "../buildfiles/use-lib.pri.in", "toolkit_gui.pri", "toolkit_gui", "core gui" ) )
    fact.appendAction( fact.newUseLibAction( "../buildfiles/use-lib.pri.in", "toolkit_interpreter.pri", "toolkit_interpreter", "core xml" ) )
    fact.appendAction( fact.newUseLibAction( "../buildfiles/use-lib.pri.in", "toolkit_resource.pri", "toolkit_resource", "core gui xml xmlpatterns" ) )
    fact.appendAction( fact.newUseLibAction( "../buildfiles/use-lib.pri.in", "toolkit_script.pri", "toolkit_script", "core script" ) )
    fact.appendAction( fact.newUseLibAction( "../buildfiles/use-lib.pri.in", "toolkit_sql.pri", "toolkit_sql", "core sql" ) )
    fact.appendAction( fact.newUseLibAction( "../buildfiles/use-lib.pri.in", "toolkit_test.pri", "toolkit_test", "core xml" ) )

    fact.appendAction( fact.newUseLibAction( "../buildfiles/use-lib.pri.in", "toolkit_qsqlmanagercore.pri", "toolkit_qsqlmanagercore", "core gui xml" ) )
    fact.appendAction( fact.newUseLibAction( "../buildfiles/use-lib.pri.in", "toolkit_utrcore.pri", "toolkit_utrcore", "core gui xml" ) )

    fact.appendAction( FileAction( inputFile = "../buildfiles/cc.doxygen.in", outputFile = "dist/doc/doxygen/toolkit.doxygen", params = {
                           "PROJECT_NAME": "toolkit",
                           "VERSION": VERSION,
                           "PROJECT_DESCRIPTION": "Toolkit Library",
                           "INPUT": "pages ../../../src/libs/toolkit_core/lib ../../../src/libs/toolkit_gui/lib ../../../src/libs/toolkit_interpreter/lib ../../../src/libs/toolkit_resource/lib ../../../src/libs/toolkit_script/lib ../../../src/libs/toolkit_sql/lib ../../../src/libs/toolkit_test/lib ../../../src/tools/utr/utr ../../../src/tools/utr/lib"
                           } ) )

    fact.appendAction( FileAction( inputFile = "../buildfiles/Makefile.doxygen.in", outputFile = "dist/doc/doxygen/Makefile", params = {
                           "DOXYGEN_FILE": "toolkit.doxygen",
                           "PROJECT_NAME": "toolkit"
                           } ) )

    return fact.main( args )

# =========================================================================================
#                       Execution
# =========================================================================================

main( sys.argv )

