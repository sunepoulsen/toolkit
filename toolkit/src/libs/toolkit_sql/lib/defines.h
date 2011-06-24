//----------------------------------------------------------------------------
/*!
    \file defines.h
    \brief 
*/
//----------------------------------------------------------------------------

#ifndef __TOOLKIT_SQL_DEFINES_H__
#define __TOOLKIT_SQL_DEFINES_H__

//----------------------------------------------------------------------------
/*!
	\define TOOLKIT_SQL_API
	\brief Defines __declspec(dllXXXX) directives to export/import classes on win32.

	\par Usage

	Simple put it in front of the class name in a class declaration:

	\code
	class TOOLKIT_SQL_API Database {
	public:
	  ...
	}
	\endcode
*/
#ifdef WIN32
    #ifdef TOOLKIT_SQL_MAKE_DLL
        #define TOOLKIT_SQL_API __declspec(dllexport)
    #else
        #define TOOLKIT_SQL_API __declspec(dllimport)
    #endif
#else
    #define TOOLKIT_SQL_API
#endif

#endif

