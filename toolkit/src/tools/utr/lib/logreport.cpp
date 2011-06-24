//-------------------------------------------------------------------------
/*!
    \file logreport.cpp
    \brief
*/

//-------------------------------------------------------------------------

// Include Header File
#include "logreport.h"

// Include Toolkit Test Files
#include <toolkit/test/abstracttest.h>

// Include Toolkit Core Files
#include <toolkit/core/deviceformat.h>
#include <toolkit/core/log.h>

// Include STD Files
#include <iostream>

//-------------------------------------------------------------------------
using namespace Toolkit::Core;
using namespace Toolkit::Test;

//-------------------------------------------------------------------------
unsigned int LogReport::m_IndentSize( 0 );

//-------------------------------------------------------------------------
LogReport::LogReport() :
    AbstractReport(),
    m_OutputType( RT_SHORT_OUTPUT ),
    m_PrintTests( false ),    
    m_PrintStatistics( false )
{
};

LogReport::LogReport( const LogReport& other ) :
    AbstractReport( other ),
    m_OutputType( other.m_OutputType ),
    m_PrintTests( other.m_PrintTests ),    
    m_PrintStatistics( other.m_PrintStatistics )
{
};

LogReport::~LogReport() {
};

LogReport::OutputType LogReport::getOutputType() const {
    return m_OutputType;
};

void LogReport::setOutputType( OutputType newOutputType ) {
    m_OutputType = newOutputType;
};

bool LogReport::getPrintTests() const {
    return m_PrintTests;
};

void LogReport::setPrintTests( bool newPrintTests ) {
    m_PrintTests = newPrintTests;
};

bool LogReport::getPrintStatistics() const {
    return m_PrintStatistics;
};

void LogReport::setPrintStatistics( bool newPrintStatistics ) {
    m_PrintStatistics = newPrintStatistics;
};

void LogReport::doBeginReport() {
};

void LogReport::doEndReport() {
    if( m_PrintStatistics ) {
        DeviceFormat::write( stdout, "\n" );
        DeviceFormat::write( stdout, "Statistics:\n" );
        DeviceFormat::write( stdout, "=================================================\n" );
        DeviceFormat::write( stdout, "Number of %20s %s\n", "OK:", QString::number( countResult( TestResultType::RT_OK ) ) );
        DeviceFormat::write( stdout, "Number of %20s %s\n", "warnings:", QString::number( countResult( TestResultType::RT_WARNING ) ) );
        DeviceFormat::write( stdout, "Number of %20s %s\n", "required failures:", QString::number( countResult( TestResultType::RT_REQUIRED ) ) );
        DeviceFormat::write( stdout, "Number of %20s %s\n", "failures:", QString::number( countResult( TestResultType::RT_FAILURE ) ) );
        DeviceFormat::write( stdout, "Number of %20s %s\n", "critical errors:", QString::number( countResult( TestResultType::RT_CRITICAL ) ) );
        DeviceFormat::write( stdout, "Number of %20s %s\n", "fatal errors:", QString::number( countResult( TestResultType::RT_FATAL ) ) );        
    };
    
    DeviceFormat::write( stdout, "\n" );
    int noErrors = countResultErrors();
    if( noErrors ) {
        DeviceFormat::write( stdout, "The test has detected %i error(s)!\n", noErrors );
    }
    else {
        DeviceFormat::write( stdout, "No errors detected!\n" );
        
        int noWarnings = countResult( TestResultType::RT_WARNING );
        if( noWarnings ) {
            DeviceFormat::write( stdout, "The test has detected %i warning(s)!\n", noWarnings );
        };
    };
    DeviceFormat::write( stdout, "\n" );
};

void LogReport::doBeginTest( const AbstractTest* test ) {
    if( m_PrintTests ) {
        try {
            DeviceFormat::write( stdout, "%s Begin test: %s\n", QString( m_IndentSize, ' ' ), test->getId() );
            m_IndentSize += 2;
        }
        catch( FormatException& e ) {
            printf( "FormatException: %s\n", e.getMessage().toLatin1().data() );
        };
    };
};

void LogReport::doEndTest( const AbstractTest* test ) {
    if( m_PrintTests ) {
        m_IndentSize -= 2;
        DeviceFormat::write( stdout, "%s End test: %s\n", QString( m_IndentSize, ' ' ), test->getId() );
    };
};

void LogReport::doBeginExecuteTest( const AbstractTest* test, const QString& testId ) {
    if( m_PrintTests ) {
        DeviceFormat::write( stdout, "%s Begin execute test: %s::%s\n", QString( m_IndentSize, ' ' ), test->getId(), testId );
        m_IndentSize += 2;
    };
};

void LogReport::doEndExecuteTest( const AbstractTest* test, const QString& testId ) {
    if( m_PrintTests ) {
        m_IndentSize -= 2;
        DeviceFormat::write( stdout, "%s End execute test: %s::%s\n", QString( m_IndentSize, ' ' ), test->getId(), testId );
    };
};

QString LogReport::AssertTypeOp( int assertType ) const {
    if( assertType == TestResult::ASSERT_EQUAL ) {
        return "==";
    }
    else if( assertType == TestResult::ASSERT_NOT_EQUAL ) {
        return "!=";
    }
    else if( assertType == TestResult::ASSERT_TRUE ) {
        return "==";
    }
    else if( assertType == TestResult::ASSERT_FALSE ) {
        return "==";
    };
    
    return "?";
};

QString LogReport::AssertTypeFailOp( int assertType ) const {
    if( assertType == TestResult::ASSERT_EQUAL ) {
        return "!=";
    }
    else if( assertType == TestResult::ASSERT_NOT_EQUAL ) {
        return "==";
    }
    else if( assertType == TestResult::ASSERT_TRUE ) {
        return "!=";
    }
    else if( assertType == TestResult::ASSERT_FALSE ) {
        return "!=";
    };
    
    return "?";
};

bool LogReport::doWillWriteResultType( const TestResultType& resType ) const {
    return resType.getResultType() != TestResultType::RT_OK;
};

void LogReport::doWriteAssertEqual( const TestResult& testRes, const std::pair<QString, QString>& expr, const std::pair<QString, QString>& exprValue ) {
    Log log( Log::LT_INFO, Log::MOD_MAIN, "void LogReport::doWriteAssertEqual( const TestResult& testRes, const QString& actual, const QString& expected )" );
    log.write( Log::LT_TRACE, "%s:%i: %s", testRes.getSourceLine().getFileName(), testRes.getSourceLine().getLineNumber(), testRes.getMessage() );
    log.write( Log::LT_TRACE, "Actual: %ds", exprValue.first );
    log.write( Log::LT_TRACE, "Expected: %ds", exprValue.second );
    
    switch( m_OutputType ) {
        case RT_SHORT_OUTPUT: {
            if( testRes.getMessage().isEmpty() ) {
                DeviceFormat::write( stdout, QString( m_IndentSize, ' ' ) );
                DeviceFormat::write( stdout, "%s:%i: %s: %ds %s %ds ==> [%ds %s %ds]\n", 
                                             testRes.getSourceLine().getFileName(), testRes.getSourceLine().getLineNumber(),
                                             testRes.getResultType().toString(), 
                                             expr.first, AssertTypeOp( testRes.getAssertType() ), expr.second, 
                                             exprValue.first, AssertTypeFailOp( testRes.getAssertType() ), exprValue.second );
            }
            else {
                DeviceFormat::write( stdout, QString( m_IndentSize, ' ' ) );
                DeviceFormat::write( stdout, "%s:%i: %s: %s: %ds %s %ds ==> [%ds %s %ds]\n", 
                                             testRes.getSourceLine().getFileName(), testRes.getSourceLine().getLineNumber(), testRes.getResultType().toString(),
                                             testRes.getMessage(), 
                                             expr.first, AssertTypeOp( testRes.getAssertType() ), expr.second, 
                                             exprValue.first, AssertTypeFailOp( testRes.getAssertType() ), exprValue.second );
            };
            
            break;
        }
        
        case RT_LONG_OUTPUT: {
            DeviceFormat::write( stdout, QString( m_IndentSize, ' ' ) );
            DeviceFormat::write( stdout, "%s:%i: Assert Type: %s (%i): %s\n", testRes.getSourceLine().getFileName(), testRes.getSourceLine().getLineNumber(), 
                                                                testRes.toAssertTypeString(), testRes.getAssertType(), testRes.getResultType().toString() );
            DeviceFormat::write( stdout, QString( m_IndentSize, ' ' ) );
            DeviceFormat::write( stdout, "  Message: %ds\n", testRes.getMessage() );
            
            DeviceFormat::write( stdout, QString( m_IndentSize, ' ' ) );
            DeviceFormat::write( stdout, "  Actual:   %ds ==> [%ds]\n", expr.first, exprValue.first );
            
            DeviceFormat::write( stdout, QString( m_IndentSize, ' ' ) );
            DeviceFormat::write( stdout, "  Expected: %ds ==> [%ds]\n", expr.second, exprValue.second );
            
            break;
        }
    };
};

void LogReport::doWriteAssertException( const TestResult& testRes, const QString& expName, const QString& expMessage ) {
    Log log( Log::LT_INFO, Log::MOD_MAIN, "void LogReport::doWriteAssertException( const TestResult& testRes, const QString& expName )" );
    log.write( Log::LT_TRACE, "%s:%i: %s", testRes.getSourceLine().getFileName(), testRes.getSourceLine().getLineNumber(), testRes.getMessage() );
    log.write( Log::LT_TRACE, "expName: %s", expName );
    
    switch( m_OutputType ) {
        case RT_SHORT_OUTPUT: {
            QString s = StringFormat::format( "%s:%i: %s: ",
                                              testRes.getSourceLine().getFileName(),
                                              testRes.getSourceLine().getLineNumber(),
                                              testRes.getResultType().toString() );

            if( !testRes.getMessage().isEmpty() ) {
                s += testRes.getMessage() + ": ";
            };

            if( testRes.getAssertType() == TestResult::ASSERT_EXCEPTION ) {
                s += "Expected exception: " + expName;
            }
            else if( testRes.getAssertType() == TestResult::ASSERT_WRONG_EXCEPTION ) {
                s += "Unexpected exception (" + expName + "): " + expMessage;
            };

            DeviceFormat::write( stdout, QString( m_IndentSize, ' ' ) );
            DeviceFormat::write( stdout, s + "\n" );
            
            break;
        }
        
        case RT_LONG_OUTPUT: {
            DeviceFormat::write( stdout, QString( m_IndentSize, ' ' ) );
            DeviceFormat::write( stdout, "%s:%i: Assert Type: %s (%i): %s\n", testRes.getSourceLine().getFileName(), testRes.getSourceLine().getLineNumber(), 
                                                                testRes.toAssertTypeString(), testRes.getAssertType(), testRes.getResultType().toString() );
            
            DeviceFormat::write( stdout, QString( m_IndentSize, ' ' ) );
            DeviceFormat::write( stdout, "  Exception: %ds\n", expName );
            
            DeviceFormat::write( stdout, QString( m_IndentSize, ' ' ) );
            DeviceFormat::write( stdout, "  Message: %ds\n", expMessage );
            
            break;
        }
    };
};

void LogReport::doWriteAssert( const TestResult& testRes ) {
    Log log( Log::LT_INFO, Log::MOD_MAIN, "void LogReport::doWriteAssert( const TestResult& testRes )" );
    log.write( Log::LT_TRACE, "%s:%i: %s", testRes.getSourceLine().getFileName(), testRes.getSourceLine().getLineNumber(), testRes.getMessage() );
    
    switch( m_OutputType ) {
        case RT_SHORT_OUTPUT: {
            DeviceFormat::write( stdout, QString( m_IndentSize, ' ' ) );
            DeviceFormat::write( stdout, "%s:%i: %s: %ds\n", testRes.getSourceLine().getFileName(), testRes.getSourceLine().getLineNumber(), 
                                                             testRes.getResultType().toString(), testRes.getMessage() );
            
            break;
        }
        
        case RT_LONG_OUTPUT: {
            DeviceFormat::write( stdout, QString( m_IndentSize, ' ' ) );
            DeviceFormat::write( stdout, "%s:%i: Assert Type: %s (%i): %s\n", testRes.getSourceLine().getFileName(), testRes.getSourceLine().getLineNumber(), 
                                                                testRes.toAssertTypeString(), testRes.getAssertType(), testRes.getResultType().toString() );
            
            DeviceFormat::write( stdout, QString( m_IndentSize, ' ' ) );
            DeviceFormat::write( stdout, "  Message: %ds\n", testRes.getMessage() );
            
            break;
        }
    };
};

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
