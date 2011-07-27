//-------------------------------------------------------------------------
/*!
    \file sourcelinetestcase.h
    \brief
*/

//-------------------------------------------------------------------------
#ifndef __TOOLKIT_TEST_CORE_SOURCELINETESTCASE_H__
#define __TOOLKIT_TEST_CORE_SOURCELINETESTCASE_H__

// Include Toolkit Test Files
#include <toolkit/test/testcase.h>

//-------------------------------------------------------------------------
/*!
    \brief Implements a test case to test the class Toolkit::Core::SourceLine
*/
class SourceLineTestCase : public Toolkit::Test::TestCase {
    Q_OBJECT
    
public:
    //!\name Constructors & Destructor
    //@{
    SourceLineTestCase();
    virtual ~SourceLineTestCase();
    //@}
    
public slots:
    //!\name Constructors
    //@{
    void testConstructors();
    void testMacro();
    //@}

    //!\name Properties
    //@{
    void testFileName();
    void testLineNumber();
    //@}

    //!\name Operators
    //@{
    void testOpAssign();
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
