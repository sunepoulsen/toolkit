//-------------------------------------------------------------------------------------------------
/*!
    \file replacecharconverter.h
    \brief
*/

//-------------------------------------------------------------------------------------------------
#ifndef __TOOLKIT_CORE_REPLACECHARCONVERTER_H__
#define __TOOLKIT_CORE_REPLACECHARCONVERTER_H__

// Include Toolkit Core Files
#include "defines.h"
#include "abstractcharconverter.h"

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
        class TOOLKIT_CORE_API ReplaceCharConverter : public AbstractCharConverter {
        public:
            //!\name Constructors & Destructor
            //@{
            ReplaceCharConverter();
            ReplaceCharConverter( const QChar& startChar, const QString& replaceValue );
            ReplaceCharConverter( const ReplaceCharConverter& other );
            virtual ~ReplaceCharConverter();
            //@}

            //!\name Properties
            //@{
            const QString& getReplaceValue() const;
            void setReplaceValue( const QString& newReplaceValue );
            //@}

            //!\name Operator
            //@{
            ReplaceCharConverter& operator=( const ReplaceCharConverter& other );
            //@}

        private:
            //!\name Checks
            //@{
            virtual bool doCanConvertFromUnicode( const QChar& ch ) const;
            virtual bool doCanConvertToUnicode( const QString& str, int pos ) const;
            //@}

            //!\name Converters
            //@{
            virtual QString doFromUnicode( const QChar& ch ) const;
            virtual QChar doToUnicode( const QString& str, int& pos ) const;
            //@}

        private:
            /*!
                \brief The string that m_StartChar should be replaced with in non-unicode.
            */
            QString m_ReplaceValue;
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
