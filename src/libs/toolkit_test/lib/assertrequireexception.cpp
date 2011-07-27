//---------------------------------------------------------------------------------------
/*!
    \file assertrequireexception.cpp
    \brief 
*/

//---------------------------------------------------------------------------------------

// Include Header File
#include "assertrequireexception.h"

//-------------------------------------------------------------
using namespace Toolkit::Core;
using namespace Toolkit::Test;

//-------------------------------------------------------------
AssertRequireException::AssertRequireException( const SourceLine& srcLine, const QString& message ) :
    AssertException( srcLine, message )
{
};

AssertRequireException::AssertRequireException( const AssertRequireException& other ) :
    AssertException( other )
{
};
    
AssertRequireException::~AssertRequireException() {
};

AssertRequireException& AssertRequireException::operator=( const AssertRequireException& other ) {
    AssertException::operator=( other );
    
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
