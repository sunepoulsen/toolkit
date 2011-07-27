//-------------------------------------------------------------------------------------------------
/*!
    \file abstractcharconverter.h
    \brief
*/

//-------------------------------------------------------------------------------------------------
#ifndef __TOOLKIT_CORE_ABSTRACTCHARCONVERTER_H__
#define __TOOLKIT_CORE_ABSTRACTCHARCONVERTER_H__

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
        class TOOLKIT_CORE_API AbstractCharConverter {
        public:
            //!\name Constructors & Destructor
            //@{
            AbstractCharConverter();
            AbstractCharConverter( const QChar& startChar );
            AbstractCharConverter( const AbstractCharConverter& other );
            virtual ~AbstractCharConverter();
            //@}

            //!\name Properties
            //@{
            const QChar& getStartChar() const;
            void setStartChar( const QChar& newChar );
            //@}

            //!\name Checks
            //@{
            bool canConvertFromUnicode( const QChar& ch ) const;
            bool canConvertToUnicode( const QString& str, int pos ) const;
            //@}

            //!\name Converters
            //@{
            QString fromUnicode( const QChar& ch ) const;
            QChar toUnicode( const QString& str, int& pos ) const;
            //@}

            //!\name Operator
            //@{
            AbstractCharConverter& operator=( const AbstractCharConverter& other );
            //@}

        private:
            //!\name Checks
            //@{
            /*!
                \brief Checks if \e ch can be converted using this char converter.

                An AbstractTextConverter uses this check to find a soutable char converter to convert \e ch.

                \param ch The ch to check for.

                \retval true  The char can be converted.
                \retval false The char can not be converted.
            */
            virtual bool doCanConvertFromUnicode( const QChar& ch ) const = 0;

            /*!
                \brief Checks if some begining of \e str from position \e pos, can be converted using this
                       char converter.

                An AbstractTextConverter uses this check to find a soutable char converter to convert \e str.

                \param str The string to check for.
                \param pos The position in \e str to start the check for.

                \retval true  The string can be converted.
                \retval false The string can not be converted.
            */
            virtual bool doCanConvertToUnicode( const QString& str, int pos ) const = 0;
            //@}

            //!\name Converters
            //@{
            virtual QString doFromUnicode( const QChar& ch ) const;
            virtual QChar doToUnicode( const QString& str, int& pos ) const;
            //@}

        private:
            //!\name Properties
            //@{
            /*!
                \brief The first unicode char this char converter can convert.

                An AbstractTextConverter uses this member to find a soutable char converter to
                convert a \e QChar.

                \note
                    Changeing this member may require an AbstractTextConverter to resort its AbstractCharConverter's,
                    if it contains them in a container for binary lookup.
            */
            QChar m_StartChar;
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
