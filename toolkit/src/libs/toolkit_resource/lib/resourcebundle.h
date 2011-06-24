//---------------------------------------------------------------------------------------
/*!
    \file resourcebundle.h
    \brief
*/

//---------------------------------------------------------------------------------------
#ifndef __TOOLKIT_RESOURCE_RESOURCEBUNDLE_H__
#define __TOOLKIT_RESOURCE_RESOURCEBUNDLE_H__

// Include Toolkit Resource Files
#include "defines.h"
#include "groupresource.h"

//---------------------------------------------------------------------------------------
class QMenu;
class QMenuBar;

//---------------------------------------------------------------------------------------
namespace Toolkit {

    namespace Resource {
        //---------------------------------------------------------------------------------------
        /*!
            \ingroup grp_Resources
            \brief
        */
        class TOOLKIT_RESOURCE_API ResourceBundle {
        public:
            static const QString PATH_SEP;

        public:
            //!\name Constructors & Destructor
            //@{
            ResourceBundle( const QString& id = QString::null );
            ResourceBundle( const ResourceBundle& other );
            virtual ~ResourceBundle();
            //@}

            //!\name Properties
            //@{
            const QString& getId() const;
            void setId( const QString& newId );
            const GroupResource::Pointer& getResources() const;
            void setResources( GroupResource::Pointer& newResources );
            //@}

            //!\name Resources
            //@{
            QString getString( const QString& keyPath, const QString& defValue = QString::null ) const;

            template< typename Type >
            Type getValue( const QString& keyPath, const Type& defValue = Type() ) const {
                const AbstractResource::Pointer res = findResource( keyPath );
                if( res && res->toVariant().canConvert<Type>() ) {
                    return res->toVariant().value<Type>();
                };

                return defValue;
            };

            QMenu* getMenu( const QString& keyPath ) const;
            QMenuBar* getMenuBar( const QString& keyPath ) const;
            //@}

            //!\name Lookups
            //@{
            const AbstractResource::Pointer findResource( const QString& keyPath ) const;
            const AbstractResource::Pointer findResource( const GroupResource::Pointer& root, const QString& keyPath ) const;
            const AbstractResource::Pointer findResource( const GroupResource::Pointer& root, const QStringList& keyPath, int index = 0 ) const;
            //@}

            //!\name Operators
            //@{
            ResourceBundle& operator=( const ResourceBundle& other );
            //@}

        private:
            //!\name Properties
            //@{
            QString m_Id;
            GroupResource::Pointer m_Resources;
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
