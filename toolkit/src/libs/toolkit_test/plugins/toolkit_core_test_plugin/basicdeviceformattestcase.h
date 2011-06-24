//-------------------------------------------------------------------------
/*!
    \file basicdeviceformattestcase.h
    \brief
*/

//-------------------------------------------------------------------------
#ifndef __TOOLKIT_TEST_CORE_BASICDEVICEFORMATTESTCASE_H__
#define __TOOLKIT_TEST_CORE_BASICDEVICEFORMATTESTCASE_H__

// Include Toolkit Test Files
#include <toolkit/test/testcase.h>

// Include Toolkit Core Files
#include <toolkit/core/deviceformat.h>

// Include Qt Files
#include <QBuffer>
#include <QByteArray>

//-------------------------------------------------------------------------
/*!
    \brief Implements a test case to test the class Toolkit::Core::BasicDeviceFormat<T>
*/
class BasicDeviceFormatTestCase : public Toolkit::Test::TestCase {
    Q_OBJECT

public:
    //!\name Constructors & Destructor
    //@{
    BasicDeviceFormatTestCase();
    virtual ~BasicDeviceFormatTestCase();
    //@}

public slots:
    //!\name Constructors
    //@{
    void testConstructors();
    //@}

    //!\name Methods
    //@{
    void testWriteString();
    //@}

private:
    //!\name Helpers
    //@{
    Toolkit::Core::DeviceFormat createFormater();
    QByteArray readBuffer();
    //@}

private:
    QByteArray m_DeviceData;
    QBuffer m_Device;
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
