//-------------------------------------------------------------
/*!
    \file stringformat_imp.h
    \brief 
*/

//-------------------------------------------------------------

#ifndef __TOOLKIT_CORE_STRINGFORMAT_IMP_H__
#define __TOOLKIT_CORE_STRINGFORMAT_IMP_H__

//-------------------------------------------------------------
//      Implementation of template functions.
//-------------------------------------------------------------

//-------------------------------------------------------------
template< typename formaterType >
BasicStringFormat<formaterType>::BasicStringFormat( const formaterType& formater ) :
    AbstractFormat<formaterType>( QLocale::system(), formater ),
    m_Result()
{
};

template< typename formaterType >
BasicStringFormat<formaterType>::~BasicStringFormat() {
};

template< typename formaterType >
void BasicStringFormat<formaterType>::clear() {
    m_Result = "";
};

template< typename formaterType >
const QString& BasicStringFormat<formaterType>::lastResult() const {
    return m_Result;
};

template< typename formaterType >
template< typename T1 >
QString BasicStringFormat<formaterType>::format( const QString& format, T1 p1 ) {
    BasicStringFormat<formaterType> f;

    f.printf( format, p1 );
    return f.lastResult();
};

template< typename formaterType >
template< typename T1, typename T2 >
QString BasicStringFormat<formaterType>::format( const QString& format, T1 p1, T2 p2 ) {
    BasicStringFormat<formaterType> f;

    f.printf( format, p1, p2 );
    return f.lastResult();
};

template< typename formaterType >
template< typename T1, typename T2, typename T3 >
QString BasicStringFormat<formaterType>::format( const QString& format, T1 p1, T2 p2, T3 p3 ) {
    BasicStringFormat<formaterType> f;

    f.printf( format, p1, p2, p3 );
    return f.lastResult();
};

template< typename formaterType >
template< typename T1, typename T2, typename T3, typename T4 >
QString BasicStringFormat<formaterType>::format( const QString& format, T1 p1, T2 p2, T3 p3, T4 p4 ) {
    BasicStringFormat<formaterType> f;

    f.printf( format, p1, p2, p3, p4 );
    return f.lastResult();
};

template< typename formaterType >
template< typename T1, typename T2, typename T3, typename T4, typename T5 >
QString BasicStringFormat<formaterType>::format( const QString& format, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5 ) {
    BasicStringFormat<formaterType> f;

    f.printf( format, p1, p2, p3, p4, p5 );
    return f.lastResult();
};

template< typename formaterType >
template< typename T1, typename T2, typename T3, typename T4, typename T5,
            typename T6 >
QString BasicStringFormat<formaterType>::format( const QString& format, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5,
                                                        T6 p6 )
{
    BasicStringFormat<formaterType> f;

    f.printf( format, p1, p2, p3, p4, p5, p6 );
    return f.lastResult();
};                                                                

template< typename formaterType >
template< typename T1, typename T2, typename T3, typename T4, typename T5,
            typename T6, typename T7 >
QString BasicStringFormat<formaterType>::format( const QString& format, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5,
                                                        T6 p6, T7 p7 )
{
    BasicStringFormat<formaterType> f;

    f.printf( format, p1, p2, p3, p4, p5, p6, p7 );
    return f.lastResult();
};                                                                

template< typename formaterType >
template< typename T1, typename T2, typename T3, typename T4, typename T5,
            typename T6, typename T7, typename T8 >
QString BasicStringFormat<formaterType>::format( const QString& format, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5,
                                                        T6 p6, T7 p7, T8 p8 )
{
    BasicStringFormat<formaterType> f;

    f.printf( format, p1, p2, p3, p4, p5, p6, p7, p8 );
    return f.lastResult();
};                                                                

template< typename formaterType >
template< typename T1, typename T2, typename T3, typename T4, typename T5,
            typename T6, typename T7, typename T8, typename T9 >
QString BasicStringFormat<formaterType>::format( const QString& format, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5,
                                                        T6 p6, T7 p7, T8 p8, T9 p9 )
{
    BasicStringFormat<formaterType> f;

    f.printf( format, p1, p2, p3, p4, p5, p6, p7, p8, p9 );
    return f.lastResult();
};                                                                

template< typename formaterType >
template< typename T1, typename T2, typename T3, typename T4, typename T5,
            typename T6, typename T7, typename T8, typename T9, typename T10 >
QString BasicStringFormat<formaterType>::format( const QString& format, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5,
                                                        T6 p6, T7 p7, T8 p8, T9 p9, T10 p10 )
{
    BasicStringFormat<formaterType> f;

    f.printf( format, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10 );
    return f.lastResult();
};                                                                    

template< typename formaterType >
void BasicStringFormat<formaterType>::doWriteString( const QString& str ) {
    m_Result.append( str );
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
