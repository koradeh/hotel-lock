#include <REG931.h>			//�Դ���P89LPC931��ͷ�ļ�
#include "Group_Fun.h"		//�������ú���ͷ�ļ�
#include "Group_Pin.h"		//Ӳ������ͷ��
//ϵͳ��ʼ������
void Systemp_Init(void)
{
	RS232_Init();
}

//SPI��ʼ��
void SPI_Init(void)
{
	P2M1=0x00;
	P2M2=0x00;
	SPCTL=0x50; //SSIG=0,SPIEN=1,MSTR=1;
	SPSTAT=0xC0; //���SPSTAT�еı�־λ;
}
//RS232 TTL����
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
//ϵͳ���������������
void Main(void)
{
	Systemp_Init();
	while(1)
	{
		;
	};
}
  */