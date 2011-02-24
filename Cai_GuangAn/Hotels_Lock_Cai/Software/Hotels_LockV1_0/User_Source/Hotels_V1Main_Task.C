#include <REG931.h>			//自带的P89LPC931的头文件
#include "Group_Fun.h"		//程序所用函数头文件
#include "Group_Pin.h"		//硬件配置头文
//系统初始化函数
void Systemp_Init(void)
{
	RS232_Init();
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
	;
}
void delay (unsigned int cnt)
{
  while (--cnt);
}

void main()
{
  unsigned char i;

  P1M1 = 0;

  for(;;)
  { for (i = 0x01; i; i <<= 1)
    { P1 = i;				// simulate running lights
      delay (50000);
    }
    for (i = 0x80; i; i >>= 1)
    { P1 = i;
      delay (50000);
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