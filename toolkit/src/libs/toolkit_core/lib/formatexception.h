//---------------------------------------------------------------------------------------
/*!
  \file formatexception.h
  \brief Declares our exception class for exceptions that should be handled.
*/

//---------------------------------------------------------------------------------------
#ifndef __TOOLKIT_CORE_FORMATEXCEPTION_H__
#define __TOOLKIT_CORE_FORMATEXCEPTION_H__

// Include Toolkit Files
#include "exception.h"

//---------------------------------------------------------------------------------------
namespace Toolkit {
       
    namespace Core {
        //---------------------------------------------------------------------------------------
        /*!
            \ingroup grp_Exceptions
            \ingroup grp_Formats
        
            \brief Implements an exception class to be used to report an error that should
                   be handled by the application. It should be considered a bug if an exception
                   of this type caurces the application to exit.
        */
        class TOOLKIT_CORE_API FormatException : public Exception {
        public:
            //!\name Constructors & Destructor
            //@{
            FormatException( const SourceLine& srcLine, const QString& message );
            FormatException( const FormatException& other );
            virtual ~FormatException();
            //@}
                   
            //!\name Operators
            //@{
            FormatException& operator=( const FormatException& other );
            //@}
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
