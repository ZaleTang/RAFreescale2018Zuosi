#ifndef _GETSIG_H
#define _GETSIG_H


//获取各通道AD值
#define AD0 adc_once(ADC_CHANNEL_AD0,ADC_12BIT)
#define AD1 adc_once(ADC_CHANNEL_AD1,ADC_12BIT)
#define AD2 adc_once(ADC_CHANNEL_AD2,ADC_12BIT)
#define AD3 adc_once(ADC_CHANNEL_AD3,ADC_12BIT)
#define AD4 adc_once(ADC_CHANNEL_AD4,ADC_12BIT)

void getsig(uint16_t *a);

#endif