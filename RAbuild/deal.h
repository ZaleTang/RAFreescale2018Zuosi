#ifndef _DEAL_H
#define _DEAL_H

#define lostline 0      //丢线临界电感值，可能用不到


//标志位枚举
typedef enum
{
	FP=0,		//普通赛道
	FCE=1,		//进入环岛标志
	FCD=2,		//环岛内标志
	FT=3,		//十字标志，估计永不上
}FLAG;


//extern 声明的变量不能在声明时直接赋值，否则extern就没用了

//标志位
extern FLAG fg;

//存储五个电感值的数据，打算从左到右0,1,2,3,4排序
extern uint16_t ADvalue[5],AD_Data[5],AD_cha,AD_he;

//xjb写的，用于在不知道条件时编译程序不报错�
extern uint8_t condition;

//方向控制传参
extern int fvalue;
extern int last_value;

//此处本打算用ferror，由于和MDK底层某文件撞名字了，故删去一个r，改为feror
extern float feror;
extern float last_err;

//PID参数，设置成了长度为三的参数，用于配置多速度档位或者其他不同情况下的PID值
extern float kp[3],ki[3],kd[3];			

void DirectionControl(void);	

#endif