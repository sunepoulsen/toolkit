//-------------------------------------------------------------
/*!
    \file formatparam.h
    \brief 
*/

//-------------------------------------------------------------
#ifndef __TOOLKIT_CORE_FORMATPARAM_H__
#define __TOOLKIT_CORE_FORMATPARAM_H__

// Include Toolkit Core Files
#include "defines.h"

// Include QT Files
#include <QDateTime>
#include <QIODevice>
#include <QLocale>
#include <QRegExp>
#include <QString>

//-------------------------------------------------------------
namespace Toolkit {
        
    namespace Core {
        //-------------------------------------------------------------
        /*!
            \ingroup grp_Formats
            \brief Implements a format parameter.
            
            \par Parameter format
            \code
            %[ArgumentIndex$][Flags][[-]Width][.Precision]]{Conversion}
            \endcode
        */
        class TOOLKIT_CORE_API FormatParam {
        public:
            static const QString PARAM_PATTERN;
            static const QString PARAM_PREFIX_CHAR;
            static const QString PARAM_PREFIX_ESCAPE;
            static const int PARAM_PATTERN_ARGINDEX_TEST_CAP;
            static const int PARAM_PATTERN_ARGINDEX_CAP;
            static const int PARAM_PATTERN_FLAGS_TEST_CAP;
            static const int PARAM_PATTERN_FLAGS_CAP;
            static const int PARAM_PATTERN_WIDTH_TEST_CAP;
            static const int PARAM_PATTERN_WIDTH_CAP;
            static const int PARAM_PATTERN_PRECISION_TEST_CAP;
            static const int PARAM_PATTERN_PRECISION_CAP;
            static const int PARAM_PATTERN_CONVERSION_TEST_CAP;
            static const int PARAM_PATTERN_CONVERSION_CAP;

        public:
            //!\name Constructors & Destructor
            //@{
            FormatParam( const QString& str = "" );
            FormatParam( QRegExp& rx );
            FormatParam( const FormatParam& other );
            virtual ~FormatParam();
            //@}
            
            //!\name Properties
            //@{
            int getArgIndex() const;
            void setArgIndex( int newArgIndex );
            const QString& getFlags() const;
            void setFlags( const QString& newFlags );
            int getWidth() const;
            void setWidth( int newWidth );
            int getPrecision() const;
            void setPrecision( int newPrecision );
            const QChar& getConversion() const;
            void setConversion( const QChar& newConversion );
            //@}

            //!\name Checks
            //@{
            bool hasArgIndex() const;
            bool hasFlag( const QChar& flag ) const;
            bool hasFlags() const;
            bool hasWidth() const;
            bool hasPrecision() const;
            bool hasConversion( const QChar& conv ) const;
            //@}

            //!\name Converters
            //@{
            QString toString() const;
            bool fromString( const QString& str );
            //@}

            //!\name Operators
            //@{
            FormatParam& operator=( const FormatParam& other );
            FormatParam& operator=( const QString& str );
            //@}

        private:
            //!\name Helpers
            //@{
            void clear();
            bool extract( const QRegExp& rx );
            //@}
            
        private:
            int m_ArgIndex;
            QString m_Flags;
            int m_Width;
            int m_Precision;
            QChar m_Conversion;
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
