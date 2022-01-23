/*##########################################################################*/
/*######################====QPARALLELPORT_GLOBAL====########################*/
/*##########################################################################*/
/*Description:
    QPARALLELPORT_GLOBAL contains QT defines for creating external DLL library
*/
#ifndef QPARALLELPORT_GLOBAL_H
#define QPARALLELPORT_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(QPARALLELPORT_LIBRARY)
#  define QPARALLELPORTSHARED_EXPORT Q_DECL_EXPORT
#else
#  define QPARALLELPORTSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // QPARALLELPORT_GLOBAL_H
