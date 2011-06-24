//-------------------------------------------------------------
/*!
    \file deviceformat.h
    \brief 
*/

//-------------------------------------------------------------
#ifndef __TOOLKIT_CORE_DEVICEFORMAT_H__
#define __TOOLKIT_CORE_DEVICEFORMAT_H__

// Include Toolkit Core Files
#include "abstractformat.h"
#include "stringformat.h"

// Include QT Files
#include <QFile>
#include <QString>

//-------------------------------------------------------------
namespace Toolkit {
        
    namespace Core {
        //-------------------------------------------------------------
        /*!
            \ingroup grp_Formats
            \brief Format strings to be written to a IO device.
            
            \code
            QFile file;
            
            try {
                if( !file.open( stderr, QIODevice::WriteOnly ) )
                    return;
                    
                DeviceFormat formater( file );
                
                formater.printf( "QT version: %s", QT_VERSION_STR );
            }
            catch( FormatException& exp ) {
                // Error handling...
            };
            \endcode
            
            If \e file is not open or writable DeviceFormat will throw a FormatException.
        */
        template< typename formaterType >
        class TOOLKIT_CORE_API BasicDeviceFormat : public AbstractFormat<formaterType> {
        public:
            //!\name Constructors & Destructor
            //@{
            BasicDeviceFormat( QIODevice& device, const formaterType& formater = formaterType() );
            BasicDeviceFormat( const BasicDeviceFormat& other );
            virtual ~BasicDeviceFormat();
            //@}
            
            //!\name Properties
            //@{
            const QIODevice& getDevice() const;
            //@}            
            
            //!\name Write functions.
            //@{
            static void write( FILE* fh, const QString& format );
            
            template< typename T1 >
            static void write( FILE* fh, const QString& format, T1 p1 );
            
            template< typename T1, typename T2 >
            static void write( FILE* fh, const QString& format, T1 p1, T2 p2 );
            
            template< typename T1, typename T2, typename T3 >
            static void write( FILE* fh, const QString& format, T1 p1, T2 p2, T3 p3 );
            
            template< typename T1, typename T2, typename T3, typename T4 >
            static void write( FILE* fh, const QString& format, T1 p1, T2 p2, T3 p3, T4 p4 );
            
            template< typename T1, typename T2, typename T3, typename T4, typename T5 >
            static void write( FILE* fh, const QString& format, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5 );
            
            template< typename T1, typename T2, typename T3, typename T4, typename T5,
                      typename T6 >
            static void write( FILE* fh, const QString& format, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5,
                                                T6 p6 );
            
            template< typename T1, typename T2, typename T3, typename T4, typename T5,
                      typename T6, typename T7 >
            static void write( FILE* fh, const QString& format, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5,
                                                T6 p6, T7 p7 );
            
            template< typename T1, typename T2, typename T3, typename T4, typename T5,
                      typename T6, typename T7, typename T8 >
            static void write( FILE* fh, const QString& format, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5,
                                                T6 p6, T7 p7, T8 p8 );
            
            template< typename T1, typename T2, typename T3, typename T4, typename T5,
                      typename T6, typename T7, typename T8, typename T9 >
            static void write( FILE* fh, const QString& format, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5,
                                                T6 p6, T7 p7, T8 p8, T9 p9 );
            
            template< typename T1, typename T2, typename T3, typename T4, typename T5,
                      typename T6, typename T7, typename T8, typename T9, typename T10 >
            static void write( FILE* fh, const QString& format, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5,
                                                T6 p6, T7 p7, T8 p8, T9 p9, T10 p10 );        
            //@}
        
        private:
            //!\name Write functions
            //@{
            virtual void doWriteString( const QString& str );
            //@}
        
        private:
            QIODevice* m_Device;
        };
    
        //-------------------------------------------------------------
        // Include implementation file of template functions.
        #include "deviceformat_imp.h"

        //-------------------------------------------------------------
        /*!
            \brief Typedef for easier use of BasicDeviceFormat<T>
        */
        typedef BasicDeviceFormat<DefaultArgumentFormater> DeviceFormat;
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
