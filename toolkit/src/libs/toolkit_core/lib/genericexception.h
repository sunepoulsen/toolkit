//---------------------------------------------------------------------------------------
/*!
  \file genericexception.h
  \brief
*/

//---------------------------------------------------------------------------------------
#ifndef __TOOLKIT_CORE_GENERICEXCEPTION_H__
#define __TOOLKIT_CORE_GENERICEXCEPTION_H__

// Include Toolkit Files
#include "exception.h"

//---------------------------------------------------------------------------------------
namespace Toolkit {

    namespace Core {
        //---------------------------------------------------------------------------------------
        /*!
            \ingroup grp_Exceptions
            \brief
        */
        class TOOLKIT_CORE_API GenericException : public Exception {
        public:
            //!\name Constructors & Destructor
            //@{
            GenericException( const SourceLine& srcLine, const QString& message );
            GenericException( const GenericException& other );
            virtual ~GenericException();
            //@}

            //!\name Operators
            //@{
            GenericException& operator=( const GenericException& other );
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
