//---------------------------------------------------------------------------------------
/*!
    \file sqlfield.h
    \brief
*/

//---------------------------------------------------------------------------------------
#ifndef __TOOLKIT_SQL_SQLFIELD_H__
#define __TOOLKIT_SQL_SQLFIELD_H__

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
            \brief Implements an abstract interface of SQL fields.

            \par Responsability

            Responsability...

            \par Memory Management

            Memory Management...
        */
        class TOOLKIT_SQL_API SqlField {
        public:
            typedef QMap<QString, QVariant> jsdoc_type;
            enum FieldType {
                FT_GENERIC = 1,
                FT_JSDOC = 2
            };


        public:
            //!\name Constructors & Destructor
            //@{
            SqlField( FieldType fieldType = FT_GENERIC, const QString& fieldName = QString(), QVariant::Type valueType = QVariant::Invalid );
            SqlField( const QSqlField& other );
            SqlField( const SqlField& other );
            virtual ~SqlField();
            //@}

            //!\name Field properties
            //@{
            FieldType getFieldType() const;
            void setFieldType( FieldType newFieldType );
            const QString& getName() const;
            void setName( const QString& newName );
            bool getReadOnly() const;
            void setReadOnly( bool newReadOnly );
            int getLength() const;
            void setLength( int newLength );
            int getPrecision() const;
            void setPrecision( int newPrecision );
            QSqlField::RequiredStatus getRequired() const;
            void setRequired( QSqlField::RequiredStatus newRequired );
            //@}

            //!\name Value properties
            //@{
            const QVariant& getDefaultValue() const;
            void setDefaultValue( const QVariant& newDefaultValue );
            bool getAutoValue() const;
            void setAutoValue( bool newAutoValue );
            bool getGenerated() const;
            void setGenerated( bool newGenerated );
            QVariant::Type getValueType() const;
            void setValueType( QVariant::Type newValueType );
            const QVariant& getValue() const;
            void setValue( const QVariant& newValue );
            //@}

            //!\name JS Documents
            //@{
            bool hasField( const QString& fieldName ) const;
            //@}

            //!\name Operators
            //@{
            SqlField& operator=( const SqlField& other );
            SqlField& operator=( const QSqlField& other );
            //@}

        private:
            //!\name Field
            //@{
            FieldType m_FieldType;
            QString m_Name;
            bool m_IsReadOnly;
            int m_Length;
            int m_Precision;
            QSqlField::RequiredStatus m_Required;
            //@}

            //!\name Values
            //@{
            QVariant m_DefaultValue;
            bool m_AutoValue;
            bool m_IsGenerated;
            QVariant::Type m_ValueType;
            QVariant m_Value;
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
