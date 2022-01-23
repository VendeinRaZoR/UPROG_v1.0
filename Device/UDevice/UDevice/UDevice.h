/*#############################################################*/
/*######################====UDEVICE====########################*/
/*#############################################################*/
/*Description:
    UDEVICE (Universal Common Device) contains UDeviceCommon class
    that creates particular device inherited from abstract UProgBase class
    It have method createDevice that works like abstract factory: initializes
    abstract UProgBase pointer by initialization objects of Device type
    by choosing interface & device type names setted by user
*/
#ifndef UDEVICE_H //guard defines
#define UDEVICE_H

#include "udevice_global.h"
#include "AT17.h"
#include <QString>

class UDEVICESHARED_EXPORT UDeviceCommon
{
    QString m_szDeviceType;
    QString m_szInterfaceType;
public:
    UDeviceCommon(){}
    ~UDeviceCommon(){}
    UProgBase *createDevice(QString szDeviceType,QString szInterfaceType); //Abstract factory of Device's objects
    QString currentDevice() const;//Get last Device type parameter of Device initialized
    QString currentInterface() const;//Get last Interface type parameter of Device initialized
};

#endif // UDEVICE_H
