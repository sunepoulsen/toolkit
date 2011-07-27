//---------------------------------------------------------------------------------------
/*!
    \file sqlfielddef.h
    \brief
*/

//---------------------------------------------------------------------------------------
#ifndef __TOOLKIT_SQL_SQLFIELDDEF_H__
#define __TOOLKIT_SQL_SQLFIELDDEF_H__

// Include Toolkit Sql Files
#include "defines.h"

// Include Qt Files
#include <QSqlField>

//---------------------------------------------------------------------------------------
namespace Toolkit {

    namespace Sql {
        //---------------------------------------------------------------------------------------
        /*!
            \ingroup grp_Sql
            \brief Implements a definition of a SQL field constaint.

            \par Responsability

            Responsability...

            \par Memory Management

            Memory Management...
        */
        class TOOLKIT_SQL_API SqlFieldConstraintDef {
        public:
            enum ConstraintType {
                CT_PRIMARY_KEY,
                CT_REQUIRED,
                CT_UNIQUE,
                CT_CHECK,
                CT_DEFAULT,
                CT_FOREIGN_KEY
            };

        public:
            //!\name Constructors & Destructor
            //@{
            SqlFieldConstraintDef();
            SqlFieldConstraintDef( const SqlFieldConstraintDef& other );
            virtual ~SqlFieldConstraintDef();
            //@}

            //!\name Operators
            //@{
            SqlFieldConstraintDef& operator=( const SqlFieldConstraintDef& other );
            //@}

        private:
            ConstraintType m_Type;

            bool m_AutoValue;
            Qt::SortOrder m_SortOrder;
            QVariant m_Expr;
        };

        //---------------------------------------------------------------------------------------
        /*!
            \ingroup grp_Sql
            \brief Implements a definition of a SQL field.

            \par Responsability

            Responsability...

            \par Memory Management

            Memory Management...
        */
        class TOOLKIT_SQL_API SqlFieldDef {
        public:
            enum FieldType {
                FT_STRING,
                FT_TEXT,
                FT_INT,
                FT_DOUBLE,
                FT_DATE,
                FT_TIME,
                FT_DATETIME,
                FT_BLOB
            };

        public:
            //!\name Constructors & Destructor
            //@{
            SqlFieldDef();
            SqlFieldDef( const SqlFieldDef& other );
            virtual ~SqlFieldDef();
            //@}

            //!\name Properties
            //@{
            const QString& getName() const;
            void setName( const QString& newName );
            FieldType getFieldType() const;
            void setFieldType( FieldType newFieldType );
            int getLength() const;
            void setLength( int newLength );
            int getPrecision() const;
            void setPrecision( int newPrecision );
            QSqlField::RequiredStatus getRequired() const;
            void setRequired( QSqlField::RequiredStatus newRequired );
            const QVariant& getDefaultValue() const;
            void setDefaultValue( const QVariant& newDefaultValue );
            //@}

            //!\name Operators
            //@{
            SqlFieldDef& operator=( const SqlFieldDef& other );
            //@}

        private:
            //!\name Property members
            //@{
            QString m_Name;
            FieldType m_Type;
            int m_Length;
            int m_Precision;
            QSqlField::RequiredStatus m_Required;
            bool m_AutoValue;
            QVariant m_DefaultValue;
            //@}
        };

    }

}

#endif

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
