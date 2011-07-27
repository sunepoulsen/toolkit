//-------------------------------------------------------------
/*!
    \file stringformat.h
    \brief 
*/

//-------------------------------------------------------------
#ifndef __TOOLKIT_CORE_STRINGFORMAT_H__
#define __TOOLKIT_CORE_STRINGFORMAT_H__

// Include Toolkit Core Files
#include "abstractformat.h"
#include "defaultargumentformater.h"

//-------------------------------------------------------------
namespace Toolkit {
        
    namespace Core {       
        //-------------------------------------------------------------
        /*!
            \ingroup grp_Formats
            \brief Format strings into a retuned QString.
            
            \code
            QString s = StringFormat::format( "%1$Dt/%1$Mt-%1$Yt", QDate::curentDate() );
            
            // s = "11/06-2006";
            \endcode
        */
        template< typename formaterType >
        class TOOLKIT_CORE_API BasicStringFormat : public AbstractFormat<formaterType> {
        public:
            //!\name Constructors & Destructor
            //@{
            BasicStringFormat( const formaterType& formater = formaterType() );
            virtual ~BasicStringFormat();
            //@}
            
            //!\name Result functions
            //@{
            void clear();
            const QString& lastResult() const;
            //@}
                    
        public:
            //!\name Format functions
            //@{
            template< typename T1 >
            static QString format( const QString& format, T1 p1 );
            
            template< typename T1, typename T2 >
            static QString format( const QString& format, T1 p1, T2 p2 );
            
            template< typename T1, typename T2, typename T3 >
            static QString format( const QString& format, T1 p1, T2 p2, T3 p3 );
            
            template< typename T1, typename T2, typename T3, typename T4 >
            static QString format( const QString& format, T1 p1, T2 p2, T3 p3, T4 p4 );
            
            template< typename T1, typename T2, typename T3, typename T4, typename T5 >
            static QString format( const QString& format, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5 );
            
            template< typename T1, typename T2, typename T3, typename T4, typename T5,
                      typename T6 >
            static QString format( const QString& format, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5,
                                                          T6 p6 );
            
            template< typename T1, typename T2, typename T3, typename T4, typename T5,
                      typename T6, typename T7 >
            static QString format( const QString& format, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5,
                                                          T6 p6, T7 p7 );
            
            template< typename T1, typename T2, typename T3, typename T4, typename T5,
                      typename T6, typename T7, typename T8 >
            static QString format( const QString& format, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5,
                                                          T6 p6, T7 p7, T8 p8 );
            
            template< typename T1, typename T2, typename T3, typename T4, typename T5,
                      typename T6, typename T7, typename T8, typename T9 >
            static QString format( const QString& format, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5,
                                                          T6 p6, T7 p7, T8 p8, T9 p9 );
            
            template< typename T1, typename T2, typename T3, typename T4, typename T5,
                      typename T6, typename T7, typename T8, typename T9, typename T10 >
            static QString format( const QString& format, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5,
                                                          T6 p6, T7 p7, T8 p8, T9 p9, T10 p10 );
            //@}
        
        private:
            //!\name Write functions
            //@{
            virtual void doWriteString( const QString& str );
            //@}
            
        private:
            QString m_Result;
        };
        
        //-------------------------------------------------------------
        // Include implementation file of template functions.
        #include "stringformat_imp.h"

        //-------------------------------------------------------------
        /*!
            \brief Typedef for easier use of BasicStringFormat<T>
        */
        typedef BasicStringFormat<DefaultArgumentFormater> StringFormat;
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
