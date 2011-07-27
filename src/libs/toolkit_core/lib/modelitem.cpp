//-------------------------------------------------------------------------------------------------
/*!
    \file modelitem.h
    \brief
*/

//-------------------------------------------------------------------------------------------------

// Include Header File
#include "modelitem.h"

// Include Toolkit Core Files
#include "stl.h"

// Include STL Files
#include <algorithm>

//-------------------------------------------------------------------------------------------------
using namespace Toolkit::Core;

//-------------------------------------------------------------------------------------------------
ModelItem::ModelItem( ModelItem* parent ) :
    m_Parent( parent ),
    m_Items()
{
}

ModelItem::~ModelItem() {
    clear();
}

const ModelItem* ModelItem::getParent() const {
    return m_Parent;
}

ModelItem* ModelItem::getParent() {
    return m_Parent;
}

void ModelItem::setParent( ModelItem* newParent ) {
    m_Parent = newParent;
}

ModelItem::iterator ModelItem::begin() {
    return m_Items.begin();
}

ModelItem::const_iterator ModelItem::begin() const {
    return m_Items.begin();
}

ModelItem::iterator ModelItem::end() {
    return m_Items.end();
}

ModelItem::const_iterator ModelItem::end() const {
    return m_Items.end();
}

ModelItem::reverse_iterator ModelItem::rbegin() {
    return m_Items.rbegin();
}

ModelItem::const_reverse_iterator ModelItem::rbegin() const {
    return m_Items.rbegin();
}

ModelItem::reverse_iterator ModelItem::rend() {
    return m_Items.rend();
}

ModelItem::const_reverse_iterator ModelItem::rend() const {
    return m_Items.rend();
}

ModelItem::reference ModelItem::front() {
    return m_Items.front();
}

ModelItem::const_reference ModelItem::front() const {
    return m_Items.front();
}

ModelItem::reference ModelItem::back() {
    return m_Items.back();
}

ModelItem::const_reference ModelItem::back() const {
    return m_Items.back();
}

void ModelItem::clear() {
    std::for_each( begin(), end(), Destroy<ModelItem>() );
    m_Items.clear();
}

bool ModelItem::empty() const {
    return m_Items.empty();
}

ModelItem::size_type ModelItem::size() const {
    return m_Items.size();
}

void ModelItem::resize( size_type n, value_type t ) {
    m_Items.resize( n, t );
}

ModelItem::size_type ModelItem::max_size() const {
    return m_Items.max_size();
}

ModelItem::size_type ModelItem::capacity() const {
    return m_Items.capacity();
}

void ModelItem::reserve( size_type n ) {
    m_Items.reserve( n );
}

ModelItem::iterator ModelItem::insert( iterator pos, const value_type& v ) {
    return m_Items.insert( pos, v );
}

void ModelItem::insert( iterator pos, size_type n, const value_type& v ) {
    m_Items.insert( pos, n, v );
}

ModelItem::iterator ModelItem::erase( iterator pos ) {
    delete *pos;
    return m_Items.erase( pos );
}

ModelItem::iterator ModelItem::erase( iterator __begin, iterator __end ) {
    std::for_each( __begin, __end, Destroy<ModelItem>() );
    return m_Items.erase( __begin, __end );
}

void ModelItem::push_back( const value_type& v ) {
    if( v ) {
        v->setParent( this );
    };

    return m_Items.push_back( v );
}

void ModelItem::pop_back() {
    return m_Items.pop_back();
}

bool ModelItem::canFetchMore() const {
    return doCanFetchMore();
}

void ModelItem::fetchMore() {
    doFetchMore();
}

Qt::ItemFlags ModelItem::flags( const ModelColumn& col ) const {
    return doFlags( col );
}

QVariant ModelItem::getAccessibleDescription( const ModelColumn& col ) const {
    return doGetAccessibleDescription( col );
}

bool ModelItem::setAccessibleDescription( const ModelColumn& col, const QVariant& newAccessibleDescription ) {
    return doSetAccessibleDescription( col, newAccessibleDescription );
}

QVariant ModelItem::getAccessibleText( const ModelColumn& col ) const {
    return doGetAccessibleText( col );
}

bool ModelItem::setAccessibleText( const ModelColumn& col, const QVariant& newAccessibleText ) {
    return doSetAccessibleText( col, newAccessibleText );
}

QVariant ModelItem::getBackground( const ModelColumn& col ) const {
    return doGetBackground( col );
}

bool ModelItem::setBackground( const ModelColumn& col, const QVariant& newBackground ) {
    return doSetBackground( col, newBackground );
}

QVariant ModelItem::getCheckState( const ModelColumn& col ) const {
    return doGetCheckState( col );
}

bool ModelItem::setCheckState( const ModelColumn& col, const QVariant& newCheckState ) {
    return doSetCheckState( col, newCheckState );
}

QVariant ModelItem::getDecoration( const ModelColumn& col ) const {
    return doGetDecoration( col );
}

bool ModelItem::setDecoration( const ModelColumn& col, const QVariant& newDecoration ) {
    return doSetDecoration( col, newDecoration );
}

QVariant ModelItem::getFont( const ModelColumn& col ) const {
    return doGetFont( col );
}

bool ModelItem::setFont( const ModelColumn& col, const QVariant& newFont ) {
    return doSetFont( col, newFont );
}

QVariant ModelItem::getForeground( const ModelColumn& col ) const {
    return doGetForeground( col );
}

bool ModelItem::setForeground( const ModelColumn& col, const QVariant& newForeground ) {
    return doSetForeground( col, newForeground );
}

QVariant ModelItem::getEditValue( const ModelColumn& col ) const {
    return doGetEditValue( col );
}

bool ModelItem::setEditValue( const ModelColumn& col, const QVariant& newEditValue ) {
    return doSetEditValue( col, newEditValue );
}

QVariant ModelItem::getSizeHint( const ModelColumn& col ) const {
    return doGetSizeHint( col );
}

bool ModelItem::setSizeHint( const ModelColumn& col, const QVariant& newSizeHint ) {
    return doSetSizeHint( col, newSizeHint );
}

QVariant ModelItem::getStatusTip( const ModelColumn& col ) const {
    return doGetStatusTip( col );
}

bool ModelItem::setStatusTip( const ModelColumn& col, const QVariant& newStatusTip ) {
    return doSetStatusTip( col, newStatusTip );
}

QVariant ModelItem::getTextAlignment( const ModelColumn& col ) const {
    return doGetTextAlignment( col );
}

bool ModelItem::setTextAlignment( const ModelColumn& col, const QVariant& newTextAlignment ) {
    return doSetTextAlignment( col, newTextAlignment );
}

QVariant ModelItem::getToolTip( const ModelColumn& col ) const {
    return doGetToolTip( col );
}

bool ModelItem::setToolTip( const ModelColumn& col, const QVariant& newToolTip ) {
    return doSetToolTip( col, newToolTip );
}

QVariant ModelItem::getValue( const ModelColumn& col ) const {
    return doGetValue( col );
}

bool ModelItem::setValue( const ModelColumn& col, const QVariant& newValue ) {
    return doSetValue( col, newValue );
}

QVariant ModelItem::getWhatsThis( const ModelColumn& col ) const {
    return doGetWhatsThis( col );
}

bool ModelItem::setWhatsThis( const ModelColumn& col, const QVariant& newWhatsThis ) {
    return doSetWhatsThis( col, newWhatsThis );
}

ModelItem::reference ModelItem::operator[]( size_type n ) {
    return m_Items[ n ];
}

ModelItem::const_reference ModelItem::operator[]( size_type n ) const {
    return m_Items[ n ];
}

ModelItem* ModelItem::indexData( const QModelIndex& index ) {
    if( !index.isValid() ) {
        return NULL;
    };

    ModelItem* obj = reinterpret_cast<ModelItem*>( index.internalPointer() );
    return static_cast<ModelItem*>( obj );
}

bool ModelItem::doCanFetchMore() const {
    return !empty();
}

void ModelItem::doFetchMore() {
}

Qt::ItemFlags ModelItem::doFlags( const ModelColumn& ) const {
    return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

QVariant ModelItem::doGetAccessibleDescription( const ModelColumn& ) const {
    return QVariant();
}

bool ModelItem::doSetAccessibleDescription( const ModelColumn&, const QVariant& ) {
    return false;
}

QVariant ModelItem::doGetAccessibleText( const ModelColumn& ) const {
    return QVariant();
}

bool ModelItem::doSetAccessibleText( const ModelColumn&, const QVariant& ) {
    return false;
}

QVariant ModelItem::doGetBackground( const ModelColumn& ) const {
    return QVariant();
}

bool ModelItem::doSetBackground( const ModelColumn&, const QVariant& ) {
    return false;
}

QVariant ModelItem::doGetCheckState( const ModelColumn& ) const {
    return QVariant();
}

bool ModelItem::doSetCheckState( const ModelColumn&, const QVariant& ) {
    return false;
}

QVariant ModelItem::doGetDecoration( const ModelColumn& ) const {
    return QVariant();
}

bool ModelItem::doSetDecoration( const ModelColumn&, const QVariant& ) {
    return false;
}

QVariant ModelItem::doGetFont( const ModelColumn& ) const {
    return QVariant();
}

bool ModelItem::doSetFont( const ModelColumn&, const QVariant& ) {
    return false;
}

QVariant ModelItem::doGetForeground( const ModelColumn& ) const {
    return QVariant();
}

bool ModelItem::doSetForeground( const ModelColumn&, const QVariant& ) {
    return false;
}

QVariant ModelItem::doGetEditValue( const ModelColumn& ) const {
    return QVariant();
}

bool ModelItem::doSetEditValue( const ModelColumn&, const QVariant& ) {
    return false;
}

QVariant ModelItem::doGetSizeHint( const ModelColumn& ) const {
    return QVariant();
}

bool ModelItem::doSetSizeHint( const ModelColumn&, const QVariant& ) {
    return false;
}

QVariant ModelItem::doGetStatusTip( const ModelColumn& ) const {
    return QVariant();
}

bool ModelItem::doSetStatusTip( const ModelColumn&, const QVariant& ) {
    return false;
}

QVariant ModelItem::doGetTextAlignment( const ModelColumn& col ) const {
    return QVariant( col.getAlignment() );
}

bool ModelItem::doSetTextAlignment( const ModelColumn&, const QVariant& ) {
    return false;
}

QVariant ModelItem::doGetToolTip( const ModelColumn& ) const {
    return QVariant();
}

bool ModelItem::doSetToolTip( const ModelColumn&, const QVariant& ) {
    return false;
}

QVariant ModelItem::doGetValue( const ModelColumn& ) const {
    return QVariant();
}

bool ModelItem::doSetValue( const ModelColumn&, const QVariant& ) {
    return false;
}

QVariant ModelItem::doGetWhatsThis( const ModelColumn& ) const {
    return QVariant();
}

bool ModelItem::doSetWhatsThis( const ModelColumn&, const QVariant& ) {
    return false;
}

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
