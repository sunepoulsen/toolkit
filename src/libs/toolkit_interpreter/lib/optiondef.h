//---------------------------------------------------------------------------------------
/*!
    \file optiondef.h
    \brief 
*/

//---------------------------------------------------------------------------------------
#ifndef __TOOLKIT_INTERPRETER_OPTIONDEF_H__
#define __TOOLKIT_INTERPRETER_OPTIONDEF_H__

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
        class TOOLKIT_INTERPRETER_API OptionDef {
        public:
            //!\name Constructors & Destructor
            //@{
            OptionDef( const QString& id, const QString& shortName = QString(), const QString& longName = QString(), const QString& descr = QString() );
            OptionDef( const OptionDef& other );
            virtual ~OptionDef();
            //@}
            
            //!\name Properties
            //@{
            const QString& getId() const;
            void setId( const QString& newId );
            const QString& getShortName() const;
            void setShortName( const QString& newShortName );
            const QString& getLongName() const;
            void setLongName( const QString& newLongName );
            const QString& getDescripton() const;
            void setDescription( const QString& newDescription );
            //@}
                        
            //!\name Values
            //@{
            bool getDefaultValue() const;
            void setDefaultValue( bool newDefaultValue );
            //@}
            
            //!\name Operators
            //@{
            OptionDef& operator=( const OptionDef& other );
            //@}
            
        private:
            //!\name Properties
            //@{
            /*!
                \brief Internal unique id of this option.
            */
            QString m_Id;
            
            /*!
                \brief The short name of the option.
            */
            QString m_ShortName;
            
            /*!
                \brief The long name of the option.
            */
            QString m_LongName;
            
            /*!
                \brief The description of the option.
            */
            QString m_Description;            
            //@}
            
            //!\name Values
            //@{
            bool m_DefaultValue;
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
