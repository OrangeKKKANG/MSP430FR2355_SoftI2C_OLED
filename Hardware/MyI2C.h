#ifndef __MYI2C_H
#define __MYI2C_H

//P6.0 SCL
//P6.1 SDA
#define    SCL_HIGH    P6OUT |= BIT0
#define    SCL_LOW     P6OUT &= ~BIT0

#define    SDA_HIGH    P6OUT |= BIT1
#define    SDA_LOW     P6OUT &= ~BIT1

#define    SDA_OUT     P6DIR |= BIT1
#define    SDA_IN      P6DIR &=~ BIT1

#define    SCL_OUT     P6DIR |= BIT0
#define    SDA         P6IN & BIT1

void MyI2C_Init(void);
void MyI2C_Start(void);
void MyI2C_Stop(void);
void MyI2C_SendByte(uint8_t Byte);
uint8_t MyI2C_ReceiveByte(void);
void MyI2C_SendAck(uint8_t AckBit);
uint8_t MyI2C_ReceiveAck(void);

#endif
