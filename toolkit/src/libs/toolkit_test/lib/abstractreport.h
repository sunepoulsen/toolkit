//-------------------------------------------------------------------------
/*!
    \file abstractreport.h
    \brief
*/

//-------------------------------------------------------------------------
#ifndef __TOOLKIT_TEST_ABSTRACTREPORT_H__
#define __TOOLKIT_TEST_ABSTRACTREPORT_H__

// Include Toolkit Test Files
#include "defines.h"
#include "testresult.h"

// Include QT Files
#include <QDate>
#include <QDateTime>
#include <QSharedPointer>
#include <QTime>

// Include STD Files
#include <map>
#include <utility>

//-------------------------------------------------------------
namespace Toolkit {
    
    namespace Test {
        //-------------------------------------------------------------------------
        class AbstractTest;
        
        //-------------------------------------------------------------------------
	/*!
            \ingroup grp_Test
            \brief
	*/
	class TOOLKIT_TEST_API AbstractReport {
        public:
            typedef std::map<int, int> results_container_type;
            typedef results_container_type::key_type results_key_type;
            typedef results_container_type::reference results_reference;
            typedef results_container_type::const_reference results_const_reference;
            
	public:
            //!\name Constructors & Destructor
            //@{
            AbstractReport();
            AbstractReport( const AbstractReport& other );
            virtual ~AbstractReport();
            //@}
            
            //!\name Properties
            //@{
            const QString& getId() const;
            void setId( const QString& newId );
            //@}
            
            //!\name Events
            //@{
            void beginReport();
            void endReport();
            void beginTest( const AbstractTest* test );
            void endTest( const AbstractTest* test );
            void beginExecuteTest( const AbstractTest* test, const QString& testId );
            void endExecuteTest( const AbstractTest* test, const QString& testId );
            //@}
            
            //!\name Writers
            //@{
            bool willWriteResultType( const TestResultType& resType ) const;
            void writeAssertEqual( const TestResult& testRes, const std::pair<QString, QString>& expr, const std::pair<QString, QString>& exprValue );
            void writeAssertException( const TestResult& testRes, const QString& expName, const QString& expMessage );
            void writeAssert( const TestResult& testRes );
            //@}

            //!\name Statistics
            //@{
            void clearResults();
            void addResult( const TestResultType& resType );
            int countResult( int key ) const;
            int countResultErrors() const;
            //@}
            
            //!\name Operators
            //@{
            AbstractReport& operator=( const AbstractReport& other );
            //@}

        private:
            //!\name Events
            //@{
            virtual void doBeginReport();
            virtual void doEndReport();
            virtual void doBeginTest( const AbstractTest* test );
            virtual void doEndTest( const AbstractTest* test );
            virtual void doBeginExecuteTest( const AbstractTest* test, const QString& testId );
            virtual void doEndExecuteTest( const AbstractTest* test, const QString& testId );
            //@}
            
            //!\name Writers
            //@{
            virtual bool doWillWriteResultType( const TestResultType& resType ) const = 0;
            virtual void doWriteAssertEqual( const TestResult& testRes, const std::pair<QString, QString>& expr, const std::pair<QString, QString>& exprValue ) = 0;
            virtual void doWriteAssertException( const TestResult& testRes, const QString& expName, const QString& expMessage ) = 0;
            virtual void doWriteAssert( const TestResult& testRes ) = 0;
            //@}
            
	private:
            QString m_Id;
            results_container_type m_Results;
	};

	//-------------------------------------------------------------------------
        typedef QSharedPointer<AbstractReport> AbstractReportPtr;
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
