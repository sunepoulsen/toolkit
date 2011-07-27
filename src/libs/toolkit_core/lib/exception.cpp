//---------------------------------------------------------------------------------------
/*!
  \file exception.cpp
  \brief Implements our exception class for exceptions that should be handled.
*/

//---------------------------------------------------------------------------------------

// Include Header File
#include "exception.h"

//-------------------------------------------------------------
using namespace Toolkit::Core;

//-------------------------------------------------------------
Exception::Exception( const SourceLine& srcLine, const QString& message ) :
    Throwable( srcLine, message )
{    
};

Exception::Exception( const Exception& other ) :
    Throwable( other )
{
};
    
Exception::~Exception() {
};

Exception& Exception::operator=( const Exception& other ) {
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
