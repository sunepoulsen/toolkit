//---------------------------------------------------------------------------------------
/*!
    \file noimpexception.cpp
    \brief
*/

//---------------------------------------------------------------------------------------

// Include Header File
#include "noimpexception.h"

//---------------------------------------------------------------------------------------
using namespace Toolkit::Core;

//---------------------------------------------------------------------------------------
const QString NoImpException::DEFAULT_MESSAGE( "The feature is not implementated yet!" );

//---------------------------------------------------------------------------------------
NoImpException::NoImpException( const SourceLine& srcLine, const QString& message ) :
    Exception( srcLine, message )
{
};

NoImpException::NoImpException( const NoImpException& other ) :
    Exception( other )
{
};

NoImpException::~NoImpException() {
};

NoImpException& NoImpException::operator=( const NoImpException& other ) {
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
