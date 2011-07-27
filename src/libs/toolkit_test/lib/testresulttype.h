//-------------------------------------------------------------------------
/*!
    \file testresulttype.h
    \brief
*/

//-------------------------------------------------------------------------
#ifndef __TOOLKIT_TEST_TESTRESULTTYPE_H__
#define __TOOLKIT_TEST_TESTRESULTTYPE_H__

// Include Toolkit Test Files
#include "defines.h"

// Include QT Files
#include <QString>

//-------------------------------------------------------------
namespace Toolkit {
    
    namespace Test {
	//-------------------------------------------------------------------------
	/*!
            \ingroup grp_Test
            \brief
	*/
	class TOOLKIT_TEST_API TestResultType {
	public:
            enum ResultType {
                /*!
                    \brief A test was OK and is written to the report.
                */
                RT_OK,

                /*!
                    \brief A test has result in a warning, that is written to the report.
                */
                RT_WARNING,

                /*!
                    \brief A test has failed in a required condition, and is written to the report.
                */
                RT_REQUIRED,

                /*!
                    \brief A test has failed. The result is written to the report.
                */
                RT_FAILURE,

                /*!
                    \brief A test has a critical failure. The result is written to the report.
                    
                    A critical failure has the side effect, that the execution of the test function is stoped
                    and the execution continues to the next test function.
                    \par
                */
                RT_CRITICAL,

                /*!
                    \brief A test has a fatal failure. The result is written to the report.

                    A fatal failure means that execution of the current test case is stopped. Execution continues 
                    to the next test case or test suite.
                */
                RT_FATAL
            };

	public:
            //!\name Constructors & Destructor
            //@{
            TestResultType();
            TestResultType( ResultType resType );
            TestResultType( const TestResultType& other );
            virtual ~TestResultType();
            //@}
            
            //!\name Properties
            //@{
            ResultType getResultType() const;
            void setResultType( ResultType newResultType );
            //@}
            
            //!\name Converters
            //@{
            QString toString() const;
            //@}

            //!\name Operators
            //@{
            TestResultType& operator=( const TestResultType& other );
            //@}

	private:
            ResultType m_ResultType;
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
