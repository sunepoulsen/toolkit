//-------------------------------------------------------------------------
/*!
    \file testcase.h
    \brief
*/

//-------------------------------------------------------------------------
#ifndef __TOOLKIT_TEST_TESTCASE_H__
#define __TOOLKIT_TEST_TESTCASE_H__

// Include Toolkit Test Files
#include "defines.h"
#include "abstracttest.h"
#include "assert.h"
#include "assertexception.h"
#include "defaultassertwriter.h"
#include "testresulttype.h"

// Include Toolkit Core Files
#include <toolkit/core/sourceline.h>
#include <toolkit/core/stringformat.h>

// Include QT Files
#include <QSharedPointer>
#include <QString>

// Include STD Files
#include <vector>

// Include Test Macros
#include "testmacros.h"

//-------------------------------------------------------------
namespace Toolkit {
    
    namespace Test {
        //-------------------------------------------------------------------------
        /*!
                \ingroup grp_Test
                \brief
        */
        class TOOLKIT_TEST_API TestCase : public AbstractTest {
            Q_OBJECT
                
        public:
            //!\name Constructors & Destructor
            //@{
            TestCase();
            TestCase( const TestCase& other );
            virtual ~TestCase();
            //@}
            
            //!\name Properties
            //@{
            Assert& getAssert();
            const Assert& getAssert() const;
            void setAssert( const Assert& newAssert );
            //@}
    
            //!\name Execute
            //@{
            void beforeExecuteClass();
            void afterExecuteClass();
            void beforeExecute();
            void afterExecute();
            //@}
    
            //!\name Operators
            //@{
            TestCase& operator=( const TestCase& other );
            //@}
    
        private:
            //!\name Execute
            //@{
            virtual void doBeforeExecuteClass();
            virtual void doAfterExecuteClass();
            virtual void doBeforeExecute();
            virtual void doAfterExecute();
            //@}
    
        private:
            Assert m_Assert;
        };
    
        //-------------------------------------------------------------------------
        typedef QSharedPointer<TestCase> TestCasePtr;
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
