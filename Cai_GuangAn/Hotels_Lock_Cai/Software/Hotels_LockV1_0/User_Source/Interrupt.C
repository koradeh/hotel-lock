#include <REG931.h>			//�Դ���P89LPC931��ͷ�ļ�
#include "Group_Fun.h"		//�������ú���ͷ�ļ�
#include "Group_Pin.h"		//Ӳ������ͷ��

void Key_Int(void) interrupt 7
{
	KBCON = 0x00; //��������ж�

}

//-----------------------------------------------------------------------------------------
//���ܣ����ڽ���
//ֻ�������ݣ������������ݣ������������к���
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
		M_SioInTailPoint++;                                // ÿ���յ�1Byte����, βָ�������1
        if (M_SioInTailPoint > SIO_IN_END_ADDRESS)		   //�ж��Ƿ�β��ַ������Ļ�ʱ�л���
        {
            M_SioInTailPoint = SIO_IN_BASE_ADDRESS;
        };

		EA=1;
    };
}