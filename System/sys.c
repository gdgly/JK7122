#include "pbdata.h"
void RCC_Configuration(void)
{
    SystemInit();//72m
	//uart1 2
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOE|RCC_APB2Periph_GPIOF|RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOC|
	RCC_APB2Periph_USART1|RCC_APB2Periph_GPIOG|RCC_APB2Periph_GPIOD,ENABLE);
	
	
	//RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1,ENABLE);
	
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC|RCC_APB1Periph_TIM3,ENABLE);
	RCC->APB2ENR |= 0x00000001; //����afioʱ��
//GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE); //�ر�JTAG 
//AFIO->MAPR = (0x00FFFFFF & AFIO->MAPR)|0x04000000; //�ر�JTAG 
	//time2
	//RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	//  adc
	//RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	//RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1,ENABLE);
	//RCC_ADCCLKConfig(RCC_PCLK2_Div6);//12M  ���14M
}




