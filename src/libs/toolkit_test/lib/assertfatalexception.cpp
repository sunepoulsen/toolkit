//---------------------------------------------------------------------------------------
/*!
    \file assertfatalexception.cpp
    \brief 
*/

//---------------------------------------------------------------------------------------

// Include Header File
#include "assertfatalexception.h"

//-------------------------------------------------------------
using namespace Toolkit::Core;
using namespace Toolkit::Test;

//-------------------------------------------------------------
AssertFatalException::AssertFatalException( const SourceLine& srcLine, const QString& message ) :
    AssertException( srcLine, message )
{
};

AssertFatalException::AssertFatalException( const AssertFatalException& other ) :
    AssertException( other )
{
};
    
AssertFatalException::~AssertFatalException() {
};

AssertFatalException& AssertFatalException::operator=( const AssertFatalException& other ) {
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
