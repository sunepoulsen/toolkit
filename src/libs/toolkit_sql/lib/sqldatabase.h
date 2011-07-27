//---------------------------------------------------------------------------------------
/*!
    \file sqldatabase.h
    \brief
*/

//---------------------------------------------------------------------------------------
#ifndef __TOOLKIT_SQL_SQLDATABASE_H__
#define __TOOLKIT_SQL_SQLDATABASE_H__

// Include Toolkit Sql Files
#include "defines.h"

// Include Qt Files
#include <QObject>
#include <QSqlDatabase>

//---------------------------------------------------------------------------------------
namespace Toolkit {

    namespace Sql {
        //---------------------------------------------------------------------------------------
        /*!
            \ingroup grp_Sql
            \brief Implements a sql database connection.

            \par Responsability

            Responsability...

            \par Memory Management

            Memory Management...
        */
        class TOOLKIT_SQL_API SqlDatabase : public QObject {
            Q_OBJECT

        public:
            //!\name Constructors & Destructor
            //@{
            SqlDatabase();
            SqlDatabase( const SqlDatabase& other );
            virtual ~SqlDatabase();
            //@}

            //!\name Database
            //@{
            QSqlDatabase& getDatabase();
            const QSqlDatabase& getDatabase() const;
            //@}

            //!\name Operators
            //@{
            SqlDatabase& operator=( const SqlDatabase& other );
            //@}

        private:
            //!\name Database
            //@{
            QSqlDatabase m_Database;            
            //@}

            //!\name Properties
            //@{

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
