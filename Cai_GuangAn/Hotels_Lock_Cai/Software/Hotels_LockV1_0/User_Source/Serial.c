#include <REG931.h>			//自带的P89LPC931的头文件
#include "Group_Fun.h"		//程序所用函数头文件
#include "Group_Pin.h"		//硬件配置头文

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

//初始化通讯缓冲区
void InitSioBuff(void)
{
	unsigned char i;

    M_SioInHeadPoint = SIO_IN_OUT_BASE_ADDRESS;     // 初始化串口接收数据头尾指针
    M_SioInTailPoint = SIO_IN_OUT_BASE_ADDRESS;
	
	for (i=0; i<SIO_IN_OUT_LEN; i++)             // 清空串口接收Buffer
    {
        M_SioInBuffer[i] = 0x00;
    }
}

//----------------------------------------------------------------------------------------
//功能：串口发送一个字符
//----------------------------------------------------------------------------------------
void Send_Char(BYTE ch)  
{
	SBUF=ch;
    while(TI==0);
    TI=0;
}

void Send_String(BYTE *str ,BYTE len)	
{
	while(len>0)
	{
		Send_Char(*str++);
		len--;
///*后面的加减Len的结果是不变的，为的是增加一些延时否则有的时候会出现发送出去对方接收不到或验证不正确	
		len--;
		len++;
		len--;
		len++;
		len--;
		len++;
	}
}