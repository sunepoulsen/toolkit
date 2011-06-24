//-------------------------------------------------------------------------------------------------
/*!
    \file abstractcharconverter.cpp
    \brief
*/

//-------------------------------------------------------------------------------------------------

// Include Header File
#include "abstractcharconverter.h"

//-------------------------------------------------------------------------------------------------
using namespace Toolkit::Core;

//-------------------------------------------------------------------------------------------------
/*!
    \brief Empty constructor.
*/
AbstractCharConverter::AbstractCharConverter() :
    m_StartChar()
{
};

/*!
    \brief Constructs a char converter with a start char.

    \param startChar The char to use.
*/
AbstractCharConverter::AbstractCharConverter( const QChar& startChar ) :
    m_StartChar( startChar )
{
};

/*!
    \brief Copy constructor.
*/
AbstractCharConverter::AbstractCharConverter( const AbstractCharConverter& other ) :
    m_StartChar( other.m_StartChar )
{
};

/*!
    \brief Empty destructor.
*/
AbstractCharConverter::~AbstractCharConverter() {
};

/*!
    \brief Returns the start char of this converter.

    \sa
        m_StartChar
*/
const QChar& AbstractCharConverter::getStartChar() const {
    return m_StartChar;
};

/*!
    \brief Starts a new start char.

    \param newChar The new char.

    \sa
        m_StartChar
*/
void AbstractCharConverter::setStartChar( const QChar& newChar ) {
    m_StartChar = newChar;
};

/*!
    \brief Checks if \e ch can be converted using this char converter.

    \copydetails doCanConvertFromUnicode

    \note
        Doing to the NVI design pattern, this function simply calls doCanConvertFromUnicode()
*/
bool AbstractCharConverter::canConvertFromUnicode( const QChar& ch ) const {
    return doCanConvertFromUnicode( ch );
};

/*!
    \brief Checks if some begining of \e str from position \e pos, can be converted using this char converter.

    \copydetails doCanConvertToUnicode

    \note
        Doing to the NVI design pattern, this function simply calls doCanConvertToUnicode()
*/
bool AbstractCharConverter::canConvertToUnicode( const QString& str, int pos ) const {
    return doCanConvertToUnicode( str, pos );
};

/*!
    \brief Converts \e ch from unicode to a QString.

    \copydetails doFromUnicode

    \note
        Doing to the NVI design pattern, this function simply calls doFromUnicode()
*/
QString AbstractCharConverter::fromUnicode( const QChar& ch ) const {
    return doFromUnicode( ch );
};

/*!
    \brief Converts \e str at position \e pos to a unicode char.

    \copydetails doToUnicode

    \note
        Doing to the NVI design pattern, this function simply calls doToUnicode()
*/
QChar AbstractCharConverter::toUnicode( const QString& str, int& pos ) const {
    return doToUnicode( str, pos );
};

/*!
    \brief Assignment operator.
*/
AbstractCharConverter& AbstractCharConverter::operator=( const AbstractCharConverter& other ) {
    m_StartChar = other.m_StartChar;

    return *this;
};

/*!
    \brief Converts \e ch from unicode to a QString.

    The default implementation just returns the char as a string.

    \param ch The QChar to convert.
*/
QString AbstractCharConverter::doFromUnicode( const QChar& ch ) const {
    return QString( ch );
};

/*!
    \brief Converts \e str at pos \e pos to a unicode char.

    The default implementation just returns the char at \e pos and increases \e pos with 1.

    \param str The string to convert.
    \param pos The position in \e str to convert.

    \note
        Subclasses must increase \e pos with the number of chars converted from \e str.
*/
QChar AbstractCharConverter::doToUnicode( const QString& str, int& pos ) const {
    QChar ch = str.at( pos );
    pos++;

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
