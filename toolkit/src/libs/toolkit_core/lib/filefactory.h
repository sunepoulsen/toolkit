//-------------------------------------------------------------------------------------------------
/*!
    \file filefactory.h
    \brief
*/

//-------------------------------------------------------------------------------------------------
#ifndef __TOOLKIT_CORE_FILEFACTORY_H__
#define __TOOLKIT_CORE_FILEFACTORY_H__

// Include Qt Files
#include <QByteArray>
#include <QIODevice>

//-------------------------------------------------------------------------------------------------
namespace Toolkit {

    namespace Core {
        //-------------------------------------------------------------------------------------------------
        /*!
            \brief Implements a factory for useful operations on files, that QFile does not support.
        */
        class FileFactory {
        public:
            //!\name Constructors & Destructor
            //@{
            FileFactory();
            FileFactory( const FileFactory& other );
            virtual ~FileFactory();
            //@}

            //!\name Operators
            //@{
            FileFactory& operator=( const FileFactory& other );
            //@}

        public:
            //!\name Static interface
            //@{
            static QByteArray readFile( const QString& fileName, QIODevice::OpenMode openMode = QIODevice::ReadOnly );
            static bool writeFile( const QString& fileName, const QByteArray& bytes, QIODevice::OpenMode openMode = QIODevice::WriteOnly );
            //@}
        };

    };

};

#endif
