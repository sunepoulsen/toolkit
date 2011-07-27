//----------------------------------------------------------------------------
/*!
  \file defines.h
  \brief 
*/
//----------------------------------------------------------------------------

#ifndef __TOOLKIT_QSQLMANAGER_CORE_DEFINES_H__
#define __TOOLKIT_QSQLMANAGER_CORE_DEFINES_H__

//----------------------------------------------------------------------------
/*!
	\define TOOLKIT_QSQLMANAGER_CORE_API
*/
#ifdef WIN32
    #ifdef TOOLKIT_QSQLMANAGER_CORE_MAKE_DLL
        #define TOOLKIT_QSQLMANAGER_CORE_API __declspec(dllexport)
    #else
        #define TOOLKIT_QSQLMANAGER_CORE_API __declspec(dllimport)
    #endif
#else
    #define TOOLKIT_QSQLMANAGER_CORE_API
#endif

#endif

