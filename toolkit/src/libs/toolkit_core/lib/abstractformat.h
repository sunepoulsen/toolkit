//-------------------------------------------------------------
/*!
  \file abstractformat.h
  \brief 
*/

//-------------------------------------------------------------
#ifndef __TOOLKIT_CORE_ABSTRACTFORMAT_H__
#define __TOOLKIT_CORE_ABSTRACTFORMAT_H__

// Include Toolkit Core Files
#include "formatparam.h"

// Include QT Files
#include <QLocale>
#include <QString>

//-------------------------------------------------------------
namespace Toolkit {
        
    namespace Core {
        //-------------------------------------------------------------
        /*!
            \ingroup grp_Formats
            \brief Abstract formater class that hows how to parse and execute format arguments.

            \param formaterType A class with format methods to format a parsed argument from a
                                format string.
        */
        template< typename formaterType >
        class TOOLKIT_CORE_API AbstractFormat {
        public:
            //!\name Constructors & Destructor
            //@{
            AbstractFormat( const QLocale& locale = QLocale::system(), const formaterType& formater = formaterType() );
            AbstractFormat( const AbstractFormat& other );
            virtual ~AbstractFormat();
            //@}
            
            //!\name Write functions
            //@{
            void writeString( const QString& str );
            //@}
            
            //!\name Parse functions
            //@{
            void printf( const QString& str );

            template< typename T1 >
            void printf( const QString& format, T1 p1 );
            
            template< typename T1, typename T2 >
            void printf( const QString& format, T1 p1, T2 p2 );
            
            template< typename T1, typename T2, typename T3 >
            void printf( const QString& format, T1 p1, T2 p2, T3 p3 );
            
            template< typename T1, typename T2, typename T3, typename T4 >
            void printf( const QString& format, T1 p1, T2 p2, T3 p3, T4 p4 );
            
            template< typename T1, typename T2, typename T3, typename T4, typename T5 >
            void printf( const QString& format, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5 );
            
            template< typename T1, typename T2, typename T3, typename T4, typename T5,
                      typename T6 >
            void printf( const QString& format, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5,
                                               T6 p6 );
            
            template< typename T1, typename T2, typename T3, typename T4, typename T5,
                      typename T6, typename T7 >
            void printf( const QString& format, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5,
                                               T6 p6, T7 p7 );
            
            template< typename T1, typename T2, typename T3, typename T4, typename T5,
                      typename T6, typename T7, typename T8 >
            void printf( const QString& format, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5,
                                               T6 p6, T7 p7, T8 p8 );
            
            template< typename T1, typename T2, typename T3, typename T4, typename T5,
                      typename T6, typename T7, typename T8, typename T9 >
            void printf( const QString& format, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5,
                                               T6 p6, T7 p7, T8 p8, T9 p9 );
            
            template< typename T1, typename T2, typename T3, typename T4, typename T5,
                      typename T6, typename T7, typename T8, typename T9, typename T10 >
            void printf( const QString& format, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5,
                                               T6 p6, T7 p7, T8 p8, T9 p9, T10 p10 );
            //@}
        
        private:
            //!\name Write functions
            //@{
            virtual void doWriteString( const QString& str ) = 0;
            //@}

        private:
            //!\name Properties
            //@{
            QLocale m_Locale;
            formaterType m_Formater;
            //@}
        };
        
        //-------------------------------------------------------------
        // Include implementation file of template functions.
        #include "abstractformat_imp.h"
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
