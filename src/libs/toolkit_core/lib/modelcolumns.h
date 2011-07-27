//-------------------------------------------------------------------------------------------------
/*!
    \file modelcolumns.h
    \brief 
*/

//-------------------------------------------------------------------------------------------------
#ifndef __TOOLKIT_CORE_MODELCOLUMNS_H__
#define __TOOLKIT_CORE_MODELCOLUMNS_H__

// Include Toolkit Core Files
#include "defines.h"

// Include Qt Files
#include <QVariant>

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
        class TOOLKIT_CORE_API ModelColumn {
        public:
            //!\name Constructors & Destructor
            //@{
            ModelColumn();
            ModelColumn( const QString& id, const QString& title, Qt::Alignment align = Qt::AlignLeft | Qt::AlignVCenter );
            ModelColumn( const ModelColumn& other );
            virtual ~ModelColumn();
            //@}
            
            //!\name Properties
            //@{
            const QString& getId() const;
            void setId( const QString& newId );
            const QString& getTitle() const;
            void setTitle( const QString& newTitle );
            Qt::Alignment getAlignment() const;
            void setAlignment( Qt::Alignment newAlign );
            //@}
            
            //!\name Operators
            //@{
            ModelColumn& operator=( const ModelColumn& other );
            //@}
            
        private:
            //!\name Properties
            //@{
            QString m_Id;
            QString m_Title;
            Qt::Alignment m_Alignment;
            //@}
        };
        
        //---------------------------------------------------------------------------------------------
        /*!
            \brief
            \ingroup grp_Models
        */
        class TOOLKIT_CORE_API ModelColumnContainer {
        public:
            typedef std::vector<ModelColumn> container_type;
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
            ModelColumnContainer();
            ModelColumnContainer( const ModelColumnContainer& other );
            virtual ~ModelColumnContainer();
            //@}
            
            //!\name Columns
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
            void insert( iterator pos, InputIterator __begin, InputIterator __end );
            void insert( iterator pos, size_type n, const value_type& col );
            iterator erase( iterator pos );
            iterator erase( iterator __begin, iterator __end );
            void push_back( const value_type& col );
            void pop_back();
            //@}
            
            //!\name Qt Model Helpers
            //@{
            QVariant headerData( int section, int role ) const;
            //@}
            
            //!\name Operators
            //@{
            ModelColumnContainer& operator=( const ModelColumnContainer& other );
            reference operator[]( size_type n );
            const_reference operator[]( size_type n ) const;
            //@}
            
        private:
            container_type m_Columns;
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
