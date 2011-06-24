//---------------------------------------------------------------------------------------------
/*!
  \file stl.h
  \brief 
*/

//---------------------------------------------------------------------------------------------
#ifndef __TOOLKIT_CORE_STL_H__
#define __TOOLKIT_CORE_STL_H__

// Include Toolkit Files
#include "defines.h"

// Include STD Files
#include <functional>

//---------------------------------------------------------------------------------------------
namespace Toolkit {
    
    namespace Core {           
        //---------------------------------------------------------------------------------------------
        /*!
            \brief STL function to destroy an element in a container that contains pointers.
            \ingroup grp_core
        */
        template<typename T>
        class TOOLKIT_CORE_API Destroy : public std::unary_function<T*, void> {
        public:
            //!\name Constructors & Destructor
            //@{
            Destroy();
            virtual ~Destroy();
            //@}
            
            //!\name Operators
            //@{
            void operator()( T* x );
            //@}
        };

        //-------------------------------------------------------------
        // Include implementation file of template functions.
        #include "stl_imp.h"

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
