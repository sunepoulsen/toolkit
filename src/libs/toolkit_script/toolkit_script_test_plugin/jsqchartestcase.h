//-------------------------------------------------------------------------
/*!
    \file jsqchartestcase.h
    \brief
*/

//-------------------------------------------------------------------------
#ifndef __TOOLKIT_SCRIPT_TEST_JSQCHARTESTCASE_H__
#define __TOOLKIT_SCRIPT_TEST_JSQCHARTESTCASE_H__

// Include Toolkit Test Files
#include <toolkit/test/testcase.h>

//-------------------------------------------------------------------------
/*!
    \brief Implements a test case to test the class Toolkit::Script::CorePackage
*/
class JSQCharTestCase : public Toolkit::Test::TestCase {
    Q_OBJECT

public:
    //!\name Constructors & Destructor
    //@{
    JSQCharTestCase();
    virtual ~JSQCharTestCase();
    //@}

public slots:
    //!\name Script properties
    //@{
    void testCategoryScriptProperties();
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
