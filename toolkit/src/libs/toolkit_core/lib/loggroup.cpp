//---------------------------------------------------------------------------------------
/*!
    \file loghandler.cpp
    \brief
*/

//---------------------------------------------------------------------------------------

// Include Header File
#include "loggroup.h"

//---------------------------------------------------------------------------------------
using namespace Toolkit::Core;

//---------------------------------------------------------------------------------------
LogGroup::LogGroup() :
    m_Title(),
    m_Time(),
    m_LogLevel(),
    m_Module()
{
};

LogGroup::LogGroup( const LogGroup& other ) :
    m_Title( other.m_Title ),
    m_Time( other.m_Time ),
    m_LogLevel( other.m_LogLevel ),
    m_Module( other.m_Module )
{
};

LogGroup::~LogGroup() {
};

const QString& LogGroup::getTitle() const {
    return m_Title;
};

void LogGroup::setTitle( const QString& newTitle ) {
    m_Title = newTitle;
};

const QTime& LogGroup::getTime() const {
    return m_Time;
};

void LogGroup::setTime( const QTime& newTime ) {
    m_Time = newTime;
};

int LogGroup::getLogLevel() const {
    return m_LogLevel;
};

void LogGroup::setLogLevel( int newLogLevel ) {
    m_LogLevel = newLogLevel;
};

int LogGroup::getModule() const {
    return m_Module;
};

void LogGroup::setModule( int newModule ) {
    m_Module = newModule;
};

LogGroup& LogGroup::operator=( const LogGroup& other ) {
    m_Title = other.m_Title;
    m_Time = other.m_Time;
    m_LogLevel = other.m_LogLevel;
    m_Module = other.m_Module;

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
