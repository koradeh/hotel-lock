/*******************************************************************
*				P89LPC932硬件I2C软件包（主）
* 1  使用I2C总线软件包时P1.2，P1.3切勿写为0，并要设置为开漏输出。
* 2  总线定义为P1.2=SCL，P1.3=SDA，需外接上拉电阻2－10k。
* 3  相应寄存器：
*    地址寄存器  I2ADR   用于存放自身从地址（从方式时才有用）
*    数据寄存器  I2DAT   接收／发送数据用
*    控制寄存器  I2CON   用于硬件I2C的设置、使能、启动、结束，
*                       应答控制，中断标志等。
*    状态寄存器  I2STAT  指示I2C总线的操作状态码，高5位有效，
*                       若I2C中断志置位，可查询此寄存器判断
*                        总线情况。
*    SCL占空比寄存器  I2SCLH、I2SCLL  设置SCL的频率发生。
*                        
*    此软件包是以查询方式完成各种总线操作的，在使用前应对总线进行检查，并
* 使用看门狗，以防等待总线而造成死机。
*	 文件名：HI2C_C51.C
*                                  更新时间：2002.11.05
*******************************************************************/

/* 定义LPC932的I2C相关寄存器的定义 */
sfr		I2ADR  = 0xDB;
sfr  	I2DAT  = 0xDA;
sfr		I2CON  = 0xD8;
sfr		I2STAT = 0xD9;
sfr		I2SCLH = 0xDD;
sfr		I2SCLL = 0xDC;
sbit	STA	   = I2CON^5;
sbit	SI	   = I2CON^3;

#define uchar 	unsigned char
#define GENERATE_STOP        0x54     /* 置位 STO, 复位 STA 、 SI          */
#define RELEASE_BUS_ACK      0x44     /* 复位 STO,STA,SI 并置位  AA (ack)  */
#define RELEASE_BUS_NOACK    0x40     /* 复位 STO,STA,SI 并置位 AA (noack) */
#define RELEASE_BUS_STA      0x64     /* 起动总线/重新起动总线, 置位 STA   */


/*******************************************************************
*                  申请总线
* 功能：进行I2C总线的初始化－－包括时钟选择，I2C使能，发送起始信号等等。
*       I2EN为1，设置为主机；CRSEL位为0，使用内部SCL发生器。
*******************************************************************/
void GetBus()
{ I2SCLH = 15;				/* 设置SCL高电平的PCLK周期数 				    */
  I2SCLL = 15;              /* 设置SCL低电平的PCLK周期数，6MHz时为100Kbit/S */
  /* 申请成为主机，起动总线。使用内部SCL发生器，I2EN和AA置位。              */
  I2CON = RELEASE_BUS_STA; 	
  while( SI==0 );        	/* 等待起始位的发送                             */
}


/*******************************************************************
*                    发送数据函数
* 功能：用于向总线发送数据 
* 入口参数：ACC   待发送的数据                   
*******************************************************************/
void SendByte(uchar c)
{ I2DAT = c;
  I2CON = RELEASE_BUS_ACK;    	/* 清除SI位等等   		*/
  while( SI==0 );        		/* 等待数据的发送 		*/
}



/*******************************************************************
*                    向无子地址器件发送字节数据函数               
* 功能：从启动总线到发送地址，数据，结束总线的全过程。
* 入口参数：sla		从器件地址
*           c		待发送的数据
* 出口参数：返回1表示操作成功，否则操作有误。
********************************************************************/
bit ISendByte(uchar sla, uchar c)
{ GetBus();                 	/* 启动总线                    */
  SendByte(sla);            	/* 发送器件地址，并接收应答位  */
  if( I2STAT!=0X18 )			/* 无从机应答则退出操作        */
  { I2CON = GENERATE_STOP;
    return(0);
  }

  SendByte(c);              	/* 发送数据                    */
  if( I2STAT!=0X28 )
  { I2CON = GENERATE_STOP;
    return(0);
  }
  I2CON = GENERATE_STOP;        /* 结束总线                    */ 
  return(1);
}



/*******************************************************************
*                    向有子地址器件发送多字节数据函数                 
* 功能：从启动总线到发送地址，子地址,数据，结束总线的全过程。
* 入口参数；sla		从器件地址
*           suba    子地址
*           s       发送内容的指针
*           no      发送字节数
* 出口参数：返回1表示操作成功，否则操作有误。
********************************************************************/
bit ISendStr(uchar sla, uchar suba, uchar *s, uchar no)
{ uchar i;

  GetBus();                 /* 启动总线               	*/
  SendByte(sla);            /* 发送器件地址           	*/
  if( I2STAT!=0X18 )
  { I2CON = GENERATE_STOP;
    return(0);
  }

  SendByte(suba);           /* 发送器件子地址 			*/
  if( I2STAT!=0X28 )
  { I2CON = GENERATE_STOP;
    return(0);
  }
     
  for(i=0; i<no; i++)
  { SendByte(*s);           /* 发送数据					*/
    if( I2STAT!=0X28 )
	{ I2CON = GENERATE_STOP;
	  return(0);
	}
    s++;
  } 

  I2CON = GENERATE_STOP;    /* 结束总线					*/ 
  return(1);
}



/*******************************************************************
*                    向无子地址器件读字节数据函数                
*功能：从启动总线到发送地址，读数据，结束总线的全过程。
*入口参数：sla		从器件地址
*          c        读出的数据(地址传送)
* 出口参数：函数返回1表示操作成功，否则操作有误。
********************************************************************/
bit IRcvByte(uchar sla, uchar *c)
{ GetBus();              	/* 启动总线					     */
  SendByte(sla+1);        	/* 发送器件地址				     */   
  if( I2STAT!=0X40 )
  { I2CON = GENERATE_STOP;
    return(0);
  }
  I2CON = RELEASE_BUS_NOACK; /* 接收一字节数据即发送非应答位 */
  while( SI==0 );            /* 等待接收数据				 */  
  if( I2STAT!=0X58 )
  { I2CON = GENERATE_STOP;
    return(0);
  }
  *c = I2DAT;                /* 读取数据					 */
  I2CON = GENERATE_STOP;     /* 结束总线					 */   
  return(1);
}



/*******************************************************************
*                    向有子地址器件读取多字节数据函数                
*功能：从启动总线到发送地址，子地址,读数据，结束总线的全过程。
*入口参数：sla 		从器件地址
*          suba		子地址
*		   s	    读出的内容存储区的指针
*          no		读no个字节。
*出口参数：函数返回1表示操作成功，否则操作有误。
********************************************************************/
bit IRcvStr(uchar sla,uchar suba,uchar *s,uchar no)
{ uchar i;

  GetBus();                	/* 启动总线						*/
  SendByte(sla);            /* 发送器件地址					*/
  if( I2STAT!=0X18)
  { I2CON = GENERATE_STOP;
    return(0);
  }
  SendByte(suba);           /* 发送器件子地址				*/
  if( I2STAT!=0X28 )
  { I2CON = GENERATE_STOP;
    return(0);
  }

  I2CON = RELEASE_BUS_STA;  /* 重新启动总线					*/
  while( SI==0 );
  SendByte(sla+1);
  if( I2STAT!=0X40 )
  { I2CON = GENERATE_STOP;
    return(0);
  } 
   
  for(i=0; i<no-1; i++)
  { I2CON = RELEASE_BUS_ACK;   /* 接收一字节数据并发送应答位		*/
    while( SI==0 );            /* 等待接收数据						*/  
    if( I2STAT!=0X50 )
	{ I2CON = GENERATE_STOP;
	  return(0);
	}
    *s = I2DAT;                /* 读取数据							*/ 
    s++;
  } 
  I2CON = RELEASE_BUS_NOACK;   /* 接收最后一字节数据并发送非应答位	*/
  while( SI==0 );  
  *s = I2DAT;
  I2CON = GENERATE_STOP;       /* 结束总线							*/ 
  return(1);
}

