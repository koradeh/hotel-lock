
//初始化通讯缓冲区
void InitSioBuff(void)
{
	unsigned char i;

    M_SioInHeadPoint = SIO_IN_OUT_BASE_ADDRESS;     // 初始化串口接收数据头尾指针
    M_SioInTailPoint = SIO_IN_OUT_BASE_ADDRESS;
	
	for (i=0; i<SIO_IN_OUT_LEN; i++)             // 清空串口接收Buffer
    {
        M_SioInBuffer[i] = 0x00;
    }
}

//----------------------------------------------------------------------------------------
//功能：串口发送一个字符
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
///*后面的加减Len的结果是不变的，为的是增加一些延时否则有的时候会出现发送出去对方接收不到或验证不正确	
		len--;
		len++;
		len--;
		len++;
		len--;
		len++;
	}
}