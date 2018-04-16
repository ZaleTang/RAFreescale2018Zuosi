#ifndef _MOTOR_H
#define _MOTOR_H



/**************舵机极值****************************************************/
//极左
#define MAX_L -500

//极右
#define MAX_R 500

//中值
#define MID 100

/**************控制函数****************/

void car_direct(int Angle);

void Motor_speedL(int speed);
void Motor_speedR(int speed);

void Motor_spd(int spdl, int spdr);	//MotorB MotorA


#endif