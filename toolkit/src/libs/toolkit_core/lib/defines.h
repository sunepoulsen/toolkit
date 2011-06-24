//----------------------------------------------------------------------------
/*!
  \file defines.h
  \brief 
*/
//----------------------------------------------------------------------------

#ifndef __TOOLKIT_CORE_DEFINES_H__
#define __TOOLKIT_CORE_DEFINES_H__

//----------------------------------------------------------------------------
/*!
	\define TOOLKIT_CORE_API
	\brief Defines __declspec(dllXXXX) directives to export/import classes on win32.

	\par Usage

	Simple put it in front of the class name in a class declaration:

	\code
	class TOOLKIT_CORE_API Throwable {
	public:
	  ...
	}
	\endcode
*/
#ifdef WIN32
    #ifdef TOOLKIT_CORE_MAKE_DLL
        #define TOOLKIT_CORE_API __declspec(dllexport)
    #else
        #define TOOLKIT_CORE_API __declspec(dllimport)
    #endif
#else
    #define TOOLKIT_CORE_API
#endif

#endif
