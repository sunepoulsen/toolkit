//-------------------------------------------------------------------------------------------------
/*!
    \file generictextconverter.cpp
    \brief
*/

//-------------------------------------------------------------------------------------------------

// Include Header File
#include "generictextconverter.h"

//-------------------------------------------------------------------------------------------------
using namespace Toolkit::Core;

//-------------------------------------------------------------------------------------------------
GenericTextConverter::GenericTextConverter() :
    AbstractTextConverter(),
    m_Name(),
    m_ToUnicodeConvPattern(),
    m_Rules()
{
};

GenericTextConverter::GenericTextConverter( const GenericTextConverter& other ) :
    AbstractTextConverter( other ),
    m_Name( other.m_Name ),
    m_ToUnicodeConvPattern( other.m_ToUnicodeConvPattern ),
    m_Rules( other.m_Rules )
{
};

GenericTextConverter::~GenericTextConverter() {
};

const QString& GenericTextConverter::getName() const {
    return m_Name;
};

void GenericTextConverter::setName( const QString& newName ) {
    m_Name = newName;
};

const QString& GenericTextConverter::getToUnicodeConvPattern() const {
    return m_ToUnicodeConvPattern;
};

void GenericTextConverter::setToUnicodeConvPattern( const QString& newToUnicodeConvPattern ) {
    m_ToUnicodeConvPattern = newToUnicodeConvPattern;
};

GenericTextConverter::iterator GenericTextConverter::begin() {
    return m_Rules.begin();
};

GenericTextConverter::const_iterator GenericTextConverter::begin() const {
    return m_Rules.begin();
};

GenericTextConverter::iterator GenericTextConverter::end() {
    return m_Rules.end();
};

GenericTextConverter::const_iterator GenericTextConverter::end() const {
    return m_Rules.end();
};

GenericTextConverter::reverse_iterator GenericTextConverter::rbegin() {
    return m_Rules.rbegin();
};

GenericTextConverter::const_reverse_iterator GenericTextConverter::rbegin() const {
    return m_Rules.rbegin();
};

GenericTextConverter::reverse_iterator GenericTextConverter::rend() {
    return m_Rules.rend();
};

GenericTextConverter::const_reverse_iterator GenericTextConverter::rend() const {
    return m_Rules.rend();
};

GenericTextConverter::reference GenericTextConverter::front() {
    return m_Rules.front();
};

GenericTextConverter::const_reference GenericTextConverter::front() const {
    return m_Rules.front();
};

GenericTextConverter::reference GenericTextConverter::back() {
    return m_Rules.back();
};

GenericTextConverter::const_reference GenericTextConverter::back() const {
    return m_Rules.back();
};

void GenericTextConverter::clear() {
    m_Rules.clear();
};

bool GenericTextConverter::empty() const {
    return m_Rules.empty();
};

GenericTextConverter::size_type GenericTextConverter::size() const {
    return m_Rules.size();
};

void GenericTextConverter::resize( size_type n, value_type t ) {
    m_Rules.resize( n, t );
};

GenericTextConverter::size_type GenericTextConverter::max_size() const {
    return m_Rules.max_size();
};

GenericTextConverter::size_type GenericTextConverter::capacity() const {
    return m_Rules.capacity();
};

void GenericTextConverter::reserve( size_type n ) {
    m_Rules.reserve( n );
};

GenericTextConverter::iterator GenericTextConverter::insert( iterator pos, const value_type& res ) {
    return m_Rules.insert( pos, res );
};

template <class InputIterator>
void GenericTextConverter::insert( iterator pos, InputIterator __begin, InputIterator __end ) {
    m_Rules.insert( pos, __begin, __end );
};

void GenericTextConverter::insert( iterator pos, size_type n, const value_type& res ) {
    m_Rules.insert( pos, n, res );
};

GenericTextConverter::iterator GenericTextConverter::erase( iterator pos ) {
    return m_Rules.erase( pos );
};

GenericTextConverter::iterator GenericTextConverter::erase( iterator __begin, iterator __end ) {
    return m_Rules.erase( __begin, __end );
};

void GenericTextConverter::push_back( const value_type& res ) {
    m_Rules.push_back( res );
};

void GenericTextConverter::pop_back() {
    m_Rules.pop_back();
};

GenericTextConverter& GenericTextConverter::operator=( const GenericTextConverter& other ) {
    AbstractTextConverter::operator=( other );
    m_Name = other.m_Name;
    m_ToUnicodeConvPattern = other.m_ToUnicodeConvPattern;
    m_Rules = other.m_Rules;

    return *this;
};

GenericTextConverter::reference GenericTextConverter::operator[]( size_type n ) {
    return m_Rules[ n ];
};

GenericTextConverter::const_reference GenericTextConverter::operator[]( size_type n ) const {
    return m_Rules[ n ];
};


AbstractTextConverter* GenericTextConverter::doClone() const {
    return new GenericTextConverter( *this );
};

const QString& GenericTextConverter::doName() const {
    return m_Name;
};

QString GenericTextConverter::doFromUnicode( const QChar* str, int len ) const {
    return QString( str, len );
};

QString GenericTextConverter::doToUnicode( const QChar* str, int len ) const {
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
