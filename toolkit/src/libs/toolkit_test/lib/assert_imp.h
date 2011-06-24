template<typename AWType, typename T1, typename T2>
bool Assert::assertEquals( AWType assertWriter, const Toolkit::Core::SourceLine& srcLine, const TestResultType& resType, 
                           const expr_type& expr, const std::pair<T1, T2>& exprValue ) const 
{
    return assertEquals( assertWriter, srcLine, "", resType, expr, exprValue );
};

template<typename AWType, typename T1, typename T2>
bool Assert::assertEquals( AWType assertWriter, const Toolkit::Core::SourceLine& srcLine, const QString& message, const TestResultType& resType, 
                           const expr_type& expr, const std::pair<T1, T2>& exprValue ) const 
{
    bool assertResult = exprValue.first == exprValue.second;

    if( m_Report ) {
        TestResult testRes;

        testRes.setAssertType( TestResult::ASSERT_EQUAL );
        testRes.setSourceLine( srcLine );
        testRes.setMessage( message );

        if( assertResult ) {
            testRes.setResultType( TestResultType( TestResultType::RT_OK ) );
        }
        else {
            testRes.setResultType( TestResultType( resType ) );
        };

        m_Report->addResult( testRes.getResultType() );
        if( m_Report->willWriteResultType( testRes.getResultType() ) ) {
            assertWriter.writeAssert( m_Report, testRes, expr, exprValue );
        };
    
        throwAssertException( srcLine, testRes.getResultType().getResultType(), message );
    };

    return assertResult;
};

template<typename AWType, typename T1, typename T2>
bool Assert::assertNotEquals( AWType assertWriter, const Toolkit::Core::SourceLine& srcLine, const TestResultType& resType, 
                              const expr_type& expr, const std::pair<T1, T2>& exprValue ) const 
{
    return assertNotEquals( assertWriter, srcLine, "", resType, expr, exprValue );
};

template<typename AWType, typename T1, typename T2>
bool Assert::assertNotEquals( AWType assertWriter, const Toolkit::Core::SourceLine& srcLine, const QString& message, 
                              const TestResultType& resType, const expr_type& expr, const std::pair<T1, T2>& exprValue ) const 
{
    bool assertResult = exprValue.first != exprValue.second;

    if( m_Report ) {
        TestResult testRes;

        testRes.setAssertType( TestResult::ASSERT_NOT_EQUAL );
        testRes.setSourceLine( srcLine );
        testRes.setMessage( message );

        if( assertResult ) {
            testRes.setResultType( TestResultType( TestResultType::RT_OK ) );
        }
        else {
            testRes.setResultType( TestResultType( resType ) );
        };

        m_Report->addResult( testRes.getResultType() );
        if( m_Report->willWriteResultType( testRes.getResultType() ) ) {
            assertWriter.writeAssert( m_Report, testRes, expr, exprValue );
        };
        
        throwAssertException( srcLine, testRes.getResultType().getResultType(), message );
    };

    return assertResult;
};

template<typename AWType>
bool Assert::assertTrue( AWType assertWriter, const Toolkit::Core::SourceLine& srcLine, const TestResultType& resType, 
                         const QString& expr, bool exprValue ) const 
{
    return assertTrue( assertWriter, srcLine, "", resType, expr, exprValue );
};

template<typename AWType>
bool Assert::assertTrue( AWType assertWriter, const Toolkit::Core::SourceLine& srcLine, const QString& message, const TestResultType& resType, 
                         const QString& expr, bool exprValue ) const 
{
    bool assertResult = exprValue == true;

    if( m_Report ) {
        TestResult testRes;

        testRes.setAssertType( TestResult::ASSERT_TRUE );
        testRes.setSourceLine( srcLine );
        testRes.setMessage( message );

        if( assertResult ) {
            testRes.setResultType( TestResultType( TestResultType::RT_OK ) );
        }
        else {
            testRes.setResultType( TestResultType( resType ) );
        };

        m_Report->addResult( testRes.getResultType() );
        if( m_Report->willWriteResultType( testRes.getResultType() ) ) {
            assertWriter.writeAssert( m_Report, testRes, std::make_pair( expr, "true" ), std::make_pair( exprValue, true ) );
        };
    
        throwAssertException( srcLine, testRes.getResultType().getResultType(), message );
    };

    return assertResult;
};

template<typename AWType>
bool Assert::assertFalse( AWType assertWriter, const Toolkit::Core::SourceLine& srcLine, const TestResultType& resType, 
                          const QString& expr, bool exprValue ) const 
{
    return assertFalse( assertWriter, srcLine, "", resType, expr, exprValue );
};

template<typename AWType>
bool Assert::assertFalse( AWType assertWriter, const Toolkit::Core::SourceLine& srcLine, const QString& message, const TestResultType& resType, 
                          const QString& expr, bool exprValue ) const 
{
    bool assertResult = exprValue == false;

    if( m_Report ) {
        TestResult testRes;

        testRes.setAssertType( TestResult::ASSERT_FALSE );
        testRes.setSourceLine( srcLine );
        testRes.setMessage( message );

        if( assertResult ) {
            testRes.setResultType( TestResultType( TestResultType::RT_OK ) );
        }
        else {
            testRes.setResultType( TestResultType( resType ) );
        };

        m_Report->addResult( testRes.getResultType() );
        if( m_Report->willWriteResultType( testRes.getResultType() ) ) {
            assertWriter.writeAssert( m_Report, testRes, std::make_pair( expr, "false" ), std::make_pair( exprValue, false ) );
        };
    
        throwAssertException( srcLine, testRes.getResultType().getResultType(), message );
    };

    return assertResult;
};

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
