#include "include.h"

int feedback=0;
//��ʱ��1�жϺ���
void PIT_CH1_IRQHandler(void)
{
		feedback=FTM_count_get(CFTM1);
    
    kp[0]=200+feedback/2.3;
    kd[0]=(float)feedback*3.8;


}