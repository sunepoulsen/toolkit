//-------------------------------------------------------------------------
/*!
    \file basicdeviceformattestcase.cpp
    \brief
*/

//-------------------------------------------------------------------------

// Include Header File
#include "basicdeviceformattestcase.h"

// Include Toolkit Core Files
#include <toolkit/core/deviceformat.h>

//-------------------------------------------------------------------------
using namespace Toolkit::Core;
using namespace Toolkit::Test;

//-------------------------------------------------------------------------
BasicDeviceFormatTestCase::BasicDeviceFormatTestCase() :
    TestCase(),
    m_DeviceData(),
    m_Device( &m_DeviceData )
{
    m_Device.open( QIODevice::ReadWrite );
};

BasicDeviceFormatTestCase::~BasicDeviceFormatTestCase() {
    m_Device.close();
};

void BasicDeviceFormatTestCase::testConstructors() {
};

void BasicDeviceFormatTestCase::testWriteString() {
    DeviceFormat f = createFormater();

    f.writeString( "" );
    ASSERT_EQUAL( readBuffer(), "" );
    f.writeString( "Test" );
    ASSERT_EQUAL( readBuffer(), "Test" );
    f.writeString( "\n" );
    ASSERT_EQUAL( readBuffer(), "\n" );
    f.writeString( "Petersen" );
    ASSERT_EQUAL( readBuffer(), "Petersen" );

    m_Device.close();    
    ASSERT_EXCEPTION( f.writeString( "Tekst til lukket device!" ), FormatException );
    m_Device.open( QIODevice::ReadOnly );
    ASSERT_EXCEPTION( f.writeString( "Tekst til ReadOnly device!" ), FormatException );
    m_Device.close();
    m_Device.open( QIODevice::ReadWrite );
};

DeviceFormat BasicDeviceFormatTestCase::createFormater() {
    return DeviceFormat( m_Device );
};

/*!
    \brief Returns and clears the contents of the used QIODevice.

    \post
        The device is now empty.
*/
QByteArray BasicDeviceFormatTestCase::readBuffer() {
    if( !m_Device.isOpen() ) {
        return QByteArray();
    };

    QByteArray ba = m_Device.data();

    // We have to close and reopen the device because QBuffer::setData has no effect on an open buffer.
    QIODevice::OpenMode mode = m_Device.openMode();
    m_Device.close();
    m_Device.setData( QByteArray( "" ) );
    m_Device.open( mode );

    return ba;
};

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
