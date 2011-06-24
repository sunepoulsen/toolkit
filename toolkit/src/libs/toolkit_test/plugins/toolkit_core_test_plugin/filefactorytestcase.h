//-------------------------------------------------------------------------
/*!
    \file filefactorytestcase.h
    \brief
*/

//-------------------------------------------------------------------------
#ifndef __TOOLKIT_TEST_CORE_FILEFACTORYTESTCASE_H__
#define __TOOLKIT_TEST_CORE_FILEFACTORYTESTCASE_H__

// Include Toolkit Test Files
#include <toolkit/test/testcase.h>

//-------------------------------------------------------------------------
/*!
    \brief Implements a test case to test the class Toolkit::Core::FileFactory
*/
class FileFactoryTestCase : public Toolkit::Test::TestCase {
    Q_OBJECT

public:
    //!\name Constructors & Destructor
    //@{
    FileFactoryTestCase();
    virtual ~FileFactoryTestCase();
    //@}

public slots:
    //!\name Static members
    //@{
    void testReadFile();
    void testWriteFile();
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
