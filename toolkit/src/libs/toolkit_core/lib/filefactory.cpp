//-------------------------------------------------------------------------------------------------
/*!
    \file filefactory.h
    \brief
*/

//-------------------------------------------------------------------------------------------------

// Include Header File
#include "filefactory.h"

// Include Toolkit Core Files
#include "noimpexception.h"

// Include Qt Files
#include <QFile>

//-------------------------------------------------------------------------------------------------
using namespace Toolkit::Core;

//-------------------------------------------------------------------------------------------------
/*!
    \brief Default empty constructor.
*/
FileFactory::FileFactory() {
}

/*!
    \brief Default empty copy constructor.
*/
FileFactory::FileFactory( const FileFactory& ) {
}

/*!
    \brief Default empty destructor.
*/
FileFactory::~FileFactory() {
}

/*!
    \brief Default empty assignment.
*/
FileFactory& FileFactory::operator=( const FileFactory& ) {
    return *this;
}

//-------------------------------------------------------------------------------------------------
QByteArray FileFactory::readFile( const QString& fileName, QIODevice::OpenMode openMode ) {
    QByteArray bytes;
    QFile file( fileName );

    if( file.open( openMode ) ) {
        bytes = file.readAll();
        file.close();
    }

    return bytes;
}

bool FileFactory::writeFile( const QString& fileName, const QByteArray& bytes, QIODevice::OpenMode openMode ) {
    QFile file( fileName );

    if( file.open( openMode ) ) {
        file.write( bytes );
        file.close();

        return true;
    }

    return false;
}
