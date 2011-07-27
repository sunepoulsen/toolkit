//-------------------------------------------------------------------------
/*!
    \file basictestcase.h
    \brief
*/

//-------------------------------------------------------------------------
#ifndef __TOOLKIT_TEST_TEST_BASISTESTCASE_H__
#define __TOOLKIT_TEST_TEST_BASISTESTCASE_H__

// Include Toolkit Test Files
#include <toolkit/test/testcase.h>

//-------------------------------------------------------------------------
/*!
    \brief Implements some basis tests of the test system.
    
    This test case is not intended to prove that the test system works,
    but only to be used in the development process.

    Run this test case and check to log file, to see if the methods is
    called in the right order and with the right results.
*/
class BasicTestCase : public Toolkit::Test::TestCase {
    Q_OBJECT

public:
    //!\name Constructors & Destructor
    //@{
    BasicTestCase();
    virtual ~BasicTestCase();
    //@}
    
public slots:
    //!\name Equal asserts
    //@{
    void testAssertEqualImplChars();
    void testAssertEqualImplStrings();
    void testAssertEqualImplBools();
    void testAssertEqualImplInts();
    void testAssertEqualImplArrays();
    void testAssertEqualImplDateTimes();
    //@}

    //!\name Not equal asserts
    //@{
    void testAssertNotEqualImplChars();
    void testAssertNotEqualImplStrings();
    void testAssertNotEqualImplBools();
    void testAssertNotEqualImplInts();
    void testAssertNotEqualImplArrays();
    void testAssertNotEqualImplDateTimes();
    //@}
    
    //!\name Boolean asserts
    //@{
    void testAssertTrue();
    void testAssertFalse();
    //@}
    
    //!\name Assert types
    //@{
    void testAssertFail();
    void testAssertRequired();
    void testAssertCriticals();
    void testAssertFatal();
    //@}
};

//-------------------------------------------------------------------------
/*!
    \brief Implements tests to test the ASSERT_XXXX macros.
    
    
*/
class MacroTestCase : public Toolkit::Test::TestCase {
    Q_OBJECT

public:
    //!\name Constructors & Destructor
    //@{
    MacroTestCase();
    virtual ~MacroTestCase();
    //@}
    
public slots:
    //!\name Macro asserts
    //@{
    void testAssertFailureMacros();
    //@}
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
