//---------------------------------------------------------------------------------------
/*!
    \file menuresource.h
    \brief
*/

//---------------------------------------------------------------------------------------
#ifndef __TOOLKIT_RESOURCE_MENURESOURCE_H__
#define __TOOLKIT_RESOURCE_MENURESOURCE_H__

// Include Toolkit Resource Files
#include "actionresource.h"

// Include Qt Files
#include <QAction>

//---------------------------------------------------------------------------------------
class QMenu;
class QMenuBar;

//---------------------------------------------------------------------------------------
namespace Toolkit {

    namespace Resource {
        //---------------------------------------------------------------------------------------
        /*!
            \ingroup grp_Resources
            \brief Implements a menu resource.

        */
        class TOOLKIT_RESOURCE_API MenuResource : public AbstractResource {
        public:
            //!\name Constructors & Destructor
            //@{
            MenuResource( const QString& key = QString::null );
            MenuResource( const MenuResource& other );
            virtual ~MenuResource();
            //@}

            //!\name Properties
            //@{
            const ActionResource& getActions() const;
            void setActions( const ActionResource& newActions );
            //@}

            //!\name Converters
            //@{
            QMenu* toMenu() const;
            QMenuBar* toMenuBar() const;
            QMenu* appendToMenu( QMenu* menu ) const;
            QMenuBar* appendToMenuBar( QMenuBar* menuBar ) const;
            //@}

            //!\name Operators
            //@{
            MenuResource& operator=( const MenuResource& other );
            //@}

        private:
            //!\name Properties
            //@{
            ActionResource m_Actions;
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
