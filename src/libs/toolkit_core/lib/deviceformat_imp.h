//-------------------------------------------------------------
/*!
  \file deviceformat_imp.h
  \brief 
*/

//-------------------------------------------------------------

#ifndef __TOOLKIT_CORE_DEVICEFORMAT_IMP_H__
#define __TOOLKIT_CORE_DEVICEFORMAT_IMP_H__

//-------------------------------------------------------------
//      Implementation of template functions.
//-------------------------------------------------------------

//-------------------------------------------------------------
template< typename formaterType >
BasicDeviceFormat<formaterType>::BasicDeviceFormat( QIODevice& device, const formaterType& formater ) :
    AbstractFormat<formaterType>( QLocale::system(), formater ),
    m_Device( &device )
{
};

template< typename formaterType >
BasicDeviceFormat<formaterType>::BasicDeviceFormat( const BasicDeviceFormat& other ) :
    AbstractFormat<formaterType>( other ),
    m_Device( other.m_Device )
{
};

template< typename formaterType >
BasicDeviceFormat<formaterType>::~BasicDeviceFormat() {
};

template< typename formaterType >
const QIODevice& BasicDeviceFormat<formaterType>::getDevice() const {
    return *m_Device;
};

template< typename formaterType >
void BasicDeviceFormat<formaterType>::write( FILE* fh, const QString& format ) {
    QFile file;

    if( file.open( fh, QIODevice::WriteOnly ) ) {
        BasicDeviceFormat<formaterType> formater( file );
        formater.printf( format );

        file.close();
    }
    else {
        throw FormatException( SOURCELINE, "Unable to open the std file *fh!" );
    };
};

template< typename formaterType >
template< typename T1 >
void BasicDeviceFormat<formaterType>::write( FILE* fh, const QString& format, T1 p1 ) {
    BasicDeviceFormat<formaterType>::write( fh, BasicStringFormat<formaterType>::format( format, p1 ) );
};

template< typename formaterType >
template< typename T1, typename T2 >
void BasicDeviceFormat<formaterType>::write( FILE* fh, const QString& format, T1 p1, T2 p2 ) {
    BasicDeviceFormat<formaterType>::write( fh, BasicStringFormat<formaterType>::format( format, p1, p2 ) );
};

template< typename formaterType >
template< typename T1, typename T2, typename T3 >
void BasicDeviceFormat<formaterType>::write( FILE* fh, const QString& format, T1 p1, T2 p2, T3 p3 ) {
    BasicDeviceFormat<formaterType>::write( fh, BasicStringFormat<formaterType>::format( format, p1, p2, p3 ) );
};

template< typename formaterType >
template< typename T1, typename T2, typename T3, typename T4 >
void BasicDeviceFormat<formaterType>::write( FILE* fh, const QString& format, T1 p1, T2 p2, T3 p3, T4 p4 ) {
    BasicDeviceFormat<formaterType>::write( fh, BasicStringFormat<formaterType>::format( format, p1, p2, p3, p4 ) );
};

template< typename formaterType >
template< typename T1, typename T2, typename T3, typename T4, typename T5 >
void BasicDeviceFormat<formaterType>::write( FILE* fh, const QString& format, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5 ) {
    BasicDeviceFormat<formaterType>::write( fh, BasicStringFormat<formaterType>::format( format, p1, p2, p3, p4, p5 ) );
};

template< typename formaterType >
template< typename T1, typename T2, typename T3, typename T4, typename T5,
          typename T6 >
void BasicDeviceFormat<formaterType>::write( FILE* fh, const QString& format, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5,
                                                           T6 p6 ) 
{
    BasicDeviceFormat<formaterType>::write( fh, BasicStringFormat<formaterType>::format( format, p1, p2, p3, p4, p5, p6 ) );
};

template< typename formaterType >
template< typename T1, typename T2, typename T3, typename T4, typename T5,
          typename T6, typename T7 >
void BasicDeviceFormat<formaterType>::write( FILE* fh, const QString& format, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5,
                                                           T6 p6, T7 p7 ) 
{
    BasicDeviceFormat<formaterType>::write( fh, BasicStringFormat<formaterType>::format( format, p1, p2, p3, p4, p5, p6, p7 ) );
};

template< typename formaterType >
template< typename T1, typename T2, typename T3, typename T4, typename T5,
          typename T6, typename T7, typename T8 >
void BasicDeviceFormat<formaterType>::write( FILE* fh, const QString& format, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5,
                                                           T6 p6, T7 p7, T8 p8 ) 
{
    BasicDeviceFormat<formaterType>::write( fh, BasicStringFormat<formaterType>::format( format, p1, p2, p3, p4, p5, p6, p7, p8 ) );
};

template< typename formaterType >
template< typename T1, typename T2, typename T3, typename T4, typename T5,
          typename T6, typename T7, typename T8, typename T9 >
void BasicDeviceFormat<formaterType>::write( FILE* fh, const QString& format, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5,
                                                           T6 p6, T7 p7, T8 p8, T9 p9 ) 
{
    BasicDeviceFormat<formaterType>::write( fh, BasicStringFormat<formaterType>::format( format, p1, p2, p3, p4, p5, p6, p7, p8, p9 ) );
};

template< typename formaterType >
template< typename T1, typename T2, typename T3, typename T4, typename T5,
          typename T6, typename T7, typename T8, typename T9, typename T10 >
void BasicDeviceFormat<formaterType>::write( FILE* fh, const QString& format, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5,
                                                           T6 p6, T7 p7, T8 p8, T9 p9, T10 p10 ) 
{
    BasicDeviceFormat<formaterType>::write( fh, BasicStringFormat<formaterType>::format( format, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10 ) );
};

template< typename formaterType >
void BasicDeviceFormat<formaterType>::doWriteString( const QString& str ) {
    if( !m_Device ) {
        throw FormatException( SOURCELINE, "Internal error. m_Device is not initialized!" );
    };

    if( m_Device->write( str.toLocal8Bit() ) < 0 ) {
        throw FormatException( SOURCELINE,
                               BasicStringFormat<formaterType>::format( "Error in writing to device:\n%s", m_Device->errorString() ) );
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
