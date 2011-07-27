//---------------------------------------------------------------------------------------
/*!
    \file log_imp.h
    \brief Implements template functions declared in log.h

    This file is included by log.h, so you would not have to include it yourself.
*/

//---------------------------------------------------------------------------------------
template< typename T1 >
void Log::write( LogLevel logLevel, const QString& msg, T1 p1 ) {
    if( m_Handler != m_Handlers.end() ) {
        m_Handler->second.write( (LogHandler::LogLevel)logLevel, (LogHandler::ModuleType)m_Module, msg, p1 );
    };
};

template< typename T1, typename T2 >
void Log::write( LogLevel logLevel, const QString& msg, T1 p1, T2 p2 ) {
    if( m_Handler != m_Handlers.end() ) {
        m_Handler->second.write( (LogHandler::LogLevel)logLevel, (LogHandler::ModuleType)m_Module, msg, p1, p2 );
    };
};

template< typename T1, typename T2, typename T3 >
void Log::write( LogLevel logLevel, const QString& msg, T1 p1, T2 p2, T3 p3 ) {
    if( m_Handler != m_Handlers.end() ) {
        m_Handler->second.write( (LogHandler::LogLevel)logLevel, (LogHandler::ModuleType)m_Module, msg, p1, p2, p3 );
    };
};

template< typename T1, typename T2, typename T3, typename T4 >
void Log::write( LogLevel logLevel, const QString& msg, T1 p1, T2 p2, T3 p3, T4 p4 ) {
    if( m_Handler != m_Handlers.end() ) {
        m_Handler->second.write( (LogHandler::LogLevel)logLevel, (LogHandler::ModuleType)m_Module, msg, p1, p2, p3, p4 );
    };
};

template< typename T1, typename T2, typename T3, typename T4, typename T5 >
void Log::write( LogLevel logLevel, const QString& msg,
                 T1 p1, T2 p2, T3 p3, T4 p4, T5 p5 )
{
    if( m_Handler != m_Handlers.end() ) {
        m_Handler->second.write( (LogHandler::LogLevel)logLevel, (LogHandler::ModuleType)m_Module, msg, p1, p2, p3, p4, p5 );
    };
};

template< typename T1, typename T2, typename T3, typename T4, typename T5,
          typename T6 >
void Log::write( LogLevel logLevel, const QString& msg,
                 T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6 )
{
    if( m_Handler != m_Handlers.end() ) {
        m_Handler->second.write( (LogHandler::LogLevel)logLevel, (LogHandler::ModuleType)m_Module, msg, p1, p2, p3, p4, p5, p6 );
    };
};

template< typename T1, typename T2, typename T3, typename T4, typename T5,
          typename T6, typename T7 >
void Log::write( LogLevel logLevel, const QString& msg,
                 T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7 )
{
    if( m_Handler != m_Handlers.end() ) {
        m_Handler->second.write( (LogHandler::LogLevel)logLevel, (LogHandler::ModuleType)m_Module, msg, p1, p2, p3, p4, p5, p6, p7 );
    };
};

template< typename T1, typename T2, typename T3, typename T4, typename T5,
          typename T6, typename T7, typename T8 >
void Log::write( LogLevel logLevel, const QString& msg,
                 T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7, T8 p8 )
{
    if( m_Handler != m_Handlers.end() ) {
        m_Handler->second.write( (LogHandler::LogLevel)logLevel, (LogHandler::ModuleType)m_Module, msg, p1, p2, p3, p4, p5, p6, p7, p8 );
    };
};

template< typename T1, typename T2, typename T3, typename T4, typename T5,
          typename T6, typename T7, typename T8, typename T9 >
void Log::write( LogLevel logLevel, const QString& msg,
                 T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7, T8 p8, T9 p9 )
{
    if( m_Handler != m_Handlers.end() ) {
        m_Handler->second.write( (LogHandler::LogLevel)logLevel, (LogHandler::ModuleType)m_Module, msg, p1, p2, p3, p4, p5, p6, p7, p8, p9 );
    };
};

template< typename T1, typename T2, typename T3, typename T4, typename T5,
          typename T6, typename T7, typename T8, typename T9, typename T10 >
void Log::write( LogLevel logLevel, const QString& msg,
                 T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7, T8 p8, T9 p9, T10 p10 )
{
    if( m_Handler != m_Handlers.end() ) {
        m_Handler->second.write( (LogHandler::LogLevel)logLevel, (LogHandler::ModuleType)m_Module, msg, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10 );
    };
};

//---------------------------------------------------------------------------------------
template< typename T1 >
void Log::trace( const QString& msg, T1 p1 ) {
    write( Log::LT_TRACE, msg, p1 );
}

template< typename T1, typename T2 >
void Log::trace( const QString& msg, T1 p1, T2 p2 ) {
    write( Log::LT_TRACE, msg, p1, p2 );
}

template< typename T1, typename T2, typename T3 >
void Log::trace( const QString& msg, T1 p1, T2 p2, T3 p3 ) {
    write( Log::LT_TRACE, msg, p1, p2, p3 );
}

template< typename T1, typename T2, typename T3, typename T4 >
void Log::trace( const QString& msg, T1 p1, T2 p2, T3 p3, T4 p4 ) {
    write( Log::LT_TRACE, msg, p1, p2, p3, p4 );
}

template< typename T1, typename T2, typename T3, typename T4, typename T5 >
void Log::trace( const QString& msg,
                 T1 p1, T2 p2, T3 p3, T4 p4, T5 p5 )
{
    write( Log::LT_TRACE, msg, p1, p2, p3, p4, p5 );
}

template< typename T1, typename T2, typename T3, typename T4, typename T5,
          typename T6 >
void Log::trace( const QString& msg,
                 T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6 )
{
    write( Log::LT_TRACE, msg, p1, p2, p3, p4, p5, p6 );
}

template< typename T1, typename T2, typename T3, typename T4, typename T5,
          typename T6, typename T7 >
void Log::trace( const QString& msg,
                 T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7 )
{
    write( Log::LT_TRACE, msg, p1, p2, p3, p4, p5, p6, p7 );
}

template< typename T1, typename T2, typename T3, typename T4, typename T5,
          typename T6, typename T7, typename T8 >
void Log::trace( const QString& msg,
                 T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7, T8 p8 )
{
   write( Log::LT_TRACE, msg, p1, p2, p3, p4, p5, p6, p7, p8 );
}

template< typename T1, typename T2, typename T3, typename T4, typename T5,
          typename T6, typename T7, typename T8, typename T9 >
void Log::trace( const QString& msg,
                 T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7, T8 p8, T9 p9 )
{
    write( Log::LT_TRACE, msg, p1, p2, p3, p4, p5, p6, p7, p8, p9 );
}

template< typename T1, typename T2, typename T3, typename T4, typename T5,
          typename T6, typename T7, typename T8, typename T9, typename T10 >
void Log::trace( const QString& msg,
                 T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7, T8 p8, T9 p9, T10 p10 )
{
    write( Log::LT_TRACE, msg, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10 );
}

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
