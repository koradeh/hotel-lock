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
*使用看门狗，以防等待总线而造成死机。
*	 文件名：HI2C_C51.H
*                                  更新时间：2002.11.05
*******************************************************************/

#ifndef   HI2C_C51_H
  #define HI2C_C51_H

#ifdef    uchar 
  #define READYDEF 1   /*宏uchar已定义*/
#else  
  #define uchar unsigned char
#endif



/*软件包接口函数,其中adr为器件的从地址,suba为器件子地址*/

/*******************************************************************
                 向无子地址器件发送字节数据函数               
描述:     从启动总线到发送地址，数据，结束总线的全过程,从器件地址sla，
          待发送的数据c，如果返回1表示操作成功，否则操作有误。
********************************************************************/
extern bit ISendByte(uchar sla,uchar c);
 

/*******************************************************************
                    向有子地址器件发送多字节数据函数               
描述:     从启动总线到发送地址，子地址,数据，结束总线的全过程,从器件
          地址sla，子地址suba，发送内容是s指向的内容，发送no个字节。
           如果返回1表示操作成功，否则操作有误。
********************************************************************/
extern bit ISendStr(uchar sla,uchar suba,uchar *s,uchar no) ;


/*******************************************************************
                    向无子地址器件读字节数据函数               
描述:     从启动总线到发送地址，读数据，结束总线的全过程,从器件地
          址sla，返回值在c.
           如果返回1表示操作成功，否则操作有误。
********************************************************************/
extern bit IRcvByte(uchar sla,uchar *c);


/*******************************************************************
                    向有子地址器件读取多字节数据函数               
描述:     从启动总线到发送地址，子地址,读数据，结束总线的全过程,从器件
          地址sla，子地址suba，读出的内容放入s指向的存储区，读no个字节。
           如果返回1表示操作成功，否则操作有误。
********************************************************************/
extern bit IRcvStr(uchar sla,uchar suba,uchar *s,uchar no);



#ifndef  READYDEF
  #undef uchar
#endif

#endif
