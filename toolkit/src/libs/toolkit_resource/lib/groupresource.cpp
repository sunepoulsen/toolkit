//---------------------------------------------------------------------------------------
/*!
    \file groupresource.h
    \brief 
*/
//---------------------------------------------------------------------------------------

// Include Header File
#include "groupresource.h"

//---------------------------------------------------------------------------------------
using namespace Toolkit::Resource;

//---------------------------------------------------------------------------------------
GroupResource::GroupResource( const QString& key ) :
	AbstractResource( key ),
	m_Resources()
{
};

GroupResource::GroupResource( const GroupResource& other ) :
	AbstractResource( other ),
	m_Resources( other.m_Resources )
{
};

GroupResource::~GroupResource() {
};

GroupResource::iterator GroupResource::begin() {
	return m_Resources.begin();
};

GroupResource::const_iterator GroupResource::begin() const {
	return m_Resources.begin();
};

GroupResource::iterator GroupResource::end() {
	return m_Resources.end();
};

GroupResource::const_iterator GroupResource::end() const {
	return m_Resources.end();
};

GroupResource::reverse_iterator GroupResource::rbegin() {
	return m_Resources.rbegin();
};

GroupResource::const_reverse_iterator GroupResource::rbegin() const {
	return m_Resources.rbegin();
};

GroupResource::reverse_iterator GroupResource::rend() {
	return m_Resources.rend();
};

GroupResource::const_reverse_iterator GroupResource::rend() const {
	return m_Resources.rend();
};

GroupResource::reference GroupResource::front() {
	return m_Resources.front();
};

GroupResource::const_reference GroupResource::front() const {
	return m_Resources.front();
};

GroupResource::reference GroupResource::back() {
	return m_Resources.back();
};

GroupResource::const_reference GroupResource::back() const {
	return m_Resources.back();
};

void GroupResource::clear() {
	m_Resources.clear();
};

bool GroupResource::empty() const {
	return m_Resources.empty();
};

GroupResource::size_type GroupResource::size() const {
	return m_Resources.size();
};

void GroupResource::resize( size_type n, value_type t ) {
	m_Resources.resize( n, t );
};

GroupResource::size_type GroupResource::max_size() const {
	return m_Resources.max_size();
};

GroupResource::size_type GroupResource::capacity() const {
	return m_Resources.capacity();
};

void GroupResource::reserve( size_type n ) {
	m_Resources.reserve( n );
};

GroupResource::iterator GroupResource::insert( iterator pos, const value_type& res ) {
	return m_Resources.insert( pos, res );
};

template <class InputIterator>
void GroupResource::insert( iterator pos, InputIterator __begin, InputIterator __end ) {
	m_Resources.insert( pos, __begin, __end );
};

void GroupResource::insert( iterator pos, size_type n, const value_type& res ) {
	m_Resources.insert( pos, n, res );
};

GroupResource::iterator GroupResource::erase( iterator pos ) {
	return m_Resources.erase( pos );
};

GroupResource::iterator GroupResource::erase( iterator __begin, iterator __end ) {
	return m_Resources.erase( __begin, __end );
};

void GroupResource::push_back( const value_type& res ) {
	m_Resources.push_back( res );
};

void GroupResource::pop_back() {
	m_Resources.pop_back();
};

GroupResource& GroupResource::operator=( const GroupResource& other ) {
	AbstractResource::operator=( other );
	m_Resources = other.m_Resources;

	return *this;
};

GroupResource::reference GroupResource::operator[]( size_type n ) {
	return m_Resources[ n ];
};

GroupResource::const_reference GroupResource::operator[]( size_type n ) const {
	return m_Resources[ n ];
};

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
