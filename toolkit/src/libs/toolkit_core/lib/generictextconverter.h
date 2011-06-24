//-------------------------------------------------------------------------------------------------
/*!
    \file generictextconverter.h
    \brief
*/

//-------------------------------------------------------------------------------------------------
#ifndef __TOOLKIT_CORE_GENERICTEXTCONVERTER_H__
#define __TOOLKIT_CORE_GENERICTEXTCONVERTER_H__

// Include Toolkit Files
#include "defines.h"
#include "abstractcharconverter.h"
#include "abstracttextconverter.h"

// Include Qt Files
#include <QSharedPointer>
#include <QTextCodec>

// Include STD Files
#include <vector>

//-------------------------------------------------------------------------------------------------
namespace Toolkit {

    namespace Core {
        //---------------------------------------------------------------------------------------------
        /*!
            \ingroup grp_TextConverters
            \brief
        */
        class TOOLKIT_CORE_API GenericTextConverter : public AbstractTextConverter {
        public:
            typedef QSharedPointer<AbstractCharConverter> item_type;
            typedef std::vector<item_type> container_type;
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
            GenericTextConverter();
            GenericTextConverter( const GenericTextConverter& other );
            virtual ~GenericTextConverter();
            //@}

            //!\name Properties
            //@{
            const QString& getName() const;
            void setName( const QString& newName );
            const QString& getToUnicodeConvPattern() const;
            void setToUnicodeConvPattern( const QString& newToUnicodeConvPattern );
            //@}

            //!\name Rules
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

            //!\name Operator
            //@{
            GenericTextConverter& operator=( const GenericTextConverter& other );
            reference operator[]( size_type n );
            const_reference operator[]( size_type n ) const;
            //@}

        private:
            //!\name Class
            //@{
            virtual AbstractTextConverter* doClone() const;
            virtual const QString& doName() const;
            //@}

            //!\name Converter interface
            //@{
            virtual QString doFromUnicode( const QChar* str, int len ) const;
            virtual QString doToUnicode( const QChar* str, int len ) const;
            //@}

        private:
            //!\name Properties
            //@{
            QString m_Name;
            QString m_ToUnicodeConvPattern;
            container_type m_Rules;
            //@}
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
