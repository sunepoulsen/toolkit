//-------------------------------------------------------------------------------------------------
/*!
    \file abstractcharconverter.cpp
    \brief
*/

//-------------------------------------------------------------------------------------------------

// Include Header File
#include "replacecharconverter.h"

//-------------------------------------------------------------------------------------------------
using namespace Toolkit::Core;

//-------------------------------------------------------------------------------------------------
ReplaceCharConverter::ReplaceCharConverter() :
    AbstractCharConverter(),
    m_ReplaceValue()
{
};

ReplaceCharConverter::ReplaceCharConverter( const QChar& startChar, const QString& replaceValue ) :
    AbstractCharConverter( startChar ),
    m_ReplaceValue( replaceValue )
{
};

ReplaceCharConverter::ReplaceCharConverter( const ReplaceCharConverter& other ) :
    AbstractCharConverter( other ),
    m_ReplaceValue( other.m_ReplaceValue )
{
};

ReplaceCharConverter::~ReplaceCharConverter() {
};

const QString& ReplaceCharConverter::getReplaceValue() const {
    return m_ReplaceValue;
};

void ReplaceCharConverter::setReplaceValue( const QString& newReplaceValue ) {
    m_ReplaceValue = newReplaceValue;
};

ReplaceCharConverter& ReplaceCharConverter::operator=( const ReplaceCharConverter& other ) {
    AbstractCharConverter::operator=( other );
    m_ReplaceValue = other.m_ReplaceValue;

    return *this;
};

/*!
    \brief Checks if \e ch can be converted using this char converter.

    An AbstractTextConverter uses this check to find a soutable char converter to convert \e ch.

    \param ch The ch to check for.

    \retval true  The \e ch equals AbstractCharConverter::m_StartChar
    \retval false Otherwise.
*/
bool ReplaceCharConverter::doCanConvertFromUnicode( const QChar& ch ) const {
    return ch == getStartChar();
};

/*!
    \brief Checks if some begining of \e str from position \e pos, can be converted using this
           char converter.

    An AbstractTextConverter uses this check to find a soutable char converter to convert \e str.

    \param str The string to check for.
    \param pos The position in \e str to start the check for.

    \retval true  \e str at position \e pos equals ReplaceCharConverter::m_ReplaceValue.
    \retval false Otherwise.
*/
bool ReplaceCharConverter::doCanConvertToUnicode( const QString& str, int pos ) const {
    return m_ReplaceValue == str.midRef( pos, m_ReplaceValue.length() );
};

/*!
    \brief Converts \e ch from unicode to a QString.

    \param ch Ignored.

    \return
        Always m_ReplaceValue
*/
QString ReplaceCharConverter::doFromUnicode( const QChar& ch ) const {
    if( canConvertFromUnicode( ch ) ) {
        return m_ReplaceValue;
    };

    return "";
};

QChar ReplaceCharConverter::doToUnicode( const QString& str, int& pos ) const {
    QChar ch;

    if( canConvertToUnicode( str, pos ) ) {
        ch = getStartChar();
        pos += m_ReplaceValue.length();
    };

    return ch;
};


/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
