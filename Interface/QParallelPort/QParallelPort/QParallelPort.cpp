/*###################################################################*/
/*######################====QPARALLELPORT====########################*/
/*###################################################################*/
/*Description:
    QParallelPort library wraps using QT libraries low-level parallel
    port io libraries on various operating systems such as Linux & Window
*/
#include "QParallelPort.h"
//For windows version we use inpout.dll library, for linux - sys/io
#ifdef _WIN32
#include <C:/QTCreator/inpout32/inpout32.h>
#elif __linux__
#include <sys/io.h>
#endif

#include <QDebug>
//Set parallel port address by default
QParallelPort::QParallelPort()
{
    m_nBaseAddress = 0x0378;
}
//Set parallel port address by user
QParallelPort::QParallelPort(short int baseAddress)
{
    m_nBaseAddress = baseAddress;
}
//copy, reserved
QParallelPort::QParallelPort(QParallelPort&)
{

}
//cleanup
QParallelPort::~QParallelPort()
{

}
//Set parallel port address by user (separate function)
void QParallelPort::setAddress(short baseAddress)
{
    m_nBaseAddress = baseAddress;
}
//Windows version of parallel port functions
#ifdef _WIN32
//Read from LPT port in Windows
QParallelDataIn QParallelPort::read()
{
    m_nData = Inp32(m_nBaseAddress);//inpout.dll function
    m_nStatus = Inp32(m_nBaseAddress + 1);//
    QParallelDataIn parallelDataIn;
    for(int i=0;i<PARPORT_DATA_LEN;i++)
        parallelDataIn.data[i] = (m_nData & (1 << i)) >> i; //read from DATA pins
    parallelDataIn.ack = (m_nStatus & (1 << 6)) >> 6; //read from ACK pin
    parallelDataIn.busy = (m_nStatus & (1 << 7)) >> 7; //read from BUSY pin
    parallelDataIn.error = (m_nStatus & (1 << 3)) >> 3; //read from ERROR pin
    parallelDataIn.pe = (m_nStatus & (1 << 5)) >> 5; //read from PE pin
    parallelDataIn.sel = (m_nStatus & (1 << 4)) >> 4; //read from SEL pin
    return parallelDataIn; //input structure
}
//Write into LPT port in Windows
int QParallelPort::write(QParallelDataOut* pParallelDataOut)
{
    short int data = 0;
    short int status = 0;
    for(int i=0;i<PARPORT_DATA_LEN;i++)
        data |= (pParallelDataOut->data[i] << i); //write on DATA pins from structure
    status |= pParallelDataOut->autolf << 1; //write on AUTOLF pin from structure
    status |= pParallelDataOut->init << 2; //write on INIT pin from structure
    status |= pParallelDataOut->selin << 3; //write on SELIN pin from structure
    status |= pParallelDataOut->strobe << 0; //write on STROBE pin from structure
    Out32(m_nBaseAddress,data); //inpout.dll frunction
    Out32(m_nBaseAddress + 1,status);//
    return PARPORT_OK;
}
//Linux version of parallel port functions
#elif __linux__
//Read from LPT port in Linux
QParallelDataIn QParallelPort::read()
{
   // if(/*ioperm(m_nBaseAddress,3,1)*/iopl(3))
    //{
        iopl(3); //UPROG app must be run with SUDO !!!
        m_nData = inb(m_nBaseAddress); //receive all 16-bit data from LPT controller DATA register
        m_nStatus = inb(m_nBaseAddress + 1); //receive all 16-bit status from LPT controller STATUS register
    //}
    /*else
    {
        return PARPORT_FAIL;
    }*/
    QParallelDataIn parallelDataIn;
    for(int i=0;i<PARPORT_DATA_LEN;i++) //decode all received data into input structure
        parallelDataIn.data[i] = (m_nData & (1 << i)) >> i;
    parallelDataIn.ack = (m_nStatus & (1 << 6)) >> 6;
    parallelDataIn.busy = (m_nStatus & (1 << 7)) >> 7;
    parallelDataIn.error = (m_nStatus & (1 << 3)) >> 3;
    parallelDataIn.pe = (m_nStatus & (1 << 5)) >> 5;
    parallelDataIn.sel = (m_nStatus & (1 << 4)) >> 4;
    return parallelDataIn;
}
//Write into LPT port in Linux
int QParallelPort::write(QParallelDataOut* pParallelDataOut)
{
    short int data = 0;
    short int status = 0;
    for(int i=0;i<PARPORT_DATA_LEN;i++) //fill status & data values with structure fields
        data |= (pParallelDataOut->data[i] << i);
    status |= pParallelDataOut->autolf << 1;
    status |= pParallelDataOut->init << 2;
    status |= pParallelDataOut->selin << 3;
    status |= pParallelDataOut->strobe << 0;
    //if(/*ioperm(m_nBaseAddress,3,1)*/iopl(3))
    //{
        iopl(3);//UPROG app must be run with SUDO !!!
        outb(data,m_nBaseAddress); //Send data and status values to appropriate registers
        outb(status,m_nBaseAddress + 1);//
        return PARPORT_OK;
    //}
    //else
    //{
        return PARPORT_FAIL;
    //}
}

#endif
