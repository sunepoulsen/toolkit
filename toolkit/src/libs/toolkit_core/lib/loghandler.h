//---------------------------------------------------------------------------------------
/*!
    \file loghandler.h
    \brief
*/

//---------------------------------------------------------------------------------------
#ifndef __TOOLKIT_CORE_LOGHANDLER_H__
#define __TOOLKIT_CORE_LOGHANDLER_H__

// Include Toolkit Core Files
#include "defines.h"
#include "logdevice.h"
#include "loggroup.h"
#include "format.h"

// Include QT Files
#include <QString>
#include <QTime>

// Include STD Files
#include <stack>

//---------------------------------------------------------------------------------------
namespace Toolkit {

    namespace Core {       
        //---------------------------------------------------------------------------------------
        /*!
            \ingroup grp_Logs
            \brief 
        */
        class TOOLKIT_CORE_API LogHandler {
        public:
            //!\name Types
            //@{
            enum LogLevel {
                LT_TRACE = 1,
                LT_DEBUG = 2,
                LT_INFO = 3,
                LT_WARNING = 4,
                LT_ERROR = 5,
                LT_FATAL = 6
            };

            enum ModuleType {
                MOD_MAIN = 1,
                MOD_OS = 2,
                MOD_QT = 3
            };
            //@}
            
            //!\name Options
            //@{
            static quint64 OPT_INDENT;
            static quint64 OPT_FLUSH;
            static quint64 OPT_PRINT_TYPE_NAME;
            static quint64 OPT_PRINT_MODULE_NAME;
            static quint64 OPT_PRINT_TIME_STRAP;
            static quint64 OPT_PRINT_TIME_ELAPSED;
            static quint64 OPT_PRINT_TIME_HUMAN;
            static quint64 OPT_ALL;
            //@}
            
            //!\name Different constants
            //@{
            static uint INDENT_SIZE;
            static QString TIME_STRAP_FORMAT;
            static QString TIME_ELAPSED_FORMAT;
            static QString TIME_ELAPSED_HUMAN_FORMAT;
            static QString BEGIN_GROUP_PREFIX;
            static QString END_GROUP_PREFIX;
            //@}
            
        public:
            //!\name Constructors & Destructor
            //@{
            LogHandler( const LogDevice& device, quint64 options = OPT_ALL, LogLevel logLevel = LT_TRACE );
            LogHandler( const LogHandler& other );
            virtual ~LogHandler();
            //@}
            
            //!\name Options
            //@{
            bool getIndent() const;
            void setIndent( bool newIndent );
            bool getFlush() const;
            void setFlush( bool newFlush );
            bool getPrintTypeName() const;
            void setPrintTypeName( bool newPrintTypeName );
            bool getPrintModuleName() const;
            void setPrintModuleName( bool newPrintModuleName );
            bool getPrintTimeStrap() const;
            void setPrintTimeStrap( bool newPrintTimeStrap );
            bool getPrintTimeElapsed() const;
            void setPrintTimeElapsed( bool newPrintTimeElapsed );
            bool getPrintTimeHuman() const;
            void setPrintTimeHuman( bool newPrintTimeHuman );
            void setOptions( quint64 newOptions );
            //@}
            
            //!\name Log types
            //@{
            LogLevel getLogLevel() const;
            void setLogLevel( LogLevel newLogLevel );
            QString logLevelName( LogLevel logLevel ) const;
            //@}
            
            //!\name Modules
            //@{
            QString moduleName( ModuleType module ) const;
            //@}
            
            //!\name Logning
            //@{
            bool willLog( LogLevel logLevel ) const;
            //@}
            
            //!\name Write functions
            //@{
            bool write( LogLevel logLevel, ModuleType module, const QString& msg );
            
            template< typename T1 >
            bool write( LogLevel logLevel, ModuleType module, const QString& msg, T1 p1 );
            
            template< typename T1, typename T2 >
            bool write( LogLevel logLevel, ModuleType module, const QString& msg, T1 p1, T2 p2 );
            
            template< typename T1, typename T2, typename T3 >
            bool write( LogLevel logLevel, ModuleType module, const QString& msg, T1 p1, T2 p2, T3 p3 );
            
            template< typename T1, typename T2, typename T3, typename T4 >
            bool write( LogLevel logLevel, ModuleType module, const QString& msg, T1 p1, T2 p2, T3 p3, T4 p4 );
            
            template< typename T1, typename T2, typename T3, typename T4, typename T5 >
            bool write( LogLevel logLevel, ModuleType module, const QString& msg,
                        T1 p1, T2 p2, T3 p3, T4 p4, T5 p5 );
            
            template< typename T1, typename T2, typename T3, typename T4, typename T5,
                      typename T6 >
            bool write( LogLevel logLevel, ModuleType module, const QString& msg,
                        T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6 );
            
            template< typename T1, typename T2, typename T3, typename T4, typename T5,
                      typename T6, typename T7 >
            bool write( LogLevel logLevel, ModuleType module, const QString& msg,
                        T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7 );
            
            template< typename T1, typename T2, typename T3, typename T4, typename T5,
                      typename T6, typename T7, typename T8 >
            bool write( LogLevel logLevel, ModuleType module, const QString& msg,
                        T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7, T8 p8 );
            
            template< typename T1, typename T2, typename T3, typename T4, typename T5,
                      typename T6, typename T7, typename T8, typename T9 >
            bool write( LogLevel logLevel, ModuleType module, const QString& msg,
                        T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7, T8 p8, T9 p9 );
            
            template< typename T1, typename T2, typename T3, typename T4, typename T5,
                      typename T6, typename T7, typename T8, typename T9, typename T10 >
            bool write( LogLevel logLevel, ModuleType module, const QString& msg,
                        T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7, T8 p8, T9 p9, T10 p10 );        
            
            void beginGroup( LogLevel logLevel, ModuleType module, const QString& msg );
            void endGroup();
            //@}
                    
        private:
            /*!
                \name Format
                \brief Helper functions to format the output strings.
            */
            //@{
            QString formatMessage( LogLevel logLevel, ModuleType module ) const;
            QString formatElapsed() const;
            //@}
            
        private:
            typedef std::stack<LogGroup> group_container;
            typedef group_container::value_type value_type;
            typedef group_container::size_type size_type;
        
        private:
            //!\name Settings
            //@{
            /*!
                \brief Minimum log level to log.
            */
            LogLevel m_LogLevel;
            
            /*!
                \brief Bitvise options on this log handler.
            */
            quint64 m_Options;            
            //@}
            
            //!\name Indent
            //@{
            /*!
                \brief Internal counter on how many spaces the next log line will be indented.
            */
            unsigned int m_Indent;
        
            /*!
                \brief 
            */
            group_container m_Groups;
            //@}
            
            //!\name Times
            //@{
            /*!
                \brief Time strap of the current log message.
                
                The difference between \e m_LastTime and \e m_CurTime is the elapsed time 
                of the current log message.
            */
            QTime m_CurTime;
            
            /*!
                \brief Time strap of the last log message.
            */
            QTime m_LastTime;
            //@}
            
            //!\name Device & Formater
            //@{
            LogDevice m_LogDevice;

            /*!
                \brief
            */
            DeviceFormat m_Formater;
            //@}
        };
        
        //-------------------------------------------------------------
        // Include implementation file of template functions.
        #include "loghandler_imp.h"

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

