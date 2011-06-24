//---------------------------------------------------------------------------------------
/*!
    \file loggroup.h
    \brief
*/

//---------------------------------------------------------------------------------------
#ifndef __TOOLKIT_CORE_LOGGROUP_H__
#define __TOOLKIT_CORE_LOGGROUP_H__

// Include Toolkit Core Files
#include "defines.h"

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
        class TOOLKIT_CORE_API LogGroup {
        public:
            //!\name Constructors & Destructor
            //@{
            LogGroup();
            LogGroup( const LogGroup& other );
            virtual ~LogGroup();
            //@}

            //!\name Properties
            //@{
            const QString& getTitle() const;
            void setTitle( const QString& newTitle );
            const QTime& getTime() const;
            void setTime( const QTime& newTime );
            int getLogLevel() const;
            void setLogLevel( int newLogLevel );
            int getModule() const;
            void setModule( int newModule );
            //@}

            //!\name Operators
            //@{
            LogGroup& operator=( const LogGroup& other );
            //@}

        private:
            QString m_Title;
            QTime m_Time;
            int m_LogLevel;
            int m_Module;
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

