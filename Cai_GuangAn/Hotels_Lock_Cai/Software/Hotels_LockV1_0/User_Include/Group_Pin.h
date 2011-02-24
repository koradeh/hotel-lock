#ifndef _Group_Pin_H
#define _Group_Pin_H
/*
	��Ŀ�����ùܽŶ�������ʹ�ù���
1��UART 	�ճ̿��ƿ�
2��SPI		MF�����ƶ˿ڶ�����������
3��IIC		ʱ����洢����
4����ͨ��GPIO�����ϵ������빦��
   1��OUT
		�������			P2.0��P2.1
		LED�ƿ���        P1.7ͨ����P1.6ʧ�ܣ�P2.6����
        ����������		P2.7
        MF��ģ���Դ		P0.7
		
   2��IN
*/

//P0�˿ڶ���
#define RST_MF			P0^0
//#define
//P1�˿ڶ���
#define PASS_OK			P1^7
#define PASS_FAIL		P1^6
//#define 
//P2�˿ڶ���
#define CTRL_BEEP		P2^7
#define PASS_SET		P2^6
#define MOTO_PIN1		P2^1
#define MOTO_PIN0		P2^0


#endif		//end Group_Pin.h
