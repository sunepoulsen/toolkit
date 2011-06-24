//-------------------------------------------------------------------------
/*!
    \file qttestcase.h
    \brief
*/

//-------------------------------------------------------------------------
#ifndef __TOOLKIT_TEST_CORE_QTTESTCASE_H__
#define __TOOLKIT_TEST_CORE_QTTESTCASE_H__

// Include Toolkit Test Files
#include <toolkit/test/testcase.h>

//-------------------------------------------------------------------------
/*!
    \brief Implements a test case for some Qt isscues.

    This test case is not ment to actual test the Qt Library, we assume it works
    correctly. But we use it to check and detected different isscues about Qt.

    For instance does QDir::path() include a tailing slash "/" or not. Tests like
    that.
*/
class QtTestCase : public Toolkit::Test::TestCase {
    Q_OBJECT

public:
    //!\name Database driver constants
    //@{
    static const QString SQLITE_DRIVER_NAME;
    //@}

    //!\name Text codec constants
    //@{
    static const QString CODEC_LATIN1_NAME;
    static const QString CODEC_ISO88591_NAME;
    static const QString CODEC_UTF8_NAME;
    static const QString CODEC_UTF16_NAME;
    //@}

public:
    //!\name Constructors & Destructor
    //@{
    QtTestCase();
    virtual ~QtTestCase();
    //@}

public slots:
    //!\name QtCore
    //@{
    void testCodecNames();
    void testQDir();
    void testRegExpWildcards();
    void testQUrl();
    //@}

    //!\name QtSql
    //@{
    void testDatabaseDrivers();
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
