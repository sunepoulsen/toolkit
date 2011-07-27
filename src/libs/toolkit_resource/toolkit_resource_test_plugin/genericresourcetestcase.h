//-------------------------------------------------------------------------
/*!
    \file genericresourcetestcase.h
    \brief
*/

//-------------------------------------------------------------------------
#ifndef __TOOLKIT_RESOURCE_TEST_GENERICRESOURCETESTCASE_H__
#define __TOOLKIT_RESOURCE_TEST_GENERICRESOURCETESTCASE_H__

// Include Toolkit Test Files
#include <toolkit/test/testcase.h>

//-------------------------------------------------------------------------
/*!
    \brief Implements a test case to test the class Toolkit::Resource::GenericResource
*/
class GenericResourceTestCase : public Toolkit::Test::TestCase {
    Q_OBJECT

public:
    //!\name Constructors & Destructor
    //@{
    GenericResourceTestCase();
    virtual ~GenericResourceTestCase();
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
