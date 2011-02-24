#include <REG931.h>			//自带的P89LPC931的头文件
#include "Group_Fun.h"		//程序所用函数头文件
#include "Group_Pin.h"		//硬件配置头文
//延时ns级
void Delay_Nns(unsigned int Nns)
{
	unsigned int i;
	for(i=0;i<Nns;i++)
	{
		;
	}
}
//延时ms级
void Delay_Nms(unsigned int Nms)
{
	unsigned int i;
	unsigned char j;
	for(i=0;i<Nms;i++)
	{
		for(j=0;j<102;j++)
		{
			;
		}
	}
}

