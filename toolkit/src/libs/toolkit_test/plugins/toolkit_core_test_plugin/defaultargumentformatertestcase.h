//-------------------------------------------------------------------------------------------------
/*!
    \file defaultargumentformatertestcase.h
    \brief
*/

//-------------------------------------------------------------------------------------------------
#ifndef __TOOLKIT_TEST_CORE_DEFAULTARGUMENTFORMATERTESTCASE_H__
#define __TOOLKIT_TEST_CORE_DEFAULTARGUMENTFORMATERTESTCASE_H__

// Include Toolkit Test Files
#include <toolkit/test/testcase.h>

//-------------------------------------------------------------------------------------------------
/*!
    \brief Implements a test case to test the class Toolkit::Core::DefaultArgumentFormater.
*/
class DefaultArgumentFormaterTestCase : public Toolkit::Test::TestCase {
    Q_OBJECT

public:
    //!\name Constructors & Destructor
    //@{
    DefaultArgumentFormaterTestCase();
    virtual ~DefaultArgumentFormaterTestCase();
    //@}

public slots:
    //!\name Constants
    //@{
    void testConstants();
    //@}

    //!\name Converters
    //@{
    void testChar();
    void testQChar();
    void testCString();
    void testStdString();
    void testQString();
    void testBool();
    void testDouble();
    void testFloat();
    void testInt();
    void testUInt();
    void testShort();
    void testUShort();
    void testQLongLong();
    void testQULongLong();
    void testQBitArray();
    void testQByteArray();
    void testQDate();
    void testQTime();
    void testQDateTime();
    //@}

    //!\name Helpers
    //@{
    void testFormatFloats();
    void testFormatIntegers();
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
