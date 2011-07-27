//----------------------------------------------------------------------------
/*!
  \file defines.h
  \brief 
*/
//----------------------------------------------------------------------------

#ifndef __TOOLKIT_TEST_DEFINES_H__
#define __TOOLKIT_TEST_DEFINES_H__

//----------------------------------------------------------------------------
/*!
    \define TOOLKIT_TEST_API
    \brief Defines __declspec(dllXXXX) directives to export/import classes on win32.

    \par Usage

    Simple put it in front of the class name in a class declaration:

    \code
    class TOOLKIT_TEST_API Throwable {
    public:
        ...
    }
    \endcode
*/
#ifdef WIN32
    #ifdef TOOLKIT_TEST_MAKE_DLL
        #define TOOLKIT_TEST_API __declspec(dllexport)
    #else
        #define TOOLKIT_TEST_API __declspec(dllimport)
    #endif
#else
    #define TOOLKIT_TEST_API
#endif

#endif
