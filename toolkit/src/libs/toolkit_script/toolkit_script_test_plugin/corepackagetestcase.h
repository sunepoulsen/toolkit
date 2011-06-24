//-------------------------------------------------------------------------
/*!
    \file corepackagetestcase.h
    \brief
*/

//-------------------------------------------------------------------------
#ifndef __TOOLKIT_SCRIPT_TEST_COREPACKAGETESTCASE_H__
#define __TOOLKIT_SCRIPT_TEST_COREPACKAGETESTCASE_H__

// Include Toolkit Test Files
#include <toolkit/test/testcase.h>

//-------------------------------------------------------------------------
/*!
    \brief Implements a test case to test the class Toolkit::Script::CorePackage
*/
class CorePackageTestCase : public Toolkit::Test::TestCase {
    Q_OBJECT

public:
    //!\name Constructors & Destructor
    //@{
    CorePackageTestCase();
    virtual ~CorePackageTestCase();
    //@}

public slots:
    //!\name Qt
    //@{
    void testQUrl();
    //@}

    //!\name Constructors
    //@{
    void testConstructors();
    //@}

    //!\name Check packages
    //@{
    void testCheckPackage();
    void testCheckPackageSchemaName();
    void testCheckPackageNameSpace();
    //@}

    //!\name Extract packages
    //@{
    void testExtractPackages();
    void testExtractPackagesSchemaName();
    void testExtractPackagesNameSpace();
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
