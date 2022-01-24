/*##########################################################*/
/*######################====AT17====########################*/
/*##########################################################*/
/*Description:
    AT17 Device integral circuit programming class that reimplements
    methods of UProgBase programmer's class
*/
#include "AT17.h"
#include <stdarg.h>
#include <stdio.h>
#include <QThread>
#include <iostream>
#include <bitset>
#include <QDebug>
//Initialize Device with Type and Interface
AT17::AT17(QString szDeviceType, QString szInterfaceType)
{
    m_szAT17Type = szDeviceType;
    m_szInterfaceType = szInterfaceType;
    m_bResPolarity = false;
    m_pFirmData = 0;
    m_pI2C = 0;
    m_bFirmAlloc = false;
    m_bProgRun = false;
}
//cleanup
AT17::~AT17()
{

}
//Set firmware data pointer
int AT17::setFirmware(QVector<unsigned long> *pFirmFile)
{
    if(pFirmFile)//Firmware data pointer not null
    {
        if(m_pFirmData && m_bFirmAlloc) //is AT17 Firmware data not null and data already allocated
        {
            m_bFirmAlloc = false;//memory not allocated
            delete m_pFirmData;//delete memory instance
        }
        m_pFirmData = pFirmFile;//in this case set firmware data ponter
    }
    return 0;//return not defined yet
}
//Get firmware data pointer that allocated or was set before
QVector<unsigned long> *AT17::getFirmware() const
{
    return m_pFirmData;
}
//reserved, bot used yet
int AT17::deleteFirmware()
{
    //if(m_pFirmData)
        //delete m_pFirmData;
    return 1;
}
//Set AT17 programmer's interface type
void AT17::setInterface(QString szInterfaceType)
{
    m_szInterfaceType = szInterfaceType;
}
//Get interface type
QString AT17::getInterface() const
{
    return m_szInterfaceType;
}
//Initialize device info with 0xFF and
int AT17::init()
{
    m_pI2C->init();
    m_devInfo.byte0 = 0xFF;
    m_devInfo.byte1 = 0xFF;
    m_devInfo.byte2 = 0xFF;
    m_devInfo.byte3 = 0xFF;
    m_devInfo.byte4 = 0xFF;
    m_devInfo.byte5 = 0xFF;
    m_devInfo.byte6 = 0xFF;
    m_devInfo.byte7 = 0xFF;
    return 0;
}
//Set signals on AT17 device pins by DeviceSignals structure
void AT17::setSignals(DeviceSignals devSgnl)
{
    m_parallelDataOut.data[0] = devSgnl.pin2;//SCLK
    m_parallelDataOut.data[7] = devSgnl.pin1;//SDA_out
    m_parallelDataOut.data[6] = devSgnl.pin8;//VCC
    m_parallelDataOut.data[4] = devSgnl.pin7;//SER_EN
    m_parallelDataOut.data[3] = devSgnl.pin3;//RESET/OE
    m_parallelDataOut.data[2] = devSgnl.pin4;//nCS
    m_parallelPort.write(&m_parallelDataOut);//write all pins
}
//Get signals from AT17 device's pins
DeviceSignals AT17::getSignals()
{
    DeviceSignals devSgnl;
    QParallelDataIn parallelDataIn;
    parallelDataIn = m_parallelPort.read();//read input pins
    devSgnl.pin1 = parallelDataIn.ack;//SDA_in
    return devSgnl;
}
//Power on VCC pin
void AT17::powerOn()
{
    m_parallelDataOut.data[6] = 1;//VCC
    m_parallelPort.write(&m_parallelDataOut);
}
//Power off VCC pin
void AT17::powerOff()
{
    m_parallelDataOut.data[6] = 0;//VCC
    m_parallelPort.write(&m_parallelDataOut);
}
//Set AT17 device type
void AT17::setType(QString szDeviceType)
{
    m_szAT17Type = szDeviceType;
}
//Get AT17 device type
QString AT17::getType() const
{
    return m_szAT17Type;
}
//Get info from AT17 device
DeviceInfo AT17::getInfo()
{
    powerOn();//VCC pin to logic 1
    m_pI2C->startCondition();//Start Condition signal on I2C bus
    m_pI2C->sendByte(0xA6);//Send bytes byte-by-byte on I2C bus
    m_pI2C->sendByte(0x04);//
    m_pI2C->sendByte(0x00);//
    m_pI2C->sendByte(0x00);//
    m_pI2C->startCondition();//Stop Condition signal on I2C bus
    m_pI2C->sendByte(0xA7);//
    m_devInfo.byte0 = m_pI2C->recvByte(1);//get info byte 0 on I2C bus with ACK 0 (active)
    m_devInfo.byte1 = m_pI2C->recvByte(0);//get info byte 1 on I2C bus with ACK 1 (not active)
    m_pI2C->stopCondition();//Stop Condition
    powerOff();//VCC pin to logic 0
    return m_devInfo;//Device info object
}
//Check received device info structure
bool AT17::checkInfo() const
{
    if(m_devInfo.byte0 == 0x78 && m_devInfo.byte1 == 0xEF)
        return DEVICE_OK;//ALL OK
    else
        return DEVICE_FAIL;//WARNING
}
//Get number of pages in device
int AT17::getNumPages() const
{
    if(m_szAT17Type == AT17LVC65)
        return T_PAGE_AT17LVC65;
    if(m_szAT17Type == AT17LVC128)
        return T_PAGE_AT17LVC128;
    if(m_szAT17Type == AT17LVC256)
        return T_PAGE_AT17LVC256;
    if(m_szAT17Type == AT17LVC512)
        return T_PAGE_AT17LVC512;
    if(m_szAT17Type == AT17LVC010)
        return T_PAGE_AT17LVC010;
    if(m_szAT17Type == AT17LVC002)
        return T_PAGE_AT17LVC002;
    if(m_szAT17Type == AT17LVC040)
        return T_PAGE_AT17LVC040;
    return T_PAGE_UNKNOWN;
}
//Get page size of device
int AT17::getPageSize() const
{
    if(m_szAT17Type == AT17LVC65)
        return T_BYTE_AT17LVC65;
    if(m_szAT17Type == AT17LVC128)
        return T_BYTE_AT17LVC128;
    if(m_szAT17Type == AT17LVC256)
        return T_BYTE_AT17LVC256;
    if(m_szAT17Type == AT17LVC512)
        return T_BYTE_AT17LVC512;
    if(m_szAT17Type == AT17LVC010)
        return T_BYTE_AT17LVC010;
    if(m_szAT17Type == AT17LVC002)
        return T_BYTE_AT17LVC002;
    if(m_szAT17Type == AT17LVC040)
        return T_BYTE_AT17LVC040;
    return T_BYTE_UNKNOWN;
}
//Get full device memory size
int AT17::getSize() const
{
    if(m_szAT17Type == AT17LVC65)
        return TT_BYTE_AT17LVC65;
    if(m_szAT17Type == AT17LVC128)
        return TT_BYTE_AT17LVC128;
    if(m_szAT17Type == AT17LVC256)
        return TT_BYTE_AT17LVC256;
    if(m_szAT17Type == AT17LVC512)
        return TT_BYTE_AT17LVC512;
    if(m_szAT17Type == AT17LVC010)
        return TT_BYTE_AT17LVC010;
    if(m_szAT17Type == AT17LVC002)
        return TT_BYTE_AT17LVC002;
    if(m_szAT17Type == AT17LVC040)
        return TT_BYTE_AT17LVC040;
    return TT_BYTE_UNKNOWN;
}
//Read full device memory by LPT interface
int AT17::_readFullLPT()
{
    unsigned long byte;
    if(!m_bFirmAlloc)
    {
        m_pFirmData = new QVector<unsigned long>(getSize()+1);
        m_bFirmAlloc = true;
    }
    m_pFirmData->fill(0x00FF);
    if(m_szAT17Type == AT17LVC65 || m_szAT17Type == AT17LVC128 || m_szAT17Type == AT17LVC256)
    {
        m_pI2C->startCondition();
        if(m_pI2C->sendByte(0xA6) != I2C_ACK) {emit readError(); return READ_ERROR;}
        if(m_pI2C->sendByte(0x00) != I2C_ACK) {emit readError(); return READ_ERROR;}
        if(m_pI2C->sendByte(0x00) != I2C_ACK) {emit readError(); return READ_ERROR;}
        m_pI2C->startCondition();
        if(m_pI2C->sendByte(0xA7) != I2C_ACK) {emit readError(); return READ_ERROR;}
        for(int i=0;i<getSize();i++)
        {
            if(m_bProgRun)
                byte = m_pI2C->recvByte(1) & 0x00FF;
            else
                return 0;
            (*m_pFirmData)[i] = byte;
            emit progStatus(i);
        }
        byte = m_pI2C->recvByte(0) & 0x00FF;
        (*m_pFirmData)[getSize()] = byte;
        m_pI2C->stopCondition();
    }
    else
    {
        m_pI2C->startCondition();
        if(m_pI2C->sendByte(0xA6) != I2C_ACK) {emit readError(); return READ_ERROR;}
        if(m_pI2C->sendByte(0x00) != I2C_ACK) {emit readError(); return READ_ERROR;}
        if(m_pI2C->sendByte(0x00) != I2C_ACK) {emit readError(); return READ_ERROR;}
        if(m_pI2C->sendByte(0x00) != I2C_ACK) {emit readError(); return READ_ERROR;}
        m_pI2C->startCondition();
        if(m_pI2C->sendByte(0xA7) != I2C_ACK) {emit readError(); return READ_ERROR;}
        for(int i=0;i<getSize();i++)
        {
            if(m_bProgRun)
                byte = m_pI2C->recvByte(1) & 0x00FF;
            else
                return 0;
            (*m_pFirmData)[i] = byte;
            emit progStatus(i);
        }
        byte = m_pI2C->recvByte(0) & 0x00FF;
        (*m_pFirmData)[getSize()] = byte;
        m_pI2C->stopCondition();
    }
    return 0;
}
//Read full main function
int AT17::_readFull()
{
    powerOn();
    QThread::msleep(25);
    int res;
    if(m_szInterfaceType == "LPT_I2C")//I2C bus protocol over LPT
       res = _readFullLPT();
    QThread::msleep(25);
    powerOff();
    if(res)
        return res; //if result not null return Last Error
    else
        emit readDone();//if Last Error = 0 then emit readDone signal
    return res;
}
//Read burst wasn't implemented yet
int AT17::_readBurst(int nAddrFrom,int nNumWords)
{
    QList<unsigned long>m_m_readBuffer;
    return READ_OK;
}
//Read from page wasn't implemented yet
int AT17::_readFromPage(int nPage,int nAddrFrom,int nAddrTo)
{
    QList<unsigned long>m_m_readBuffer;
    return READ_OK;
}
//Read pages wasn't implemented yet
int AT17::_readPages(int nPageFrom,int nPageTo)
{
    QList<unsigned long>m_m_readBuffer;
    return READ_OK;
}
//Read Word auxiliary method for configuration memory programming
unsigned long AT17::readWord(int nAddr)
{
    char byte;
    QThread::msleep(25);//pause 25 ms
    powerOn();//VCC in logic 1
    m_pI2C->startCondition();//Start condition signal
    if(m_szAT17Type == AT17LVC65 || m_szAT17Type == AT17LVC128 || m_szAT17Type == AT17LVC256)
    {
        if(m_pI2C->sendByte(0xA6) != I2C_ACK) return I2C_ERROR;
        if(m_pI2C->sendByte(nAddr >> 8) != I2C_ACK) return I2C_ERROR;
        if(m_pI2C->sendByte(nAddr) != I2C_ACK) return I2C_ERROR;
        m_pI2C->startCondition();
        m_pI2C->sendByte(0xA7);//Send device's address with read request bit
        byte = m_pI2C->recvByte(0);//get byte with ACK = 1 (last byte)
    }
    else //All the same for another device types
    {
        if(m_pI2C->sendByte(0xA6) != I2C_ACK) return I2C_ERROR;
        if(m_pI2C->sendByte(nAddr >> 16) != I2C_ACK) return I2C_ERROR;
        if(m_pI2C->sendByte(nAddr >> 8) != I2C_ACK) return I2C_ERROR;
        if(m_pI2C->sendByte(nAddr) != I2C_ACK) return I2C_ERROR;
        m_pI2C->startCondition();
        m_pI2C->sendByte(0xA7);
        byte = m_pI2C->recvByte(0);
    }
    m_pI2C->stopCondition();
    powerOff();
    QThread::msleep(25);
    return byte;
}
//Read device memory page functionality not realized yet
int AT17::_readPage(int nPage)
{
    QList<unsigned long>m_m_readBuffer;
    return READ_OK;
}
//Write full from LPT port not used yet
int AT17::_writeFullLPT()
{
   /* if(m_szAT17Type == AT17LVC65 || m_szAT17Type == AT17LVC128 || m_szAT17Type == AT17LVC256)
    {
        m_pI2C->startCondition();
        if(m_pI2C->sendByte(0xA6) != I2C_ACK) {emit writeError(); return I2C_ERROR;}
        if(m_pI2C->sendByte(0x00) != I2C_ACK) {emit writeError(); return I2C_ERROR;}
        if(m_pI2C->sendByte(0x00) != I2C_ACK) {emit writeError(); return I2C_ERROR;}
        for(int nAddr=0;nAddr<getSize();nAddr++)
        {
            if(m_pI2C->sendByte((unsigned char)(*m_pFirmData)[nAddr]) != I2C_ACK) {emit writeError(); return I2C_ERROR;}
            emit progStatus(nAddr);
        }
        m_pI2C->stopCondition();
        return WRITE_OK;
    }
    if(m_szAT17Type == AT17LVC512 || m_szAT17Type == AT17LVC010)
    {
        m_pI2C->startCondition();
        if(m_pI2C->sendByte(0xA6) != I2C_ACK) {emit writeError(); return I2C_ERROR;}
        if(m_pI2C->sendByte(0x00) != I2C_ACK) {emit writeError(); return I2C_ERROR;}
        if(m_pI2C->sendByte(0x00) != I2C_ACK) {emit writeError(); return I2C_ERROR;}
        if(m_pI2C->sendByte(0x00) != I2C_ACK) {emit writeError(); return I2C_ERROR;}
        for(int nAddr=0;nAddr<getSize();nAddr++)
        {
            if(m_pI2C->sendByte((unsigned char)(*m_pFirmData)[nAddr]) != I2C_ACK) {emit writeError(); return I2C_ERROR;}
            emit progStatus(nAddr);
        }
        m_pI2C->stopCondition();
        return WRITE_OK;
    }
    if(m_szAT17Type == AT17LVC002 || m_szAT17Type == AT17LVC040)
    {
        m_pI2C->startCondition();
        if(m_pI2C->sendByte(0xA6) != I2C_ACK) {emit writeError(); return I2C_ERROR;}
        if(m_pI2C->sendByte(0x00) != I2C_ACK) {emit writeError(); return I2C_ERROR;}
        if(m_pI2C->sendByte(0x00) != I2C_ACK) {emit writeError(); return I2C_ERROR;}
        if(m_pI2C->sendByte(0x00) != I2C_ACK) {emit writeError(); return I2C_ERROR;}
        for(int nAddr=0;nAddr<getSize();nAddr++)
        {
            if(m_pI2C->sendByte((unsigned char)(*m_pFirmData)[nAddr]) != I2C_ACK) {emit writeError(); return I2C_ERROR;}
            emit progStatus(nAddr);
        }
        m_pI2C->stopCondition();
        return WRITE_OK;
    }*/
    return WRITE_OK;
}
//Write to device full memory functionality
int AT17::_writeFull()
{
    powerOn();//Turn on AT17 device
    QThread::msleep(25);//Wait 25 ms
    if(m_szInterfaceType == "LPT_I2C") //I2C over LPT programmer's interface
    {
        for(int i=0;i<((*m_pFirmData).size()/getPageSize());i++)
        {
            QThread::msleep(25);//wait
            int res = this->_writeToPage(i,0,getPageSize());//write in memory page of device
            if(res == WRITE_ERROR || res == I2C_ERROR)
            {
                emit writeError();//in wrong result case emit signal
                return WRITE_ERROR;
            }
            if(res == PROG_TERMINATE) //If programming was terminated by user (for example: pressing button)
            {
                QThread::msleep(25);
                powerOff();//Turn off power of AT17 device
                emit writeDone(); //write done signal
                return WRITE_OK;
            }
        }
    }
    emit writeDone(); //write done signal
    QThread::msleep(25);
    powerOff();//Turn off power of AT17
    return WRITE_OK;
}
//Write in AT17 memory page
int AT17::_writeToPage(int nPage,int nAddrFrom,int nAddrTo)
{
    if(m_szAT17Type == AT17LVC65 || m_szAT17Type == AT17LVC128 || m_szAT17Type == AT17LVC256)
    {
        m_pI2C->startCondition();
        if(m_pI2C->sendByte(0xA6) != I2C_ACK) return I2C_ERROR;
        if(m_pI2C->sendByte(((nPage << 6) & 0x00FF00) >> 8) != I2C_ACK) return I2C_ERROR;//Send page address via
        if(m_pI2C->sendByte((nPage << 6) & 0x0000FF) != I2C_ACK) return I2C_ERROR;//I2C bus
        int begin = ((nPage<<6)|nAddrFrom);//starting address to write in page
        int end = ((nPage<<6)|(nAddrTo-1));//ending address to write in page
        for(int nAddr=begin;nAddr<=end;nAddr++)
        {
            if(m_bProgRun)//is program process is running
            {   //Send data byte via I2C bus to device page or emit writeError if something wrong
                if(m_pI2C->sendByte((unsigned char)(*m_pFirmData)[nAddr]) != I2C_ACK) {emit writeError(); return I2C_ERROR;}
                emit progStatus(nAddr);//Programming status progress
            }
            else
            {
                return PROG_TERMINATE;//terminate programming process by user
            }
        }
        m_pI2C->stopCondition();
        return WRITE_OK;
    }
    if(m_szAT17Type == AT17LVC512 || m_szAT17Type == AT17LVC010)
    {
        m_pI2C->startCondition();
        if(m_pI2C->sendByte(0xA6) != I2C_ACK) return I2C_ERROR;
        if(m_pI2C->sendByte(((nPage << 7) & 0xFF0000) >> 16) != I2C_ACK) return I2C_ERROR;//Send page address n-bit length
        if(m_pI2C->sendByte(((nPage << 7) & 0x00FF00) >> 8) != I2C_ACK) return I2C_ERROR;//apropriate for this
        if(m_pI2C->sendByte((nPage << 7) & 0x0000FF) != I2C_ACK) return I2C_ERROR;//device type
        int begin = ((nPage<<7)|nAddrFrom);
        int end = ((nPage<<7)|(nAddrTo-1));
        for(int nAddr=begin;nAddr<=end;nAddr++)
        {
            if(m_bProgRun)
            {
                if(m_pI2C->sendByte((unsigned char)(*m_pFirmData)[nAddr]) != I2C_ACK) {emit writeError(); return I2C_ERROR;}
                emit progStatus(nAddr);
            }
            else
            {
                return PROG_TERMINATE;
            }
        }
        m_pI2C->stopCondition();
        return WRITE_OK;
    }
    if(m_szAT17Type == AT17LVC002 || m_szAT17Type == AT17LVC040)
    {
        m_pI2C->startCondition();
        if(m_pI2C->sendByte(0xA6) != I2C_ACK) return I2C_ERROR;
        if(m_pI2C->sendByte(((nPage << 8) & 0xFF0000) >> 16) != I2C_ACK) return I2C_ERROR;//All the same but
        if(m_pI2C->sendByte(((nPage << 8) & 0x00FF00) >> 8) != I2C_ACK) return I2C_ERROR;//another page address
        if(m_pI2C->sendByte((nPage << 8) & 0x0000FF) != I2C_ACK) return I2C_ERROR; //length
        int begin = ((nPage<<8)|nAddrFrom);
        int end = ((nPage<<8)|(nAddrTo-1));
        for(int nAddr=begin;nAddr<=end;nAddr++)
        {
            if(m_bProgRun)
            {
                if(m_pI2C->sendByte((unsigned char)(*m_pFirmData)[nAddr]) != I2C_ACK) {emit writeError(); return I2C_ERROR;}
                emit progStatus(nAddr);
            }
            else
            {
                return PROG_TERMINATE;
            }
        }
        m_pI2C->stopCondition();
        return WRITE_OK;
    }
    return WRITE_ERROR;//Write error if device's type is wrong
}
//Temporary not reimplemented function
int AT17::_writePages(int nPageFrom,int nPageTo)
{
    return 0;
}
//Write word auxiliary function
int AT17::writeWord(int nAddr, unsigned long word)
{
    QThread::msleep(25);//wait 25 ms
    powerOn();//Turn on AT17
    m_pI2C->startCondition();
    if(m_szAT17Type == AT17LVC65 || m_szAT17Type == AT17LVC128 || m_szAT17Type == AT17LVC256)
    {
        std::cout << m_szAT17Type.toStdString() << std::endl;
        std::cout << std::hex << nAddr << " " << (nAddr >> 8) << " " << word << std::endl;
        if(m_pI2C->sendByte(0xA6) != I2C_ACK) return I2C_ERROR;//I2C address with Write bit set
        if(m_pI2C->sendByte(nAddr >> 8) != I2C_ACK) return I2C_ERROR;//Memory address
        if(m_pI2C->sendByte(nAddr) != I2C_ACK) return I2C_ERROR;
        if(m_pI2C->sendByte((unsigned char)word) != I2C_ACK) return I2C_ERROR;
        std::cout << "Write succeeded!" << std::endl;
    }
    else
    {
        if(m_pI2C->sendByte(0xA6) != I2C_ACK) return I2C_ERROR; //All the same
        if(m_pI2C->sendByte(nAddr >> 16) != I2C_ACK) return I2C_ERROR;
        if(m_pI2C->sendByte(nAddr >> 8) != I2C_ACK) return I2C_ERROR;
        if(m_pI2C->sendByte(nAddr) != I2C_ACK) return I2C_ERROR;
        if(m_pI2C->sendByte(word) != I2C_ACK) return I2C_ERROR;
    }
    m_pI2C->stopCondition();
    powerOff();
    QThread::msleep(25);;//Turn off AT17
    return WRITE_OK;
}
//Temporary not reimplemented function
int AT17::_writePage(int nPage)
{
    return 0;
}
//Temporary not reimplemented function
///TODO: Address boundary check !!!!!
int AT17::_writeBurst(int nAddrFrom, int nNumWords)
{
    /*QThread::msleep(25);
    powerOn();
    //Q_ASSERT_X(nNumWords - nAddrFrom < getPageSize(),"Address out of page","Address greater than page size");
    if(m_szAT17Type == AT17LVC65 || m_szAT17Type == AT17LVC128 || m_szAT17Type == AT17LVC256)
    {
        if(m_szInterfaceType == "LPT_I2C")
        {
            m_pI2C->startCondition();
            if(m_pI2C->sendByte(0xA6) != I2C_ACK) return I2C_ERROR;
            if(m_pI2C->sendByte((nAddrFrom & 0x00FFFF) >> 8) != I2C_ACK) return I2C_ERROR;
            if(m_pI2C->sendByte(nAddrFrom & 0x00FFFF) != I2C_ACK) return I2C_ERROR;
            std::cout << (nAddrFrom & 0x00FFFF) << std::endl;
            int begin = nAddrFrom;
            int end = nAddrFrom+nNumWords - 1;
            std::cout << begin << end << std::endl;
            for(int nAddr=begin,i=0;nAddr<=end;i++,nAddr++)
            {
                if(m_pI2C->sendByte((unsigned char)(*m_pFirmData)[i]) != I2C_ACK) return I2C_ERROR;
            }
            m_pI2C->stopCondition();
            return WRITE_OK;
        }
        return WRITE_ERROR;
    }
    if(m_szAT17Type == AT17LVC512 || m_szAT17Type == AT17LVC010)
    {
        if(m_szInterfaceType == "LPT_I2C")
        {
            m_pI2C->startCondition();
            if(m_pI2C->sendByte(0xA6) != I2C_ACK) return I2C_ERROR;
            if(m_pI2C->sendByte((nAddrFrom & 0xFFFFFF) >> 16) != I2C_ACK) return I2C_ERROR;///address less than 0xFFFFFF !!!!
            if(m_pI2C->sendByte((nAddrFrom & 0xFFFFFF) >> 8) != I2C_ACK) return I2C_ERROR;
            if(m_pI2C->sendByte(nAddrFrom & 0xFFFFFF) != I2C_ACK) return I2C_ERROR;
            int begin = nAddrFrom;
            int end = nAddrFrom+nNumWords - 1;
            std::cout << (nAddrFrom & 0xFFFFFF) << " " <<  ((nAddrFrom & 0xFFFFFF) >> 8) << " " <<  ((nAddrFrom & 0xFFFFFF) >> 16) << std::endl;
            std::cout << begin << " " << end << std::endl;
            for(int nAddr=begin,i=0;nAddr<=end;i++,nAddr++)
            {
                std::cout << i << " " << (*m_pFirmData)[i] << std::endl;
                if(m_pI2C->sendByte((unsigned char)(*m_pFirmData)[i]) != I2C_ACK) return I2C_ERROR;
            }
            m_pI2C->stopCondition();
            return WRITE_OK;
        }
        return WRITE_ERROR;
    }
    if(m_szAT17Type == AT17LVC002 || m_szAT17Type == AT17LVC040)
    {
        if(m_szInterfaceType == "LPT_I2C")
        {
            m_pI2C->startCondition();
            if(m_pI2C->sendByte(0xA6) != I2C_ACK) return I2C_ERROR;
            if(m_pI2C->sendByte((nAddrFrom & 0xFFFFFF) >> 16) != I2C_ACK) return I2C_ERROR;///address less than 0xFFFFFF !!!!
            if(m_pI2C->sendByte((nAddrFrom & 0xFFFFFF) >> 8) != I2C_ACK) return I2C_ERROR;
            if(m_pI2C->sendByte(nAddrFrom & 0xFFFFFF) != I2C_ACK) return I2C_ERROR;
            int begin = nAddrFrom;
            int end = nAddrFrom+nNumWords;
            for(int nAddr=begin,i=0;nAddr<=end;i++,nAddr++)
            {
                if(m_pI2C->sendByte((unsigned char)(*m_pFirmData)[nAddr]) != I2C_ACK) return I2C_ERROR;
            }
            m_pI2C->stopCondition();
            return WRITE_OK;
        }
        return WRITE_ERROR;
    }
    powerOff();
    QThread::msleep(25);*/
    return WRITE_OK;
}
//Write DCLK direction (from AT17 device or from Master device like FPGA)
int AT17::writeDCLKDirection(bool bDirection)
{
    if(bDirection) //0 (0x00) - DCLK from Master device (internal DCLK in device - off)
    {
        if(this->writeWord(0x380000,0x00) == I2C_ERROR) return WRITE_ERROR; //use our auxiliary
    }
    else //1 (0xFF) - DCLK sends from AT17 device
    {
        if(this->writeWord(0x380000,0xFF) == I2C_ERROR) return WRITE_ERROR;//write in configuration memory
    }
    return WRITE_OK;
}
//Write RESET signal polarity for AT17 device (active Low or High)
int AT17::writeResetPolarity(bool bPolarity)
{
    DeviceSignals devSgnl;
    if(m_szAT17Type == AT17LVC65 || m_szAT17Type == AT17LVC128 || m_szAT17Type == AT17LVC256)
    {
        if(bPolarity) //RESET active HIGH & OE active LOW
        {
            powerOn();
            devSgnl.pin1 = 0;//initial device pins setup
            devSgnl.pin2 = 0;
            devSgnl.pin3 = 0;
            devSgnl.pin4 = 1;//nCS high
            devSgnl.pin5 = 0;//empty
            devSgnl.pin6 = 0;//empty
            devSgnl.pin7 = 0;
            devSgnl.pin8 = 1;//VCC
            setSignals(devSgnl);//set AT17 signals on its input
            QThread::msleep(25);//wait 25 ms
            this->writeWord(0x3FFF,0x00FF);//write word with signals we set
            devSgnl.pin1 = 0;
            devSgnl.pin2 = 0;
            devSgnl.pin3 = 0;
            devSgnl.pin4 = 0;//nCS low
            devSgnl.pin5 = 0;//empty
            devSgnl.pin6 = 0;//empty
            devSgnl.pin7 = 0;
            devSgnl.pin8 = 1;
            setSignals(devSgnl);//
            QThread::msleep(25);//wait 25 ms
            powerOff();
        }
        else //RESET active LOW & OE active HIGH
        {
            devSgnl.pin1 = 0;
            devSgnl.pin2 = 0;
            devSgnl.pin3 = 1;//RESET/OE high
            devSgnl.pin4 = 1;//nCS high
            devSgnl.pin5 = 0;//empty
            devSgnl.pin6 = 0;//empty
            devSgnl.pin7 = 0;
            devSgnl.pin8 = 1;
            setSignals(devSgnl);
            QThread::msleep(25);
            this->writeWord(0x3FFF,0x00FF);
            devSgnl.pin1 = 0;
            devSgnl.pin2 = 0;
            devSgnl.pin3 = 0;//RESET/OE low
            devSgnl.pin4 = 0;//nCS low
            devSgnl.pin5 = 0;//empty
            devSgnl.pin6 = 0;//empty
            devSgnl.pin7 = 0;
            devSgnl.pin8 = 1;
            setSignals(devSgnl);
            QThread::msleep(25);
            powerOff();
        }
    }
    else if(m_szAT17Type == AT17LVC512 || m_szAT17Type == AT17LVC010)
    {
        unsigned long bResByte0 = (unsigned char)this->readWord(0x020000);
        unsigned long bResByte1 = (unsigned char)this->readWord(0x020001);
        unsigned long bResByte2 = (unsigned char)this->readWord(0x020002);
        unsigned long bResByte3 = (unsigned char)this->readWord(0x020003);
        std::cout << bResByte0 << " " << bResByte1 << " " << bResByte2 << " " << bResByte3 << std::endl;
        if(bPolarity) //All the same but another methodics
        {
            if(this->writeWord(0x020000,0xFF) == I2C_ERROR) return WRITE_ERROR; //RESET active HIGH, OE active LOW
            if(this->writeWord(0x020001,0xFF) == I2C_ERROR) return WRITE_ERROR;
            if(this->writeWord(0x020002,0xFF) == I2C_ERROR) return WRITE_ERROR;
            if(this->writeWord(0x020003,0xFF) == I2C_ERROR) return WRITE_ERROR;
        }
        else
        {
            if(this->writeWord(0x020000,0x00) == I2C_ERROR) return WRITE_ERROR; //RESET active LOW, OE active HIGH
            if(this->writeWord(0x020001,0x00) == I2C_ERROR) return WRITE_ERROR;
            if(this->writeWord(0x020002,0x00) == I2C_ERROR) return WRITE_ERROR;
            if(this->writeWord(0x020003,0x00) == I2C_ERROR) return WRITE_ERROR;
        }
        /////Verify RESET Polarity (OPTIONAL yet)
        bResByte0 = (unsigned char)this->readWord(0x020000);
        bResByte1 = (unsigned char)this->readWord(0x020001);
        bResByte2 = (unsigned char)this->readWord(0x020002);
        bResByte3 = (unsigned char)this->readWord(0x020003);
        std::cout << bResByte0 << " " << bResByte1 << " " << bResByte2 << " " << bResByte3 << std::endl;
        devSgnl.pin1 = 0;
        devSgnl.pin2 = 0;
        devSgnl.pin3 = 0;
        devSgnl.pin4 = 1;
        devSgnl.pin5 = 0;//empty
        devSgnl.pin6 = 0;//empty
        devSgnl.pin7 = 1;
        devSgnl.pin8 = 0;
        setSignals(devSgnl);
        if(bPolarity)
            return (bResByte3 == bResByte2 == bResByte1 == bResByte0 == 0xFF) ? WRITE_OK : WRITE_ERROR;
        else
            return (bResByte3 == bResByte2 == bResByte1 == bResByte0 == 0x00) ? WRITE_OK : WRITE_ERROR;
    }
    else if(m_szAT17Type == AT17LVC002 || m_szAT17Type == AT17LVC040)
    {
        if(bPolarity) //All the same for another device types
        {
            if(this->writeWord(0x400000,0xFF) == I2C_ERROR) return WRITE_ERROR;
            if(this->writeWord(0x400001,0xFF) == I2C_ERROR) return WRITE_ERROR;
            if(this->writeWord(0x400002,0xFF) == I2C_ERROR) return WRITE_ERROR;
            if(this->writeWord(0x400003,0xFF) == I2C_ERROR) return WRITE_ERROR;
        }
        else
        {
            if(this->writeWord(0x400000,0x00) == I2C_ERROR) return WRITE_ERROR;
            if(this->writeWord(0x400001,0x00) == I2C_ERROR) return WRITE_ERROR;
            if(this->writeWord(0x400002,0x00) == I2C_ERROR) return WRITE_ERROR;
            if(this->writeWord(0x400003,0x00) == I2C_ERROR) return WRITE_ERROR;
        }
        /////Verify RESET Polarity
        bool bResByte0 = this->readWord(0x400000);
        bool bResByte1 = this->readWord(0x400001);
        bool bResByte2 = this->readWord(0x400002);
        bool bResByte3 = this->readWord(0x400003);
        devSgnl.pin1 = 0;
        devSgnl.pin2 = 0;
        devSgnl.pin3 = 0;
        devSgnl.pin4 = 1;
        devSgnl.pin5 = 0;//empty
        devSgnl.pin6 = 0;//empty
        devSgnl.pin7 = 1;
        devSgnl.pin8 = 0;
        setSignals(devSgnl);
        if(bPolarity)
            return (bResByte3 == bResByte2 == bResByte1 == bResByte0 == 0xFF) ? WRITE_OK : WRITE_ERROR;
        else
            return (bResByte3 == bResByte2 == bResByte1 == bResByte0 == 0x00) ? WRITE_OK : WRITE_ERROR;
    }
    return WRITE_OK;
}
//Setup interface by UI controls
QString AT17::setupInterface(UControlBase* pControlBase)
{
    if(m_szInterfaceType == "LPT_I2C") //I2C bus protocol over LPT port
    {
        bool ok;
        if(pControlBase->lineEditValue(0).length() > 4 || pControlBase->lineEditValue(0).toUInt(&ok,16) == 0)
            return SETUP_INTERFACE_WRONG_ADDRESS_LPT; //Get line edit value from UI
        m_parallelPort.setAddress(pControlBase->lineEditValue(0).toUInt(&ok,16));//Set LPT port address by UI line edit control
        m_pI2C = new I2CLPT(&m_parallelPort,&m_parallelDataOut,&m_parallelDataIn);//I2C_LPT version of I2C interface
    }
    return QString("");
}
//Write all configurations into AT17 configuration memory
void AT17::writeConfiguration(UControlBase* pControlBase)
{
    writeResetPolarity(pControlBase->radioButtonValue(0));//RESET/OE polarity signal
    if(getType() == AT17LVC512 || getType() == AT17LVC010 || getType() == AT17LVC040 || getType() == AT17LVC002 )
    {
        writeDCLKDirection(pControlBase->radioButtonValue(1));//DCLK direction not on all Devices exists
    }
}
//Full erasing of device (but not used yet)
int AT17::_eraseFull()
{
    QList<unsigned long>fwNullData;
    for(int i =0;i<getSize();i++)
        fwNullData.append(0xFFFFFFFF);
    //writeFull(&fwNullData);
    return WRITE_OK;
}
//Temporary not reimplemented function
int AT17::_eraseBurst(int nAddrFrom,int nNumWords)
{
    return 0;
}
//Temporary not reimplemented function
int AT17::_eraseToPage(int nPage,int nAddrFrom,int nAddrTo)
{
    return 0;
}
//Temporary not reimplemented function
int AT17::_erasePages(int nPageFrom,int nPageTo)
{
    return 0;
}
//Temporary auxiliary not realized function
int AT17::eraseWord(int nAddr)
{
    return 0;
}
//Temporary not reimplemented function
int AT17::_erasePage(int nPage)
{
    return 0;
}
//Programming state machine controls programming process
void AT17::progRun()
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
void AT17::progAbort()
{
    m_bProgRun = false;
}


