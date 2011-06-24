//-------------------------------------------------------------
/*!
    \file format_imp.h
    \brief 
*/

//-------------------------------------------------------------

#ifndef __TOOLKIT_CORE_STL_IMP_H__
#define __TOOLKIT_CORE_STL_IMP_H__

//-------------------------------------------------------------
//      Implementation of template functions.
//-------------------------------------------------------------

//-------------------------------------------------------------
template<typename T>
Destroy<T>::Destroy() {
};

template<typename T>
Destroy<T>::~Destroy() {
};

template<typename T>
void Destroy<T>::operator()( T* x ) {
    delete x;
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
