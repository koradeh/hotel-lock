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
#define MFPower			P0^7  //out
#define MachineKey		P0^6  //in
#define LockAlarm		P0^5  //in
#define LockInside		P0^4  //in
#define Power_Testctrl	P0^3  //in
#define Power_Test		P0^2  //out
#define Key_Null		P0^1  //in
#define RST_MF			P0^0  //out

//P1�˿ڶ���
#define PASS_OK			P1^7  //out
#define PASS_FAIL		P1^6  //out
#define HW-Send			P1^4
#define I2C_SDA			P1^3  //in/out
#define I2C_SCL			P1^2  //out
#define RXD				P1^1  //in
#define TXD				P1^0  //out
 
//P2�˿ڶ���
#define CTRL_BEEP		P2^7  //out
#define PASS_SET		P2^6  //out
#define SPI_SCK			P2^5  //
#define SPI_SS			P2^4
#define SPI_MISO		P2^3
#define SPI_MOSI		P2^2
#define MOTO_PIN1		P2^1   //out
#define MOTO_PIN0		P2^0   //out

//P3�˿ڶ���
#define HW_POWER		P3^1
#define HW_RECEIVE		P3^0




#endif		//end Group_Pin.h
