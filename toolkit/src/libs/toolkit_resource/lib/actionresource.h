//---------------------------------------------------------------------------------------
/*!
    \file actionresource.h
    \brief
*/

//---------------------------------------------------------------------------------------
#ifndef __TOOLKIT_RESOURCE_ACTIONRESOURCE_H__
#define __TOOLKIT_RESOURCE_ACTIONRESOURCE_H__

// Include Toolkit Resource Files
#include "abstractresource.h"

// Include Qt Files
#include <QAction>

//---------------------------------------------------------------------------------------
namespace Toolkit {

    namespace Resource {
        //---------------------------------------------------------------------------------------
        /*!
            \ingroup grp_Resources
            \brief Implements an action resource to be used with menus and toolbars.

        */
        class TOOLKIT_RESOURCE_API ActionResource : public AbstractResource {
        public:
            //!\name Sub items vector typedefs
            //@{
            typedef std::vector<QSharedPointer<ActionResource> > container_type;
            typedef container_type::iterator iterator;
            typedef container_type::const_iterator const_iterator;
            typedef container_type::reverse_iterator reverse_iterator;
            typedef container_type::const_reverse_iterator const_reverse_iterator;
            typedef container_type::reference reference;
            typedef container_type::const_reference const_reference;
            typedef container_type::size_type size_type;
            typedef container_type::value_type value_type;
            //@}

            /*!
                \brief Action type of this action.

                The action type specifies what type of control that will be created in the
                menu or toolbar, that this action belongs to.
            */
            enum ActionType {
                AT_ITEM = 1,      //!< An item with title, icon, shortcut, etc.
                AT_SEPARATOR = 2, //!< A separator.
                AT_GROUP = 3,     //!< A group (with title and icon) of items.
                AT_SUBMENU = 4    //!< A submenu item with title and icon.
            };

        public:
            //!\name Constructors & Destructor
            //@{
            ActionResource( const QString& key = QString::null );
            ActionResource( const ActionResource& other );
            virtual ~ActionResource();
            //@}

            //!\name Properties
            //@{
            ActionType getType() const;
            void setType( ActionType newType );
            bool getAutoRepeat() const;
            void setAutoRepeat( bool newAutoRepeat );
            bool getCheckable() const;
            void setCheckable( bool newCheckable );
            bool getChecked() const;
            void setChecked( bool newChecked );
            const QVariant& getData() const;
            void setData( const QVariant& newData );
            const QFont& getFont() const;
            void setFont( const QFont& newFont );
            const QIcon& getIcon() const;
            void setIcon( const QIcon& newIcon );
            bool getIconVisibleInMenu() const;
            void setIconVisibleInMenu( bool newIconVisibleInMenu );
            QAction::MenuRole getMenuRole() const;
            void setMenuRole( QAction::MenuRole newMenuRole );
            const QKeySequence& getShortcut() const;
            void setShortcut( const QKeySequence& newShortcut );
            Qt::ShortcutContext getShortcutContext() const;
            void setShortcutContext( Qt::ShortcutContext newShortcutContext );
            const QString& getStatusTip() const;
            void setStatusTip( const QString& newStatusTip );
            const QString& getText() const;
            void setText( const QString& newText );
            const QString& getTooltip() const;
            void setTooltip( const QString& newTooltip );
            bool getVisible() const;
            void setVisible( bool newVisible );
            const QString& getWhatsThis() const;
            void setWhatsThis( const QString& newWhatsThis );
            //@}

            //!\name Sub action items
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

            //!\name Converters
            //@{
            QAction* toQAction() const;
            QMenu* toMenu() const;
            QMenu* appendToMenu( QMenu* menu ) const;
            //@}

            //!\name Operators
            //@{
            ActionResource& operator=( const ActionResource& other );
            reference operator[]( size_type n );
            const_reference operator[]( size_type n ) const;
            //@}

        public:
            //!\name Factories
            //@{
            static value_type newItem( const QString& title, const QVariant& data = QVariant(), const QKeySequence& shortcut = QKeySequence(), const QIcon& icon = QIcon() );
            static value_type newSeparator( const QString& title = QString::null );
            static value_type newGroup();
            static value_type newMenu( const QString& title, const QIcon& icon = QIcon() );
            //@}

        private:
            //!\name Properties
            //@{
            ActionType m_Type;
            bool m_AutoRepeat;
            bool m_Checkable;
            bool m_Checked;
            QVariant m_Data;
            QFont m_Font;
            QIcon m_Icon;
            bool m_IconVisibleInMenu;
            QAction::MenuRole m_MenuRole;
            QKeySequence m_Shortcut;
            Qt::ShortcutContext m_ShortcutContext;
            QString m_StatusTip;
            QString m_Text;
            QString m_Tooltip;
            bool m_Visible;
            QString m_WhatsThis;
            //@}

            //!\name Sub menu items
            //@{
            container_type m_SubItems;
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
