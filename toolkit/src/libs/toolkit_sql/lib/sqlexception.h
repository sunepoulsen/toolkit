//---------------------------------------------------------------------------------------
/*!
    \file sqlexception.h
    \brief
*/

//---------------------------------------------------------------------------------------
#ifndef __TOOLKIT_SQL_SQLEXCEPTION_H__
#define __TOOLKIT_SQL_SQLEXCEPTION_H__

// Include Toolkit Sql Files
#include "defines.h"

// Include Qt Files
#include <QSqlError>

// Include Toolkit Core Files
#include <toolkit/core/exception.h>

//---------------------------------------------------------------------------------------
class QSqlDatabase;
class QSqlQuery;

//---------------------------------------------------------------------------------------
namespace Toolkit {

    namespace Sql {
        //---------------------------------------------------------------------------------------
        /*!
            \ingroup grp_Sql
            \brief Implements a sql exception.

            \par Responsability

            Responsability...

            \par Memory Management

            Memory Management...
        */
        class TOOLKIT_SQL_API SqlException : public Toolkit::Core::Exception {
        public:
            //!\name Constructors & Destructor
            //@{
            SqlException( const Toolkit::Core::SourceLine& srcLine, const QString& message );
            SqlException( const Toolkit::Core::SourceLine& srcLine, const QSqlDatabase& db );
            SqlException( const Toolkit::Core::SourceLine& srcLine, const QSqlQuery& query );
            SqlException( const Toolkit::Core::SourceLine& srcLine, const QSqlError& sqlError );
            SqlException( const SqlException& other );
            virtual ~SqlException();
            //@}

            //!\name Properties
            //@{
            const QSqlError& sqlError() const;
            const QString& sqlQuery() const;
            //@}

            //!\name Operators
            //@{
            SqlException& operator=( const SqlException& other );
            //@}

        private:
            //!\name Properties
            //@{
            QSqlError m_SqlError;
            QString m_SqlQuery;
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
