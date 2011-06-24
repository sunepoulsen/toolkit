//-------------------------------------------------------------------------------------------------
/*!
    \file formatparamtestcase.h
    \brief
*/

//-------------------------------------------------------------------------------------------------
#ifndef __TOOLKIT_TEST_CORE_FORMATPARAMTESTCASE_H__
#define __TOOLKIT_TEST_CORE_FORMATPARAMTESTCASE_H__

// Include Toolkit Test Files
#include <toolkit/test/testcase.h>

//-------------------------------------------------------------------------------------------------
/*!
    \brief Implements a test case to test the class Toolkit::Core::FormatParam
*/
class FormatParamTestCase : public Toolkit::Test::TestCase {
    Q_OBJECT

public:
    //!\name Constructors & Destructor
    //@{
    FormatParamTestCase();
    virtual ~FormatParamTestCase();
    //@}

public slots:
    //!\name Constants
    //@{
    void testRegExp();
    //@}

    //!\name Constructors
    //@{
    void testConstructor();
    void testRegExpConstructor();
    void testCopyConstructor();
    //@}

    //!\name Properties
    //@{
    void testProperties();
    //@}

    //!\name Converters
    //@{
    void testToString();
    void testFromString();
    //@}

    //!\name Operators
    //@{
    void testOpAssign();
    void testOpAssignString();
    //@}

private:
    //!\name Helpers
    //@{
    Toolkit::Core::FormatParam createParam( const QString& str );
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
