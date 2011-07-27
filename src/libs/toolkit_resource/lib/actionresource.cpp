//---------------------------------------------------------------------------------------
/*!
    \file actionresource.h
    \brief
*/
//---------------------------------------------------------------------------------------

// Include Header File
#include "actionresource.h"

// Include Qt Files
#include <QAction>
#include <QApplication>
#include <QMenu>

// include Toolkit Core Files
#include <toolkit/core/log.h>

//---------------------------------------------------------------------------------------
using namespace Toolkit::Core;
using namespace Toolkit::Resource;

//---------------------------------------------------------------------------------------
ActionResource::ActionResource( const QString& key ) :
    AbstractResource( key ),
    m_Type( AT_ITEM ),
    m_AutoRepeat( true ),
    m_Checkable( false ),
    m_Checked( false ),
    m_Data(),
    m_Font( qApp->font() ),
    m_Icon(),
    m_IconVisibleInMenu( !QCoreApplication::testAttribute( Qt::AA_DontShowIconsInMenus ) ),
    m_MenuRole( QAction::TextHeuristicRole ),
    m_Shortcut(),
    m_ShortcutContext( Qt::WindowShortcut ),
    m_StatusTip(),
    m_Text(),
    m_Tooltip(),
    m_Visible( true ),
    m_WhatsThis(),
    m_SubItems()
{
};

ActionResource::ActionResource( const ActionResource& other ) :
    AbstractResource( other ),
    m_Type( other.m_Type ),
    m_AutoRepeat( other.m_AutoRepeat ),
    m_Checkable( other.m_Checkable ),
    m_Checked( other.m_Checked ),
    m_Data( other.m_Data ),
    m_Font( other.m_Font ),
    m_Icon( other.m_Icon ),
    m_IconVisibleInMenu( other.m_IconVisibleInMenu ),
    m_MenuRole( other.m_MenuRole ),
    m_Shortcut( other.m_Shortcut ),
    m_ShortcutContext( other.m_ShortcutContext ),
    m_StatusTip( other.m_StatusTip ),
    m_Text( other.m_Text ),
    m_Tooltip( other.m_Tooltip ),
    m_Visible( other.m_Visible ),
    m_WhatsThis( other.m_WhatsThis ),
    m_SubItems( other.m_SubItems )
{
};

ActionResource::~ActionResource() {
};

ActionResource::ActionType ActionResource::getType() const {
    return m_Type;
};

void ActionResource::setType( ActionType newType ) {
    m_Type = newType;
};

bool ActionResource::getAutoRepeat() const {
    return m_AutoRepeat;
};

void ActionResource::setAutoRepeat( bool newAutoRepeat ) {
    m_AutoRepeat = newAutoRepeat;
};

bool ActionResource::getCheckable() const {
    return m_Checkable;
};

void ActionResource::setCheckable( bool newCheckable ) {
    m_Checkable = newCheckable;
};

bool ActionResource::getChecked() const {
    return m_Checked;
};

void ActionResource::setChecked( bool newChecked ) {
    m_Checked = newChecked;
};

const QVariant& ActionResource::getData() const {
    return m_Data;
};

void ActionResource::setData( const QVariant& newData ) {
    m_Data = newData;
};

const QFont& ActionResource::getFont() const {
    return m_Font;
};

void ActionResource::setFont( const QFont& newFont ) {
    m_Font = newFont;
};

const QIcon& ActionResource::getIcon() const {
    return m_Icon;
};

void ActionResource::setIcon( const QIcon& newIcon ) {
    m_Icon = newIcon;
};

bool ActionResource::getIconVisibleInMenu() const {
    return m_IconVisibleInMenu;
};

void ActionResource::setIconVisibleInMenu( bool newIconVisibleInMenu ) {
    m_IconVisibleInMenu = newIconVisibleInMenu;
};

QAction::MenuRole ActionResource::getMenuRole() const {
    return m_MenuRole;
};

void ActionResource::setMenuRole( QAction::MenuRole newMenuRole ) {
    m_MenuRole = newMenuRole;
};

const QKeySequence& ActionResource::getShortcut() const {
    return m_Shortcut;
};

void ActionResource::setShortcut( const QKeySequence& newShortcut ) {
    m_Shortcut = newShortcut;
};

Qt::ShortcutContext ActionResource::getShortcutContext() const {
    return m_ShortcutContext;
};

void ActionResource::setShortcutContext( Qt::ShortcutContext newShortcutContext ) {
    m_ShortcutContext = newShortcutContext;
};

const QString& ActionResource::getStatusTip() const {
    return m_StatusTip;
};

void ActionResource::setStatusTip( const QString& newStatusTip ) {
    m_StatusTip = newStatusTip;
};

const QString& ActionResource::getText() const {
    return m_Text;
};

void ActionResource::setText( const QString& newText ) {
    m_Text = newText;
};

const QString& ActionResource::getTooltip() const {
    return m_Tooltip;
};

void ActionResource::setTooltip( const QString& newTooltip ) {
    m_Tooltip = newTooltip;
};

bool ActionResource::getVisible() const {
    return m_Visible;
};

void ActionResource::setVisible( bool newVisible ) {
    m_Visible = newVisible;
};

const QString& ActionResource::getWhatsThis() const {
    return m_WhatsThis;
};

void ActionResource::setWhatsThis( const QString& newWhatsThis ) {
    m_WhatsThis = newWhatsThis;
};

ActionResource::iterator ActionResource::begin() {
    return m_SubItems.begin();
};

ActionResource::const_iterator ActionResource::begin() const {
    return m_SubItems.begin();
};

ActionResource::iterator ActionResource::end() {
    return m_SubItems.end();
};

ActionResource::const_iterator ActionResource::end() const {
    return m_SubItems.end();
};

ActionResource::reverse_iterator ActionResource::rbegin() {
    return m_SubItems.rbegin();
};

ActionResource::const_reverse_iterator ActionResource::rbegin() const {
    return m_SubItems.rbegin();
};

ActionResource::reverse_iterator ActionResource::rend() {
    return m_SubItems.rend();
};

ActionResource::const_reverse_iterator ActionResource::rend() const {
    return m_SubItems.rend();
};

ActionResource::reference ActionResource::front() {
    return m_SubItems.front();
};

ActionResource::const_reference ActionResource::front() const {
    return m_SubItems.front();
};

ActionResource::reference ActionResource::back() {
    return m_SubItems.back();
};

ActionResource::const_reference ActionResource::back() const {
    return m_SubItems.back();
};

void ActionResource::clear() {
    m_SubItems.clear();
};

bool ActionResource::empty() const {
    return m_SubItems.empty();
};

ActionResource::size_type ActionResource::size() const {
    return m_SubItems.size();
};

void ActionResource::resize( size_type n, value_type t ) {
    m_SubItems.resize( n, t );
};

ActionResource::size_type ActionResource::max_size() const {
    return m_SubItems.max_size();
};

ActionResource::size_type ActionResource::capacity() const {
    return m_SubItems.capacity();
};

void ActionResource::reserve( size_type n ) {
    m_SubItems.reserve( n );
};

ActionResource::iterator ActionResource::insert( iterator pos, const value_type& res ) {
    return m_SubItems.insert( pos, res );
};

template <class InputIterator>
void ActionResource::insert( iterator pos, InputIterator __begin, InputIterator __end ) {
    m_SubItems.insert( pos, __begin, __end );
};

void ActionResource::insert( iterator pos, size_type n, const value_type& res ) {
    m_SubItems.insert( pos, n, res );
};

ActionResource::iterator ActionResource::erase( iterator pos ) {
    return m_SubItems.erase( pos );
};

ActionResource::iterator ActionResource::erase( iterator __begin, iterator __end ) {
    return m_SubItems.erase( __begin, __end );
};

void ActionResource::push_back( const value_type& res ) {
    m_SubItems.push_back( res );
};

void ActionResource::pop_back() {
    m_SubItems.pop_back();
};

QAction* ActionResource::toQAction() const {
    Log log( Log::LT_TRACE, Log::MOD_MAIN, "QAction* ActionResource::toQAction() const" );

    if( !( m_Type == AT_ITEM || m_Type == AT_SEPARATOR ) ) {
        return NULL;
    };

    log.write( Log::LT_TRACE, "Produce item %s", getText() );
    QAction* act = new QAction( getText(), NULL );
    act->setAutoRepeat( getAutoRepeat() );
    act->setCheckable( getCheckable() );
    act->setChecked( getChecked() );
    act->setData( getData() );
    act->setFont( getFont() );
    act->setIcon( getIcon() );
    act->setIconVisibleInMenu( getIconVisibleInMenu() );
    act->setMenuRole( getMenuRole() );
    act->setSeparator( m_Type == AT_SEPARATOR );
    act->setShortcut( getShortcut() );
    act->setShortcutContext( getShortcutContext() );
    act->setStatusTip( getStatusTip() );
    act->setToolTip( getTooltip() );
    act->setVisible( getVisible() );
    act->setWhatsThis( getWhatsThis() );

    return act;
};

QMenu* ActionResource::toMenu() const {
    QMenu* result = new QMenu();

    return appendToMenu( result );
};

QMenu* ActionResource::appendToMenu( QMenu* menu ) const {
    Log log( Log::LT_TRACE, Log::MOD_MAIN, "QMenu* ActionResource::toMenu() const" );

    if( m_Type != AT_SUBMENU ) {
        return menu;
    };

    log.write( Log::LT_TRACE, "Produce menu %s", getText() );
    for( const_iterator it = begin(); it != end(); ++it ) {
        switch( (*it)->getType() ) {
            case AT_ITEM: {
                menu->addAction( (*it)->toQAction() );
                break;
            };

            case AT_SEPARATOR: {
                menu->addSeparator();
                break;
            };

            case AT_GROUP: {
                QActionGroup* group = new QActionGroup( menu );
                for( const_iterator grpIt = (*it)->begin(); grpIt != (*it)->end(); ++grpIt ) {
                    QAction* act = (*grpIt)->toQAction();
                    menu->addAction( act );
                    group->addAction( act );
                };

                break;
            };

            case AT_SUBMENU: {
                QMenu* subMenu = menu->addMenu( (*it)->getText() );
                (*it)->appendToMenu( subMenu );
                break;
            };
        };
    };

    return menu;
};

ActionResource& ActionResource::operator=( const ActionResource& other ) {
    AbstractResource::operator=( other );
    m_Type = other.m_Type;
    m_AutoRepeat = other.m_AutoRepeat;
    m_Checkable = other.m_Checkable;
    m_Checked = other.m_Checked;
    m_Data = other.m_Data;
    m_Font = other.m_Font;
    m_Icon = other.m_Icon;
    m_IconVisibleInMenu = other.m_IconVisibleInMenu;
    m_MenuRole = other.m_MenuRole;
    m_Shortcut = other.m_Shortcut;
    m_ShortcutContext = other.m_ShortcutContext;
    m_StatusTip = other.m_StatusTip;
    m_Text = other.m_Text;
    m_Tooltip = other.m_Tooltip;
    m_Visible = other.m_Visible;
    m_WhatsThis = other.m_WhatsThis;
    m_SubItems = other.m_SubItems;

    return *this;
};

ActionResource::reference ActionResource::operator[]( size_type n ) {
    return m_SubItems[ n ];
};

ActionResource::const_reference ActionResource::operator[]( size_type n ) const {
    return m_SubItems[ n ];
};

ActionResource::value_type ActionResource::newItem( const QString& title, const QVariant& data, const QKeySequence& shortcut, const QIcon& icon ) {
    value_type v( new ActionResource() );

    v->setType( AT_ITEM );
    v->setText( title );
    v->setData( data );
    v->setShortcut( shortcut );
    v->setIcon( icon );

    return v;
};

ActionResource::value_type ActionResource::newSeparator( const QString& title ) {
    value_type v( new ActionResource() );

    v->setType( AT_SEPARATOR );
    v->setText( title );

    return v;
};

ActionResource::value_type ActionResource::newGroup() {
    value_type v( new ActionResource() );

    v->setType( AT_GROUP );

    return v;
};

ActionResource::value_type ActionResource::newMenu( const QString& title, const QIcon& icon ) {
    value_type v( new ActionResource() );

    v->setType( AT_SUBMENU );
    v->setText( title );
    v->setIcon( icon );

    return v;
};

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
