//---------------------------------------------------------------------------------------
/*!
    \file assertcriticalexception.cpp
    \brief 
*/

//---------------------------------------------------------------------------------------

// Include Header File
#include "assertcriticalexception.h"

//-------------------------------------------------------------
using namespace Toolkit::Core;
using namespace Toolkit::Test;

//-------------------------------------------------------------
AssertCriticalException::AssertCriticalException( const SourceLine& srcLine, const QString& message ) :
    AssertException( srcLine, message )
{
};

AssertCriticalException::AssertCriticalException( const AssertCriticalException& other ) :
    AssertException( other )
{
};
    
AssertCriticalException::~AssertCriticalException() {
};

AssertCriticalException& AssertCriticalException::operator=( const AssertCriticalException& other ) {
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
