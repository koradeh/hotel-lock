#ifndef _Group_Pin_H
#define _Group_Pin_H
/*
	项目中所用管脚定义与其使用功能
1、UART 	烧程控制口
2、SPI		MF卡控制端口读卡部分设置
3、IIC		时钟与存储部分
4、普通的GPIO功能上的设置与功能
   1）OUT
		电机控制			P2.0，P2.1
		LED灯控制        P1.7通过，P1.6失败，P2.6设置
        蜂鸣器控制		P2.7
        MF卡模块电源		P0.7
		
   2）IN
*/

//P0端口定义
#define MFPower			P0^7  //out
#define MachineKey		P0^6  //in
#define LockAlarm		P0^5  //in
#define LockInside		P0^4  //in
#define Power_Testctrl	P0^3  //in
#define Power_Test		P0^2  //out
#define Key_Null		P0^1  //in
#define RST_MF			P0^0  //out

//P1端口定义
#define PASS_OK			P1^7  //out
#define PASS_FAIL		P1^6  //out
#define HW-Send			P1^4
#define I2C_SDA			P1^3  //in/out
#define I2C_SCL			P1^2  //out
#define RXD				P1^1  //in
#define TXD				P1^0  //out
 
//P2端口定义
#define CTRL_BEEP		P2^7  //out
#define PASS_SET		P2^6  //out
#define SPI_SCK			P2^5  //
#define SPI_SS			P2^4
#define SPI_MISO		P2^3
#define SPI_MOSI		P2^2
#define MOTO_PIN1		P2^1   //out
#define MOTO_PIN0		P2^0   //out

//P3端口定义
#define HW_POWER		P3^1
#define HW_RECEIVE		P3^0




#endif		//end Group_Pin.h
