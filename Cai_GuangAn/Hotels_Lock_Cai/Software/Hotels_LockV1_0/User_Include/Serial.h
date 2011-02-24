#ifndef          _Serial_H_
#define          _Serial_H_

#define SIO_IN_OUT_LEN 				20
#define SIO_IN_OUT_BASE_ADDRESS  	&M_SioInOutBuffer[0];
#define SIO_IN_OUT_END_ADDRESS		&M_SioInOutBuffer[SIO_IN_END_ADDRESS-1];

unsigned char M_SioInOutBuffer[SIO_IN_OUT_LEN];   //串口通讯缓冲区
unsigned char *M_SioInOutHeadPoint;				  //串口通讯头指针
unsigned char *M_SioInOutTailPoint;				  //串口通讯尾指针

void InitSioBuff(void);
void Send_Char(BYTE ch);//发送一个字符
void Send_String(BYTE *str ,BYTE len);  //发送一个字符串


#endif