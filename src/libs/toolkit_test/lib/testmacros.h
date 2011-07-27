//-------------------------------------------------------------------------
/*!
    \file testmacros.h
    \brief
*/

//-------------------------------------------------------------------------
#ifndef __TOOLKIT_TEST_TESTMACROS_H__
#define __TOOLKIT_TEST_TESTMACROS_H__

// Include Toolkit Test Files
#include <toolkit/test/assertexception.h>
#include <toolkit/test/assertrequireexception.h>
#include <toolkit/test/assertcriticalexception.h>
#include <toolkit/test/assertfatalexception.h>

// Include STD Files
#include <typeinfo>
#include <cxxabi.h>

//-------------------------------------------------------------------------
//            Helper Macros
//-------------------------------------------------------------------------

/*!
    \name Assert helper macros
*/
//@{
/*!
    \ingroup grp_Test
    \brief Implementation macro for assert equals.

    \param assertWriter Instance of a assert writer class.
    \param status       Status of the test. An instance of TestResultType
    \param message      The message of the test.
    \param actual       Actual value.
    \param expected     Expected value.
*/
#define ASSERT_EQUAL_MESSAGE_IMPL( assertWriter, status, message, actual, expected ) \
{ \
    ASSERT_TRY_IMPL \
        getAssert().assertEquals( assertWriter, SOURCELINE, Toolkit::Test::TestResultType( status ), std::make_pair( #actual, #expected ), std::make_pair( actual, expected ) ); \
    } \
    ASSERT_CATCH_ASSERT_EXCEPTIONS \
    ASSERT_CATCH_SYS_EXCEPTIONS( SOURCELINE, Toolkit::Test::TestResult::ASSERT_WRONG_EXCEPTION, status, message ) \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_EQUAL_IMPL( assertWriter, status, actual, expected ) \
{ \
    ASSERT_EQUAL_MESSAGE_IMPL( assertWriter, status, "", actual, expected ); \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_NOT_EQUAL_MESSAGE_IMPL( assertWriter, status, message, actual, expected ) \
{ \
    ASSERT_TRY_IMPL \
        getAssert().assertNotEquals( assertWriter, SOURCELINE, Toolkit::Test::TestResultType( status ), std::make_pair( #actual, #expected ), std::make_pair( actual, expected ) ); \
    } \
    ASSERT_CATCH_ASSERT_EXCEPTIONS \
    ASSERT_CATCH_SYS_EXCEPTIONS( SOURCELINE, Toolkit::Test::TestResult::ASSERT_WRONG_EXCEPTION, status, message ) \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_NOT_EQUAL_IMPL( assertWriter, status, actual, expected ) \
{ \
    ASSERT_NOT_EQUAL_MESSAGE_IMPL( assertWriter, status, "", actual, expected ); \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_TRUE_MESSAGE_IMPL( assertWriter, status, message, expr ) \
{ \
    ASSERT_TRY_IMPL \
        getAssert().assertTrue( assertWriter, SOURCELINE, message, Toolkit::Test::TestResultType( status ), #expr, expr ); \
    } \
    ASSERT_CATCH_ASSERT_EXCEPTIONS \
    ASSERT_CATCH_SYS_EXCEPTIONS( SOURCELINE, Toolkit::Test::TestResult::ASSERT_WRONG_EXCEPTION, status, message ) \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_TRUE_IMPL( assertWriter, status, expr ) \
{ \
    ASSERT_TRUE_MESSAGE_IMPL( assertWriter, status, "", expr ); \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_FALSE_MESSAGE_IMPL( assertWriter, status, message, expr ) \
{ \
    ASSERT_TRY_IMPL \
        getAssert().assertFalse( assertWriter, SOURCELINE, message, Toolkit::Test::TestResultType( status ), #expr, expr ); \
    } \
    ASSERT_CATCH_ASSERT_EXCEPTIONS \
    ASSERT_CATCH_SYS_EXCEPTIONS( SOURCELINE, Toolkit::Test::TestResult::ASSERT_WRONG_EXCEPTION, status, message ) \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_FALSE_IMPL( assertWriter, status, expr ) \
{ \
    ASSERT_FALSE_MESSAGE_IMPL( assertWriter, status, "", expr ); \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_FAIL_IMPL( status, message ) \
{ \
    ASSERT_TRY_IMPL \
        getAssert().assertFail( SOURCELINE, Toolkit::Test::TestResultType( status ), message ); \
    } \
    ASSERT_CATCH_ASSERT_EXCEPTIONS \
    ASSERT_CATCH_SYS_EXCEPTIONS( SOURCELINE, Toolkit::Test::TestResult::ASSERT_WRONG_EXCEPTION, status, message ) \
}
//@}

//-------------------------------------------------------------------------
//            Exception helper macros
//-------------------------------------------------------------------------

/*!
    \name Assert exception helper macros
*/
//@{
/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_TRY_IMPL \
{ \
    try {

#define ASSERT_CATCH_ASSERT_EXCEPTIONS \
    catch( Toolkit::Test::AssertRequireException& reqExp ) { \
        throw reqExp; \
    } \
    catch( Toolkit::Test::AssertCriticalException& criExp ) { \
        throw criExp; \
    } \
    catch( Toolkit::Test::AssertFatalException& fatalExp ) { \
        throw fatalExp; \
    }

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_CATCH_SYS_EXCEPTIONS( srcLine, assertType, status, message ) \
    catch( Toolkit::Core::Throwable& coreExp ) { \
        getAssert().assertException( srcLine, assertType, message, Toolkit::Test::TestResultType( status ), abi::__cxa_demangle( typeid( coreExp ).name(), NULL, NULL, NULL ), coreExp.getMessage() ); \
    } \
    catch( std::exception& stdExp ) { \
        getAssert().assertException( srcLine, assertType, message, Toolkit::Test::TestResultType( status ), abi::__cxa_demangle( typeid( stdExp ).name(), NULL, NULL, NULL ), stdExp.what() ); \
    } \
    catch( ... ) { \
        getAssert().assertException( srcLine, assertType, message, Toolkit::Test::TestResultType( status ), "unknown exception", "" ); \
    } \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_EXCEPTION_MESSAGE_IMPL( srcLine, status, message, expr, expName ) \
    ASSERT_TRY_IMPL \
        expr; \
        getAssert().assertFail( srcLine, Toolkit::Test::TestResultType( status ), StringFormat::format( "Expected exception (%s) was not throwed: %s", #expName, message ) ); \
    } \
    ASSERT_CATCH_ASSERT_EXCEPTIONS \
    catch( expName& ) { \
        getAssert().assertFail( srcLine, Toolkit::Test::TestResultType( Toolkit::Test::TestResultType::RT_OK ), message ); \
    } \
    ASSERT_CATCH_SYS_EXCEPTIONS( srcLine, Toolkit::Test::TestResult::ASSERT_EXCEPTION, status, message )

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_NO_EXCEPTION_MESSAGE_IMPL( srcLine, status, message, expr ) \
    ASSERT_TRY_IMPL \
    expr; \
    getAssert().assertFail( srcLine, Toolkit::Test::TestResultType( Toolkit::Test::TestResultType::RT_OK ), message ); \
    } \
    ASSERT_CATCH_ASSERT_EXCEPTIONS \
    ASSERT_CATCH_SYS_EXCEPTIONS( srcLine, Toolkit::Test::TestResult::ASSERT_WRONG_EXCEPTION, status, message )
//@}

//-------------------------------------------------------------------------
//            Assert Failure Macros
//-------------------------------------------------------------------------

/*!
    \name Normal Assert Macros
*/
//@{
/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_EQUAL_MESSAGE( message, actual, expected ) \
{ \
    ASSERT_EQUAL_MESSAGE_IMPL( Toolkit::Test::DefaultAssertWriter(), Toolkit::Test::TestResultType::RT_FAILURE, message, actual, expected ); \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_EQUAL( actual, expected ) \
{ \
    ASSERT_EQUAL_MESSAGE( "", actual, expected ); \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_NOT_EQUAL_MESSAGE( message, actual, expected ) \
{ \
    ASSERT_NOT_EQUAL_MESSAGE_IMPL( Toolkit::Test::DefaultAssertWriter(), Toolkit::Test::TestResultType::RT_FAILURE, message, actual, expected ); \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_NOT_EQUAL( actual, expected ) \
{ \
    ASSERT_NOT_EQUAL_MESSAGE( "", actual, expected ); \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_TRUE_MESSAGE( message, expr ) \
{ \
    ASSERT_TRUE_MESSAGE_IMPL( Toolkit::Test::DefaultAssertWriter(), Toolkit::Test::TestResultType::RT_FAILURE, message, expr ); \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_TRUE( expr ) \
{ \
    ASSERT_TRUE_MESSAGE( "", expr ); \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_FALSE_MESSAGE( message, expr ) \
{ \
    ASSERT_FALSE_MESSAGE_IMPL( Toolkit::Test::DefaultAssertWriter(), Toolkit::Test::TestResultType::RT_FAILURE, message, expr ); \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_FALSE( expr ) \
{ \
    ASSERT_FALSE_MESSAGE( "", expr ); \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_EXCEPTION_MESSAGE( message, expr, expName ) \
{ \
    ASSERT_EXCEPTION_MESSAGE_IMPL( SOURCELINE, Toolkit::Test::TestResultType::RT_FAILURE, message, expr, expName ) \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_EXCEPTION( expr, expName ) \
{ \
    ASSERT_EXCEPTION_MESSAGE_IMPL( SOURCELINE, Toolkit::Test::TestResultType::RT_FAILURE, "", expr, expName ) \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_NO_EXCEPTION_MESSAGE( message, expr ) \
{ \
    ASSERT_NO_EXCEPTION_MESSAGE_IMPL( SOURCELINE, Toolkit::Test::TestResultType::RT_FAILURE, message, expr ) \
}
    
/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_NO_EXCEPTION( expr ) \
{ \
    ASSERT_NO_EXCEPTION_MESSAGE_IMPL( SOURCELINE, Toolkit::Test::TestResultType::RT_FAILURE, "", expr ) \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_OK( message ) \
{ \
    ASSERT_FAIL_IMPL( Toolkit::Test::TestResultType::RT_OK, message ); \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_FAIL( message ) \
{ \
    ASSERT_FAIL_IMPL( Toolkit::Test::TestResultType::RT_FAILURE, message ); \
}
//@}

//-------------------------------------------------------------------------
//            Assert Warning Macros
//-------------------------------------------------------------------------

/*!
    \name Warning Assert Macros
*/
//@{
/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_WARNING_EQUAL_MESSAGE( message, actual, expected ) \
{ \
    ASSERT_EQUAL_MESSAGE_IMPL( Toolkit::Test::DefaultAssertWriter(), Toolkit::Test::TestResultType::RT_WARNING, message, actual, expected ); \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_WARNING_EQUAL( actual, expected ) \
{ \
    ASSERT_WARNING_EQUAL_MESSAGE( "", actual, expected ); \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_WARNING_NOT_EQUAL_MESSAGE( message, actual, expected ) \
{ \
    ASSERT_NOT_EQUAL_MESSAGE_IMPL( Toolkit::Test::DefaultAssertWriter(), Toolkit::Test::TestResultType::RT_WARNING, message, actual, expected ); \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_WARNING_NOT_EQUAL( actual, expected ) \
{ \
    ASSERT_WARNING_NOT_EQUAL_MESSAGE( "", actual, expected ); \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_WARNING_TRUE_MESSAGE( message, expr ) \
{ \
    ASSERT_TRUE_MESSAGE_IMPL( Toolkit::Test::DefaultAssertWriter(), Toolkit::Test::TestResultType::RT_WARNING, message, expr ); \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_WARNING_TRUE( expr ) \
{ \
    ASSERT_WARNING_TRUE_MESSAGE( "", expr ); \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_WARNING_FALSE_MESSAGE( message, expr ) \
{ \
    ASSERT_FALSE_MESSAGE_IMPL( Toolkit::Test::DefaultAssertWriter(), Toolkit::Test::TestResultType::RT_WARNING, message, expr ); \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_WARNING_FALSE( expr ) \
{ \
    ASSERT_WARNING_FALSE_MESSAGE( "", expr ); \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_WARNING_EXCEPTION_MESSAGE( message, expr, expName ) \
{ \
    ASSERT_EXCEPTION_MESSAGE_IMPL( SOURCELINE, Toolkit::Test::TestResultType::RT_WARNING, message, expr, expName ) \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_WARNING_EXCEPTION( expr, expName ) \
{ \
    ASSERT_EXCEPTION_MESSAGE_IMPL( SOURCELINE, Toolkit::Test::TestResultType::RT_WARNING, "", expr, expName ) \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_WARNING_NO_EXCEPTION_MESSAGE( message, expr ) \
{ \
    ASSERT_NO_EXCEPTION_MESSAGE_IMPL( SOURCELINE, Toolkit::Test::TestResultType::RT_WARNING, message, expr ) \
}
    
/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_WARNING_NO_EXCEPTION( expr ) \
{ \
    ASSERT_NO_EXCEPTION_MESSAGE_IMPL( SOURCELINE, Toolkit::Test::TestResultType::RT_WARNING, "", expr ) \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_WARNING_FAIL( message ) \
{ \
    ASSERT_FAIL_IMPL( Toolkit::Test::TestResultType::RT_WARNING, message ); \
}
//@}

//-------------------------------------------------------------------------
//            Assert Required Macros
//-------------------------------------------------------------------------

/*!
    \name Required Assert Macros
*/
//@{
/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_REQUIRE_EQUAL_MESSAGE( message, actual, expected ) \
{ \
    ASSERT_EQUAL_MESSAGE_IMPL( Toolkit::Test::DefaultAssertWriter(), Toolkit::Test::TestResultType::RT_REQUIRED, message, actual, expected ); \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_REQUIRE_EQUAL( actual, expected ) \
{ \
    ASSERT_REQUIRE_EQUAL_MESSAGE( "", actual, expected ); \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_REQUIRE_NOT_EQUAL_MESSAGE( message, actual, expected ) \
{ \
    ASSERT_NOT_EQUAL_MESSAGE_IMPL( Toolkit::Test::DefaultAssertWriter(), Toolkit::Test::TestResultType::RT_REQUIRED, message, actual, expected ); \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_REQUIRE_NOT_EQUAL( actual, expected ) \
{ \
    ASSERT_REQUIRE_NOT_EQUAL_MESSAGE( "", actual, expected ); \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_REQUIRE_TRUE_MESSAGE( message, expr ) \
{ \
    ASSERT_TRUE_MESSAGE_IMPL( Toolkit::Test::DefaultAssertWriter(), Toolkit::Test::TestResultType::RT_REQUIRED, message, expr ); \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_REQUIRE_TRUE( expr ) \
{ \
    ASSERT_REQUIRE_TRUE_MESSAGE( "", expr ); \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_REQUIRE_FALSE_MESSAGE( message, expr ) \
{ \
    ASSERT_FALSE_MESSAGE_IMPL( Toolkit::Test::DefaultAssertWriter(), Toolkit::Test::TestResultType::RT_REQUIRED, message, expr ); \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_REQUIRE_FALSE( expr ) \
{ \
    ASSERT_REQUIRE_FALSE_MESSAGE( "", expr ); \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_REQUIRE_EXCEPTION_MESSAGE( message, expr, expName ) \
{ \
    ASSERT_EXCEPTION_MESSAGE_IMPL( SOURCELINE, Toolkit::Test::TestResultType::RT_REQUIRED, message, expr, expName ) \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_REQUIRE_EXCEPTION( expr, expName ) \
{ \
    ASSERT_EXCEPTION_MESSAGE_IMPL( SOURCELINE, Toolkit::Test::TestResultType::RT_REQUIRED, "", expr, expName ) \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_REQUIRE_NO_EXCEPTION_MESSAGE( message, expr ) \
{ \
    ASSERT_NO_EXCEPTION_MESSAGE_IMPL( SOURCELINE, Toolkit::Test::TestResultType::RT_REQUIRED, message, expr ) \
}
    
/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_REQUIRE_NO_EXCEPTION( expr ) \
{ \
    ASSERT_NO_EXCEPTION_MESSAGE_IMPL( SOURCELINE, Toolkit::Test::TestResultType::RT_REQUIRED, "", expr ) \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_REQUIRE_FAIL( message ) \
{ \
    ASSERT_FAIL_IMPL( Toolkit::Test::TestResultType::RT_REQUIRED, message ); \
}
//@}

//-------------------------------------------------------------------------
//            Assert Critical Macros
//-------------------------------------------------------------------------

/*!
    \name Critical Assert Macros
*/
//@{
/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_CRITICAL_EQUAL_MESSAGE( message, actual, expected ) \
{ \
    ASSERT_EQUAL_MESSAGE_IMPL( Toolkit::Test::DefaultAssertWriter(), Toolkit::Test::TestResultType::RT_CRITICAL, message, actual, expected ); \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_CRITICAL_EQUAL( actual, expected ) \
{ \
    ASSERT_CRITICAL_EQUAL_MESSAGE( "", actual, expected ); \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_CRITICAL_NOT_EQUAL_MESSAGE( message, actual, expected ) \
{ \
    ASSERT_NOT_EQUAL_MESSAGE_IMPL( Toolkit::Test::DefaultAssertWriter(), Toolkit::Test::TestResultType::RT_CRITICAL, message, actual, expected ); \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_CRITICAL_NOT_EQUAL( actual, expected ) \
{ \
    ASSERT_CRITICAL_NOT_EQUAL_MESSAGE( "", actual, expected ); \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_CRITICAL_TRUE_MESSAGE( message, expr ) \
{ \
    ASSERT_TRUE_MESSAGE_IMPL( Toolkit::Test::DefaultAssertWriter(), Toolkit::Test::TestResultType::RT_CRITICAL, message, expr ); \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_CRITICAL_TRUE( expr ) \
{ \
    ASSERT_CRITICAL_TRUE_MESSAGE( "", expr ); \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_CRITICAL_FALSE_MESSAGE( message, expr ) \
{ \
    ASSERT_FALSE_MESSAGE_IMPL( Toolkit::Test::DefaultAssertWriter(), Toolkit::Test::TestResultType::RT_CRITICAL, message, expr ); \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_CRITICAL_FALSE( expr ) \
{ \
    ASSERT_CRITICAL_FALSE_MESSAGE( "", expr ); \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_CRITICAL_EXCEPTION_MESSAGE( message, expr, expName ) \
{ \
    ASSERT_EXCEPTION_MESSAGE_IMPL( SOURCELINE, Toolkit::Test::TestResultType::RT_CRITICAL, message, expr, expName ) \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_CRITICAL_EXCEPTION( expr, expName ) \
{ \
    ASSERT_EXCEPTION_MESSAGE_IMPL( SOURCELINE, Toolkit::Test::TestResultType::RT_CRITICAL, "", expr, expName ) \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_CRITICAL_NO_EXCEPTION_MESSAGE( message, expr ) \
{ \
    ASSERT_NO_EXCEPTION_MESSAGE_IMPL( SOURCELINE, Toolkit::Test::TestResultType::RT_CRITICAL, message, expr ) \
}
    
/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_CRITICAL_NO_EXCEPTION( expr ) \
{ \
    ASSERT_NO_EXCEPTION_MESSAGE_IMPL( SOURCELINE, Toolkit::Test::TestResultType::RT_CRITICAL, "", expr ) \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_CRITICAL_FAIL( message ) \
{ \
    ASSERT_FAIL_IMPL( Toolkit::Test::TestResultType::RT_CRITICAL, message ); \
}
//@}

//-------------------------------------------------------------------------
//            Assert Fatal Macros
//-------------------------------------------------------------------------

/*!
    \name Fatal Assert Macros
*/
//@{
/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_FATAL_EQUAL_MESSAGE( message, actual, expected ) \
{ \
    ASSERT_EQUAL_MESSAGE_IMPL( Toolkit::Test::DefaultAssertWriter(), Toolkit::Test::TestResultType::RT_FATAL, message, actual, expected ); \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_FATAL_EQUAL( actual, expected ) \
{ \
    ASSERT_FATAL_EQUAL_MESSAGE( "", actual, expected ); \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_FATAL_NOT_EQUAL_MESSAGE( message, actual, expected ) \
{ \
    ASSERT_NOT_EQUAL_MESSAGE_IMPL( Toolkit::Test::DefaultAssertWriter(), Toolkit::Test::TestResultType::RT_FATAL, message, actual, expected ); \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_FATAL_NOT_EQUAL( actual, expected ) \
{ \
    ASSERT_FATAL_NOT_EQUAL_MESSAGE( "", actual, expected ); \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_FATAL_TRUE_MESSAGE( message, expr ) \
{ \
    ASSERT_TRUE_MESSAGE_IMPL( Toolkit::Test::DefaultAssertWriter(), Toolkit::Test::TestResultType::RT_FATAL, message, expr ); \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_FATAL_TRUE( expr ) \
{ \
    ASSERT_FATAL_TRUE_MESSAGE( "", expr ); \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_FATAL_FALSE_MESSAGE( message, expr ) \
{ \
    ASSERT_FALSE_MESSAGE_IMPL( Toolkit::Test::DefaultAssertWriter(), Toolkit::Test::TestResultType::RT_FATAL, message, expr ); \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_FATAL_FALSE( expr ) \
{ \
    ASSERT_FATAL_FALSE_MESSAGE( "", expr ); \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_FATAL_EXCEPTION_MESSAGE( message, expr, expName ) \
{ \
    ASSERT_EXCEPTION_MESSAGE_IMPL( SOURCELINE, Toolkit::Test::TestResultType::RT_FATAL, message, expr, expName ) \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_FATAL_EXCEPTION( expr, expName ) \
{ \
    ASSERT_EXCEPTION_MESSAGE_IMPL( SOURCELINE, Toolkit::Test::TestResultType::RT_FATAL, "", expr, expName ) \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_FATAL_NO_EXCEPTION_MESSAGE( message, expr ) \
{ \
    ASSERT_NO_EXCEPTION_MESSAGE_IMPL( SOURCELINE, Toolkit::Test::TestResultType::RT_FATAL, message, expr ) \
}
    
/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_FATAL_NO_EXCEPTION( expr ) \
{ \
    ASSERT_NO_EXCEPTION_MESSAGE_IMPL( SOURCELINE, Toolkit::Test::TestResultType::RT_FATAL, "", expr ) \
}

/*!
    \ingroup grp_Test
    \brief
*/
#define ASSERT_FATAL_FAIL( message ) \
{ \
    ASSERT_FAIL_IMPL( Toolkit::Test::TestResultType::RT_FATAL, message ); \
}
//@}

#endif

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
