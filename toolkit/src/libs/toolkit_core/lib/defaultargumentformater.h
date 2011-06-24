//-------------------------------------------------------------------------------------------------
/*!
    \file defaultargumentformater.h
    \brief
*/

//-------------------------------------------------------------------------------------------------
#ifndef __TOOLKIT_CORE_DEFAULTARGUMENTFORMATER_H__
#define __TOOLKIT_CORE_DEFAULTARGUMENTFORMATER_H__

// Include Toolkit Core Files
#include "defines.h"
#include "formatparam.h"
#include "formatexception.h"

// Include Qt Files
#include <QBitArray>
#include <QDateTime>
#include <QLocale>

//-------------------------------------------------------------------------------------------------
namespace Toolkit {

    namespace Core {
        //---------------------------------------------------------------------------------------------
        /*!
            \ingroup grp_Formats
            \brief
        */
        class TOOLKIT_CORE_API DefaultArgumentFormater {
        public:
            //!\name Convertion constants
            //@{
            static const QChar CONV_STRING;
            static const QChar CONV_BOOL;
            static const QChar CONV_INT;
            static const QChar CONV_DECIMAL;
            static const QChar CONV_HEX;
            static const QChar CONV_OCTAL;
            static const QChar CONV_DOUBLE;
            static const QChar CONV_FLOAT;
            static const QChar CONV_EXP;
            static const QChar CONV_DATETIME;

            static const QString QCHAR_CONVS;
            static const QString QSTRING_CONVS;
            static const QString BOOL_CONVS;
            static const QString DOUBLE_CONVS;
            static const QString DATETIME_CONVS;
            //@}

            //!\name Flags constants
            //@{
            static const QChar FLAG_DEBUG;
            static const QChar FLAG_FILL_ZEROS;
            static const QChar FLAG_GROUP_SEP;
            static const QChar FLAG_LOWERCASE;
            static const QChar FLAG_PARENTES;
            static const QChar FLAG_TRUNCATE;
            static const QChar FLAG_UPPERCASE;
            //@}

            //!\name Value constants
            //@{
            static const QString NULL_VALUE;
            static const QString EMPTY_VALUE;
            static const QString TRUE_VALUE;
            static const QString FALSE_VALUE;
            static const QString TRUE_NAME_VALUE;
            static const QString FALSE_NAME_VALUE;
            static const QString DATE_FORMAT;
            static const QString TIME_FORMAT;
            static const QString DATETIME_FORMAT;
            //@}

        public:
            //!\name Constructors & Destructor
            //@{
            DefaultArgumentFormater();
            virtual ~DefaultArgumentFormater();
            //@}

            //!\name Strings
            //@{
            QString format( const QLocale& locale, const FormatParam& param, const char ch ) const;
            QString format( const QLocale& locale, const FormatParam& param, const QChar& ch ) const;
            QString format( const QLocale& locale, const FormatParam& param, const char* str ) const;
            QString format( const QLocale& locale, const FormatParam& param, const std::string& str ) const;
            QString format( const QLocale& locale, const FormatParam& param, const QString& str ) const;
            //@}

            //!\name
            //@{
            QString format( const QLocale& locale, const FormatParam& param, bool b ) const;
            //@}

            //!\name Floats
            //@{
            QString format( const QLocale& locale, const FormatParam& param, double d ) const;
            QString format( const QLocale& locale, const FormatParam& param, float d ) const;
            //@}

            //!\name Integers
            //@{
            QString format( const QLocale& locale, const FormatParam& param, int i ) const;
            QString format( const QLocale& locale, const FormatParam& param, uint i ) const;
            QString format( const QLocale& locale, const FormatParam& param, long i ) const;
            QString format( const QLocale& locale, const FormatParam& param, ulong i ) const;
            QString format( const QLocale& locale, const FormatParam& param, short i ) const;
            QString format( const QLocale& locale, const FormatParam& param, ushort i ) const;
            QString format( const QLocale& locale, const FormatParam& param, qlonglong i ) const;
            QString format( const QLocale& locale, const FormatParam& param, qulonglong i ) const;
            //@}

            //!\name Arrays
            //@{
            QString format( const QLocale& locale, const FormatParam& param, const QBitArray& ba ) const;
            QString format( const QLocale& locale, const FormatParam& param, const QByteArray& ba ) const;
            //@}

            //!\name Date & Times
            //@{
            QString format( const QLocale& locale, const FormatParam& param, const QDate& date ) const;
            QString format( const QLocale& locale, const FormatParam& param, const QTime& time ) const;
            QString format( const QLocale& locale, const FormatParam& param, const QDateTime& dateTime ) const;
            //@}

            //!\name Format helpers
            //@{
            bool checkConversion( const QString& convs, const QChar& conv ) const;
            QString justifyCases( const FormatParam& param, const QString& str ) const;
            QString justifyWidth( const QLocale& locale, const FormatParam& param, const QString& str ) const;

            /*!
                \brief Formats a double based on the format parameter \e param.

                \par Supported Conversions
                <dl>
                    <dt>f</dt>
                    <dd>
                        Formats the double as [-]9.9
                        <p/>
                        <b>Flags:</b> \e g, \e p and \e t
                    </dd>

                    <dt>e</dt>
                    <dd>
                        Formats the double as [-]9.9e[+|-]999
                        <p/>
                        <b>Flags:</b> Any.
                    </dd>
                    <dt>g</dt>
                    <dd>
                        use e or f format, whichever is the most concise
                        <p/>
                        <b>Flags:</b> Any.
                    </dd>
                </dl>

                \par Supported Flags
                <dl>
                    <dt>None</dt>
                    <dd>
                        The double is simply converted as it is.
                    </dd>

                    <dt>g</dt>
                    <dd>
                        Inserts group seperators in the result.
                    </dd>

                    <dt>p</dt>
                    <dd>
                        Puts the result in parentes if \e d is negative.
                    </dd>

                    <dt>n</dt>
                    <dd>
                        Prefixes the result with zeros if the result is rightjustified.
                    </dd>

                    <dt>u</td>
                    <dd>The result is converted to upper cases. \e u has precedens over \e l.</dd>

                    <dt>l</td>
                    <dd>The result is converted to lower cases.</dd>

                    <dt>t</dt>
                    <dd>
                        In case of a specified \e width, the result is truncated to \e width if it
                        is larger than \e width.
                    </dd>
                </dl>
                \par
                Any unsupported flags are ignored!

                \param locale The locale to use. This parameter is ignored in this implementation.
                \param param  The format parameter to use.
                \param d      The float to convert.

                \exception FormatException In case of an unsupported conversion.

                \note
                    The template parameter \e floatType must be a type, that QLocale::toString() can accept.
            */
            template< typename floatType >
            QString formatFloat( const QLocale& locale, const FormatParam& param, floatType d ) const;

            /*!
                \brief Formats an integer based on the format parameter \e param.

                \par Supported Conversions
                <dl>
                    <dt>i</dt>
                    <dd>
                        Convert the integer in base 10.
                        <p/>
                        <b>Flags:</b> Any
                    </dd>

                    <dt>b</dt>
                    <dd>
                        Convert the integer in base 2.
                        <p/>
                        <b>Flags:</b> Any
                    </dd>

                    <dt>o</dt>
                    <dd>
                        Convert the integer in base 8.
                        <p/>
                        <b>Flags:</b> Any
                    </dd>

                    <dt>h</dt>
                    <dd>
                        Convert the integer in base 16.
                        <p/>
                        <b>Flags:</b> Any
                    </dd>

                </dl>

                \par Supported Flags
                <dl>
                    <dt>None</dt>
                    <dd>
                        The integer is simply converted as it is.
                    </dd>

                    <dt>g</dt>
                    <dd>
                        Inserts group seperators in the result.
                    </dd>

                    <dt>p</dt>
                    <dd>
                        Puts the result in parentes if \e d is negative.
                    </dd>

                    <dt>n</dt>
                    <dd>
                        Prefixes the result with zeros if the result is rightjustified.
                    </dd>

                    <dt>u</td>
                    <dd>The result is converted to upper cases. \e u has precedens over \e l.</dd>

                    <dt>l</td>
                    <dd>The result is converted to lower cases.</dd>

                    <dt>t</dt>
                    <dd>
                        In case of a specified \e width, the result is truncated to \e width if it
                        is larger than \e width.
                    </dd>
                </dl>
                \par
                Any unsupported flags are ignored!

                \param locale The locale to use. This parameter is ignored in this implementation.
                \param param  The format parameter to use.
                \param i      The integer to convert.

                \exception FormatException In case of an unsupported conversion.

                \note
                    The template parameter \e intType must be a type, that QLocale::toString() and QString::number() can accept.
            */
            template< typename intType >
            QString formatInteger( const QLocale& locale, const FormatParam& param, intType i ) const;
            //@}
        };

        //-------------------------------------------------------------------------------------------------
        // Include implementation file of template functions.
        #include "defaultargumentformater_imp.h"
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
