//---------------------------------------------------------------------------------------
/*!
  \file noimpexception.h
  \brief Declares our exception class for exceptions that should be handled.
*/

//---------------------------------------------------------------------------------------
#ifndef __TOOLKIT_CORE_NOIMPEXCEPTION_H__
#define __TOOLKIT_CORE_NOIMPEXCEPTION_H__

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
        class TOOLKIT_CORE_API NoImpException : public Exception {
        public:
            static const QString DEFAULT_MESSAGE;

        public:
            //!\name Constructors & Destructor
            //@{
            NoImpException( const SourceLine& srcLine, const QString& message = DEFAULT_MESSAGE );
            NoImpException( const NoImpException& other );
            virtual ~NoImpException();
            //@}

            //!\name Operators
            //@{
            NoImpException& operator=( const NoImpException& other );
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
