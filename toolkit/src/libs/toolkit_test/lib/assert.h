//-------------------------------------------------------------------------
/*!
    \file assert.h
    \brief
*/

//-------------------------------------------------------------------------
#ifndef __TOOLKIT_TEST_ASSERT_H__
#define __TOOLKIT_TEST_ASSERT_H__

// Include Toolkit Test Files
#include "defines.h"
#include "abstractreport.h"
#include "testresult.h"

// Include QT Files
#include <QObject>

// Include Toolkit Core Files
#include <toolkit/core/sourceline.h>

// Include STD Files
#include <math.h>
#include <utility>

//-------------------------------------------------------------
namespace Toolkit {
    
    namespace Test {
	//-------------------------------------------------------------------------
	/*!
            \ingroup grp_Test
            \brief
	*/
	class TOOLKIT_TEST_API Assert : public QObject {
            Q_OBJECT

        public:
            typedef std::pair<QString, QString> expr_type;
            
	public:
            //!\name Constructors & Destructor
            //@{
            Assert();
            Assert( const Assert& other );
            virtual ~Assert();
            //@}

            //!\name Properties
            //@{
            AbstractReport* getReport();
            const AbstractReport* getReport() const;
            void setReport( AbstractReport* newReport );
            //@}

            //!\name Asserts
            //@{
            template<typename AWType, typename T1, typename T2>
            bool assertEquals( AWType assertWriter, const Toolkit::Core::SourceLine& srcLine, const TestResultType& resType, 
                               const expr_type& expr, const std::pair<T1, T2>& exprValue ) const;

            template<typename AWType, typename T1, typename T2>
            bool assertEquals( AWType assertWriter, const Toolkit::Core::SourceLine& srcLine, const QString& message, const TestResultType& resType, 
                               const expr_type& expr, const std::pair<T1, T2>& exprValue ) const;

            template<typename AWType, typename T1, typename T2>
            bool assertNotEquals( AWType assertWriter, const Toolkit::Core::SourceLine& srcLine, const TestResultType& resType, 
                                  const expr_type& expr, const std::pair<T1, T2>& exprValue ) const;

            template<typename AWType, typename T1, typename T2>
            bool assertNotEquals( AWType assertWriter, const Toolkit::Core::SourceLine& srcLine, const QString& message, const TestResultType& resType, 
                                  const expr_type& expr, const std::pair<T1, T2>& exprValue ) const;

            template<typename AWType>
            bool assertTrue( AWType assertWriter, const Toolkit::Core::SourceLine& srcLine, const TestResultType& resType, const QString& expr, bool exprValue ) const;
            
            template<typename AWType>
            bool assertTrue( AWType assertWriter, const Toolkit::Core::SourceLine& srcLine, const QString& message, const TestResultType& resType, 
                             const QString& expr, bool exprValue ) const;
            
            template<typename AWType>
            bool assertFalse( AWType assertWriter, const Toolkit::Core::SourceLine& srcLine, const TestResultType& resType, 
                              const QString& expr, bool exprValue ) const;
            
            template<typename AWType>
            bool assertFalse( AWType assertWriter, const Toolkit::Core::SourceLine& srcLine, const QString& message, const TestResultType& resType, 
                              const QString& expr, bool exprValue ) const;
            
            void assertException( const Toolkit::Core::SourceLine& srcLine, int assertType, const QString& message, const TestResultType& resType, const QString& expName, const QString& expMessage ) const;
            void assertFail( const Toolkit::Core::SourceLine& srcLine, const TestResultType& res, const QString& message ) const;
            //@}
            
            //!\name Operators
            //@{
            Assert& operator=( const Assert& other );
            //@}

        private:
            //!\name Helpers
            //@{
            void throwAssertException( const Toolkit::Core::SourceLine& srcLine, const TestResultType& res, const QString& message ) const;
            //@}
            
	private:
            //!\name Properties
            //@{
            AbstractReport* m_Report;
            //@}
	};

        //-------------------------------------------------------------
        // Include implementation file of template functions.
        #include "assert_imp.h"
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
