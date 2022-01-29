/*################################################################*/
/*######################====PATTERNDEV====########################*/
/*################################################################*/
/*Description:
    PATTERNDEV Device integral circuit programming class that
    reimplements methods of UProgBase programmer's class
*/
#include "patterndev.h"

#include <stdarg.h>
#include <stdio.h>
#include <QThread>
#include <iostream>
#include <bitset>
#include <QDebug>
//Initialize Device with Type and Interface
PatternDev::PatternDev(QString szDeviceType, QString szInterfaceType)
{
    m_szPatterDevType = szDeviceType;
    m_szInterfaceType = szInterfaceType;
    m_bResPolarity = false;
    m_pFirmData = 0;
    m_bFirmAlloc = false;
    m_bProgRun = false;
}
//cleanup
PatternDev::~PatternDev()
{

}
//Set firmware data pointer
int PatternDev::setFirmware(QVector<unsigned long> *pFirmFile)
{
    return 0;//return not defined yet
}
//Get firmware data pointer that allocated or was set before
QVector<unsigned long> *PatternDev::getFirmware() const
{
    return m_pFirmData;
}
//reserved, bot used yet
int PatternDev::deleteFirmware()
{
    return 1;
}
//Set PatternDev programmer's interface type
void PatternDev::setInterface(QString szInterfaceType)
{
    m_szInterfaceType = szInterfaceType;
}
//Get interface type
QString PatternDev::getInterface() const
{
    return m_szInterfaceType;
}
//Initialize device info with 0xFF and
int PatternDev::init()
{
    return 0;
}
//Set signals on PatternDev device pins by DeviceSignals structure
void PatternDev::setSignals(DeviceSignals devSgnl)
{
}
//Get signals from PatternDev device's pins
DeviceSignals PatternDev::getSignals()
{
    DeviceSignals devSgnl;
    return devSgnl;
}
//Power on VCC pin
void PatternDev::powerOn()
{
}
//Power off VCC pin
void PatternDev::powerOff()
{
}
//Set PatternDev device type
void PatternDev::setType(QString szDeviceType)
{
    m_szPatterDevType = szDeviceType;
}
//Get PatternDev device type
QString PatternDev::getType() const
{
    return m_szPatterDevType;
}
//Get info from PatternDev device
DeviceInfo PatternDev::getInfo()
{
    return m_devInfo;//Device info object
}
//Check received device info structure
bool PatternDev::checkInfo() const
{
    return DEVICE_OK;//ALL OK
}
//Get number of pages in device
int PatternDev::getNumPages() const
{
    return 0;
}
//Get page size of device
int PatternDev::getPageSize() const
{
    return 0;
}
//Get full device memory size
int PatternDev::getSize() const
{
    return 0;
}
//Read full main function
int PatternDev::_readFull()
{
    return READ_OK;
}
//Read burst wasn't implemented yet
int PatternDev::_readBurst(int nAddrFrom,int nNumWords)
{
    QList<unsigned long>m_m_readBuffer;
    return READ_OK;
}
//Read from page wasn't implemented yet
int PatternDev::_readFromPage(int nPage,int nAddrFrom,int nAddrTo)
{
    QList<unsigned long>m_m_readBuffer;
    return READ_OK;
}
//Read pages wasn't implemented yet
int PatternDev::_readPages(int nPageFrom,int nPageTo)
{
    QList<unsigned long>m_m_readBuffer;
    return READ_OK;
}
//Read device memory page functionality not realized yet
int PatternDev::_readPage(int nPage)
{
    QList<unsigned long>m_m_readBuffer;
    return READ_OK;
}
//Write to device full memory functionality
int PatternDev::_writeFull()
{
    return WRITE_OK;
}
//Write in PatternDev memory page
int PatternDev::_writeToPage(int nPage,int nAddrFrom,int nAddrTo)
{
    return WRITE_OK;//Write error if device's type is wrong
}
//Temporary not reimplemented function
int PatternDev::_writePages(int nPageFrom,int nPageTo)
{
    return 0;
}
//Temporary not reimplemented function
int PatternDev::_writePage(int nPage)
{
    return 0;
}
//Temporary not reimplemented function
int PatternDev::_writeBurst(int nAddrFrom, int nNumWords)
{
    return WRITE_OK;
}
//Setup interface by UI controls
QString PatternDev::setupInterface(UControlBase* pControlBase)
{
    return QString("Error message");
}
//Write all configurations into PatternDev configuration memory
void PatternDev::writeConfiguration(UControlBase* pControlBase)
{
}
//Full erasing of device (but not used yet)
int PatternDev::_eraseFull()
{
    return WRITE_OK;
}
//Temporary not reimplemented function
int PatternDev::_eraseBurst(int nAddrFrom,int nNumWords)
{
    return 0;
}
//Temporary not reimplemented function
int PatternDev::_eraseToPage(int nPage,int nAddrFrom,int nAddrTo)
{
    return 0;
}
//Temporary not reimplemented function
int PatternDev::_erasePages(int nPageFrom,int nPageTo)
{
    return 0;
}
//Temporary not reimplemented function
int PatternDev::_erasePage(int nPage)
{
    return 0;
}
//Programming state machine controls programming process
void PatternDev::progRun()
{
    m_bProgRun = true; //programming process is running
    switch (m_progState) //ProgState states enum
    {
        case READ_FULL: //programming states
            m_nLastError = this->_readFull();//functionality
            break;
        case READ_FROM_PAGE:
            m_nLastError = this->_readFromPage(m_nPage,m_nAddrFrom,m_nAddrTo);
            break;
        case READ_PAGES:
            m_nLastError = this->_readPages(m_nPageFrom,m_nPageTo);
            break;
        case READ_PAGE:
            m_nLastError = this->_readPage(m_nPage);//Set last error result
            break;
        case READ_BURST:
            m_nLastError = this->_readBurst(m_nAddrFrom,m_nNumWords);
            break;
        case WRITE_FULL:
            m_nLastError = this->_writeFull();
            break;
        case WRITE_TO_PAGE:
            m_nLastError = this->_writeToPage(m_nPage,m_nAddrFrom,m_nAddrTo);
            break;
        case WRITE_PAGES:
            m_nLastError = this->_writePages(m_nPageFrom,m_nPageTo);
            break;
        case WRITE_PAGE:
            m_nLastError = this->_writePage(m_nPage);
            break;
        case WRITE_BURST:
            m_nLastError = this->_writeBurst(m_nAddrFrom,m_nNumWords);
            break;
        case ERASE_FULL:
            m_nLastError = this->_eraseFull();
            break;
        case ERASE_TO_PAGE:
            m_nLastError = this->_eraseToPage(m_nPage,m_nAddrFrom,m_nAddrTo);
            break;
        case ERASE_PAGES:
            m_nLastError = this->_erasePages(m_nPageFrom,m_nPageTo);
            break;
        case ERASE_PAGE:
            m_nLastError = this->_erasePage(m_nPage);
            break;
        case ERASE_BURST:
            m_nLastError = this->_eraseBurst(m_nAddrFrom,m_nNumWords);
            break;
        default:
            m_nLastError = 0;//LastError = 0 then no errors was happened
            break;
    }
}
//Terminate programming process slot by user action (like button pressing)
void PatternDev::progAbort()
{
    m_bProgRun = false;
}



