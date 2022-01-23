/*###################################################################*/
/*##########################====I2CLPT====###########################*/
/*###################################################################*/
/*Description:
    I2CLPT class inherits from I2C abstract class and implements
    its methods for I2C bus on LPT port signals realization
*/
#ifndef I2CLPT_H
#define I2CLPT_H

#include "I2C.h"
#include "QParallelPort.h"

class I2CSHARED_EXPORT I2CLPT : public I2C
{
    short int m_nBaseAddress; //LPT base address
    QParallelPort *m_pParallelPort;
    QParallelDataOut *m_pParallelDataOut;
    QParallelDataIn *m_pParallelDataIn;
public:
    I2CLPT(QParallelPort *pParallelPort,QParallelDataOut *pParallelDataOut,QParallelDataIn *pParallelDataIn); //initialize I2C with LPT port
    virtual ~I2CLPT(); //cleanup
    void setPort(QParallelPort *pParallelPort,QParallelDataOut *pParallelDataOut,QParallelDataIn *pParallelDataIn); //set LPT interface
    void setSignals(QParallelDataOut *pParallelDataOut,QParallelDataIn *pParallelDataIn); //set LPT input & output signals
    void init(); //initialize I2C bus
    void startCondition(); //send start condition signal on I2C bus
    void stopCondition(); //send stop condition signal on I2C bus
    bool sendByte(char byte); //send byte on I2C bus
    char recvByte(bool bAck); //receive byte from I2C bus
};

#endif // I2CLPT_H
