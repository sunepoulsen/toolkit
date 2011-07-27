//---------------------------------------------------------------------------------------
/*!
    \file jsqchar.h
    \brief
*/

//---------------------------------------------------------------------------------------
#ifndef __TOOLKIT_SCRIPT_JSQCHAR_H__
#define __TOOLKIT_SCRIPT_JSQCHAR_H__

// Include Toolkit Script Files
#include "defines.h"

#include "scriptobject.h"

// Include Qt Files
#include <QChar>
#include <QObject>
#include <QScriptable>

//---------------------------------------------------------------------------------------
namespace Toolkit {

    namespace Script {
        //---------------------------------------------------------------------------------------
        /*!
            \ingroup grp_ScriptApi
            \brief
        */
        class TOOLKIT_SCRIPT_API JSQChar : public QObject, public ScriptObject<QChar>, protected QScriptable {
            Q_OBJECT

        public:
            static QScriptValue constructor( QScriptContext* ctx, QScriptEngine* eng );

        public:
            //!\name Constructors & Destructor
            //@{
            JSQChar();
            JSQChar( QChar* data, ObjectOwnership ownership = ScriptOwnership );
            JSQChar( const QSharedPointer<QChar>& data );
            virtual ~JSQChar();
            //@}

        public slots:
            uint category() const;
            uint cell() const;
            QString decomposition() const;
            uint decompositionTag() const;
            int digitValue() const;
            uint direction() const;
            bool hasMirrored() const;
            bool isAscii() const;
            bool isDigit() const;
            bool isHighSurrogate() const;
            bool isLatin1() const;
            bool isLetter() const;
            bool isLetterOrNumber() const;
            bool isLowSurrogate() const;
            bool isLower() const;
            bool isMark() const;
            bool isNull() const;
            bool isNumber() const;
            bool isPrint() const;
            bool isPunct() const;
            bool isSpace() const;
            bool isSymbol() const;
            bool isTitleCase() const;
            bool isUpper() const;
            uint joining() const;
            QObject* mirroredChar() const;
            uint row() const;
            QObject* toCaseFolded() const;
            QObject* toLower() const;
            QString toString() const;
            QObject* toTitleCase() const;
            QObject* toUpper() const;
            ushort unicode() const;
            uint unicodeVersion() const;
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
