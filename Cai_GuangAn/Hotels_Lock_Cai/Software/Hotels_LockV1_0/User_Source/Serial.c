
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