//---------------------------------------------------------------------------------------
/*!
    \file genericexception.cpp
    \brief Implements our exception class for exceptions that should be handled.
*/

//---------------------------------------------------------------------------------------

// Include Header File
#include "genericexception.h"

//-------------------------------------------------------------
using namespace Toolkit::Core;

//-------------------------------------------------------------
GenericException::GenericException( const SourceLine& srcLine, const QString& message ) :
    Exception( srcLine, message )
{
};

GenericException::GenericException( const GenericException& other ) :
        Exception( other )
{
};

GenericException::~GenericException() {
};

GenericException& GenericException::operator=( const GenericException& other ) {
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
