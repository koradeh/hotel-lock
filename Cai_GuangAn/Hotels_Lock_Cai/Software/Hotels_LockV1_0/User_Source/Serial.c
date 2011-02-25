#include <REG931.h>			//�Դ���P89LPC931��ͷ�ļ�
#include "Group_Fun.h"		//�������ú���ͷ�ļ�
#include "Group_Pin.h"		//Ӳ������ͷ��

//RS232 TTL����
void RS232_Init(void)
{
	P1M1=0x00;
	P1M2=0x00; //�˿ڳ�ʼ��
	SCON=0x50; //ʹ�ܽ���ѡ�񴮿�ģʽ1
	SSTAT=0xE0; //ѡ�������Tx/Rx�ж�
	BRGR0=0xF0; //9600 baud @ 7.373MHz
	BRGR1=0x02;
	// BRGR0=0x70; //19200 baud @ 7.373MHz
	// BRGR1=0x01;
	// BRGR0=0x30; //115200 baud @ 7.373MHz
	// BRGR1=0x00;
	BRGCON =0x03; //ʹ��BRG
	ESR=1; //ESR=Enable Serial Recieve
	//EST=1; //EST=Enable Serial Transmit
	EA=1; //ʹ���ж�
}

//��ʼ��ͨѶ������
void InitSioBuff(void)
{
	unsigned char i;

    M_SioInHeadPoint = SIO_IN_OUT_BASE_ADDRESS;     // ��ʼ�����ڽ�������ͷβָ��
    M_SioInTailPoint = SIO_IN_OUT_BASE_ADDRESS;
	
	for (i=0; i<SIO_IN_OUT_LEN; i++)             // ��մ��ڽ���Buffer
    {
        M_SioInBuffer[i] = 0x00;
    }
}

//----------------------------------------------------------------------------------------
//���ܣ����ڷ���һ���ַ�
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
///*����ļӼ�Len�Ľ���ǲ���ģ�Ϊ��������һЩ��ʱ�����е�ʱ�����ַ��ͳ�ȥ�Է����ղ�������֤����ȷ	
		len--;
		len++;
		len--;
		len++;
		len--;
		len++;
	}
}