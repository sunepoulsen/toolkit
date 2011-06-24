//-------------------------------------------------------------------------
/*!
  \file testexecutor.h
  \brief
*/

//-------------------------------------------------------------------------
#ifndef __TOOLKIT_TEST_TESTEXECUTOR_H__
#define __TOOLKIT_TEST_TESTEXECUTOR_H__

// Include Toolkit Test Files
#include "defines.h"
#include "abstractreport.h"
#include "assert.h"
#include "testcase.h"
#include "testsuite.h"

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
        class TOOLKIT_TEST_API TestExecutor {
	public:
            typedef TestSuite::iterator iterator;
            typedef TestSuite::const_iterator const_iterator;
            typedef TestSuite::reference reference;
            typedef TestSuite::const_reference const_reference;
            typedef TestSuite::size_type size_type;
            typedef TestSuite::value_type value_type;
        
        public:
            //!\name Constructors & Destructor
            //@{
            TestExecutor();
            TestExecutor( const AbstractReportPtr& report );
            TestExecutor( const TestExecutor& other );
            virtual ~TestExecutor();
            //@}
            
            //!\name Properties
            //@{
            Assert& getAssert();
            const Assert& getAssert() const;
            void setAssert( const Assert& newAssert );
            AbstractReportPtr& getReport();            
            const AbstractReportPtr& getReport() const;
            void setReport( const AbstractReportPtr& newReport );
            //@}
            
            //!\name Tests
            //@{
            iterator begin();
            const_iterator begin() const;
            iterator end();
            const_iterator end() const;
            void addTest( const value_type& v );
            void clear();
            void erase( iterator pos );
            void erase( iterator __begin, iterator __end );
            iterator findTest( const QString& id );
            const_iterator findTest( const QString& id ) const;
            size_type size() const;
            //@}
            
            //!\name Execution
            //@{
            void execute();
            void executeTest( iterator it );
            void executeTestSuite( TestSuite& suite );
            void executeTestCase( TestCase& testCase );
            //@}
            
            //!\name Operators
            //@{
            TestExecutor& operator=( const TestExecutor& other );
            reference operator[]( size_type n );
            const_reference operator[]( size_type n ) const;
            //@}
            
        private:
            TestSuite m_Tests;
            Assert m_Assert;
            AbstractReportPtr m_Report;
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
