//---------------------------------------------------------------------------------------
/*!
    \file loghandler.cpp
    \brief 
*/

//---------------------------------------------------------------------------------------

// Include Header File
#include "loghandler.h"

// Include Toolkit Files
#include "format.h"

//---------------------------------------------------------------------------------------
using namespace Toolkit::Core;

//---------------------------------------------------------------------------------------
quint64 LogHandler::OPT_INDENT(             Q_UINT64_C( 0x00000001 ) );
quint64 LogHandler::OPT_FLUSH(              Q_UINT64_C( 0x00000002 ) );
quint64 LogHandler::OPT_PRINT_TYPE_NAME(    Q_UINT64_C( 0x00000004 ) );
quint64 LogHandler::OPT_PRINT_MODULE_NAME(  Q_UINT64_C( 0x00000008 ) );
quint64 LogHandler::OPT_PRINT_TIME_STRAP(   Q_UINT64_C( 0x00000010 ) );
quint64 LogHandler::OPT_PRINT_TIME_ELAPSED( Q_UINT64_C( 0x00000020 ) );

/*!
    \brief Print a time elapsed in a human readable form.
    
    The eapsed time is printed using the QTime format "(HH:mm:ss.zzz)".
*/
quint64 LogHandler::OPT_PRINT_TIME_HUMAN(   Q_UINT64_C( 0x00000040 ) );

/*!
    \brief Activates all options.
*/
quint64 LogHandler::OPT_ALL( Q_UINT64_C( 0xFFFFFFFF ) );

/*!
    \brief The number spaces to indent a log message when indention is activated.
*/
uint LogHandler::INDENT_SIZE( 2 );

QString LogHandler::TIME_STRAP_FORMAT( "HH:mm:ss.zzz" );
QString LogHandler::TIME_ELAPSED_FORMAT( "(%gi ms)" );
QString LogHandler::TIME_ELAPSED_HUMAN_FORMAT( "(HH:mm:ss.zzz)" );
QString LogHandler::BEGIN_GROUP_PREFIX( "=== BEGIN === %s" );
QString LogHandler::END_GROUP_PREFIX( "===  END  === %s" );

//---------------------------------------------------------------------------------------
LogHandler::LogHandler( const LogDevice& logDevice, quint64 options, LogLevel logLevel ) :
    m_LogLevel( logLevel ),
    m_Options( options ),
    m_Indent( 0 ),
    m_Groups(),
    m_CurTime(),
    m_LastTime(),
    m_LogDevice( logDevice ),
    m_Formater( m_LogDevice.device() )
{
};

LogHandler::LogHandler( const LogHandler& other ) :
    m_LogLevel( other.m_LogLevel ),
    m_Options( other.m_Options ),
    m_Indent( other.m_Indent ),
    m_Groups( other.m_Groups ),
    m_CurTime( other.m_CurTime ),
    m_LastTime( other.m_LastTime ),
    m_LogDevice( other.m_LogDevice ),
    m_Formater( other.m_Formater )
{
};

LogHandler::~LogHandler() {
};

bool LogHandler::getIndent() const {
    return m_Options & OPT_INDENT;
};

void LogHandler::setIndent( bool newIndent ) {
    if( newIndent )
        m_Options |= OPT_INDENT;
    else
        m_Options ^= OPT_INDENT;
};

bool LogHandler::getFlush() const {
    return m_Options & OPT_FLUSH;
};

void LogHandler::setFlush( bool newFlush ) {
    if( newFlush )
        m_Options |= OPT_FLUSH;
    else
        m_Options ^= OPT_FLUSH;
};

bool LogHandler::getPrintTypeName() const {
    return m_Options & OPT_PRINT_TYPE_NAME;
};

void LogHandler::setPrintTypeName( bool newPrintTypeName ) {
    if( newPrintTypeName )
        m_Options |= OPT_PRINT_TYPE_NAME;
    else
        m_Options ^= OPT_PRINT_TYPE_NAME;
};

bool LogHandler::getPrintModuleName() const {
    return m_Options & OPT_PRINT_MODULE_NAME;    
};

void LogHandler::setPrintModuleName( bool newPrintModuleName ) {
    if( newPrintModuleName )
        m_Options |= OPT_PRINT_MODULE_NAME;
    else
        m_Options ^= OPT_PRINT_MODULE_NAME;
};

bool LogHandler::getPrintTimeStrap() const {
    return m_Options & OPT_PRINT_TIME_STRAP;
};

void LogHandler::setPrintTimeStrap( bool newPrintTimeStrap ) {
    if( newPrintTimeStrap )
        m_Options |= OPT_PRINT_TIME_STRAP;
    else
        m_Options ^= OPT_PRINT_TIME_STRAP;
};

bool LogHandler::getPrintTimeElapsed() const {
    return m_Options & OPT_PRINT_TIME_ELAPSED;
};

void LogHandler::setPrintTimeElapsed( bool newPrintTimeElapsed ) {
    if( newPrintTimeElapsed )
        m_Options |= OPT_PRINT_TIME_ELAPSED;
    else
        m_Options ^= OPT_PRINT_TIME_ELAPSED;
};
        
bool LogHandler::getPrintTimeHuman() const {
    return m_Options & OPT_PRINT_TIME_HUMAN;
};

void LogHandler::setPrintTimeHuman( bool newPrintTimeHuman ) {
    if( newPrintTimeHuman )
        m_Options |= OPT_PRINT_TIME_HUMAN;
    else
        m_Options ^= OPT_PRINT_TIME_HUMAN;
};

void LogHandler::setOptions( quint64 newOptions ) {
    m_Options = newOptions;
};

LogHandler::LogLevel LogHandler::getLogLevel() const {
    return m_LogLevel;
};

void LogHandler::setLogLevel( LogLevel newLogLevel ) {
    m_LogLevel = newLogLevel;
};

QString LogHandler::logLevelName( LogLevel logLevel ) const {
    if( logLevel == LT_TRACE ) {
        return "TRACE";
    }
    else if( logLevel == LT_DEBUG ) {
        return "DEBUG";
    }
    else if( logLevel == LT_INFO ) {
        return "INFO";
    }
    else if( logLevel == LT_WARNING ) {
        return "WARNING";
    }
    else if( logLevel == LT_ERROR ) {
        return "ERROR";
    }
    else if( logLevel == LT_FATAL ) {
        return "FATAL";
    };

    return "";
};

QString LogHandler::moduleName( ModuleType module ) const {
    if( module == MOD_MAIN ) {
        return "MAIN";
    }
    else if( module == MOD_OS ) {
        return "OS";
    }
    else if( module == MOD_QT ) {
        return "QT";
    };

    return "UNKNOWN";
};

bool LogHandler::willLog( LogLevel logLevel ) const {
    return logLevel >= m_LogLevel;
};

bool LogHandler::write( LogLevel logLevel, ModuleType module, const QString& msg ) {
    if( willLog( logLevel ) ) {
        m_LastTime = m_CurTime;
        m_CurTime = QTime::currentTime();
        
        QString fmt = formatMessage( logLevel, module ) + msg + " " + formatElapsed() + "\n";
        
        m_Formater.printf( fmt );
        return true;
    };
    
    return false;
};

void LogHandler::beginGroup( LogLevel logLevel, ModuleType module, const QString& msg ) {
    if( !getIndent() ) {
        return;
    };

    bool hasElapsed = getPrintTimeElapsed();
    
    setPrintTimeElapsed( false );
    if( write( logLevel, module, StringFormat::format( BEGIN_GROUP_PREFIX, msg ) ) ) {
        LogGroup group;
        
        group.setLogLevel( logLevel );
        group.setModule( module );
        group.setTime( m_CurTime );
        group.setTitle( msg );
        
        m_Groups.push( group );
    };
    
    setPrintTimeElapsed( hasElapsed );
};

void LogHandler::endGroup() {
    if( !getIndent() ) {
        return;
    };
    
    if( m_Groups.empty() ) {
        return;
    };
        
    const LogGroup& group = m_Groups.top();
    m_CurTime = group.getTime();
    
    LogLevel logLevel = (LogLevel)( group.getLogLevel() );
    ModuleType module = (ModuleType)( group.getModule() );
    QString msg = group.getTitle();
    
    m_Groups.pop();
    
    write( logLevel, module, StringFormat::format( END_GROUP_PREFIX, msg ) );
};

QString LogHandler::formatMessage( LogLevel logLevel, ModuleType module ) const {
    QString res;
    
    if( getPrintTimeStrap() ) {
        res += m_CurTime.toString( TIME_STRAP_FORMAT ) + " ";
    };
        
    if( getPrintModuleName() ) {
        res += StringFormat::format( "%7s ", "[" + moduleName( module ) + "]" );
    };
        
    if( getPrintTypeName() ) {
        res += StringFormat::format( "%9s ", "[" + logLevelName( logLevel ) + "]" );
    };
                    
    if( getIndent() ) {
        res += QString( "| " ).rightJustified( m_Groups.size() * INDENT_SIZE + 2, ' ' );
    };
    
    return res;
};

QString LogHandler::formatElapsed() const {
    QString res;

    if( getPrintTimeElapsed() ) {
        int elapsed = m_LastTime.msecsTo( m_CurTime );
        
        if( getPrintTimeHuman() ) {
            QTime t = QTime().addMSecs( elapsed );
            
            if( t.hour() > 1 ) {
                res += t.toString( "(HH:mm:ss,zzz" ) + " timer)";
            }
            else if( t.hour() > 0 ) {
                res += t.toString( "(HH:mm:ss,zzz" ) + " time)";
            }
            else if( t.minute() > 0 ) {
                res += t.toString( "(mm:ss,zzz" ) + " min)";
            }
            else if( t.second() > 0 ) {
                res += t.toString( "(s,zzz" ) + " sek)";
            }
            else {
                res += StringFormat::format( TIME_ELAPSED_FORMAT, elapsed );
            };
        }
        else {
            res += StringFormat::format( TIME_ELAPSED_FORMAT, elapsed );
        };
    };
    
    return res;
};

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
