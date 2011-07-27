//-------------------------------------------------------------
/*!
  \file library.h
  \brief 
*/

//-------------------------------------------------------------
#ifndef __TOOLKIT_CORE_LIBRARY_H__
#define __TOOLKIT_CORE_LIBRARY_H__

// Include Toolkit Core Files
#include "defines.h"

// Include QT Files
#include <QString>

//-------------------------------------------------------------
// #define TOOLKIT_VERSION_STR "0.1.0"

//-------------------------------------------------------------
namespace Toolkit {
    
    namespace Core {
        //-------------------------------------------------------------
        /*!
            \brief 
            \ingroup grp_Core
        */
        class TOOLKIT_CORE_API Library {
        public:
            static QString VERSION_NUMBER;
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
