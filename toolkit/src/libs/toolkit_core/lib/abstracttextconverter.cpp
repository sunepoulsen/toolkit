//-------------------------------------------------------------------------------------------------
/*!
    \file abstracttextconverter.cpp
    \brief 
*/

//-------------------------------------------------------------------------------------------------

// Include Header File
#include "abstracttextconverter.h"

//-------------------------------------------------------------------------------------------------
using namespace Toolkit::Core;

//-------------------------------------------------------------------------------------------------
AbstractTextConverter::AbstractTextConverter() {
};

AbstractTextConverter::AbstractTextConverter( const AbstractTextConverter& ) {
};

AbstractTextConverter::~AbstractTextConverter() {
};

AbstractTextConverter* AbstractTextConverter::clone() const {
    return doClone();
};

const QString& AbstractTextConverter::name() const {
    return doName();
};

QString AbstractTextConverter::fromUnicode( const QString& str ) const {
    return doFromUnicode( str.data(), str.length() );
};

QString AbstractTextConverter::fromUnicode( const QChar* str, int len ) const {
    return doFromUnicode( str, len );
};

QString AbstractTextConverter::toUnicode( const QString& str ) const {
    return doToUnicode( str.data(), str.length() );
};

QString AbstractTextConverter::toUnicode( const QChar* str, int len ) const {
    return doToUnicode( str, len );
};

AbstractTextConverter& AbstractTextConverter::operator=( const AbstractTextConverter& ) {
    return *this;
};

QString AbstractTextConverter::doFromUnicode( const QChar* str, int len ) const {
    return QString( str, len );
};

QString AbstractTextConverter::doToUnicode( const QChar* str, int len ) const {
    return QString( str, len );
};

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
