#include <include.h>

/*************************************************************************
*  ��������:SystermInit
*  ����˵����ϵͳ��ʼ��
*  ʹ��˵���������еĳ�ʼ������д�����У�����ʱ����
*  
*************************************************************************/

void SystermInit()
{
  FTM_init();
  DATAinit();
	LED_Init();
	
	time_delay_ms(1000);
	LED_Ctrl(LEDALL,LEDON);
	time_delay_ms(1000);
	LED_Ctrl(LEDALL,LEDOFF);
	
}

//

/*************************************************************************
*  �������ƣ�DATAinit
*  ����˵�����豻������õĲ�����ʼ������д����SystemInit��
*  
*  
*************************************************************************/

void DATAinit()
{
  uint8_t i;
  fg=FP;
  for(i=0;i<5;i++)
    ADvalue[i]=0;
  
  for(i=0;i<3;i++)
  {
    kp[i]=0;ki[i]=0;kp[i]=0;
  }
  
  condition=0;
  fvalue=0;
  last_value=0;
  feror=0;
  last_err=0;

}


/*************************************************************************
*  �������ƣ�FTM_init
*  ����˵������ʼ������PWM��������ţ������������
*  
*  
*************************************************************************/


void FTM_init()               
{

    FTM_PWM_init(CFTM1, FTM_CH1,FTM_PTE7, 100, MID);//?????

    FTM_PWM_init(CFTM2, FTM_CH0,FTM_PTH0, 12500, 200);//PWM2 PTH0
    FTM_PWM_init(CFTM2, FTM_CH1,FTM_PTH1, 12500, 200);//PWM2 PTH1
	
		FTM_PWM_init(CFTM2, FTM_CH2,FTM_PTD0, 12500, 200);
		FTM_PWM_init(CFTM2, FTM_CH3,FTM_PTD1, 12500, 200);
}


//����ֵ�������ƺ��������Դ���������д��һ��
int abs(int number) 
{
  if(number>0)
    return number;
  else return -number;
}

float abs_f(float number)
{
	if(number>0)
		return number;
	else return -number;
}