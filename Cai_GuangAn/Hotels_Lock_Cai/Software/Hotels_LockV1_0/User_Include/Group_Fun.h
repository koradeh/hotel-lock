#ifndef _Group_Fun_H
#define _Group_Fun_H

#define Cheak_Fail  0
#define Check_OK    1
#define Check_Set   2


extern void Systemp_Init(void);         //ϵͳ��ʼ��
extern void Delay_Nns(unsigned int Nns);    //��ʱ΢�뼶
extern void Delay_Nms(unsigned int Nms);    //��ʱ���뼶
//����������     Open_delay ����ʱ  Close_delay ����ʱ  Views ����
extern void Beep_Ctrl(unsigned int Open_delay,unsigned int Close_delay,unsigned char Views);        
//LED�ƿ��ƣ� YGR ���̻������ƣ�delay ��ʱ��������ʱ���ţ�Views ����
extern void LED_Ctrl(unsigned char YGR,unsigned int delay,unsigned char Views);
	


#endif	//end Group_Fun.h
