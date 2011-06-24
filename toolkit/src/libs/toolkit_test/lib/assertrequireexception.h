//---------------------------------------------------------------------------------------
/*!
    \file assertrequireexception.h
    \brief 
*/

//---------------------------------------------------------------------------------------
#ifndef __TOOLKIT_TEST_ASSERTREQUIREEXCEPTION_H__
#define __TOOLKIT_TEST_ASSERTREQUIREEXCEPTION_H__

// Include UnitTests Files
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
	class TOOLKIT_TEST_API AssertRequireException : public AssertException {
        public:
            //!\name Constructors & Destructor
            //@{
            AssertRequireException( const Toolkit::Core::SourceLine& srcLine, const QString& message );
            AssertRequireException( const AssertRequireException& other );
            virtual ~AssertRequireException();
            //@}
                
            //!\name Operators
            //@{
            AssertRequireException& operator=( const AssertRequireException& other );
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
