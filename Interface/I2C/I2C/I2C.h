/*################################################################*/
/*##########################====I2C====###########################*/
/*################################################################*/
/*Description:
    I2C class contains I2C base interface with basic I2C functions
    not assigned to specific interface and for further implementation
*/
#ifndef I2C_H
#define I2C_H

#include "i2c_global.h"

#define I2C_ERROR 1 //ERROR value defines
#define I2C_ACK 0
#define I2C_NACK 1

class I2C
{
public:
    virtual void init() = 0; //initialization of I2C bus
    virtual void startCondition() = 0; //start condition signal on I2C bus
    virtual void stopCondition() = 0; //stop condition signal on I2C bus
    virtual bool sendByte(char byte) = 0; //send byte on I2C bus
    virtual char recvByte(bool bAck) = 0; //send
};

#endif // I2C_H
