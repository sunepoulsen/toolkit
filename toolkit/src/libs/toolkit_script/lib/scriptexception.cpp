//---------------------------------------------------------------------------------------
/*!
    \file scriptexception.cpp
    \brief
*/

//---------------------------------------------------------------------------------------

// Include Header File
#include "scriptexception.h"

//-------------------------------------------------------------
using namespace Toolkit::Core;
using namespace Toolkit::Script;

//-------------------------------------------------------------
ScriptException::ScriptException( const QScriptValue& scriptExp ) :
    Exception( SourceLine( scriptExp.property( "fileName" ).toString().toLatin1().data(), scriptExp.property( "lineNumber" ).toInt32() ),
               scriptExp.toString() ),
    m_Exception( scriptExp )
{
};

ScriptException::ScriptException( const ScriptException& other ) :
    Exception( other ),
    m_Exception( other.m_Exception )
{
};

ScriptException::~ScriptException() {
};

ScriptException& ScriptException::operator=( const ScriptException& other ) {
    Exception::operator=( other );
    m_Exception = other.m_Exception;

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
