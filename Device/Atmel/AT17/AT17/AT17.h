/*##########################################################*/
/*######################====AT17====########################*/
/*##########################################################*/
/*Description:
    AT17 Device integral circuit programming class that reimplements
    methods of UProgBase programmer's class
*/
#ifndef AT17_H
#define AT17_H

#include "at17_global.h"
#include "QParallelPort.h"
#include "../../../UProgBase.h"
#include "../../../UControlBase.h"
#include "I2CLPT.h"

#define TT_BYTE_UNKNOWN -1 //unknown AT17 type parameter
#define T_BYTE_UNKNOWN -1 //unknown AT17 type parameter
#define T_PAGE_UNKNOWN -1 //unknown AT17 type parameter
//AT17 Device Types
#define AT17LVC65 "AT17LV(C)65"
#define AT17LVC128 "AT17LV(C)128"
#define AT17LVC256 "AT17LV(C)256"
#define AT17LVC512 "AT17LV(C)512"
#define AT17LVC010 "AT17LV(C)010"
#define AT17LVC002 "AT17LV(C)002"
#define AT17LVC040 "AT17LV(C)040"
//AT17 device's memory sizes in bytes
#define TT_BYTE_AT17LVC65 8192
#define TT_BYTE_AT17LVC128 16384
#define TT_BYTE_AT17LVC256 32768
#define TT_BYTE_AT17LVC512 65536
#define TT_BYTE_AT17LVC010 131072
#define TT_BYTE_AT17LVC002 262144
#define TT_BYTE_AT17LVC040 524288
//AT17 device's memory page sizes in bytes
#define T_BYTE_AT17LVC65 64
#define T_BYTE_AT17LVC128 64
#define T_BYTE_AT17LVC256 64
#define T_BYTE_AT17LVC512 128
#define T_BYTE_AT17LVC010 128
#define T_BYTE_AT17LVC002 256
#define T_BYTE_AT17LVC040 256
//AT17 number of pages in device's memory
#define T_PAGE_AT17LVC65 128
#define T_PAGE_AT17LVC128 256
#define T_PAGE_AT17LVC256 512
#define T_PAGE_AT17LVC512 512
#define T_PAGE_AT17LVC010 1024
#define T_PAGE_AT17LVC002 1024
#define T_PAGE_AT17LVC040 2048
//Return string of Interface Setup result with universal error or warning message
#define SETUP_INTERFACE_WRONG_ADDRESS_LPT tr("Допустимое значение адреса LPT порта\n(Необходимый диапазон: от 1 до FFFF)")

class AT17SHARED_EXPORT AT17 : public UProgBase
{
    Q_OBJECT
    I2C *m_pI2C; //I2C bus protocol object of abstract I2C class
    QParallelPort m_parallelPort;//LPT port object
    QParallelDataOut m_parallelDataOut;//LPT output signals
    QParallelDataIn m_parallelDataIn;//LPT input signals
    DeviceInfo m_devInfo; //Device info structure object
    QString m_szAT17Type; //Currect AT17 device type of current manufacture & series
    QString m_szInterfaceType; //Currect Interface type such as LPT (or others, in future)
    bool m_bResPolarity;//RESET pin polarity of AT17 device (in configuration memory)
    bool m_bFirmAlloc;//Firmware data allocation indicator
    bool m_bProgRun;//Programming process running indicator
    QVector<unsigned long> *m_pFirmData;//Firmware data pointer
public:
    AT17(QString szDeviceType,QString szInterfaceType);//init
    ~AT17();//cleanup
private:
    int _readFull();//Reimplemented functionality of UProgBase's IUProg interface
    int _readFromPage(int nPage,int nAddrFrom,int nAddrTo);//reimplementing
    int _readPages(int nPageFrom,int nPageTo);//reimplementing
    int _readBurst(int nAddrFrom,int nNumWords);//reimplementing
    int _readPage(int nPage);//reimplementing
    int _writeFull();//reimplementing
    int _writeToPage(int nPage,int nAddrFrom,int nAddrTo);//reimplementing
    int _writePages(int nPageFrom,int nPageTo);//reimplementing
    int _writeBurst(int nAddrFrom,int nNumWords);//reimplementing
    int _writePage(int nPage);//reimplementing
    int _eraseFull();//reimplementing
    int _eraseToPage(int nPage,int nAddrFrom,int nAddrTo);//reimplementing
    int _erasePages(int nPageFrom,int nPageTo);//reimplementing
    int _eraseBurst(int nAddrFrom,int nNumWords);//reimplementing
    int _erasePage(int nPage);//reimplementing
private:
    int writeResetPolarity(bool bPolarity);//Additional AT17 functionality auxiliary functions
    int writeDCLKDirection(bool bDirection);//that is used to program configuration AT17 memory
private:
    int _readFullLPT();//_readFull function extension for LPT port programming
    int _writeFullLPT();//_writeFull function extension for LPT port programming
public:
    int init(); //Initialize AT17 device pins
    void powerOn(); //Turn on VCC pin of AT17 device
    void powerOff(); //Turn off VCC pin of AT17 device
    QVector<unsigned long> *getFirmware() const;//reimplementing
    QString getInterface() const;//reimplementing
    QString getType() const;//reimplementing
    DeviceInfo getInfo();//reimplementing
    DeviceSignals getSignals();//reimplementing
    int getNumPages() const;//reimplementing
    int getPageSize() const;//reimplementing
    int getSize() const;//reimplementing
    bool checkInfo() const;//Chekc AT17 device info
    int setFirmware(QVector<unsigned long> *pFrimFile=0);//set firmware data pointer
    int deleteFirmware();//reserved but not used
    void setInterface(QString szInterfaceType);//set programmer's interface type
    void setType(QString szDeviceType);//set programmer's AT17 device type
    void setSignals(DeviceSignals devSgnl);//reimplementing
    void writeConfiguration(UControlBase* pControlBase);//Write Device configs via UI
    QString setupInterface(UControlBase* pControlBase);//Write Interface configs via UI
    void progAbort();//Abort programming process
private:
    int writeWord(int nAddr, unsigned long word);//auxiliary functions
    unsigned long readWord(int nAddr);//maybe will be deleted in future
    int eraseWord(int nAddr);//
public slots:
    void progRun();//Programming thread slot with state machine
};

#endif // AT17_H
