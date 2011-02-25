#ifndef _Group_Fun_H
#define _Group_Fun_H

#define Cheak_Fail  0
#define Check_OK    1
#define Check_Set   2


extern void Systemp_Init(void);         //系统初始化
extern void Delay_Nns(unsigned int Nns);    //延时微秒级
extern void Delay_Nms(unsigned int Nms);    //延时毫秒级
//蜂鸣器控制     Open_delay 开延时  Close_delay 关延时  Views 次数
extern void Beep_Ctrl(unsigned int Open_delay,unsigned int Close_delay,unsigned char Views);        
//LED灯控制， YGR 红绿黄三个灯，delay 延时，开关延时相信，Views 次数
extern void LED_Ctrl(unsigned char YGR,unsigned int delay,unsigned char Views);
	


#endif	//end Group_Fun.h
