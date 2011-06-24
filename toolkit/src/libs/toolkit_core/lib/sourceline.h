//-------------------------------------------------------------
/*!
    \file sourceline.h
    \brief Declares a SourceLine class to represent a line of code in a source file.
*/

//-------------------------------------------------------------
#ifndef __TOOLKIT_CORE_SOURCELINE_H__
#define __TOOLKIT_CORE_SOURCELINE_H__

// Include Toolkit Files
#include "defines.h"

// Include QT Files
#include <QString>

//-------------------------------------------------------------
namespace Toolkit {
    
    namespace Core {           
        //-------------------------------------------------------------
        /*!
            \ingroup grp_Exceptions
            \brief This macro constructs a SourceLine instance with file name and line 
                   number of source position where it apairs.
        */
        #define SOURCELINE Toolkit::Core::SourceLine( __FILE__, __LINE__ )
        
        //-------------------------------------------------------------
        /*!
            \ingroup grp_Exceptions
            \brief Implements a class to represent a line of code in a source file. This is
                   used in collaboration with exceptions and logs.
        */
        class TOOLKIT_CORE_API SourceLine {
        public:
            typedef unsigned int size_type;
        
        public:
            //!\name Constructors & Destructor
            //@{
            SourceLine();
            SourceLine( const char* fileName, size_type lineNumber );
            SourceLine( const SourceLine& other );
            virtual ~SourceLine();
            //@}
            
            //!\name Properties
            //@{
            const QString& getFileName() const;
            void setFileName( const QString& newFileName );
            size_type getLineNumber() const;
            void setLineNumber( size_type newLineNumber );
            //@}
            
            //!\name Operators
            //@{
            SourceLine& operator=( const SourceLine& other );
            //@}
            
        private:
            QString m_FileName;
            size_type m_LineNumber;
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
