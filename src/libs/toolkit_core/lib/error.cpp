//---------------------------------------------------------------------------------------
/*!
  \file error.cpp
  \brief Implements our Error exception class for exceptions that should not be handled.
*/

//---------------------------------------------------------------------------------------

// Include Header File
#include "error.h"

//-------------------------------------------------------------
using namespace Toolkit::Core;

//-------------------------------------------------------------
Error::Error( const SourceLine& srcLine, const QString& message ) :
    Throwable( srcLine, message )
{
};

Error::Error( const Error& other ) :
    Throwable( other )
{
};
    
Error::~Error() {
};

Error& Error::operator=( const Error& other ) {
    Throwable::operator=( other );
    
    return *this;
};

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */

