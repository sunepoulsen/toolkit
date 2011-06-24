//-------------------------------------------------------------------------
/*!
    \file environmenttestcase.h
    \brief
*/

//-------------------------------------------------------------------------
#ifndef __TOOLKIT_SCRIPT_TEST_ENVIRONMENTTESTCASE_H__
#define __TOOLKIT_SCRIPT_TEST_ENVIRONMENTTESTCASE_H__

// Include Toolkit Test Files
#include <toolkit/test/testcase.h>

//-------------------------------------------------------------------------
/*!
    \brief Implements a test case to test the class Toolkit::Script::Environment
*/
class EnvironmentTestCase : public Toolkit::Test::TestCase {
    Q_OBJECT

public:
    //!\name Constructors & Destructor
    //@{
    EnvironmentTestCase();
    virtual ~EnvironmentTestCase();
    //@}

public slots:
    //!\name Constructors
    //@{
    void testConstructors();
    //@}

    //!\name Evaluations
    //@{
    void testEvaluateExpr();
    void testEvaluateCallScriptFunction();
    //@}

    //!\name Registrations
    //@{
    void testEvaluateCallRegFunction();
    void testEvaluateCallRegObject();
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
