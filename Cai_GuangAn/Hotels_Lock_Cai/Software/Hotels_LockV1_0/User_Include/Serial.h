#ifndef          _Serial_H_
#define          _Serial_H_

#define SIO_IN_OUT_LEN 				20
#define SIO_IN_OUT_BASE_ADDRESS  	&M_SioInOutBuffer[0];
#define SIO_IN_OUT_END_ADDRESS		&M_SioInOutBuffer[SIO_IN_END_ADDRESS-1];

unsigned char M_SioInOutBuffer[SIO_IN_OUT_LEN];   //����ͨѶ������
unsigned char *M_SioInOutHeadPoint;				  //����ͨѶͷָ��
unsigned char *M_SioInOutTailPoint;				  //����ͨѶβָ��

void InitSioBuff(void);
void Send_Char(BYTE ch);//����һ���ַ�
void Send_String(BYTE *str ,BYTE len);  //����һ���ַ���


#endif