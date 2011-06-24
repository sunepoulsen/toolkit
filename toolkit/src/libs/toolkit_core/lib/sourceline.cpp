//-------------------------------------------------------------
/*!
    \file sourceline.cpp
    \brief Defines the class VDF::SourceLine.
*/

//-------------------------------------------------------------

// Include Header File
#include "sourceline.h"

//-------------------------------------------------------------
using namespace Toolkit::Core;

//-------------------------------------------------------------
SourceLine::SourceLine() :
    m_FileName(),
    m_LineNumber()
{
};


SourceLine::SourceLine( const char* fileName, size_type lineNumber ) :
    m_FileName( fileName ),
    m_LineNumber( lineNumber )
{
};

SourceLine::SourceLine( const SourceLine& other ) :
    m_FileName( other.m_FileName ),
    m_LineNumber( other.m_LineNumber )
{
};
    
SourceLine::~SourceLine() {
};

const QString& SourceLine::getFileName() const {
    return m_FileName;
};

void SourceLine::setFileName( const QString& newFileName ) {
    m_FileName = newFileName;
};

SourceLine::size_type SourceLine::getLineNumber() const {
    return m_LineNumber;
};

void SourceLine::setLineNumber( size_type newLineNumber ) {
    m_LineNumber = newLineNumber;
};

SourceLine& SourceLine::operator=( const SourceLine& other ) {
    m_FileName = other.m_FileName;
    m_LineNumber = other.m_LineNumber;
    
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
