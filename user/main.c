
/*LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL
��ƽ    ̨������S9KEAZ128���ܳ�MINI���İ�ĸ��
����    д��CHIUSIR
��E-mail  ��chiusir@163.com
������汾��V1.0
�������¡�2017��11��11��
�������Ϣ�ο����е�ַ��
����    վ��http://www.lqist.cn
���Ա����̡�http://shop36265907.taobao.com
------------------------------------------------
��dev.env.��IAR7.80.4
��Target  ��S9KEAZ128
��Crystal ��16.000Mhz
��busclock��40.000MHz
��pllclock��40.000MHz
QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ*/
/*************************����˵��******************************/
/****************************************************************
  ����ʲô���ܾ�ȥ����Ӧ����ǰ�ġ�//��
  ���������mini���İ��Լ�����ĸ���д�������汾���İ��޸�����
  TF��&OLED�汾���İ���OLED�ӿ���ADC�����е�ADC���ų�ͻ��ע���޸�
  PWM�ͱ������ɼ���������ͬʱ���ã���ΪFTMģ���ͻ
  ÿ�����Ժ�����д�� while��1����ͬʱʹ���������Ժ�����ִ�еĺ�����Ч
*******************************************************************/
/******************************************************************
�ӿڶ��壺
-------------------------------------------------------------
LED         ��Ƭ���ӿ�
//���İ���RGB����
LED0           PTC2
LED1           PTB4
LED2           PTE5
//ĸ����LED����
LED3           PTI4
LED4           PTH6
===============================================================
KEY        ��Ƭ���ӿ�
//���İ��ϰ���
KEY0          PTA0
//ĸ�尴��
KEY1          PTB5
KEY2          PTH2
KEY3          PTE6
===============================================================
���뿪��    ��Ƭ���ӿ�
KEY0          PTI2
KEY1          PTI3
KEY2          PTE2
KEY3          PTE3
===============================================================
TSL1401ģ��     ��Ƭ���ӿ�
VCC             5V
GND             GND
SI              I5/D5
SCK             I6/D6
ADC             AD8 C0/AD9 C1
===============================================================
��·���ģ��    ��Ƭ���ӿ�
VCC             5V
GND             GND
ADCͨ��         �ܽŹ�ϵ     
ADC12           F4      
ADC13           F5      
ADC14           F6      
ADC15           F7       
ADC4            B0      
ADC5            B1   
ADC6            B2       
ADC7            B3
-------------------------------------------------------------
��Դ��ػ�������    
ADC11           C3              
-------------------------------------------------------------
MPU6050        ��Ƭ���ӿ�   FLEXCOMM8
VCC             5V
GND             GND
SDA1            H3
SCL1            H4
//////////////////////////////////////////////////////////ͨ�ò��ֹ���//////////
�������        ��Ƭ���ӿ�   
VCC             5V
PWM1            FTM2-CH0  H0
PWM2            FTM2-CH1  H1
PWM3            FTM2-CH2  D0
PWM4            FTM2-CH3  D1
-------------------------------------------------------------
����ӿ�        ��Ƭ���ӿ�
VCC             �ɵ�
GND             GND
PWM1            FTM1-CH1  E7
-------------------------------------------------------------
����512������   ��Ƭ���ӿ�   
VCC             5V
GND             GND      
LSB/A           FTM0 E0    
DIR/B           H7     
LSB/A           FTM1 E7     
DIR/B           H5     
-------------------------------------------------------------
OLEDģ��        ��Ƭ���ӿ�
VCC             5V
GND             GND
SCK             F3
SDA             F2
RST             A7
DC              A6
-------------------------------------------------------------
����/USBTTL    ��Ƭ���ӿ�   FLEXCOMM0
VCC             5V
GND             GND
UART2_RX        I1    
UART2_TX        I0
=============================================================*/

#include "include.h"

int main(void)
{  
	
		int ia,ja;
	uint16_t temp=0,ka[9]={0x00,0xff,0,0,0,0,0,0xff,0x00};
	int ca[5];
	//uint8_t cc[350]="aaaaaaaa";
  DisableInterrupts ;                  //��ֹ�ж�    
  EnableInterrupts;    
	
	//SystermInit();
	
  //TestLED();//����GPIOmini���İ�RGB������ɫ��˸
  //Test_KEY(); //����GPIO��������
  //Test_KEY1(); //����GPIO���뿪�ع���
  //TestADC();//����ADCת����ͨ��OLED��ʾ��UART����
  //TestKBI();//����GPIO�ⲿ�ж� ĸ����K0��K1������Ч
  //TestPIT();//����PIT��ʱ�ж�
  //TestFTM_PWM();//����PWM/OLED��������ƹ���
  //TestUART012();//����UART012���ͼ������ж�
  //TestFTM_InputCapture();//���Ա���������ɼ�����
  //TestMPU6050();
  //Test_2100_8700();//����������ᴫ����
  //TestRTC();//LED��˸��ͬʱOLED����ʾʱ�䣬��λ��
	
	FTM_init();
	
	Motor_spd(200,200);

	LED_Init();
	//LED1 blue
	time_delay_ms(1000);
	LED_Ctrl(LEDALL,LEDON);
	time_delay_ms(1000);
	LED_Ctrl(LEDALL,LEDOFF);



//	SystemInit();
	uart_init(UARTR2,Remap,9600);
	LED_Ctrl(LED4,LEDON);
	time_delay_ms(500);
	LED_Ctrl(LED4,LEDOFF);

	//int ca=0;
		while(1)
		{
			FTM_PWM_Duty(CFTM1,FTM_CH1,100);
			LED_Ctrl(LED3,LEDON);
			time_delay_ms(500);
			LED_Ctrl(LED3,LEDOFF);
			//ka[0]=0xdd;
			ca[0]=adc_ave(ADC_CHANNEL_AD4,ADC_12BIT,10);
			ca[1]=adc_ave(ADC_CHANNEL_AD6,ADC_12BIT,10);
			ca[2]=adc_ave(ADC_CHANNEL_AD7,ADC_12BIT,10);
			ca[3]=adc_ave(ADC_CHANNEL_AD15,ADC_12BIT,10);
			ca[4]=adc_ave(ADC_CHANNEL_AD14,ADC_12BIT,10);
			//ka[6]=0xdd;
			
			
			for(ia=0;ia<5;ia++)
			{
			//Uart_SendChar(UARTR2,0);
			Uart_SendChar(UARTR2,ca[ia]);
			//Uart_SendChar(UARTR2,0);
			}
			Uart_SendChar(UARTR2,0000);
			LED_Ctrl(LEDALL,LEDON);
			time_delay_ms(500);
			LED_Ctrl(LEDALL,LEDOFF);
				time_delay_ms(1000);
			
		}
	
		
	


  
}



