//---------------------------------------------------------------------------------------
/*!
    \file imageresource.h
    \brief
*/

//---------------------------------------------------------------------------------------
#ifndef __TOOLKIT_RESOURCE_IMAGERESOURCE_H__
#define __TOOLKIT_RESOURCE_IMAGERESOURCE_H__

// Include Toolkit Resource Files
#include "genericresource.h"

//---------------------------------------------------------------------------------------
namespace Toolkit {

    namespace Resource {
        //---------------------------------------------------------------------------------------
        /*!
            \ingroup grp_Resources
            \brief

        */
        class TOOLKIT_RESOURCE_API ImageResource : public GenericResource {
        public:
            //!\name Constructors & Destructor
            //@{
            ImageResource( const QString& key = QString::null );
            ImageResource( const ImageResource& other );
            virtual ~ImageResource();
            //@}

            //!\name Properties
            //@{
            const QString& getFileName() const;
            void setFileName( const QString& newFileName );
            //@}

            //!\name Operators
            //@{
            ImageResource& operator=( const ImageResource& other );
            //@}

        private:
            //!\name Properties
            //@{
            /*!
                \brief
            */
            QString m_FileName;
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
