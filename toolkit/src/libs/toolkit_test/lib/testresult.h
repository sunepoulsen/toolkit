//-------------------------------------------------------------------------
/*!
  \file testresult.h
  \brief
*/

//-------------------------------------------------------------------------
#ifndef __TOOLKIT_TEST_TESTRESULT_H__
#define __TOOLKIT_TEST_TESTRESULT_H__

// Include Toolkit Test Files
#include "defines.h"
#include "testresulttype.h"

// Include QT Files
#include <QString>

// Include Toolkit Core Files
#include <toolkit/core/sourceline.h>

//-------------------------------------------------------------
namespace Toolkit {
    
    namespace Test {
	//-------------------------------------------------------------------------
	/*!
            \ingroup grp_Test
            \brief
	*/
	class TOOLKIT_TEST_API TestResult {
	public:
            static const int ASSERT_EQUAL;
            static const int ASSERT_NOT_EQUAL;
            static const int ASSERT_EXCEPTION;
            static const int ASSERT_WRONG_EXCEPTION;
            static const int ASSERT_TRUE;
            static const int ASSERT_FALSE;
            static const int ASSERT_FAIL;

	public:
            //!\name Constructors & Destructor
            //@{
            TestResult();
            TestResult( const TestResult& other );
            virtual ~TestResult();
            //@}
            
            //!\name Properties
            //@{
            int getAssertType() const;
            void setAssertType( const int newAssertType );
            const TestResultType& getResultType() const;
            void setResultType( const TestResultType& newResultType );
            const Toolkit::Core::SourceLine& getSourceLine() const;
            void setSourceLine( const Toolkit::Core::SourceLine& newSourceLine );
            const QString& getMessage() const;
            void setMessage( const QString& newMessage );
            //@}

            //!\name Converters
            //@{
            QString toAssertTypeString() const;
            //@}
            
            //!\name Operators
            //@{
            TestResult& operator=( const TestResult& other );
            //@}

	private:
            int m_AssertType;
            TestResultType m_ResultType;
            Toolkit::Core::SourceLine m_SourceLine;
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
