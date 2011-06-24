//---------------------------------------------------------------------------------------
/*!
    \file logdevice.cpp
    \brief
*/

//---------------------------------------------------------------------------------------

// Include Header File
#include "logdevice.h"

// Include Toolkit Core Files
#include "exception.h"

// Include Qt Files
#include <QFile>

//---------------------------------------------------------------------------------------
using namespace Toolkit::Core;

//---------------------------------------------------------------------------------------
LogDevice::LogDevice( QIODevice* device ) :
    m_Device( device )
{
    if( m_Device ) {
        m_Device->open( QIODevice::WriteOnly );
    };
};

LogDevice::LogDevice( const QString& fileName, QIODevice::OpenMode mode ) :
    m_Device( new QFile( fileName ) )
{
    if( mode != QIODevice::NotOpen ) {
        m_Device->open( mode );
    };
};

LogDevice::LogDevice( FILE* fh, QIODevice::OpenMode mode ) :
    m_Device( new QFile() )
{
    m_Device.dynamicCast<QFile>()->open( fh, mode );
};

LogDevice::LogDevice( int fd, QIODevice::OpenMode mode ) :
    m_Device( new QFile() )
{
    m_Device.dynamicCast<QFile>()->open( fd, mode );
};

LogDevice::LogDevice( const LogDevice& other ) :
    m_Device( other.m_Device )
{
};

LogDevice::~LogDevice() {
};

const LogDevice::Pointer& LogDevice::getPointer() const {
    return m_Device;
};

LogDevice::Pointer& LogDevice::getPointer() {
    return m_Device;
};

void LogDevice::setPointer( const Pointer& newPointer ) {
    m_Device = newPointer;
};

QIODevice& LogDevice::device() {
    if( m_Device ) {
        return *m_Device;
    };

    throw Exception( SOURCELINE, "LogDevice is not allocated." );
};

LogDevice& LogDevice::operator=( const LogDevice& other ) {
    m_Device = other.m_Device;

    return *this;
};

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
