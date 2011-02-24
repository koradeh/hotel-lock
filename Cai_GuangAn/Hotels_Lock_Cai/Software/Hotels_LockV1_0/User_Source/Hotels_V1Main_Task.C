#include <REG931.h>			//自带的P89LPC931的头文件
#include "Group_Fun.h"		//程序所用函数头文件
#include "Group_Pin.h"		//硬件配置头文
//系统初始化函数
void Systemp_Init(void)
{
	RS232_Init();
	//按键处理
	KBPATN = 0x72;	//01110010b
	//设置按键 P1.6、P1.5、P1.4、P1.1中断源
	KBMASK = 0x72;	//01110010b
	KBCON  = 0x00;
	

}

//SPI初始化
void SPI_Init(void)
{
	P2M1=0x00;
	P2M2=0x00;
	SPCTL=0x50; //SSIG=0,SPIEN=1,MSTR=1;
	SPSTAT=0xC0; //清除SPSTAT中的标志位;
}
//RS232 TTL配置
void RS232_Init(void)
{
	P1M1=0x00;
	P1M2=0x00; //端口初始化
	SCON=0x50; //使能接收选择串口模式1
	SSTAT=0xE0; //选择独立的Tx/Rx中断
	BRGR0=0xF0; //9600 baud @ 7.373MHz
	BRGR1=0x02;
	// BRGR0=0x70; //19200 baud @ 7.373MHz
	// BRGR1=0x01;
	// BRGR0=0x30; //115200 baud @ 7.373MHz
	// BRGR1=0x00;
	BRGCON =0x03; //使能BRG
	ESR=1; //ESR=Enable Serial Recieve
	//EST=1; //EST=Enable Serial Transmit
	EA=1; //使能中断
}

void main()
{
  unsigned char i;

  P1M1 = 0;

  for(;;)
  { for (i = 0x01; i; i <<= 1)
    { P1 = i;				// simulate running lights
      Delay_Nns (50000);
    }
    for (i = 0x80; i; i >>= 1)
    { P1 = i;
      Delay_Nns (50000);
    }
  }
}
/*
//系统主函数，程序入口
void Main(void)
{
	Systemp_Init();
	while(1)
	{
		;
	};
}
  */