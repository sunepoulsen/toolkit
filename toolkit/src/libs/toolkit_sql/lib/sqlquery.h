//---------------------------------------------------------------------------------------
/*!
    \file sqlquery.h
    \brief
*/

//---------------------------------------------------------------------------------------
#ifndef __TOOLKIT_SQL_SQLQUERY_H__
#define __TOOLKIT_SQL_SQLQUERY_H__

// Include Toolkit Sql Files
#include "defines.h"

// Include Qt Files
#include <QObject>
#include <QSqlQuery>

//---------------------------------------------------------------------------------------
namespace Toolkit {

    namespace Sql {
        //---------------------------------------------------------------------------------------
        class SqlDatabase;

        //---------------------------------------------------------------------------------------
        /*!
            \ingroup grp_Sql
            \brief Implements a cacheable sql query.

            \par Responsability

            Responsability...

            \par Memory Management

            Memory Management...
        */
        class TOOLKIT_SQL_API SqlQuery : public QObject {
            Q_OBJECT

        public:
            //!\name Constructors & Destructor
            //@{
            SqlQuery();
            SqlQuery( const SqlQuery& other );
            virtual ~SqlQuery();
            //@}

            //!\name Operators
            //@{
            SqlQuery& operator=( const SqlQuery& other );
            //@}

        private:
            //!\name Properties
            //@{
            QSqlQuery m_Query;
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
