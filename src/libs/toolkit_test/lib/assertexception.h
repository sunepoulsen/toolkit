//---------------------------------------------------------------------------------------
/*!
    \file assertexception.h
    \brief 
*/

//---------------------------------------------------------------------------------------
#ifndef __TOOLKIT_TEST_ASSERTEXCEPTION_H__
#define __TOOLKIT_TEST_ASSERTEXCEPTION_H__

// Include Toolkit Test Files
#include "defines.h"
#include "testresult.h"

// Include Toolkit Core Files
#include <toolkit/core/exception.h>

//---------------------------------------------------------------------------------------
namespace Toolkit {
       
    namespace Test {
        //---------------------------------------------------------------------------------------
        /*!
            \ingroup grp_Test
            \ingroup grp_Exceptions
            \brief 
        */
	class TOOLKIT_TEST_API AssertException : public Toolkit::Core::Exception {
        public:
            //!\name Constructors & Destructor
            //@{
            AssertException( const Toolkit::Core::SourceLine& srcLine, const QString& message );
            AssertException( const AssertException& other );
            virtual ~AssertException();
            //@}
               
            //!\name Test result
            //@{
            const TestResult& getTestResult() const;
            void setTestResult( const TestResult& newTestResult );
            //@}

            //!\name Operators
            //@{
            AssertException& operator=( const AssertException& other );
            //@}

	private:
            TestResult m_TestResult;
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
