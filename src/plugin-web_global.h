#ifndef PLUGINWEB_GLOBAL_H


#include <QtCore/qglobal.h>

#if defined(PLUGINWEB_LIBRARY)
#  define PLUGINWEB_EXPORT Q_DECL_EXPORT
#else
#  define PLUGINLOGIN_EXPORT Q_DECL_IMPORT
#endif

#endif // PLUGINLOGIN_GLOBAL_H


#define PLUGINWEB_GLOBAL_H