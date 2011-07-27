//---------------------------------------------------------------------------------------
/*!
    \file sqltabledef.h
    \brief
*/

//---------------------------------------------------------------------------------------
#ifndef __TOOLKIT_SQL_SQLTABLEDEF_H__
#define __TOOLKIT_SQL_SQLTABLEDEF_H__

// Include Toolkit Sql Files
#include "defines.h"
#include "sqlfielddef.h"


// Include Qt Files
#include <QString>

// Include STL Files
#include <deque>

//---------------------------------------------------------------------------------------
namespace Toolkit {

    namespace Sql {
        //---------------------------------------------------------------------------------------
        /*!
            \ingroup grp_Sql
            \brief Implements a definition of a SQL table.

            \par Responsability

            Responsability...

            \par Memory Management

            Memory Management...
        */
        class TOOLKIT_SQL_API SqlTableDef {
        public:
            typedef std::deque<SqlFieldDef> fields_type;

        public:
            //!\name Constructors & Destructor
            //@{
            SqlTableDef();
            SqlTableDef( const SqlTableDef& other );
            virtual ~SqlTableDef();
            //@}

            //!\name Operators
            //@{
            SqlTableDef& operator=( const SqlTableDef& other );
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
