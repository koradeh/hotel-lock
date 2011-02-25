#include <REG931.h>			//自带的P89LPC931的头文件
#include "Group_Fun.h"		//程序所用函数头文件
#include "Group_Pin.h"		//硬件配置头文
#include "Serial.h"         //串口的硬件配置
//系统初始化函数
void Systemp_Init(void)
{
	P0M1 = 0x
    P0M2
	//按键处理
	KBPATN = 0x72;	//01110010b
	//设置按键 P1.6、P1.5、P1.4、P1.1中断源
	KBMASK = 0x72;	//01110010b
	KBCON  = 0x00;	
    RS232_Init();
    SPI_Init();
}

//SPI初始化
void SPI_Init(void)
{
	P2M1=0x00;
	P2M2=0x00;
	SPCTL=0x50; //SSIG=0,SPIEN=1,MSTR=1;
	SPSTAT=0xC0; //清除SPSTAT中的标志位;
}

//系统主函数，程序入口
void Main(void)
{
	Systemp_Init();
	while(1)
	{
		Send_Char(0x55);
	};
}
