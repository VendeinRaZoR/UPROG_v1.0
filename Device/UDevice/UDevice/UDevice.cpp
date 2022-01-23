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
#include "UDevice.h"
//Abstract factory of Device's objects inherited by UProgBase class
UProgBase *UDeviceCommon::createDevice(QString szDeviceType, QString szInterfaceType)
{
    m_szDeviceType = szDeviceType;
    m_szInterfaceType = szInterfaceType;
    if(szDeviceType == AT17LVC65 || szDeviceType == AT17LVC128 ||
      szDeviceType == AT17LVC256 || szDeviceType == AT17LVC512 ||
      szDeviceType == AT17LVC010 || szDeviceType == AT17LVC002 ||
      szDeviceType == AT17LVC040)
        return new AT17(szDeviceType,szInterfaceType);//Initialize by AT17 Device class object
    return 0;
}
//Get last Device type parameter of Device initialized
QString UDeviceCommon::currentDevice() const
{
    return m_szDeviceType;
}
//Get last Interface type parameter of Device initialized
QString UDeviceCommon::currentInterface() const
{
    return m_szInterfaceType;
}
