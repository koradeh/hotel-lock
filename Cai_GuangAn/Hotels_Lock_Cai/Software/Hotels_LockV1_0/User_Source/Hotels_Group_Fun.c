#include <REG931.h>			//�Դ���P89LPC931��ͷ�ļ�
#include "Group_Fun.h"		//�������ú���ͷ�ļ�
#include "Group_Pin.h"		//Ӳ������ͷ��
//��ʱns��
void Delay_Nns(unsigned int Nns)
{
	unsigned int i;
	for(i=0;i<Nns;i++)
	{
		;
	}
}
//��ʱms��
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
	if(YGR == Cheak_Fail)		//ʧ�ܵ�
	{
		while(Views)
		{
			PASS_FAIL = 0;
			Delay_Nms(delay);
			PASS_FAIL = 1;
			Delay_Nms(delay);
		}
	}
	if(YGR == Check_OK)		//ͨ����
	{
		while(Views)
		{
			PASS_OK = 0;
			Delay_Nms(delay);
			PASS_OK = 1;
			Delay_Nms(delay);
		}
	}
	if(YGR == Check_Set)	//���õ�
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
