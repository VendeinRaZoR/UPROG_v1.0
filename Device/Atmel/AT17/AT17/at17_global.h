#ifndef AT17_GLOBAL_H
#define AT17_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(AT17_LIBRARY)
#  define AT17SHARED_EXPORT Q_DECL_EXPORT
#else
#  define AT17SHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // AT17_GLOBAL_H
