//---------------------------------------------------------------------------------------
/*!
    \file genericresource.h
    \brief
*/

//---------------------------------------------------------------------------------------
#ifndef __TOOLKIT_RESOURCE_GENERICRESOURCE_H__
#define __TOOLKIT_RESOURCE_GENERICRESOURCE_H__

// Include Toolkit Resource Files
#include "abstractresource.h"

//---------------------------------------------------------------------------------------
namespace Toolkit {

    namespace Resource {
        //---------------------------------------------------------------------------------------
        /*!
            \ingroup grp_Resources
            \brief Implements a generic resource based on QVariant to hold the most common data types.

        */
        class TOOLKIT_RESOURCE_API GenericResource : public AbstractResource {
        public:
            //!\name Constructors & Destructor
            //@{
            GenericResource( const QString& key = QString::null, const QVariant& value = AbstractResource::NULL_VALUE );
            GenericResource( const GenericResource& other );
            virtual ~GenericResource();
            //@}

            //!\name Properties
            //@{
            const QVariant& getData() const;
            void setData( const QVariant& newData );
            //@}

            //!\name Operators
            //@{
            GenericResource& operator=( const GenericResource& other );
            //@}

        private:
            //!\name Converters
            //@{
            virtual const QVariant& doToVariant() const;
            //@}

        private:
            //!\name Properties
            //@{
            /*!
                \brief Resource data.

                \sa
                    getData() and setData()
            */
            QVariant m_Data;
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
