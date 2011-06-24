//-------------------------------------------------------------------------------------------------
/*!
    \file modelcolumns.cpp
    \brief 
*/

//-------------------------------------------------------------------------------------------------

// Include Header File
#include "modelcolumns.h"

//-------------------------------------------------------------------------------------------------
using namespace Toolkit::Core;

//-------------------------------------------------------------------------------------------------
ModelColumn::ModelColumn() :
    m_Id(),
    m_Title(),
    m_Alignment()
{
};

ModelColumn::ModelColumn( const QString& id, const QString& title, Qt::Alignment align ) :
    m_Id( id ),
    m_Title( title ),
    m_Alignment( align )
{
};

ModelColumn::ModelColumn( const ModelColumn& other ) :
    m_Id( other.m_Id ),
    m_Title( other.m_Title ),
    m_Alignment( other.m_Alignment )
{
};

ModelColumn::~ModelColumn() {
};

const QString& ModelColumn::getId() const {
    return m_Id;
};

void ModelColumn::setId( const QString& newId ) {
    m_Id = newId;
};

const QString& ModelColumn::getTitle() const {
    return m_Title;
};

void ModelColumn::setTitle( const QString& newTitle ) {
    m_Title = newTitle;
};

Qt::Alignment ModelColumn::getAlignment() const {
    return m_Alignment;
};

void ModelColumn::setAlignment( Qt::Alignment newAlign ) {
    m_Alignment = newAlign;
};

ModelColumn& ModelColumn::operator=( const ModelColumn& other ) {
    m_Id = other.m_Id;
    m_Title = other.m_Title;
    m_Alignment = other.m_Alignment;
    
    return *this;
};

//-------------------------------------------------------------------------------------------------
ModelColumnContainer::ModelColumnContainer() :
    m_Columns()
{
};

ModelColumnContainer::ModelColumnContainer( const ModelColumnContainer& other ) :
    m_Columns( other.m_Columns )
{
};

ModelColumnContainer::~ModelColumnContainer() {
};

ModelColumnContainer::iterator ModelColumnContainer::begin() {
    return m_Columns.begin();
};

ModelColumnContainer::const_iterator ModelColumnContainer::begin() const {
    return m_Columns.begin();
};

ModelColumnContainer::iterator ModelColumnContainer::end() {
    return m_Columns.end();
};

ModelColumnContainer::const_iterator ModelColumnContainer::end() const {
    return m_Columns.end();
};

ModelColumnContainer::reverse_iterator ModelColumnContainer::rbegin() {
    return m_Columns.rbegin();
};

ModelColumnContainer::const_reverse_iterator ModelColumnContainer::rbegin() const {
    return m_Columns.rbegin();
};

ModelColumnContainer::reverse_iterator ModelColumnContainer::rend() {
    return m_Columns.rend();
};

ModelColumnContainer::const_reverse_iterator ModelColumnContainer::rend() const {
    return m_Columns.rend();
};

ModelColumnContainer::reference ModelColumnContainer::front() {
    return m_Columns.front();
};

ModelColumnContainer::const_reference ModelColumnContainer::front() const {
    return m_Columns.front();
};

ModelColumnContainer::reference ModelColumnContainer::back() {
    return m_Columns.back();
};

ModelColumnContainer::const_reference ModelColumnContainer::back() const {
    return m_Columns.back();
};

void ModelColumnContainer::clear() {
    m_Columns.clear();
};

bool ModelColumnContainer::empty() const {
    return m_Columns.empty();
};

ModelColumnContainer::size_type ModelColumnContainer::size() const {
    return m_Columns.size();
};

void ModelColumnContainer::resize( size_type n, value_type v ) {
    m_Columns.resize( n, v );
};

ModelColumnContainer::size_type ModelColumnContainer::max_size() const {
    return m_Columns.max_size();
};

ModelColumnContainer::size_type ModelColumnContainer::capacity() const {
    return m_Columns.capacity();
};

void ModelColumnContainer::reserve( size_type n ) {
    m_Columns.reserve( n );
};

ModelColumnContainer::iterator ModelColumnContainer::insert( iterator pos, const value_type& col ) {
    return m_Columns.insert( pos, col );
};

void ModelColumnContainer::insert( iterator pos, size_type n, const value_type& col ) {
    m_Columns.insert( pos, n, col );
};

ModelColumnContainer::iterator ModelColumnContainer::erase( iterator pos ) {
    return m_Columns.erase( pos );
};

ModelColumnContainer::iterator ModelColumnContainer::erase( iterator __begin, iterator __end ) {
    return m_Columns.erase( __begin, __end );
};

void ModelColumnContainer::push_back( const value_type& col ) {
    m_Columns.push_back( col );
};

void ModelColumnContainer::pop_back() {
    m_Columns.pop_back();
};

QVariant ModelColumnContainer::headerData( int section, int role ) const {
	if( (size_type)(section) < m_Columns.size() ) {
		if( role == Qt::DisplayRole ) {
			return QVariant( m_Columns[ section ].getTitle() );
		};

		if( role == Qt::TextAlignmentRole ) {
			return QVariant( m_Columns[ section ].getAlignment() );
		};
	};
    
	return QVariant();
};

ModelColumnContainer& ModelColumnContainer::operator=( const ModelColumnContainer& other ) {
    m_Columns = other.m_Columns;
    
    return *this;
};

ModelColumnContainer::reference ModelColumnContainer::operator[]( size_type n ) {
    return m_Columns[ n ];
};

ModelColumnContainer::const_reference ModelColumnContainer::operator[]( size_type n ) const {
    return m_Columns[ n ];
};

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
