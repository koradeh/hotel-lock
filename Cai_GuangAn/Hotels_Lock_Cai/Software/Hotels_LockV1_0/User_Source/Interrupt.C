#include <REG931.h>			//自带的P89LPC931的头文件
#include "Group_Fun.h"		//程序所用函数头文件
#include "Group_Pin.h"		//硬件配置头文

void Key_Int(void) interrupt 7
{
	KBCON = 0x00; //清除按键中断

}

//-----------------------------------------------------------------------------------------
//功能：串口接收
//只接收数据，并不处理数据，处理数据另有函数
//-----------------------------------------------------------------------------------------
void serial () interrupt 4 
{
//     BYTE      count3;
//	 unsigned char ch;
	if(RI)
    {
        EA=0;
		RI = 0;
        *M_SioInTailPoint=SBUF;
		M_SioInTailPoint++;                                // 每接收到1Byte数据, 尾指针向后移1
        if (M_SioInTailPoint > SIO_IN_END_ADDRESS)		   //判断是否到尾地址如果到的话时行回绕
        {
            M_SioInTailPoint = SIO_IN_BASE_ADDRESS;
        };

		EA=1;
    };
}