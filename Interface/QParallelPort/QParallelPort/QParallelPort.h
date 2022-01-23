/*###################################################################*/
/*######################====QPARALLELPORT====########################*/
/*###################################################################*/
/*Description:
    QParallelPort library wraps using QT libraries low-level parallel
    port io libraries on various operating systems such as Linux & Window
*/
#ifndef QPARALLELPORT_H
#define QPARALLELPORT_H

#include "qparallelport_global.h"

#include <QDebug>

#define PARPORT_OK 1 //Results
#define PARPORT_FAIL 0

#define PARPORT_DATA_LEN 8 //Word len on parallel port data output

struct QParallelDataIn //Parallel port input signals in structure form
{
    bool busy;
    bool ack;
    bool sel;
    bool pe;
    bool error;
    char data[PARPORT_DATA_LEN];
};

struct QParallelDataOut //Parallel port output signals in structure form
{
    bool selin;
    bool init;
    bool autolf;
    bool strobe;
    char data[PARPORT_DATA_LEN];
};

class QPARALLELPORTSHARED_EXPORT QParallelPort
{
    short int m_nBaseAddress;
    short int m_nStatus;
    short int m_nData;
    short int m_nControl;
public:
    QParallelPort();//Set parallel port address by default
    QParallelPort(short int baseAddress);//Set parallel port address by user
    QParallelPort(QParallelPort&);//copy, reserved
    ~QParallelPort();//cleanup
public:
    QParallelDataIn read();//
    int write(QParallelDataOut*);//
    void setAddress(short int baseAddress);//
};

#endif // QPARALLELPORT_H
