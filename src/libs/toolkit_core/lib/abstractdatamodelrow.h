//-----------------------------------------------------------------------------
/*!
    \file datamodel.h
    \brief
*/

//-----------------------------------------------------------------------------
#ifndef __TOOLKIT_CORE_ABSTRACTDATAMODELROW_H__
#define __TOOLKIT_CORE_ABSTRACTDATAMODELROW_H__

// Include Toolkit Files
#include "defines.h"

// Include Qt Files
#include <QObject>

//-----------------------------------------------------------------------------
namespace Toolkit {

    namespace Core {
        //---------------------------------------------------------------------
        /*!
            \brief
        */
        class TOOLKIT_CORE_API AbstractDataModelRow : public QObject {
            Q_OBJECT

        public:
            AbstractDataModelRow();
            virtual ~AbstractDataModelRow();

        private:
            Q_DISABLE_COPY( AbstractDataModelRow )
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
