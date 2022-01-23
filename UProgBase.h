/*###############################################################*/
/*######################====UPROGBASE====########################*/
/*###############################################################*/
/*Description:
UPROGBASE contains interface IUProg, base class of the programmer
like UProgBase, interface-controller IUProgCtrl with QT signals
and slots and many useful defines
*/
#ifndef UPROGBASE_H
#define UPROGBASE_H

#include <QVector>
#include <QString>
#include <QList>
#include <QObject>
#include <QMap>
#include "UControlBase.h"
#include <QDebug>

#define WRITE_UNSUPPORT -1//Helpful defines of return values
#define WRITE_OK 0 //but not properly used yet
#define WRITE_ERROR 1
#define READ_OK 0
#define READ_ERROR 1
#define PROG_TERMINATE 2

#define DEVICE_OK 1
#define DEVICE_FAIL 0

enum ProgState //states of programmer's state machine
{
    IDLE=0, //Initial state or waiting
    READ_FULL=1, //read full device memory state
    READ_FROM_PAGE, //read from device's memory page
    READ_PAGES, //read number of pages
    READ_BURST, //read number of words from start address
    READ_PAGE, //read one page
    WRITE_FULL, //write to whole device memory
    WRITE_TO_PAGE, //write into page from address1 to address2
    WRITE_PAGES, //write number of pages
    WRITE_BURST, //read number of words from start address
    WRITE_PAGE, //write one page
    ERASE_FULL, //full erasing of device memory
    ERASE_TO_PAGE, //erase in page from address1 to address2
    ERASE_PAGES, //erase number of pages
    ERASE_BURST, //erase number of words from start address
    ERASE_PAGE //erase one page
};

struct DeviceSignals //bits field to set particular device's pins
{
    unsigned pin1 : 1;
    unsigned pin2 : 1;
    unsigned pin3 : 1;
    unsigned pin4 : 1;
    unsigned pin5 : 1;
    unsigned pin6 : 1;
    unsigned pin7 : 1;
    unsigned pin8 : 1;
    unsigned pin9 : 1;
    unsigned pin10 : 1;
    unsigned pin11 : 1;
    unsigned pin12 : 1;
    unsigned pin13 : 1;
    unsigned pin14 : 1;
    unsigned pin15 : 1;
    unsigned pin16 : 1;
};

struct DeviceInfo //bits field with short description read from device
{
    unsigned byte0 : 8;
    unsigned byte1 : 8;
    unsigned byte2 : 8;
    unsigned byte3 : 8;
    unsigned byte4 : 8;
    unsigned byte5 : 8;
    unsigned byte6 : 8;
    unsigned byte7 : 8;
};

class IUProg //Base programmer's interface with useful methods
{
public:
    virtual int setFirmware(QVector<unsigned long> *pFrimFile=0)=0; //set firmware file data pointer
    virtual QVector<unsigned long> *getFirmware() const =0;//get firmware data pointer
    virtual int deleteFirmware() = 0;//Set empty firmware data
    virtual int init()=0;//Initialize device's interface bus and reset deviceinfo
    virtual void powerOn()=0;//Turn device's power pin to ON state
    virtual void powerOff()=0;//Turn device's power pin to OFF state
    virtual void setType(QString szDeviceType)=0;//Set device type of current manufacture and series
    virtual void setInterface(QString szInterfaceType)=0;//Set programmer's interface type (LPT, COM or other)
    virtual DeviceInfo getInfo()=0;//Get info from device memory to DeviceInfo structure
    virtual bool checkInfo() const =0;//Check received device info
    virtual QString getType() const =0;//get device type (name) string
    virtual QString getInterface() const =0;//get interface type (name) string
    virtual void readFull()=0;//Read full device's memory state
    virtual void readFromPage(int nPage,int nAddrFrom,int nAddrTo)=0;//
    virtual void readPages(int nPageFrom,int nPageTo)=0;//All state functions implements
    virtual void readBurst(int nAddrFrom,int nNumWords)=0;//without '_' in UProgBase class
    virtual unsigned long readWord(int nAddr)=0;//
    virtual void readPage(int nPage)=0;//
    virtual void writeFull()=0;//
    virtual void writeToPage(int nPage,int nAddrFrom,int nAddrTo)=0;//
    virtual void writePages(int nPageFrom,int nPageTo)=0;//
    virtual void writeBurst(int nAddrFrom,int nNumWords)=0;//
    virtual int writeWord(int nAddr,unsigned long word)=0;//
    virtual void writePage(int nPage)=0;//
    virtual void eraseFull()=0;//
    virtual void eraseToPage(int nPage,int nAddrFrom,int nAddrTo)=0;//
    virtual void erasePages(int nPageFrom,int nPageTo)=0;//
    virtual void eraseBurst(int nAddrFrom,int nNumWords)=0;//
    virtual int eraseWord(int nAddr)=0;//
    virtual void erasePage(int nPage)=0;//
    virtual int getNumPages() const =0;//Get number of device's pages
    virtual int getPageSize() const =0;//Get size of device's page
    virtual int getSize() const =0;//Get device's full memory size
    virtual void writeConfiguration(UControlBase* pControlBase)=0;//Write device's configuration memory
    virtual QString setupInterface(UControlBase* pControlBase)=0;//and setup device's interface via UI visitor class
    virtual void setSignals(DeviceSignals devSgnl)=0;//Set signals on device pins
    virtual DeviceSignals getSignals()=0;//Get signals on device pins in bit field form
    virtual int getLastError()=0;//Last error hapenned while programming or another programmer's process
protected: //Contains non-state functions with programmer's functionality
    virtual int _readFull()=0;//Read full functionality
    virtual int _readFromPage(int nPage,int nAddrFrom,int nAddrTo)=0;//functionality
    virtual int _readPages(int nPageFrom,int nPageTo)=0;//functionality
    virtual int _readBurst(int nAddrFrom,int nNumWords)=0;//All functions
    virtual int _readPage(int nPage)=0;//implements functionality
    virtual int _writeFull()=0;//analogue to state machine states
    virtual int _writeToPage(int nPage,int nAddrFrom,int nAddrTo)=0;//
    virtual int _writePages(int nPageFrom,int nPageTo)=0;//
    virtual int _writeBurst(int nAddrFrom,int nNumWords)=0;//
    virtual int _writePage(int nPage)=0;//
    virtual int _eraseFull()=0;//
    virtual int _eraseToPage(int nPage,int nAddrFrom,int nAddrTo)=0;//
    virtual int _erasePages(int nPageFrom,int nPageTo)=0;//
    virtual int _eraseBurst(int nAddrFrom,int nNumWords)=0;//
    virtual int _erasePage(int nPage)=0;//
};
//Programmer's controller interface (signals and slots)
class IUProgCtrl : public QObject
{
    Q_OBJECT
signals:
    void progStatus(int); //programming status (int progress)
    void writeDone(); //programmer write done signal
    void readDone(); //programmer read done signal
    void writeError(); //programmer error signal when writing device
    void readError(); //programmer error signal when reading device
    void error(int nLastError); //another programmer error signal like a undefined device
public slots:
    virtual void progRun()=0; //slot for QThread::started signal
};
//Base programmers class that includes IUProg and IUProgCtrl interfaces
//and contains inline functions for programmer's state machine
class UProgBase : public IUProg, public IUProgCtrl
{
protected:
    int m_nAddrFrom;
    int m_nAddrTo;
    int m_nAddr;
    int m_nPageFrom;
    int m_nPageTo;
    int m_nPage;
    int m_nNumWords;
    int m_nLastError;
    ProgState m_progState;
public:
    virtual void progAbort()=0;//Programming terminate (for example by pressing button)
public:
    //Last error returned from "_" prefix functions in programmer's state machine
    inline int getLastError()
    {
        return m_nLastError;
    }
    //Read full state function of programmer's state machine
    inline void readFull()
    {
        m_progState = READ_FULL;
    }
    //Read from page state funciton of programmer's state machine
    inline void readFromPage(int nPage,int nAddrFrom,int nAddrTo)
    {
        m_nPage = nPage;
        m_nAddrFrom = nAddrFrom;
        m_nAddrTo = nAddrTo;
        m_progState = READ_FROM_PAGE;
    }
    //Read pages state funciton of programmer's state machine
    inline void readPages(int nPageFrom,int nPageTo)
    {
        m_nPageFrom = nPageFrom;
        m_nPageTo = nPageTo;
        m_progState = READ_PAGES;
    }
    //Read burst state function of programmer's state machine
    inline void readBurst(int nAddrFrom,int nNumWords)
    {
        m_nAddrFrom = nAddrFrom;
        m_nNumWords = nNumWords;
        m_progState = READ_BURST;
    }
    //Read page state function of programmer's state machine
    inline void readPage(int nPage)
    {
        m_nPage = nPage;
        m_progState = READ_PAGE;
    }
    //Write full state function of programmer's state machine
    inline void writeFull()
    {
        m_progState = WRITE_FULL;
    }
    //Write to page state function of programmer's state machine
    inline void writeToPage(int nPage,int nAddrFrom,int nAddrTo)
    {
        m_nPage = nPage;
        m_nAddrFrom = nAddrFrom;
        m_nAddrTo = nAddrTo;
        m_progState = WRITE_TO_PAGE;
    }
    //Write pages state function of programmer's state machine
    inline void writePages(int nPageFrom,int nPageTo)
    {
        m_nPageFrom = nPageFrom;
        m_nPageTo = nPageTo;
        m_progState = WRITE_PAGES;
    }
    //Write burst state function of programmer's state machine
    inline void writeBurst(int nAddrFrom,int nNumWords)
    {
        m_nAddrFrom = nAddrFrom;
        m_nNumWords = nNumWords;
        m_progState = WRITE_BURST;
    }
    //Write page state function of programmer's state machine
    inline void writePage(int nPage)
    {
        m_nPage = nPage;
        m_progState = WRITE_PAGE;
    }
    //Erase full device memory state function of programmer's state machine
    inline void eraseFull()
    {
        m_progState = ERASE_FULL;
    }
    //Erase to page state
    inline void eraseToPage(int nPage,int nAddrFrom,int nAddrTo)
    {
        m_nPage = nPage;
        m_nAddrFrom = nAddrFrom;
        m_nAddrTo = nAddrTo;
        m_progState = ERASE_TO_PAGE;
    }
    //Erase pages state
    inline void erasePages(int nPageFrom,int nPageTo)
    {
        m_nPageFrom = nPageFrom;
        m_nPageTo = nPageTo;
        m_progState = ERASE_PAGES;
    }
    //Erase burst state
    inline void eraseBurst(int nAddrFrom,int nNumWords)
    {
        m_nAddrFrom = nAddrFrom;
        m_nNumWords = nNumWords;
        m_progState = ERASE_BURST;
    }
    //Erase page state
    inline void erasePage(int nPage)
    {
        m_nPage = nPage;
        m_progState = ERASE_PAGE;
    }

};

#endif
