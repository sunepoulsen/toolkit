//---------------------------------------------------------------------------------------
/*!
  \file formatexception.cpp
  \brief Implements our exception class for exceptions that should be handled.
*/

//---------------------------------------------------------------------------------------

// Include Header File
#include "formatexception.h"

//-------------------------------------------------------------
using namespace Toolkit::Core;

//-------------------------------------------------------------
FormatException::FormatException( const SourceLine& srcLine, const QString& message ) :
    Exception( srcLine, message )
{
};

FormatException::FormatException( const FormatException& other ) :
	Exception( other )
{
};
    
FormatException::~FormatException() {
};

FormatException& FormatException::operator=( const FormatException& other ) {
    Exception::operator=( other );
    
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
