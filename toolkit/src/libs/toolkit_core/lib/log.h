//---------------------------------------------------------------------------------------
/*!
    \file log.h
    \brief 
*/

//---------------------------------------------------------------------------------------
#ifndef __TOOLKIT_CORE_LOG_H__
#define __TOOLKIT_CORE_LOG_H__

// Include Toolkit Files
#include "defines.h"
#include "loghandler.h"

// Include Qt Files
#include <QThread>

// Include STD Files
#include <map>

//---------------------------------------------------------------------------------------
namespace Toolkit {

    namespace Core {
        //---------------------------------------------------------------------------------------
        /*!
            \ingroup grp_Logs
            \brief 
        */
        class TOOLKIT_CORE_API Log {        
        public:
            //!\name Log level
            //@{
            enum LogLevel {
                LT_TRACE = LogHandler::LT_TRACE,
                LT_DEBUG = LogHandler::LT_DEBUG,
                LT_INFO = LogHandler::LT_INFO,
                LT_WARNING = LogHandler::LT_WARNING,
                LT_ERROR = LogHandler::LT_ERROR,
                LT_FATAL = LogHandler::LT_FATAL
            };
            //@}
            
            //!\name Modules
            //@{
            enum ModuleType {
                MOD_MAIN = LogHandler::MOD_MAIN,
                MOD_OS = LogHandler::MOD_OS,
                MOD_QT = LogHandler::MOD_QT
            };
            //@}

        public:
            typedef QThread* key_type;
            typedef LogHandler data_type;
            typedef std::map<key_type, data_type> container_type;
            typedef container_type::iterator iterator;
            typedef container_type::size_type size_type;

        public:
            //!\name Constructors & Destructor
            //@{
            Log( LogLevel logLevel, const QString& msg, bool createGroup = true );
            Log( LogLevel logLevel, ModuleType module, const QString& msg, bool createGroup = true );
            ~Log();
            //@}
            
            //!\name Write
            //@{
            void write( LogLevel logLevel, const QString& msg );
            
            template< typename T1 >
            void write( LogLevel logLevel, const QString& msg, T1 p1 );
            
            template< typename T1, typename T2 >
            void write( LogLevel logLevel, const QString& msg, T1 p1, T2 p2 );
            
            template< typename T1, typename T2, typename T3 >
            void write( LogLevel logLevel, const QString& msg, T1 p1, T2 p2, T3 p3 );
            
            template< typename T1, typename T2, typename T3, typename T4 >
            void write( LogLevel logLevel, const QString& msg, T1 p1, T2 p2, T3 p3, T4 p4 );
            
            template< typename T1, typename T2, typename T3, typename T4, typename T5 >
            void write( LogLevel logLevel, const QString& msg,
                        T1 p1, T2 p2, T3 p3, T4 p4, T5 p5 );
            
            template< typename T1, typename T2, typename T3, typename T4, typename T5,
                      typename T6 >
            void write( LogLevel logLevel, const QString& msg,
                        T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6 );
            
            template< typename T1, typename T2, typename T3, typename T4, typename T5,
                      typename T6, typename T7 >
            void write( LogLevel logLevel, const QString& msg,
                        T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7 );
            
            template< typename T1, typename T2, typename T3, typename T4, typename T5,
                      typename T6, typename T7, typename T8 >
            void write( LogLevel logLevel, const QString& msg,
                        T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7, T8 p8 );
            
            template< typename T1, typename T2, typename T3, typename T4, typename T5,
                      typename T6, typename T7, typename T8, typename T9 >
            void write( LogLevel logLevel, const QString& msg,
                        T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7, T8 p8, T9 p9 );
            
            template< typename T1, typename T2, typename T3, typename T4, typename T5,
                      typename T6, typename T7, typename T8, typename T9, typename T10 >
            void write( LogLevel logLevel, const QString& msg,
                        T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7, T8 p8, T9 p9, T10 p10 );        
            
            void beginGroup( LogLevel logLevel, const QString& msg );
            void endGroup();
            //@}
            
        private:
            void init( LogLevel logLevel, const QString& msg );
            void destroy();
            
        public:
            //!\name Handlers
            //@{
            static iterator currentHandler( QThread* thread = QThread::currentThread() );
            static void clearHandlers();
            static void pushHandler( const key_type& key, const data_type& data );
            static size_type sizeHandlers();
            //@}

            //!\name QT Messages
            //@{
            static void installQtMessageHandler();
            //@}
            
        private:
            ModuleType m_Module;
            iterator m_Handler;
            bool m_CreateGroup;
            
        private:
            static container_type m_Handlers;
        };
        
        //-------------------------------------------------------------
        void QtMessageHandler( QtMsgType msgType, const char* msg );
        
        //-------------------------------------------------------------
        // Include implementation file of template functions.
        #include "log_imp.h"
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
