//---------------------------------------------------------------------------------------
/*!
    \file assertfatalexception.h
    \brief 
*/

//---------------------------------------------------------------------------------------
#ifndef __TOOLKIT_TEST_ASSERTFATALEXCEPTION_H__
#define __TOOLKIT_TEST_ASSERTFATALEXCEPTION_H__

// Include Toolkit Test Files
#include "assertexception.h"

//---------------------------------------------------------------------------------------
namespace Toolkit {
       
    namespace Test {
        //---------------------------------------------------------------------------------------
        /*!
            \ingroup grp_Test
            \ingroup grp_Exceptions
            \brief 
        */
	class TOOLKIT_TEST_API AssertFatalException : public AssertException {
        public:
            //!\name Constructors & Destructor
            //@{
            AssertFatalException( const Toolkit::Core::SourceLine& srcLine, const QString& message );
            AssertFatalException( const AssertFatalException& other );
            virtual ~AssertFatalException();
            //@}
                
            //!\name Operators
            //@{
            AssertFatalException& operator=( const AssertFatalException& other );
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
