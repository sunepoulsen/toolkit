//---------------------------------------------------------------------------------------
/*!
    \file resourcerepository.h
    \brief
*/

//---------------------------------------------------------------------------------------
#ifndef __TOOLKIT_RESOURCE_RESOURCEREPOSITORY_H__
#define __TOOLKIT_RESOURCE_RESOURCEREPOSITORY_H__

// Include Toolkit Resource Files
#include "defines.h"
#include "resourcebundle.h"

// Include Qt Files
#include <QLocale>

// Include STD Files
#include <map>

//---------------------------------------------------------------------------------------
namespace Toolkit {

    namespace Resource {
        //---------------------------------------------------------------------------------------
        /*!
            \ingroup grp_Resources
            \brief
        */
        class TOOLKIT_RESOURCE_API ResourceRepository {
        public:
            //!\name Cache types
            //@{
            typedef ResourceBundle data_type;
            typedef std::map<QString, data_type> container_type;
            typedef container_type::key_type key_type;
            typedef container_type::value_type value_type;
            typedef container_type::key_compare key_compare;
            typedef container_type::value_compare value_compare;
            typedef container_type::pointer pointer;
            typedef container_type::reference reference;
            typedef container_type::const_reference const_reference;
            typedef container_type::size_type size_type;
            typedef container_type::difference_type difference_type;
            typedef container_type::iterator iterator;
            typedef container_type::const_iterator const_iterator;
            typedef container_type::reverse_iterator reverse_iterator;
            typedef container_type::const_reverse_iterator const_reverse_iterator;
            //@}

        public:
            //!\name Constructors & Destructor
            //@{
            ResourceRepository( const QLocale& locale = QLocale() );
            ResourceRepository( const ResourceRepository& other );
            virtual ~ResourceRepository();
            //@}

            //!\name Properties
            //@{
            const QLocale& getLocale() const;
            void setLocale( const QLocale& newLocale );
            //@}

            //!\name Bundles
            //@{
            void clear();
            const_reference loadResources( const key_type& id ) const;
            const_reference loadBundle( const key_type& id ) const;
            //@}

            //!\name Operators
            //@{
            ResourceRepository& operator=( const ResourceRepository& other );
            data_type& operator[]( const key_type& key );
            //@}

        private:
            //!\name Properties
            //@{
            QLocale m_Locale;            
            //@}

            //!\name Cache
            //@{
            container_type m_Cache;
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
