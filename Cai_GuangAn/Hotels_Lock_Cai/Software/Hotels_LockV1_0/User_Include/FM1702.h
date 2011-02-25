#ifndef _FM1702_H_
#define _FM1702_H_



#define FALSE	1
#define TRUE	0

#define write   0x0f  /*写操作标志字*/
#define read    0x0e  /*读操作标志字*/
/* FM1715命令码 */
#define Idle        0x00            /*空指令*/
#define Transceive	0x1E			/* 发送接收命令 */
#define Transmit	0x1a			/* 发送命令 */
#define ReadE2		0x03			/* 读FM1715 EEPROM命令 */
#define WriteE2		0x01			/* 写FM1715 EEPROM命令 */
#define Authent1	0x0c			/* 验证命令认证过程第1步 */
#define Authent2	0x14			/* 验证命令认证过程第2步 */
#define LoadKeyE2	0x0b			/* 将密钥从EEPROM复制到KEY缓存 */
#define LoadKey		0x19			/* 将密钥从FIFO缓存复制到KEY缓存 */
#define Loadconfig  0x07            /*从EEEPROOM读取数据，用于对寄存器初始化*/
#define CalcCRC     0x12            /*CRC指令*/
///////////////////////////////////////////////////////////////////
#define RF_TimeOut	0xff   /*0x7f  ,20090206*/
#define Req		    0x01
#define Sel		    0x02

#define MF_BLOCK1			0X01  /*数据块1*/
#define MF_BLOCK2			0X02  /*数据块2*/
#define MF_BLOCK3			0X03  /*数据块3*/
#define MF_BLOCK4			0X04  /*数据块4*/
/*************************************************************/

#define mifare1			1
#define mifarepro		2
#define mifarelight		3
#define unkowncard		4
#define unknowncard     4


/* 数据类型定义 */
#define uchar	unsigned char
#define uint	unsigned int

/* 卡片类型定义定义 */
#define TYPEA_MODE	    0			/* TypeA模式 */
#define TYPEB_MODE	    1			/* TypeB模式 */
#define SHANGHAI_MODE	2			/* 上海模式 */
#define TM0_HIGH	    0xf0		/* 定时器0高位,4MS定时 */
#define TM0_LOW		    0x60		/* 定时器0低位 */
#define TIMEOUT		    100			/* 超时计数器4MS×100=0.4秒 */

/* 射频卡通信命令码定义 */
#define RF_CMD_REQUEST_STD	0x26
#define RF_CMD_REQUEST_ALL	0x52
#define RF_CMD_ANTICOL		0x93
#define RF_CMD_SELECT		0x93
#define RF_CMD_AUTH_LA		0x60
#define RF_CMD_AUTH_LB		0x61
#define RF_CMD_READ		    0x30
#define RF_CMD_WRITE		0xa0
#define RF_CMD_INC		    0xc1
#define RF_CMD_DEC		    0xc0
#define RF_CMD_RESTORE		0xc2
#define RF_CMD_TRANSFER		0xb0
#define RF_CMD_HALT		    0x50

/* Status Values */
#define ALL	    0x01
#define KEYB	0x04
#define KEYA	0x00
#define _AB	    0x40
#define CRC_A	1
#define CRC_B	2
#define CRC_OK	0
#define CRC_ERR 1
#define BCC_OK	0
#define BCC_ERR 1

/* 卡类型定义 */
#define MIFARE_8K	    0			/* MIFARE系列8KB卡片 */
#define MIFARE_TOKEN	1			/* MIFARE系列1KB TOKEN卡片 */
#define SHANGHAI_8K	    2			/* 上海标准系列8KB卡片 */
#define SHANGHAI_TOKEN	3			/* 上海标准系列1KB TOKEN卡片 */

/* 函数错误代码定义 */
#define FM1715_OK		    0		/* 正确 */
#define FM1715_NOTAGERR		1		/* 无卡 */
#define FM1715_CRCERR		2		/* 卡片CRC校验错误 */
#define FM1715_EMPTY		3		/* 数值溢出错误 */
#define FM1715_AUTHERR		4		/* 验证不成功 */
#define FM1715_PARITYERR	5		/* 卡片奇偶校验错误 */
#define FM1715_CODEERR		6		/* 通讯错误(BCC校验错) */
#define FM1715_SERNRERR		8		/* 卡片序列号错误(anti-collision 错误) */
#define FM1715_SELECTERR	9		/* 卡片数据长度字节错误(SELECT错误) */
#define FM1715_NOTAUTHERR	10		/* 卡片没有通过验证 */
#define FM1715_BITCOUNTERR	11		/* 从卡片接收到的位数错误 */
#define FM1715_BYTECOUNTERR	12		/* 从卡片接收到的字节数错误仅读函数有效 */
#define FM1715_RESTERR		13		/* 调用restore函数出错 */
#define FM1715_TRANSERR		14		/* 调用transfer函数出错 */
#define FM1715_WRITEERR		15		/* 调用write函数出错 */
#define FM1715_INCRERR		16		/* 调用increment函数出错 */
#define FM1715_DECRERR		17		/* 调用decrement函数出错 */
#define FM1715_READERR		18		/* 调用read函数出错 */
#define FM1715_LOADKEYERR	19		/* 调用LOADKEY函数出错 */
#define FM1715_FRAMINGERR	20		/* FM1715帧错误 */
#define FM1715_REQERR		21		/* 调用req函数出错 */
#define FM1715_SELERR		22		/* 调用sel函数出错 */
#define FM1715_ANTICOLLERR	23		/* 调用anticoll函数出错 */
#define FM1715_INTIVALERR	24		/* 调用初始化函数出错 */
#define FM1715_READVALERR	25		/* 调用高级读块值函数出错 */
#define FM1715_DESELECTERR	26
#define FM1715_CMD_ERR		42		/* 命令错误 */

/*寄存器地址定义*/
#define Page_Sel		0x00	/* 页写寄存器 */
#define Command			0x01	/* 命令寄存器 */
#define FIFO			0x02	/* 64字节FIFO缓冲的输入输出寄存器 */
#define PrimaryStatus	0x03	/* 发射器接收器及FIFO的状态寄存器1 */
#define FIFO_Length		0x04	/* 当前FIFO内字节数寄存器 */
#define SecondaryStatus	0x05	/* 各种状态寄存器2 */
#define InterruptEn		0x06	/* 中断使能/禁止寄存器 */
#define Int_Req			0x07	/* 中断请求标识寄存器 */
#define Control			0x09	/* 控制寄存器 */
#define ErrorFlag		0x0A	/* 错误状态寄存器 */
#define CollPos			0x0B	/* 冲突检测寄存器 */
#define TimerValue		0x0c	/* 定时器当前值 */
#define Bit_Frame		0x0F	/* 位帧调整寄存器 */
#define TxControl		0x11	/* 发送控制寄存器 */
#define CWConductance	0x12	/* 选择发射脚TX1和TX2发射天线的阻抗 */
#define ModConductance	0x13	/* 定义输出驱动阻抗 */
#define CoderControl	0x14	/* 定义编码模式和时钟频率 */
#define TypeBFraming	0x17	/* 定义ISO14443B帧格式 */
#define DecoderControl	0x1a	/* 解码控制寄存器 */
#define Rxcontrol2		0x1e	/* 解码控制及选择接收源 */
#define RxWait			0x21	/* 选择发射和接收之间的时间间隔 */
#define ChannelRedundancy	0x22	/* RF通道检验模式设置寄存器 */
#define CRCPresetLSB	0x23
#define CRCPresetMSB	0x24
#define MFOUTSelect		0x26	/* mf OUT 选择配置寄存器 */
#define TimerClock		0x2a	/* 定时器周期设置寄存器 */
#define TimerControl	0x2b	/* 定时器控制寄存器 */
#define TimerReload		0x2c	/* 定时器初值寄存器 */
#define TypeSH			0x31	/* 上海标准选择寄存器 */
#define TestDigiSelect	0x3d	/* 测试管脚配置寄存器 */

#endif