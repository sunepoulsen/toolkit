//-------------------------------------------------------------------------
/*!
    \file abstractoperationtestcase.h
    \brief
*/

//-------------------------------------------------------------------------
#ifndef __TOOLKIT_TEST_SQL_ABSTRACTOPERATIONTESTCASE_H__
#define __TOOLKIT_TEST_SQL_ABSTRACTOPERATIONTESTCASE_H__

// Include Toolkit Test Files
#include <toolkit/test/testcase.h>

//-------------------------------------------------------------------------
/*!
    \brief Implements a test case to test the class Toolkit::Sql::AbstractOperation
*/
class AbstractOperationTestCase : public Toolkit::Test::TestCase {
    Q_OBJECT

public:
    //!\name Constructors & Destructor
    //@{
    AbstractOperationTestCase();
    virtual ~AbstractOperationTestCase();
    //@}

public slots:
    //!\name Constructors
    //@{
    void testConstructors();
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
