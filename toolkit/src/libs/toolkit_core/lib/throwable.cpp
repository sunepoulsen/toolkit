//---------------------------------------------------------------------------------------
/*!
    \file throwable.cpp
    \brief Implements the class Throwable.
*/

//---------------------------------------------------------------------------------------

// Include Header File
#include "throwable.h"

//-------------------------------------------------------------
using namespace Toolkit::Core;

//-------------------------------------------------------------
const QString Throwable::DEBUG_MSG( "Exception at %1:%2: %3" );

//-------------------------------------------------------------
Throwable::Throwable( const SourceLine& srcLine, const QString& message ) :
    m_SourceLine( srcLine ),
    m_Message( message )
{
}

Throwable::Throwable( const Throwable& other ) :
    m_SourceLine( other.m_SourceLine ),
    m_Message( other.m_Message )
{
}
    
Throwable::~Throwable() {
}

const SourceLine& Throwable::getSourceLine() const {
    return m_SourceLine;
}

const QString& Throwable::getMessage() const {
    return m_Message;
}

QString Throwable::debugString() const {
    return DEBUG_MSG.arg( m_SourceLine.getFileName() ).arg( m_SourceLine.getLineNumber() ).arg( m_Message );
}

Throwable& Throwable::operator=( const Throwable& other ) {
    m_SourceLine = other.m_SourceLine;
    m_Message = other.m_Message;
    
    return *this;
}

void Throwable::setSourceLine( const SourceLine& newSourceLine ) {
    m_SourceLine = newSourceLine;
}

void Throwable::setMessage( const QString& newMessage ) {
    m_Message = newMessage;
}

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */

