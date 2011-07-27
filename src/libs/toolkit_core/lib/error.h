//---------------------------------------------------------------------------------------
/*!
  \file error.h
  \brief Declares our Error exception class for exceptions that should not be handled.
*/

//---------------------------------------------------------------------------------------
#ifndef __TOOLKIT_CORE_ERROR_H__
#define __TOOLKIT_CORE_ERROR_H__

// Include Toolkit Files
#include "throwable.h"

//---------------------------------------------------------------------------------------
namespace Toolkit {
       
    namespace Core {
        //---------------------------------------------------------------------------------------
        /*!
            \ingroup grp_Exceptions
            \brief Implements an exception class to be used to report an error that should
                   caurce the application to shut down.
        */
        class TOOLKIT_CORE_API Error : public Throwable {
        public:
            //!\name Constructors & Destructor
            //@{
            Error( const SourceLine& srcLine, const QString& message );
            Error( const Error& other );
            virtual ~Error();
            //@}
                   
            //!\name Operators
            //@{
            Error& operator=( const Error& other );
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
