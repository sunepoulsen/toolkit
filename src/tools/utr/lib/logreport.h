//-------------------------------------------------------------------------
/*!
    \file logreport.h
    \brief
*/

//-------------------------------------------------------------------------
#ifndef __TOOLKIT_TEST_UTR_LOGREPORT_H__
#define __TOOLKIT_TEST_UTR_LOGREPORT_H__

// Include Toolkit Test Files
#include <toolkit/test/abstractreport.h>

// Include Toolkit Core Files
#include <toolkit/core/abstracttextconverter.h>

// Include Qt Files
#include <QFile>

//-------------------------------------------------------------------------
/*!
    \brief
*/
class LogReport : public Toolkit::Test::AbstractReport {
public:
    enum OutputType {
        RT_SHORT_OUTPUT,
        RT_LONG_OUTPUT
    };

public:
    //!\name Constructors & Destructor
    //@{
    LogReport();
    LogReport( const LogReport& other );
    virtual ~LogReport();
    //@}

    //!\name Options
    //@{
    OutputType getOutputType() const;
    void setOutputType( OutputType newOutputType );
    bool getPrintTests() const;
    void setPrintTests( bool newPrintTests );
    bool getPrintStatistics() const;
    void setPrintStatistics( bool newPrintStatistics );
    //@}

private:
    //!\name Events
    //@{
    virtual void doBeginReport();
    virtual void doEndReport();
    virtual void doBeginTest( const Toolkit::Test::AbstractTest* test );
    virtual void doEndTest( const Toolkit::Test::AbstractTest* test );
    virtual void doBeginExecuteTest( const Toolkit::Test::AbstractTest* test, const QString& testId );
    virtual void doEndExecuteTest( const Toolkit::Test::AbstractTest* test, const QString& testId );
    //@}

    //!\name Write Helpers
    //@{
    QString AssertTypeOp( int assertType ) const;
    QString AssertTypeFailOp( int assertType ) const;
    //@}

    //!\name Writers
    //@{
    virtual bool doWillWriteResultType( const Toolkit::Test::TestResultType& resType ) const;
    virtual void doWriteAssertEqual( const Toolkit::Test::TestResult& testRes, const std::pair<QString, QString>& expr, const std::pair<QString, QString>& exprValue );
    virtual void doWriteAssertException( const Toolkit::Test::TestResult& testRes, const QString& expName, const QString& expMessage );
    virtual void doWriteAssert( const Toolkit::Test::TestResult& testRes );
    //@}

private:
    //!\name Options
    //@{
    OutputType m_OutputType;
    bool m_PrintTests;
    bool m_PrintStatistics;
    //@}

    static unsigned int m_IndentSize;
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
