//-------------------------------------------------------------------------------------------------
/*!
    \file abstracttextconverter.h
    \brief 
*/

//-------------------------------------------------------------------------------------------------
#ifndef __TOOLKIT_CORE_ABSTRACTTEXTCONVERTER_H__
#define __TOOLKIT_CORE_ABSTRACTTEXTCONVERTER_H__

// Include Toolkit Files
#include "defines.h"

// Include Qt Files
#include <QTextCodec>

//-------------------------------------------------------------------------------------------------
namespace Toolkit {
    
    namespace Core {           
        //---------------------------------------------------------------------------------------------
        /*!
            \ingroup grp_TextConverters
            \brief
        */
        class TOOLKIT_CORE_API AbstractTextConverter {
        public:
            //!\name Constructors & Destructor
            //@{
            AbstractTextConverter();
            AbstractTextConverter( const AbstractTextConverter& other );
            virtual ~AbstractTextConverter();
            //@}
            
            //!\name Class
            //@{
            AbstractTextConverter* clone() const;
            const QString& name() const;
            //@}
            
            //!\name Converter interface
            //@{
            QString fromUnicode( const QString& str ) const;
            QString fromUnicode( const QChar* str, int len ) const;
            QString toUnicode( const QString& str ) const;
            QString toUnicode( const QChar* str, int len ) const;
            //@}
            
            //!\name Operator
            //@{
            AbstractTextConverter& operator=( const AbstractTextConverter& other );
            //@}
            
        private:
            //!\name Class
            //@{
            virtual AbstractTextConverter* doClone() const = 0;
            virtual const QString& doName() const = 0;
            //@}
            
            //!\name Converter interface
            //@{
            virtual QString doFromUnicode( const QChar* str, int len ) const;
            virtual QString doToUnicode( const QChar* str, int len ) const;
            //@}
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
