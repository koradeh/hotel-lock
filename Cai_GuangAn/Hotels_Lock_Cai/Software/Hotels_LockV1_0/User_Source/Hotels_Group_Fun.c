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

