/*#######################################################################*/
/*######################====PATTERNDEV_GLOBAL====########################*/
/*#######################################################################*/
/*Description:
    PATTERNDEV_GLOBAL contains QT defines for creating external DLL library
*/
#ifndef PATTERNDEV_GLOBAL_H
#define PATTERNDEV_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(PATTERNDEV_LIBRARY)
#  define PATTERNDEVSHARED_EXPORT Q_DECL_EXPORT
#else
#  define PATTERNDEVSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // PATTERNDEV_GLOBAL_H
