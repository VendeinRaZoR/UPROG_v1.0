/*####################################################################*/
/*######################====UDEVICE_GLOBAL====########################*/
/*####################################################################*/
/*Description:
    UDEVICE_GLOBAL contains QT defines for creating external DLL library
*/
#ifndef UDEVICE_GLOBAL_H
#define UDEVICE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(UDEVICE_LIBRARY)
#  define UDEVICESHARED_EXPORT Q_DECL_EXPORT
#else
#  define UDEVICESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // UDEVICE_GLOBAL_H
