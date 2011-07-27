//---------------------------------------------------------------------------------------
/*!
    \file throwable.h
    \brief Declares the basic throwable class to be used for exceptions.
*/

//---------------------------------------------------------------------------------------
#ifndef __TOOLKIT_CORE_THROWABLE_H__
#define __TOOLKIT_CORE_THROWABLE_H__

// Include Toolkit Files
#include "defines.h"
#include "sourceline.h"

// Include QT Files
#include <QObject>
#include <QString>

//---------------------------------------------------------------------------------------
namespace Toolkit {
       
    namespace Core {           
        //---------------------------------------------------------------------------------------
        /*!
            \ingroup grp_Exceptions
            \brief Implements the basic class in VDF for exceptions.
            
            \par Usage
            \code
            void f( ... ) {
                ...
                throw new Throwable( SOURCELINE, "Error message" );
            }
            \endcode
        */
		class TOOLKIT_CORE_API Throwable {
        public:
            static const QString DEBUG_MSG;
            
        public:
            //!\name Constructors & Destructor
            //@{
            Throwable( const SourceLine& srcLine, const QString& message );
            Throwable( const Throwable& other );
            virtual ~Throwable();
            //@}
                   
            //!\name Properties
            //@{
            const SourceLine& getSourceLine() const;
            const QString& getMessage() const;
            //@}
            
            //!\name Debug strings
            //@{
            QString debugString() const;
            //@}

            //!\name Operators
            //@{
            Throwable& operator=( const Throwable& other );
            //@}

        protected:
            //!\name Properties
            //@{
            void setSourceLine( const SourceLine& newSourceLine );
            void setMessage( const QString& newMessage );
            //@}

        private:
            /*!
                \brief
            */
            SourceLine m_SourceLine;
            
            /*!
                \brief
            */
            QString m_Message;
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
