//-------------------------------------------------------------------------
/*!
    \file basicstringformattestcase.h
    \brief
*/

//-------------------------------------------------------------------------
#ifndef __TOOLKIT_TEST_CORE_BASICSTRINGFORMATTESTCASE_H__
#define __TOOLKIT_TEST_CORE_BASICSTRINGFORMATTESTCASE_H__

// Include Toolkit Test Files
#include <toolkit/test/testcase.h>

//-------------------------------------------------------------------------
/*!
    \brief Implements a test case to test the class Toolkit::Core::BasicStringFormat<T>
*/
class BasicStringFormatTestCase : public Toolkit::Test::TestCase {
    Q_OBJECT

public:
    //!\name Constructors & Destructor
    //@{
    BasicStringFormatTestCase();
    virtual ~BasicStringFormatTestCase();
    //@}

public slots:
    //!\name Constructors
    //@{
    void testConstructors();
    //@}

    //!\name Format
    //@{
    void testFormat01();
    void testFormat02();
    void testFormat03();
    void testFormat04();
    void testFormat05();
    void testFormat06();
    void testFormat07();
    void testFormat08();
    void testFormat09();
    void testFormat10();
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
