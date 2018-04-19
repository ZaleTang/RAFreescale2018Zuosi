#include "include.h"


//定时器1中断函数
/*
void PIT_CH0_IRQHandler(void)
{
	int feedback=0,ia;
	
	uint8  txt[30]="X:",adt[30]="0",adt1[30]="0";
	PIT->CHANNEL[1].TFLG |= PIT_TFLG_TIF_MASK;	
	
	feedback=FTM_count_get(CFTM1);
    
    kp[0]=200+feedback/2.3;
    kd[0]=(float)feedback*3.8;
	
	getsig(AD_Data);
	AD_cha=AD_Data[2]-AD_Data[4];
	AD_he=AD_Data[2]+AD_Data[4];
	feror=AD_cha/AD_he;
	fvalue=(int)((AD_cha*40)/AD_he);
	car_direct(fvalue);

		for(ia=0;ia<5;ia++)
			{
				sprintf((char*)txt,"AD%02d:%04d  ",ia,AD_Data[ia]);
				sprintf((char*)adt,"fvalue=%04d ",fvalue);
				sprintf((char*)adt1,"cha=%04d he=%04d",AD_cha,AD_he);
				Uart_SendString(UARTR2,txt);
      if(!(ia%2))
        LCD_P6x8Str((1*(ia%2)),(ia/2),txt);
      else
       LCD_P6x8Str((64*(ia%2)),(ia/2),txt);
			LCD_P6x8Str(0,4,adt1);
			LCD_P6x8Str(3,5,adt);
			}
}
*/