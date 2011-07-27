//---------------------------------------------------------------------------------------
/*!
    \file logdevice.h
    \brief
*/

//---------------------------------------------------------------------------------------
#ifndef __TOOLKIT_CORE_LOGDEVICE_H__
#define __TOOLKIT_CORE_LOGDEVICE_H__

// Include Toolkit Files
#include "defines.h"

// Include Qt Files
#include <QIODevice>
#include <QSharedPointer>

//---------------------------------------------------------------------------------------
namespace Toolkit {

    namespace Core {
        //---------------------------------------------------------------------------------------
        /*!
            \ingroup grp_Logs
            \brief Implements a log device.
        */
        class TOOLKIT_CORE_API LogDevice {
        public:
            typedef QSharedPointer<QIODevice> Pointer;

        public:
            //!\name Constructors & Destructor
            //@{
            LogDevice( QIODevice* device );
            LogDevice( const QString& fileName, QIODevice::OpenMode mode = QIODevice::WriteOnly );
            LogDevice( FILE* fh, QIODevice::OpenMode mode = QIODevice::WriteOnly );
            LogDevice( int fd, QIODevice::OpenMode mode = QIODevice::WriteOnly );
            LogDevice( const LogDevice& other );
            virtual ~LogDevice();
            //@}

            //!\name Properties
            //@{
            const Pointer& getPointer() const;
            Pointer& getPointer();
            void setPointer( const Pointer& newPointer );
            //@}

            //!\name Device
            //@{
            QIODevice& device();
            //@}

            //!\name Operators
            //@{
            LogDevice& operator=( const LogDevice& other );
            //@}

        private:
            Pointer m_Device;
        };
    };
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
