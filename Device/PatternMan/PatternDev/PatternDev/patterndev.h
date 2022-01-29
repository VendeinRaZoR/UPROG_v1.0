/*################################################################*/
/*######################====PATTERNDEV====########################*/
/*################################################################*/
/*Description:
    PATTERNDEV Device integral circuit programming class that
    reimplements methods of UProgBase programmer's class
*/
#ifndef PATTERNDEV_H
#define PATTERNDEV_H

#include "patterndev_global.h"
//#include "QParallelPort.h"
#include "../../../../UProgBase.h"
//#include "../../../UControlBase.h"
//#include "I2CLPT.h"

class PATTERNDEVSHARED_EXPORT PatternDev : public UProgBase
{
    Q_OBJECT
    /*I2C *m_pI2C; //I2C bus protocol object of abstract I2C class
    QParallelPort m_parallelPort;//LPT port object
    QParallelDataOut m_parallelDataOut;//LPT output signals
    QParallelDataIn m_parallelDataIn;//LPT input signals*/
    DeviceInfo m_devInfo; //Device info structure object
    QString m_szPatterDevType; //Currect PatternDev device type of current manufacture & series
    QString m_szInterfaceType; //Currect Interface type such as LPT (or others, in future)
    bool m_bResPolarity;//RESET pin polarity of PatternDev device (in configuration memory)
    bool m_bFirmAlloc;//Firmware data allocation indicator
    bool m_bProgRun;//Programming process running indicator
    QVector<unsigned long> *m_pFirmData;//Firmware data pointer
public:
    PatternDev(QString szDeviceType,QString szInterfaceType);//init
    ~PatternDev();//cleanup
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
    int writeResetPolarity(bool bPolarity);//Additional PatternDev functionality auxiliary functions
    int writeDCLKDirection(bool bDirection);//that is used to program configuration PatternDev memory
private:
    //int _readFullLPT();//_readFull function extension for LPT port programming
    //int _writeFullLPT();//_writeFull function extension for LPT port programming
    //int _readFullCOM();//COM port (in future)
    //int _writeFullCOM();//COM port (in future)
public:
    int init(); //Initialize PatternDev device pins
    void powerOn(); //Turn on VCC pin of PatternDev device
    void powerOff(); //Turn off VCC pin of PatternDev device
    QVector<unsigned long> *getFirmware() const;//reimplementing
    QString getInterface() const;//reimplementing
    QString getType() const;//reimplementing
    DeviceInfo getInfo();//reimplementing
    DeviceSignals getSignals();//reimplementing
    int getNumPages() const;//reimplementing
    int getPageSize() const;//reimplementing
    int getSize() const;//reimplementing
    bool checkInfo() const;//Chekc PatternDev device info
    int setFirmware(QVector<unsigned long> *pFrimFile=0);//set firmware data pointer
    int deleteFirmware();//reserved but not used
    void setInterface(QString szInterfaceType);//set programmer's interface type
    void setType(QString szDeviceType);//set programmer's PatternDev device type
    void setSignals(DeviceSignals devSgnl);//reimplementing
    void writeConfiguration(UControlBase* pControlBase);//Write Device configs via UI
    QString setupInterface(UControlBase* pControlBase);//Write Interface configs via UI
    void progAbort();//Abort programming process
private:
    //int writeWord(int nAddr, unsigned long word);//auxiliary functions
    //unsigned long readWord(int nAddr);//maybe will be deleted in future
    //int eraseWord(int nAddr);//
public slots:
    void progRun();//Programming thread slot with state machine
};

#endif // PATTERNDEV_H
