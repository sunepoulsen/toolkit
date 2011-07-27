//-------------------------------------------------------------------------------------------------------
/*!
    \file main.cpp
    \brief
*/

//-------------------------------------------------------------------------------------------------------

// Include UTR Files
#include <toolkit/utrcore/executor.h>

// Include Toolkit Core Files
#include <toolkit/core/format.h>
#include <toolkit/core/log.h>

//-------------------------------------------------------------------------------------------------------
using namespace Toolkit::Core;

//-------------------------------------------------------------------------------------------------------
/*!
    \ingroup grp_TestExecutor
    \brief Main function of the \e utr tool.
    
    \param argc The numer of parsed arguments at the command line.
    \param argv An array of each argument as a char*.
*/
int main( int argc, char* argv[] ) {
    Executor exec( argc, argv );
    
    int appRes = exec.run();
    
    return appRes;
};

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
