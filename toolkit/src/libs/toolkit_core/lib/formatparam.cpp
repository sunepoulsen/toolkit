//-------------------------------------------------------------
/*!
    \file formatparam.cpp
    \brief 
*/

//-------------------------------------------------------------

// Include Header File
#include "formatparam.h"

// Include Toolkit Core Files
#include "formatexception.h"

//-------------------------------------------------------------
using namespace Toolkit::Core;

//-------------------------------------------------------------
const QString FormatParam::PARAM_PATTERN( "(\\%{2})|(\\%((\\d+)\\$)?(([a-z]|[A-Z])+)?(-?[0-9]+)?(\\.([0-9]+))?([a-z]|[A-Z]))" );
const QString FormatParam::PARAM_PREFIX_CHAR( '%' );
const QString FormatParam::PARAM_PREFIX_ESCAPE( PARAM_PREFIX_CHAR + PARAM_PREFIX_CHAR );
const int FormatParam::PARAM_PATTERN_ARGINDEX_TEST_CAP( 4 );
const int FormatParam::PARAM_PATTERN_ARGINDEX_CAP( PARAM_PATTERN_ARGINDEX_TEST_CAP );
const int FormatParam::PARAM_PATTERN_FLAGS_TEST_CAP( PARAM_PATTERN_ARGINDEX_TEST_CAP + 1 );
const int FormatParam::PARAM_PATTERN_FLAGS_CAP( PARAM_PATTERN_FLAGS_TEST_CAP );
const int FormatParam::PARAM_PATTERN_WIDTH_TEST_CAP( PARAM_PATTERN_FLAGS_TEST_CAP + 2 );
const int FormatParam::PARAM_PATTERN_WIDTH_CAP( PARAM_PATTERN_WIDTH_TEST_CAP );
const int FormatParam::PARAM_PATTERN_PRECISION_TEST_CAP( PARAM_PATTERN_WIDTH_TEST_CAP + 1 );
const int FormatParam::PARAM_PATTERN_PRECISION_CAP( PARAM_PATTERN_PRECISION_TEST_CAP + 1 );
const int FormatParam::PARAM_PATTERN_CONVERSION_TEST_CAP( PARAM_PATTERN_PRECISION_TEST_CAP + 2 );
const int FormatParam::PARAM_PATTERN_CONVERSION_CAP( PARAM_PATTERN_CONVERSION_TEST_CAP );

//-------------------------------------------------------------
/*!
    \brief Constructs an empty format param.
*/
FormatParam::FormatParam( const QString& str ) :
    m_ArgIndex( -1 ),
    m_Flags(),
    m_Width( 0 ),
    m_Precision( -1 ),
    m_Conversion()
{
    fromString( str );
};

/*!
    \brief Constructs a format param from a regular expression.
    
    If \e rx matches a string, then the constructor extracts the information from \e rx.
    Else it is the same as:
    \code
    FormatParam();
    \endcode
    
    \param rx The regular expression.
*/
FormatParam::FormatParam( QRegExp& rx )  :
    m_ArgIndex( -1 ),
    m_Flags(),
    m_Width( 0 ),
    m_Precision( -1 ),
    m_Conversion()
{
    extract( rx );
};

/*!
    \brief Copy constructor.
    
    \param other The FormatParam to copy.
*/
FormatParam::FormatParam( const FormatParam& other ) :
    m_ArgIndex( other.m_ArgIndex ),
    m_Flags( other.m_Flags ),
    m_Width( other.m_Width ),
    m_Precision( other.m_Precision ),
    m_Conversion( other.m_Conversion )
{
};

/*!
    \brief Destructor.
*/
FormatParam::~FormatParam() {
};

int FormatParam::getArgIndex() const {
    return m_ArgIndex;
};

void FormatParam::setArgIndex( int newArgIndex ) {
    m_ArgIndex = newArgIndex;
};

const QString& FormatParam::getFlags() const {
    return m_Flags;
};

void FormatParam::setFlags( const QString& newFlags ) {
    m_Flags = newFlags;
};

int FormatParam::getWidth() const {
    return m_Width;
};

void FormatParam::setWidth( int newWidth ) {
    m_Width = newWidth;
};

int FormatParam::getPrecision() const {
    return m_Precision;
};

void FormatParam::setPrecision( int newPrecision ) {
    m_Precision = newPrecision;
};

const QChar& FormatParam::getConversion() const {
    return m_Conversion;
};

void FormatParam::setConversion( const QChar& newConversion ) {
    m_Conversion = newConversion;
};

bool FormatParam::hasArgIndex() const {
    return m_ArgIndex != -1;
};

bool FormatParam::hasFlag( const QChar& flag ) const {
    return m_Flags.contains( flag );
};

bool FormatParam::hasFlags() const {
    return !m_Flags.isEmpty();
};

bool FormatParam::hasWidth() const {
    return m_Width != 0;
};

bool FormatParam::hasPrecision() const {
    return m_Precision != -1;
};

bool FormatParam::hasConversion( const QChar& conv ) const {
    return m_Conversion == conv;
};

QString FormatParam::toString() const {
    QString s = "";

    if( m_ArgIndex != -1 ) {
        s += QString::number( m_ArgIndex ) + "$";
    };

    s += m_Flags;
    if( m_Width != 0 ) {
        s += QString::number( m_Width );
    };

    if( m_Precision != -1 ) {
        s += "." + QString::number( m_Precision );
    };

    if( !m_Conversion.isNull() ) {
        s += m_Conversion;
    };

    if( s.isEmpty() ) {
        return s;
    };

    return "%" + s;
};

bool FormatParam::fromString( const QString& str ) {
    if( str.isEmpty() ) {
        clear();
        return true;
    };

    QRegExp rx( PARAM_PATTERN );
    rx.indexIn( str );

    return extract( rx );
};

FormatParam& FormatParam::operator=( const FormatParam& other ) {
    m_ArgIndex = other.m_ArgIndex;
    m_Flags = other.m_Flags;
    m_Width = other.m_Width;
    m_Precision = other.m_Precision;
    m_Conversion = other.m_Conversion;

    return *this;
};

FormatParam& FormatParam::operator=( const QString& str ) {
    fromString( str );

    return *this;
};

void FormatParam::clear() {
    m_ArgIndex = -1;
    m_Flags = "";
    m_Width = 0;
    m_Precision = -1;
    m_Conversion = QChar();
};

bool FormatParam::extract( const QRegExp& rx ) {
    if( rx.matchedLength() > -1 ) {
        clear();
        if( !rx.cap( PARAM_PATTERN_ARGINDEX_TEST_CAP ).isEmpty() ) {
            m_ArgIndex = rx.cap( PARAM_PATTERN_ARGINDEX_CAP ).toInt();
        };

        if( !rx.cap( PARAM_PATTERN_FLAGS_TEST_CAP ).isEmpty() ) {
            m_Flags = rx.cap( PARAM_PATTERN_FLAGS_CAP );
        };

        if( !rx.cap( PARAM_PATTERN_WIDTH_TEST_CAP ).isEmpty() ) {
            m_Width = rx.cap( PARAM_PATTERN_WIDTH_CAP ).toInt();
        };

        if( !rx.cap( PARAM_PATTERN_PRECISION_TEST_CAP ).isEmpty() ) {
            m_Precision = rx.cap( PARAM_PATTERN_PRECISION_CAP ).toInt();
        };

        if( !rx.cap( PARAM_PATTERN_CONVERSION_TEST_CAP ).isEmpty() ) {
            m_Conversion = rx.cap( PARAM_PATTERN_CONVERSION_CAP )[ 0 ];
        };

        return true;
    };

    return false;
};

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
