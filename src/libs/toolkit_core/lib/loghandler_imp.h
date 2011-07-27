//---------------------------------------------------------------------------------------
/*!
    \file loghandler_imp.h
    \brief Implements template functions declared in loghandler.h

    This file is included by loghandler.h, so you would not have to include it yourself.
*/

//---------------------------------------------------------------------------------------
template< typename T1 >
bool LogHandler::write( LogLevel logLevel, ModuleType module, const QString& msg, T1 p1 ) {
    if( willLog( logLevel ) ) {
        m_LastTime = m_CurTime;
        m_CurTime = QTime::currentTime();
        
        QString fmt = formatMessage( logLevel, module ) + msg + " " + formatElapsed() + "\n";
        
        m_Formater.printf( fmt, p1 );
        return true;
    };
    
    return false;
};

template< typename T1, typename T2 >
bool LogHandler::write( LogLevel logLevel, ModuleType module, const QString& msg, T1 p1, T2 p2 ) {
    if( willLog( logLevel ) ) {
        m_LastTime = m_CurTime;
        m_CurTime = QTime::currentTime();
        
        QString fmt = formatMessage( logLevel, module ) + msg + " " + formatElapsed() + "\n";
        
        m_Formater.printf( fmt, p1, p2 );
        return true;
    };
    
    return false;
};

template< typename T1, typename T2, typename T3 >
bool LogHandler::write( LogLevel logLevel, ModuleType module, const QString& msg, T1 p1, T2 p2, T3 p3 ) {
    if( willLog( logLevel ) ) {
        m_LastTime = m_CurTime;
        m_CurTime = QTime::currentTime();
        
        QString fmt = formatMessage( logLevel, module ) + msg + " " + formatElapsed() + "\n";
        
        m_Formater.printf( fmt, p1, p2, p3 );
        return true;
    };
    
    return false;
};

template< typename T1, typename T2, typename T3, typename T4 >
bool LogHandler::write( LogLevel logLevel, ModuleType module, const QString& msg,
                        T1 p1, T2 p2, T3 p3, T4 p4 )
{
    if( willLog( logLevel ) ) {
        m_LastTime = m_CurTime;
        m_CurTime = QTime::currentTime();
        
        QString fmt = formatMessage( logLevel, module ) + msg + " " + formatElapsed() + "\n";
        
        m_Formater.printf( fmt, p1, p2, p3, p4 );
        return true;
    };
    
    return false;
};

template< typename T1, typename T2, typename T3, typename T4, typename T5 >
bool LogHandler::write( LogLevel logLevel, ModuleType module, const QString& msg,
                        T1 p1, T2 p2, T3 p3, T4 p4, T5 p5 )
{
    if( willLog( logLevel ) ) {
        m_LastTime = m_CurTime;
        m_CurTime = QTime::currentTime();
        
        QString fmt = formatMessage( logLevel, module ) + msg + " " + formatElapsed() + "\n";
        
        m_Formater.printf( fmt, p1, p2, p3, p4, p5 );
        return true;
    };
    
    return false;
};

template< typename T1, typename T2, typename T3, typename T4, typename T5,
            typename T6 >
bool LogHandler::write( LogLevel logLevel, ModuleType module, const QString& msg,
                        T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6 )
{
    if( willLog( logLevel ) ) {
        m_LastTime = m_CurTime;
        m_CurTime = QTime::currentTime();
        
        QString fmt = formatMessage( logLevel, module ) + msg + " " + formatElapsed() + "\n";
        
        m_Formater.printf( fmt, p1, p2, p3, p4, p5, p6 );
        return true;
    };
    
    return false;
};

template< typename T1, typename T2, typename T3, typename T4, typename T5,
            typename T6, typename T7 >
bool LogHandler::write( LogLevel logLevel, ModuleType module, const QString& msg,
                        T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7 )
{
    if( willLog( logLevel ) ) {
        m_LastTime = m_CurTime;
        m_CurTime = QTime::currentTime();
        
        QString fmt = formatMessage( logLevel, module ) + msg + " " + formatElapsed() + "\n";
        
        m_Formater.printf( fmt, p1, p2, p3, p4, p5, p6, p7 );
        return true;
    };
    
    return false;
};

template< typename T1, typename T2, typename T3, typename T4, typename T5,
            typename T6, typename T7, typename T8 >
bool LogHandler::write( LogLevel logLevel, ModuleType module, const QString& msg,
                        T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7, T8 p8 )
{
    if( willLog( logLevel ) ) {
        m_LastTime = m_CurTime;
        m_CurTime = QTime::currentTime();
        
        QString fmt = formatMessage( logLevel, module ) + msg + " " + formatElapsed() + "\n";
        
        m_Formater.printf( fmt, p1, p2, p3, p4, p5, p6, p7, p8 );
        return true;
    };
    
    return false;
};

template< typename T1, typename T2, typename T3, typename T4, typename T5,
            typename T6, typename T7, typename T8, typename T9 >
bool LogHandler::write( LogLevel logLevel, ModuleType module, const QString& msg,
                        T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7, T8 p8, T9 p9 )
{
    if( willLog( logLevel ) ) {
        m_LastTime = m_CurTime;
        m_CurTime = QTime::currentTime();
        
        QString fmt = formatMessage( logLevel, module ) + msg + " " + formatElapsed() + "\n";
        
        m_Formater.printf( fmt, p1, p2, p3, p4, p5, p6, p7, p8, p9 );
        return true;
    };
    
    return false;
};

template< typename T1, typename T2, typename T3, typename T4, typename T5,
            typename T6, typename T7, typename T8, typename T9, typename T10 >
bool LogHandler::write( LogLevel logLevel, ModuleType module, const QString& msg,
                        T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7, T8 p8, T9 p9, T10 p10 )
{
    if( willLog( logLevel ) ) {
        m_LastTime = m_CurTime;
        m_CurTime = QTime::currentTime();
        
        QString fmt = formatMessage( logLevel, module ) + msg + " " + formatElapsed() + "\n";
        
        m_Formater.printf( fmt, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10 );
        return true;
    };
    
    return false;
};

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */

