/*################################################################*/
/*######################====I2C_GLOBAL====########################*/
/*################################################################*/
/*Description:
    I2C_GLOBAL contains QT defines for creating external DLL library
*/
#ifndef I2C_GLOBAL_H
#define I2C_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(I2C_LIBRARY)
#  define I2CSHARED_EXPORT Q_DECL_EXPORT
#else
#  define I2CSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // I2C_GLOBAL_H
