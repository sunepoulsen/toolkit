//-------------------------------------------------------------------------------------------------
/*!
    \file modelitem.h
    \brief
*/

//-------------------------------------------------------------------------------------------------
#ifndef __TOOLKIT_CORE_MODELITEM_H__
#define __TOOLKIT_CORE_MODELITEM_H__

// Include Toolkit Core Files
#include "defines.h"
#include "modelcolumns.h"

// Include Qt Files
#include <QModelIndex>

// Include STD Files
#include <vector>

//-------------------------------------------------------------------------------------------------
namespace Toolkit {

    namespace Core {
        //---------------------------------------------------------------------------------------------
        /*!
            \brief
            \ingroup grp_Models
        */
        class TOOLKIT_CORE_API ModelItem {
        public:
            typedef std::vector<ModelItem*> container_type;
            typedef container_type::iterator iterator;
            typedef container_type::const_iterator const_iterator;
            typedef container_type::reverse_iterator reverse_iterator;
            typedef container_type::const_reverse_iterator const_reverse_iterator;
            typedef container_type::reference reference;
            typedef container_type::const_reference const_reference;
            typedef container_type::size_type size_type;
            typedef container_type::value_type value_type;
            typedef container_type::pointer pointer;

        public:
            //!\name Constructors & Destructor
            //@{
            ModelItem( ModelItem* parent = NULL );
            virtual ~ModelItem();
            //@}

            //!\name Properties
            //@{
            const ModelItem* getParent() const;
            ModelItem* getParent();
            void setParent( ModelItem* newParent );
            //@}

            //!\name Items
            //@{
            iterator begin();
            const_iterator begin() const;
            iterator end();
            const_iterator end() const;
            reverse_iterator rbegin();
            const_reverse_iterator rbegin() const;
            reverse_iterator rend();
            const_reverse_iterator rend() const;
            reference front();
            const_reference front() const;
            reference back();
            const_reference back() const;
            void clear();
            bool empty() const;
            size_type size() const;
            void resize( size_type n, value_type t = value_type() );
            size_type max_size() const;
            size_type capacity() const;
            void reserve( size_type n );
            iterator insert( iterator pos, const value_type& col );

            template <class InputIterator>
            void insert( iterator pos, InputIterator __begin, InputIterator __end ) {
                m_Items.insert( pos, __begin, __end );
            }

            void insert( iterator pos, size_type n, const value_type& col );
            iterator erase( iterator pos );
            iterator erase( iterator __begin, iterator __end );
            void push_back( const value_type& col );
            void pop_back();
            //@}

            //!\name Model receivers
            //@{
            bool canFetchMore() const;
            void fetchMore();
            Qt::ItemFlags flags( const ModelColumn& col ) const;
            QVariant getAccessibleDescription( const ModelColumn& col ) const;
            bool setAccessibleDescription( const ModelColumn& col, const QVariant& newAccessibleDescription );
            QVariant getAccessibleText( const ModelColumn& col ) const;
            bool setAccessibleText( const ModelColumn& col, const QVariant& newAccessibleText );
            QVariant getBackground( const ModelColumn& col ) const;
            bool setBackground( const ModelColumn& col, const QVariant& newBackground );
            QVariant getCheckState( const ModelColumn& col ) const;
            bool setCheckState( const ModelColumn& col, const QVariant& newCheckState );
            QVariant getDecoration( const ModelColumn& col ) const;
            bool setDecoration( const ModelColumn& col, const QVariant& newDecoration );
            QVariant getFont( const ModelColumn& col ) const;
            bool setFont( const ModelColumn& col, const QVariant& newFont );
            QVariant getForeground( const ModelColumn& col ) const;
            bool setForeground( const ModelColumn& col, const QVariant& newForeground );
            QVariant getEditValue( const ModelColumn& col ) const;
            bool setEditValue( const ModelColumn& col, const QVariant& newEditValue );
            QVariant getSizeHint( const ModelColumn& col ) const;
            bool setSizeHint( const ModelColumn& col, const QVariant& newSizeHint );
            QVariant getStatusTip( const ModelColumn& col ) const;
            bool setStatusTip( const ModelColumn& col, const QVariant& newStatusTip );
            QVariant getTextAlignment( const ModelColumn& col ) const;
            bool setTextAlignment( const ModelColumn& col, const QVariant& newTextAlignment );
            QVariant getToolTip( const ModelColumn& col ) const;
            bool setToolTip( const ModelColumn& col, const QVariant& newToolTip );
            QVariant getValue( const ModelColumn& col ) const;
            bool setValue( const ModelColumn& col, const QVariant& newValue );
            QVariant getWhatsThis( const ModelColumn& col ) const;
            bool setWhatsThis( const ModelColumn& col, const QVariant& newWhatsThis );
            //@}

            //!\name Operators
            //@{
            reference operator[]( size_type n );
            const_reference operator[]( size_type n ) const;
            //@}

            //!\name Helpers
            //@{
            static ModelItem* indexData( const QModelIndex& index );
            //@}

        private:
            //!\name Virtual interface
            //@{
            virtual bool doCanFetchMore() const;
            virtual void doFetchMore();
            virtual Qt::ItemFlags doFlags( const ModelColumn& col ) const;
            virtual QVariant doGetAccessibleDescription( const ModelColumn& col ) const;
            virtual bool doSetAccessibleDescription( const ModelColumn& col, const QVariant& newAccessibleDescription );
            virtual QVariant doGetAccessibleText( const ModelColumn& col ) const;
            virtual bool doSetAccessibleText( const ModelColumn& col, const QVariant& newAccessibleText );
            virtual QVariant doGetBackground( const ModelColumn& col ) const;
            virtual bool doSetBackground( const ModelColumn& col, const QVariant& newBackground );
            virtual QVariant doGetCheckState( const ModelColumn& col ) const;
            virtual bool doSetCheckState( const ModelColumn& col, const QVariant& newCheckState );
            virtual QVariant doGetDecoration( const ModelColumn& col ) const;
            virtual bool doSetDecoration( const ModelColumn& col, const QVariant& newDecoration );
            virtual QVariant doGetFont( const ModelColumn& col ) const;
            virtual bool doSetFont( const ModelColumn& col, const QVariant& newFont );
            virtual QVariant doGetForeground( const ModelColumn& col ) const;
            virtual bool doSetForeground( const ModelColumn& col, const QVariant& newForeground );
            virtual QVariant doGetEditValue( const ModelColumn& col ) const;
            virtual bool doSetEditValue( const ModelColumn& col, const QVariant& newEditValue );
            virtual QVariant doGetSizeHint( const ModelColumn& col ) const;
            virtual bool doSetSizeHint( const ModelColumn& col, const QVariant& newSizeHint );
            virtual QVariant doGetStatusTip( const ModelColumn& col ) const;
            virtual bool doSetStatusTip( const ModelColumn& col, const QVariant& newStatusTip );
            virtual QVariant doGetTextAlignment( const ModelColumn& col ) const;
            virtual bool doSetTextAlignment( const ModelColumn& col, const QVariant& newTextAlignment );
            virtual QVariant doGetToolTip( const ModelColumn& col ) const;
            virtual bool doSetToolTip( const ModelColumn& col, const QVariant& newToolTip );
            virtual QVariant doGetValue( const ModelColumn& col ) const;
            virtual bool doSetValue( const ModelColumn& col, const QVariant& newValue );
            virtual QVariant doGetWhatsThis( const ModelColumn& col ) const;
            virtual bool doSetWhatsThis( const ModelColumn& col, const QVariant& newWhatsThis );
            //@}

        private:
            ModelItem* m_Parent;
            container_type m_Items;

        private:
            Q_DISABLE_COPY( ModelItem )
        };

    };

};

#endif

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
