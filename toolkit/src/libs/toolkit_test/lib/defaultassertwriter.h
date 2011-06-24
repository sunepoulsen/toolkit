//-------------------------------------------------------------------------
/*!
    \file defaultassertwriter.h
    \brief
*/

//-------------------------------------------------------------------------
#ifndef __TOOLKIT_TEST_DEFAULTASSERTWRITER_H__
#define __TOOLKIT_TEST_DEFAULTASSERTWRITER_H__

// Include Toolkit Test Files
#include "abstractreport.h"
#include "testresult.h"

// Include Toolkit Core Files
#include <toolkit/core/abstracttextconverter.h>
#include <toolkit/core/format.h>

// Include Qt Files
#include <QFile>

//-------------------------------------------------------------------------
namespace Toolkit {
    
    namespace Test {
	//-------------------------------------------------------------------------
        class AbstractReport;
        
	//-------------------------------------------------------------------------
        /*!
            \ingroup grp_Test
            \brief
        */
        class TOOLKIT_TEST_API DefaultAssertWriter {
        public:
            static const QString FORMAT_BOOL;
            static const QString FORMAT_CHAR;
            static const QString FORMAT_NON_PRINT_CHAR;
            static const QString FORMAT_QBYTEARRAY;
            static const QString FORMAT_QVARIANT;

        public:
            //!\name Constructors & Destructor
            //@{
            DefaultAssertWriter();
            virtual ~DefaultAssertWriter();
            //@}
            
            //!\name Assert Equal Chars
            //@{
            void writeAssert( AbstractReport* report, const TestResult& testRes, const std::pair<QString, QString>& expr, const std::pair<QChar, QChar>& exprValue );

            template< typename charType >
            void writeAssert( AbstractReport* report, const TestResult& testRes,
                              const std::pair<QString, QString>& expr, const std::pair<QChar, charType>& exprValue )
            {
                writeAssert( report, testRes, expr, std::make_pair( exprValue.first, QChar( exprValue.second ) ) );
            };
            //@}

            //!\name Assert Equal Strings
            //@{
            void writeAssert( AbstractReport* report, const TestResult& testRes, const std::pair<QString, QString>& expr, const std::pair<const char*, const char*>& exprValue );
            void writeAssert( AbstractReport* report, const TestResult& testRes, const std::pair<QString, QString>& expr, const std::pair<QString, QString>& exprValue );
            void writeAssert( AbstractReport* report, const TestResult& testRes, const std::pair<QString, QString>& expr, const std::pair<const char*, std::string>& exprValue );
            void writeAssert( AbstractReport* report, const TestResult& testRes, const std::pair<QString, QString>& expr, const std::pair<std::string, const char*>& exprValue );
            void writeAssert( AbstractReport* report, const TestResult& testRes, const std::pair<QString, QString>& expr, const std::pair<std::string, std::string>& exprValue );

            template< typename T >
            void writeAssert( AbstractReport* report, const TestResult& testRes,
                              const std::pair<QString, QString>& expr, const std::pair<QString, T>& exprValue )
            {
                writeAssert( report, testRes, expr, std::make_pair( exprValue.first, QString( exprValue.second ) ) );
            };

            template< typename T >
            void writeAssert( AbstractReport* report, const TestResult& testRes,
                              const std::pair<QString, QString>& expr, const std::pair<T, QString>& exprValue )
            {
                writeAssert( report, testRes, expr, std::make_pair( QString( exprValue.first ), exprValue.second ) );
            };
            //@}
            
            //!\name Assert Equal Basic types
            //@{
            void writeAssert( AbstractReport* report, const TestResult& testRes, const std::pair<QString, QString>& expr, const std::pair<bool, bool>& exprValue );

            template< typename intT1, typename intT2 >
            void writeAssert( AbstractReport* report, const TestResult& testRes, 
                              const std::pair<QString, QString>& expr, const std::pair<intT1, intT2>& exprValue )
            {
                report->writeAssertEqual( testRes, expr, std::make_pair( QString::number( exprValue.first ), QString::number( exprValue.second ) ) );
            };
            //@}
            
            //!\name Assert Equal Arrays
            void writeAssert( AbstractReport* report, const TestResult& testRes, const std::pair<QString, QString>& expr, const std::pair<const char*, QByteArray>& exprValue );
            void writeAssert( AbstractReport* report, const TestResult& testRes, const std::pair<QString, QString>& expr, const std::pair<QByteArray, const char*>& exprValue );
            void writeAssert( AbstractReport* report, const TestResult& testRes, const std::pair<QString, QString>& expr, const std::pair<QByteArray, QByteArray>& exprValue );
            //@}
            
            //!\name Assert Equal Date & Time
            void writeAssert( AbstractReport* report, const TestResult& testRes, const std::pair<QString, QString>& expr, const std::pair<QDate, QDate>& exprValue );
            void writeAssert( AbstractReport* report, const TestResult& testRes, const std::pair<QString, QString>& expr, const std::pair<QTime, QTime>& exprValue );
            void writeAssert( AbstractReport* report, const TestResult& testRes, const std::pair<QString, QString>& expr, const std::pair<QDateTime, QDateTime>& exprValue );
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
