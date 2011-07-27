//---------------------------------------------------------------------------------------
/*!
    \file sqldatabasedef.h
    \brief
*/

//---------------------------------------------------------------------------------------
#ifndef __TOOLKIT_SQL_SQLDATABASEDEF_H__
#define __TOOLKIT_SQL_SQLDATABASEDEF_H__

// Include Toolkit Sql Files
#include "defines.h"

// Include Qt Files
#include <QString>

//---------------------------------------------------------------------------------------
namespace Toolkit {

    namespace Sql {
        //---------------------------------------------------------------------------------------
        /*!
            \ingroup grp_Sql
            \brief Implements a definition of a SQL database.

            \par Responsability

            Responsability...

            \par Memory Management

            Memory Management...
        */
        class TOOLKIT_SQL_API SqlDatabaseDef {
        public:
            //!\name Constructors & Destructor
            //@{
            SqlDatabaseDef();
            SqlDatabaseDef( const SqlDatabaseDef& other );
            virtual ~SqlDatabaseDef();
            //@}

            //!\name Operators
            //@{
            SqlDatabaseDef& operator=( const SqlDatabaseDef& other );
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
