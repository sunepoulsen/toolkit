//---------------------------------------------------------------------------------------
/*!
    \file environmentoptions.h
    \brief
*/

//---------------------------------------------------------------------------------------
#ifndef __TOOLKIT_SCRIPT_ENVIRONMENTOPTIONS_H__
#define __TOOLKIT_SCRIPT_ENVIRONMENTOPTIONS_H__

// Include Toolkit Script Files
#include "defines.h"

// Include Qt Files
#include <QTextCodec>

//---------------------------------------------------------------------------------------
namespace Toolkit {

    namespace Script {
        //---------------------------------------------------------------------------------------
        /*!
            \ingroup grp_Script
            \brief
        */
        class TOOLKIT_SCRIPT_API EnvironmentOptions {
        public:
            //!\name Constructors & Destructor
            //@{
            EnvironmentOptions();
            EnvironmentOptions( const EnvironmentOptions& other );
            virtual ~EnvironmentOptions();
            //@}

            //!\name Properties
            //@{
            bool getLocalContext() const;
            void setLocalContext( bool newLocalContext );
            const QTextCodec& getCodec() const;
            void setCodec( QTextCodec* newCodec );
            void setCodec( const char* codecName );
            void setCodec( const QString& codecName );
            //@}

            //!\name Operators
            //@{
            EnvironmentOptions& operator=( const EnvironmentOptions& other );
            //@}

        private:
            //!\name Properties
            //@{
            /*!
                \brief Set whether or not function calls should be executed in a local context.
            */
            bool m_LocalContext;

            /*!
                \brief Sets the text codec for loading files into the environment.

                \par Default value
                It is initialized with the result of QTextCodec::codecForLocale(), that is a codec
                for the current locale.
            */
            QTextCodec* m_Codec;
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
