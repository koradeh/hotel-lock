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

//
void Beep_Ctrl(unsigned int Open_delay,unsigned int Close_delay,unsigned char Views)
{
	while(Views)
	{
		CTRL_BEEP=0;
		Delay_Nms(Open_delay);
		CTRL_BEEP=1;
		Delay_Nms(Close_delay);
		Views--;
	}
}

void LED_Ctrl(unsigned char YGR,unsigned int delay,unsigned char Views)
{
	if(YGR == Cheak_Fail)		//失败灯
	{
		while(Views)
		{
			PASS_FAIL = 0;
			Delay_Nms(delay);
			PASS_FAIL = 1;
			Delay_Nms(delay);
		}
	}
	if(YGR == Check_OK)		//通过灯
	{
		while(Views)
		{
			PASS_OK = 0;
			Delay_Nms(delay);
			PASS_OK = 1;
			Delay_Nms(delay);
		}
	}
	if(YGR == Check_Set)	//设置灯
	{
		while(Views)
		{
			PASS_SET = 0;
			Delay_Nms(delay);
			PASS_SET = 1;
			Delay_Nms(delay);
		}
	}
}
