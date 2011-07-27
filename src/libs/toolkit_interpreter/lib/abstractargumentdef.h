//---------------------------------------------------------------------------------------
/*!
    \file abstractargumentdef.h
    \brief 
*/

//---------------------------------------------------------------------------------------
#ifndef __TOOLKIT_INTERPRETER_ABSTRACTARGUMENTDEF_H__
#define __TOOLKIT_INTERPRETER_ABSTRACTARGUMENTDEF_H__

// Include Toolkit FS Files
#include "defines.h"

// Include Qt Files
#include <QString>

//---------------------------------------------------------------------------------------
namespace Toolkit {
       
    namespace Interpreter {
        //---------------------------------------------------------------------------------------
        /*!
            \ingroup grp_Interpreter
            \brief 
        */
        class TOOLKIT_INTERPRETER_API AbstractArgumentDef {
        public:
            //!\name Constructors & Destructor
            //@{
            AbstractArgumentDef( const QString& name = QString(), const QString& descr = QString() );
            AbstractArgumentDef( const AbstractArgumentDef& other );
            virtual ~AbstractArgumentDef();
            //@}
            
            //!\name Properties
            //@{
            const QString& getName() const;
            void setName( const QString& newName );
            const QString& getDescripton() const;
            void setDescription( const QString& newDescription );
            bool getRequired() const;
            void setRequired( bool newRequired );
            //@}
            
            //!\name Checks
            //@{
            bool isRequired() const;
            //@}
            
            //!\name Operators
            //@{
            AbstractArgumentDef& operator=( const AbstractArgumentDef& other );
            //@}
            
        private:
            //!\name Properties
            //@{
            /*!
                \brief The name of the argument.
            */
            QString m_Name;
            
            /*!
                \brief The description of the argument.
            */
            QString m_Description;
            
            /*!
                \brief This property holds whether this argument is required or not.
            
                The default value is \e false.
            */
            bool m_Required;
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
