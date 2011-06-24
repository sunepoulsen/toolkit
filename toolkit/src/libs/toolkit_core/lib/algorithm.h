//-------------------------------------------------------------------------------------------------
/*!
    \file algorithm.h
    \brief
*/

//-------------------------------------------------------------------------------------------------
#ifndef __TOOLKIT_CORE_ALGORITHM_H__
#define __TOOLKIT_CORE_ALGORITHM_H__

// Include Toolkit Files
#include "defines.h"

// Include Qt Files
#include <QTextCodec>

//-------------------------------------------------------------------------------------------------
namespace Toolkit {

    namespace Core {
        //---------------------------------------------------------------------------------------------
        /*!
            \ingroup grp_Core
            \brief
        */
        template< class InputIterator, class Predicate, class UnaryFunction >
        void TOOLKIT_CORE_API for_each_if( InputIterator __begin, InputIterator __end, Predicate pred, UnaryFunction& func ) {
            for( InputIterator it = __begin; it != __end; ++it ) {
                if( pred( *it ) ) {
                    func( *it );
                }
            }
        }

        //---------------------------------------------------------------------------------------------
        /*!
            \ingroup grp_Core
            \brief
        */
        template< class InputIterator, class Predicate >
        bool TOOLKIT_CORE_API is_unique( InputIterator __begin, InputIterator __end, Predicate pred ) {
            bool found = false;

            for( InputIterator it = __begin; it != __end; ++it ) {
                if( pred( *it ) ) {
                    if( found ) {
                        return false;
                    }
                    else {
                        found = true;
                    };
                }
            }

            return found;
        }
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
