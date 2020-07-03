#ifndef SET_DLL_GLOBAL_H
#define SET_DLL_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SET_DLL_LIBRARY)
#  define SET_DLL_EXPORT Q_DECL_EXPORT
#else
#  define SET_DLL_EXPORT Q_DECL_IMPORT
#endif

#endif // SET_DLL_GLOBAL_H
