/*###################################################################*/
/*##########################====I2CLPT====###########################*/
/*###################################################################*/
/*Description:
    I2CLPT class inherits from I2C abstract class and implements
    its methods for I2C bus on LPT port signals realization
*/
#include "I2CLPT.h"
//Initialize I2CLPT with LPT port
I2CLPT::I2CLPT(QParallelPort *pParallelPort,QParallelDataOut *pParallelDataOut,QParallelDataIn *pParallelDataIn)
{
    m_pParallelPort = pParallelPort;
    m_pParallelDataOut = pParallelDataOut;
    m_pParallelDataIn = pParallelDataIn;
}
//cleanup
I2CLPT::~I2CLPT()
{

}
//Set LPT port separate function
void I2CLPT::setPort(QParallelPort *pParallelPort,QParallelDataOut *pParallelDataOut,QParallelDataIn *pParallelDataIn)
{
    m_pParallelPort = pParallelPort;
    m_pParallelDataOut = pParallelDataOut;
    m_pParallelDataIn = pParallelDataIn;
}
//Set LPT port signals input & output
void I2CLPT::setSignals(QParallelDataOut *pParallelDataOut,QParallelDataIn *pParallelDataIn)
{
    m_pParallelDataOut = pParallelDataOut;
    m_pParallelDataIn = pParallelDataIn;
}
//Initialize I2C bus signals on LPT port
void I2CLPT::init()
{
    m_pParallelDataOut->autolf = 0; //LPT port AUTOLF signal
    m_pParallelDataOut->data[0] = 1; //SCK signal (DATA[0] LPT)
    m_pParallelDataOut->data[7] = 0; //SDA signal (DATA[7] LPT)
    m_pParallelDataOut->data[2] = 0; //DATA[2] LPT (any of DATA can be VCC)
    m_pParallelDataOut->data[4] = 0; //DATA[4] LPT
    m_pParallelDataOut->data[1] = 0; //DATA[1] LPT
    m_pParallelDataOut->data[3] = 0; //DATA[3] LPT
    m_pParallelDataOut->data[5] = 0; //DATA[5] LPT
    m_pParallelDataOut->data[6] = 0; //DATA[6] LPT
    m_pParallelDataOut->init = 0; //INIT LPT
    m_pParallelDataOut->selin = 0; //SELIN LPT
    m_pParallelDataOut->strobe = 0; //STROBE LPT
    m_pParallelPort->write(m_pParallelDataOut);//Initialize all LPT signals
}
//Start condition on I2C bus (SDA from 1 to 0 when SCL 1)
void I2CLPT::startCondition()
{
    m_pParallelDataOut->data[0] = 1;//DATA[0] : SCL signal
    m_pParallelDataOut->data[7] = 0;//DATA[7] : SDA signal
    m_pParallelPort->write(m_pParallelDataOut);
    m_pParallelDataOut->data[0] = 1;
    m_pParallelDataOut->data[7] = 0;
    m_pParallelPort->write(m_pParallelDataOut);
    ////////////SDA : 0 -> 1 (inverted signal because transistor should be on SDA output)
    m_pParallelDataOut->data[0] = 1;
    m_pParallelDataOut->data[7] = 1;
    m_pParallelPort->write(m_pParallelDataOut);
    m_pParallelDataOut->data[0] = 1;
    m_pParallelDataOut->data[7] = 1;
    m_pParallelPort->write(m_pParallelDataOut);
    m_pParallelDataOut->data[0] = 1;
    m_pParallelDataOut->data[7] = 1;
    m_pParallelPort->write(m_pParallelDataOut);
    m_pParallelDataOut->data[0] = 1;
    m_pParallelDataOut->data[7] = 1;
    m_pParallelPort->write(m_pParallelDataOut);
    m_pParallelDataOut->data[0] = 1;
    m_pParallelDataOut->data[7] = 1;
    m_pParallelPort->write(m_pParallelDataOut);
    m_pParallelDataOut->data[0] = 1;
    m_pParallelDataOut->data[7] = 1;
    m_pParallelPort->write(m_pParallelDataOut);
    m_pParallelDataOut->data[0] = 1;
    m_pParallelDataOut->data[7] = 1;
    m_pParallelPort->write(m_pParallelDataOut);
    m_pParallelDataOut->data[0] = 1;
    m_pParallelDataOut->data[7] = 1;
    m_pParallelPort->write(m_pParallelDataOut);
    ////////////SCL : 1 -> 0
    m_pParallelDataOut->data[0] = 0;
    m_pParallelDataOut->data[7] = 1;
    m_pParallelPort->write(m_pParallelDataOut);
    m_pParallelDataOut->data[0] = 0;
    m_pParallelDataOut->data[7] = 1;
    m_pParallelPort->write(m_pParallelDataOut);
}
//Stop condition on I2C bus (SDA from 0 to 1 when SCL 1)
void I2CLPT::stopCondition()
{
    m_pParallelDataOut->data[0] = 0;//DATA[0] : SCL signal
    m_pParallelDataOut->data[7] = 1;//DATA[7] : SDA signal
    m_pParallelPort->write(m_pParallelDataOut);
    m_pParallelDataOut->data[0] = 0;
    m_pParallelDataOut->data[7] = 1;
    m_pParallelPort->write(m_pParallelDataOut);
    ////////////SCL : 0 -> 1
    m_pParallelDataOut->data[0] = 1;
    m_pParallelDataOut->data[7] = 1;
    m_pParallelPort->write(m_pParallelDataOut);
    m_pParallelDataOut->data[0] = 1;
    m_pParallelDataOut->data[7] = 1;
    m_pParallelPort->write(m_pParallelDataOut);
    m_pParallelDataOut->data[0] = 1;
    m_pParallelDataOut->data[7] = 1;
    m_pParallelPort->write(m_pParallelDataOut);
    m_pParallelDataOut->data[0] = 1;
    m_pParallelDataOut->data[7] = 1;
    m_pParallelPort->write(m_pParallelDataOut);
    m_pParallelDataOut->data[0] = 1;
    m_pParallelDataOut->data[7] = 1;
    m_pParallelPort->write(m_pParallelDataOut);
    m_pParallelDataOut->data[0] = 1;
    m_pParallelDataOut->data[7] = 1;
    m_pParallelPort->write(m_pParallelDataOut);
    m_pParallelDataOut->data[0] = 1;
    m_pParallelDataOut->data[7] = 1;
    m_pParallelPort->write(m_pParallelDataOut);
    m_pParallelDataOut->data[0] = 1;
    m_pParallelDataOut->data[7] = 1;
    m_pParallelPort->write(m_pParallelDataOut);
    ////////////SDA : 0 -> 1 (inverted signal because transistor should be on SDA output)
    m_pParallelDataOut->data[0] = 1;
    m_pParallelDataOut->data[7] = 0;
    m_pParallelPort->write(m_pParallelDataOut);
    m_pParallelDataOut->data[0] = 1;
    m_pParallelDataOut->data[7] = 0;
    m_pParallelPort->write(m_pParallelDataOut);
}
//Send byte on I2C bus through LPT port signals
//Every instruction needs some CPU cycles
//but in protected mode in multitasking OS this
//time maybe various depends on priority of process
//and other things
//Still we need to balance instructions timings to
//make SCK signal more looks like meandr signal with
//duty cycle 50%
bool I2CLPT::sendByte(char byte)
{
    bool bAck; //Ack response from Device
    for(int i = 7;i>=0;i--) //Send 8 bits
    {
        m_pParallelDataOut->data[0] = 0; //Most significant bit shifts first on I2C bus
        m_pParallelDataOut->data[7] = ~(byte & (1 << i)) >> i; //choose i bit (and invert due to transistor) and shift it on i
        m_pParallelPort->write(m_pParallelDataOut);//because data[7] is char array in structure
        m_pParallelDataOut->data[0] = 0; // And then send it on I2C bus
        m_pParallelDataOut->data[7] = ~(byte & (1 << i)) >> i;
        m_pParallelPort->write(m_pParallelDataOut);
        m_pParallelDataOut->data[0] = 1;//SCK
        m_pParallelDataOut->data[7] = ~(byte & (1 << i)) >> i;//SDA
        m_pParallelPort->write(m_pParallelDataOut);
        m_pParallelDataOut->data[0] = 1;
        m_pParallelDataOut->data[7] = ~(byte & (1 << i)) >> i;
        m_pParallelPort->write(m_pParallelDataOut);
        m_pParallelDataOut->data[0] = 1;
        m_pParallelDataOut->data[7] = ~(byte & (1 << i)) >> i;
        m_pParallelPort->write(m_pParallelDataOut);
        m_pParallelDataOut->data[0] = 1;
        m_pParallelDataOut->data[7] = ~(byte & (1 << i)) >> i;
        m_pParallelPort->write(m_pParallelDataOut);
        m_pParallelDataOut->data[0] = 0;//SCK from 1 to 0
        m_pParallelDataOut->data[7] = ~(byte & (1 << i)) >> i;
        m_pParallelPort->write(m_pParallelDataOut);
        m_pParallelDataOut->data[0] = 0;//Middle of low level SCK signal
        m_pParallelDataOut->data[7] = ~(byte & (1 << i)) >> i;
        m_pParallelPort->write(m_pParallelDataOut);
    }
    m_pParallelDataOut->data[0] = 0;//remained cycles of SCK to read ACK response from Device
    m_pParallelDataOut->data[7] = 0;
    m_pParallelPort->write(m_pParallelDataOut);
    bAck = m_pParallelPort->read().ack; //receive ACK input signal
    m_pParallelDataOut->data[0] = 1;//SCK
    m_pParallelDataOut->data[7] = 0;//SDA
    m_pParallelPort->write(m_pParallelDataOut);
    m_pParallelDataOut->data[0] = 1;
    m_pParallelDataOut->data[7] = 0;
    m_pParallelPort->write(m_pParallelDataOut);
    m_pParallelDataOut->data[0] = 1;
    m_pParallelDataOut->data[7] = 0;
    m_pParallelPort->write(m_pParallelDataOut);
    m_pParallelDataOut->data[0] = 1;
    m_pParallelDataOut->data[7] = 0;
    m_pParallelPort->write(m_pParallelDataOut);
    m_pParallelDataOut->data[0] = 0;
    m_pParallelDataOut->data[7] = 0;
    m_pParallelPort->write(m_pParallelDataOut);
    m_pParallelDataOut->data[0] = 0;
    m_pParallelDataOut->data[7] = 0;
    m_pParallelPort->write(m_pParallelDataOut);
    return bAck;
}
//Receive byte from I2C bus through LPT port signals
//The same requirements like in sendByte case
char I2CLPT::recvByte(bool bAck)
{
    unsigned char byte = 0;//Byte we need to receive
    for(int i = 7;i>=0;i--)//Most significant bit receives first on I2C bus
    {
        m_pParallelDataOut->data[0] = 0;//SCK
        m_pParallelDataOut->data[7] = 0;//SDA - not used
        m_pParallelPort->write(m_pParallelDataOut);
        m_pParallelDataOut->data[0] = 0;
        m_pParallelDataOut->data[7] = 0;
        m_pParallelPort->write(m_pParallelDataOut);
        byte |= m_pParallelPort->read().ack << i;//Receive bit i on ACK LPT port signal
        m_pParallelDataOut->data[0] = 0;
        m_pParallelDataOut->data[7] = 0;
        m_pParallelPort->write(m_pParallelDataOut);
        m_pParallelDataOut->data[0] = 0;
        m_pParallelDataOut->data[7] = 0;
        m_pParallelPort->write(m_pParallelDataOut);
        m_pParallelDataOut->data[0] = 1;//SCK from 0 to 1
        m_pParallelDataOut->data[7] = 0;
        m_pParallelPort->write(m_pParallelDataOut);
        m_pParallelDataOut->data[0] = 1;
        m_pParallelDataOut->data[7] = 0;
        m_pParallelPort->write(m_pParallelDataOut);
        //byte |= m_pParallelPort->read().ack << i;//Receive bit i on ACK LPT port signal
        m_pParallelDataOut->data[0] = 1;
        m_pParallelDataOut->data[7] = 0;
        m_pParallelPort->write(m_pParallelDataOut);
        m_pParallelDataOut->data[0] = 1;//And repeat loop
        m_pParallelDataOut->data[7] = 0;
        m_pParallelPort->write(m_pParallelDataOut);
    }
    m_pParallelDataOut->data[0] = 0;
    m_pParallelDataOut->data[7] = bAck; //We respose to Device with ACK on I2C
    m_pParallelPort->write(m_pParallelDataOut);
    m_pParallelDataOut->data[0] = 0;
    m_pParallelDataOut->data[7] = bAck;
    m_pParallelPort->write(m_pParallelDataOut);
    m_pParallelDataOut->data[0] = 0;
    m_pParallelDataOut->data[7] = bAck;
    m_pParallelPort->write(m_pParallelDataOut);
    m_pParallelDataOut->data[0] = 0;
    m_pParallelDataOut->data[7] = bAck;
    m_pParallelPort->write(m_pParallelDataOut);
    m_pParallelDataOut->data[0] = 1;//SCK from 0 to 1
    m_pParallelDataOut->data[7] = bAck;
    m_pParallelPort->write(m_pParallelDataOut);
    m_pParallelDataOut->data[0] = 1;
    m_pParallelDataOut->data[7] = bAck;
    m_pParallelPort->write(m_pParallelDataOut);
    m_pParallelDataOut->data[0] = 1;
    m_pParallelDataOut->data[7] = bAck;
    m_pParallelPort->write(m_pParallelDataOut);
    m_pParallelDataOut->data[0] = 1;
    m_pParallelDataOut->data[7] = bAck;
    m_pParallelPort->write(m_pParallelDataOut);
    m_pParallelDataOut->data[0] = 0;
    m_pParallelDataOut->data[7] = 1; //Pause on I2C bus
    m_pParallelPort->write(m_pParallelDataOut);
    m_pParallelDataOut->data[0] = 0;
    m_pParallelDataOut->data[7] = 1; //Pause on I2C bus
    return byte;//Then return received byte after transaction done
}
