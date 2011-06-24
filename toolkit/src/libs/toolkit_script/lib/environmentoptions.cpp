//---------------------------------------------------------------------------------------
/*!
    \file environmentoptions.h
    \brief
*/

//---------------------------------------------------------------------------------------

// Include Header File
#include "environmentoptions.h"

//---------------------------------------------------------------------------------------
using namespace Toolkit::Script;

//---------------------------------------------------------------------------------------
EnvironmentOptions::EnvironmentOptions() :
    m_LocalContext( true ),
    m_Codec( QTextCodec::codecForLocale() )
{
};

EnvironmentOptions::EnvironmentOptions( const EnvironmentOptions& other ) :
    m_LocalContext( other.m_LocalContext ),
    m_Codec( other.m_Codec )
{
};

EnvironmentOptions::~EnvironmentOptions() {
};

bool EnvironmentOptions::getLocalContext() const {
    return m_LocalContext;
};

void EnvironmentOptions::setLocalContext( bool newLocalContext ) {
    m_LocalContext = newLocalContext;
};

/*!
    \brief Returns the current codec.

    If no text codec has been set then we return a reference to the
    current locale codec.
*/
const QTextCodec& EnvironmentOptions::getCodec() const {
    if( m_Codec ) {
        return *m_Codec;
    };

    return *QTextCodec::codecForLocale();
};

void EnvironmentOptions::setCodec( QTextCodec* newCodec ) {
    m_Codec = newCodec;
};

void EnvironmentOptions::setCodec( const char* codecName ) {
    setCodec( QTextCodec::codecForName( codecName ) );
};

void EnvironmentOptions::setCodec( const QString& codecName ) {
    setCodec( codecName.toLatin1().data() );
};

EnvironmentOptions& EnvironmentOptions::operator=( const EnvironmentOptions& other ) {
    m_LocalContext = other.m_LocalContext;
    m_Codec = other.m_Codec;

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
