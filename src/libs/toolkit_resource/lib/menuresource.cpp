//---------------------------------------------------------------------------------------
/*!
    \file menuresource.h
    \brief
*/
//---------------------------------------------------------------------------------------

// Include Header File
#include "menuresource.h"

// Include Qt Files
#include <QMenuBar>

// include Toolkit Core Files
#include <toolkit/core/log.h>

//---------------------------------------------------------------------------------------
using namespace Toolkit::Core;
using namespace Toolkit::Resource;

//---------------------------------------------------------------------------------------
MenuResource::MenuResource( const QString& key ) :
    AbstractResource( key ),
    m_Actions()
{
};

MenuResource::MenuResource( const MenuResource& other ) :
    AbstractResource( other ),
    m_Actions( other.m_Actions )
{
};

MenuResource::~MenuResource() {
};

const ActionResource& MenuResource::getActions() const {
    return m_Actions;
};

void MenuResource::setActions( const ActionResource& newActions ) {
    m_Actions = newActions;
};

QMenu* MenuResource::toMenu() const {
    return appendToMenu( new QMenu() );
};

QMenuBar* MenuResource::toMenuBar() const {
    return appendToMenuBar( new QMenuBar() );
};

QMenu* MenuResource::appendToMenu( QMenu* menu ) const {
    for( ActionResource::const_iterator it = getActions().begin(); it != getActions().end(); ++it ) {
        QAction* act = (*it)->toQAction();
        if( act ) {
            menu->addAction( act );
            continue;
        };

        QMenu* subMenu = menu->addMenu( (*it)->getIcon(), (*it)->getText() );
        if( subMenu ) {
            (*it)->appendToMenu( subMenu );
            continue;
        };

        QActionGroup* group = new QActionGroup( menu );
        for( ActionResource::const_iterator grpIt = (*it)->begin(); grpIt != (*it)->end(); ++grpIt ) {
            QAction* act = (*grpIt)->toQAction();
            menu->addAction( act );
            group->addAction( act );
        };
    };

    return menu;
};

QMenuBar* MenuResource::appendToMenuBar( QMenuBar* menuBar ) const {
    Log log( Log::LT_TRACE, Log::MOD_MAIN, "QMenuBar* MenuResource::appendToMenuBar() const" );

    for( ActionResource::const_iterator it = getActions().begin(); it != getActions().end(); ++it ) {
        QAction* act = (*it)->toQAction();
        if( act ) {
            log.write( Log::LT_TRACE, "Adds a new action: %s", act->text() );
            menuBar->addAction( act );
            continue;
        };

        QMenu* subMenu = menuBar->addMenu( (*it)->getIcon(), (*it)->getText() );
        if( subMenu ) {
            log.write( Log::LT_TRACE, "Adds a new menu: %s", subMenu->title() );
            (*it)->appendToMenu( subMenu );
            continue;
        };

        log.write( Log::LT_TRACE, "Adds a new group." );
        QActionGroup* group = new QActionGroup( menuBar );
        for( ActionResource::const_iterator grpIt = (*it)->begin(); grpIt != (*it)->end(); ++grpIt ) {
            QAction* act = (*grpIt)->toQAction();
            menuBar->addAction( act );
            group->addAction( act );
        };
    };

    return menuBar;
};

MenuResource& MenuResource::operator=( const MenuResource& other ) {
    AbstractResource::operator=( other );
    m_Actions = other.m_Actions;

    return *this;
};

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
