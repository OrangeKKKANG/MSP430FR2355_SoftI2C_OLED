/*软件IIC: 配置P6.0为SCL,P6.1为SDA*/

#include<driverlib.h>
#include "Delay.h"
#include "MyI2C.h"

void MyI2C_Init(void)
{
    SCL_OUT;    // 先设置输出
    SDA_OUT;    // 先设置输出
    SCL_HIGH;   // 稳定高
    SDA_HIGH;   // 稳定高
}

void MyI2C_Start(void)
{
    //1.初始化准备
    SCL_HIGH;
    SDA_HIGH;

    //2.开始标志
    __delay_cycles(10);
    SDA_LOW;
    __delay_cycles(10);
    SCL_LOW;
}

void MyI2C_Stop(void)
{
     //1.初始化准备
    SCL_LOW;
    SDA_LOW;
    __delay_cycles(10);

    //2.停止标志
    SCL_HIGH;
    __delay_cycles(10);
    SDA_HIGH;
    __delay_cycles(10);
}

void MyI2C_SendByte(uint8_t Byte)
{
    uint8_t i;
	SCL_LOW;
	__delay_cycles(10);

    for(i = 0; i < 8; i++)  
    {
        if(Byte & 0x80)    //写1
            SDA_HIGH;
        else                 //写0
            SDA_LOW;

		__delay_cycles(10);
        SCL_HIGH;
	    __delay_cycles(10);
        SCL_LOW;
	    __delay_cycles(10);

        Byte <<= 1;         //循环左移，取最高位
    }
}

uint8_t MyI2C_ReceiveByte(void)
{
    uint8_t i, Data=0; 
	SDA_IN;       //SDA设置为输入
	SCL_LOW;
	__delay_cycles(50);

	for(i = 0; i < 8; i++)
	{
		SCL_HIGH;
		Data <<= 1;
		if(SDA) Data |= 1;

        SCL_LOW;
        __delay_cycles(50);
	}

	SDA_OUT;        //SDA设置为输出
	__delay_cycles(50);
	return Data;
}

void MyI2C_SendAck(uint8_t AckBit)
{
	SCL_LOW;
	if(AckBit == 0) SDA_LOW;  //发送0表示应答 
    if(AckBit == 1) SDA_HIGH;  //发送1表示非应答

    SCL_HIGH;
	__delay_cycles(5);
	SCL_LOW;
	__delay_cycles(5);
}

uint8_t MyI2C_ReceiveAck(void)
{
    uint8_t Ack = 1; 
	SDA_IN;       //SDA设置为输入
	SCL_OUT;
	SCL_LOW;
	__delay_cycles(50);

	SCL_HIGH;
	if(SDA) Ack = 1;
    else Ack = 0; //应答成功

    SCL_LOW;
    __delay_cycles(50);
	SDA_OUT;        //SDA设置为输出
	__delay_cycles(50);
    
	return Ack;
}