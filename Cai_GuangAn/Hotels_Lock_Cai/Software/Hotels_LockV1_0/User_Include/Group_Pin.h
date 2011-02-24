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
#define RST_MF			P0^0
//#define
//P1端口定义
#define PASS_OK			P1^7
#define PASS_FAIL		P1^6
//#define 
//P2端口定义
#define CTRL_BEEP		P2^7
#define PASS_SET		P2^6
#define MOTO_PIN1		P2^1
#define MOTO_PIN0		P2^0


#endif		//end Group_Pin.h
