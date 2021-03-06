//----------------------------------------------------------------------------
/*!
    \file defines.h
    \brief 
*/
//----------------------------------------------------------------------------

#ifndef __TOOLKIT_GUI_DEFINES_H__
#define __TOOLKIT_GUI_DEFINES_H__

//----------------------------------------------------------------------------
/*!
	\define TOOLKIT_GUI_API
	\brief Defines __declspec(dllXXXX) directives to export/import classes on win32.

	\par Usage

	Simple put it in front of the class name in a class declaration:

	\code
	class TOOLKIT_GUI_API Throwable {
	public:
	  ...
	}
	\endcode
*/
#ifdef WIN32
    #ifdef TOOLKIT_GUI_MAKE_DLL
        #define TOOLKIT_GUI_API __declspec(dllexport)
    #else
        #define TOOLKIT_GUI_API __declspec(dllimport)
    #endif
#else
    #define TOOLKIT_GUI_API
#endif

#endif

