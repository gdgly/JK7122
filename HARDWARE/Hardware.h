//==========================================================
//�ļ����ƣ�Hardware.h
//�ļ�������Ӳ������ͷ�ļ�
//�ļ��汾��Ver1.0
//�������ڣ�2014.12.29
//�޸����ڣ�2015.09.06 10:46
//�ļ����ߣ�
//��ע˵������
//ע�������
//==========================================================
#ifndef __Hardware_H__
#define __Hardware_H__

//#include "STC89C5xRC_RDP.h"
//#include "Stc12c5A60s2.h"

//==========================================================
//ȫ�ֱ�������
//extern idata vu8 N4_377_Buf;//N4-377�������
//extern idata vu8 N5_377_Buf;//N5-377�������

//==========================================================
#define Os_Enter_Critical() (EA=0)	//���ж�
#define Os_Exit_Critical() 	(EA=1)	//���ж�
#define Open_Uarts_Int() 	(ES=1)	//���������ж�
#define Close_Uarts_Int() 	(ES=0)	//���������ж�

//==========================================================
//Stc12ϵ�� CPU ID ADDR (λ��idata ��)
#define CPU_ID_ADDR (0xF1)

//==========================================================
//MCP3202�ܽŶ���(SPI,12bit��αƽ���A/D,2ͨ��,2.7V-5.5V,50-100kbpb)
//sbit MCP3202_CS 	= P1^1;//�͵�ƽ��Ч
//sbit MCP3202_DOUT	= P1^2;
//sbit MCP3202_DIN	= P1^3;
//sbit MCP3202_CLK	= P1^4;

//MCP3202ͨ�������ֶ���(����λ1,����/�������1,ͨ������1,���ݷ�������1,��λ1)
#define MCP3202_CH0	(0xD0)	
#define MCP3202_CH1	(0xF0)

//==========================================================
//TLC5618�ܽŶ���(12bit D/A,2ͨ��,1.2MHz,+5V����)
//sbit TLC5618_CS 	= P1^5;//�͵�ƽ��Ч
//sbit TLC5618_CLK	= P1^4;
//sbit TLC5618_DIN	= P1^3;

//TLC5618ͨ�������ֶ���
//#define TLC5618_CHA	(0x8000)	//D15=1��ͨ��A
//#define TLC5618_CHB	(0x0000)	//D15=0��ͨ��B
//#define TLC5618_MASK (0x0fff)	//12λ����

//==========================================================
//CD4040��λ�����źţ�����������ƣ�CD4040-RST-11,RST=1ʱ��λ�����ȫ��
//sbit WaveOutEnable = P3^4;
#define Sin_Clk_Enable() 	(TIM_Cmd(TIM2,ENABLE))	//������Ҳ�Ƶ��
#define Sin_Clk_Disable() 	(TIM_Cmd(TIM2,DISABLE))	//��ֹ���Ҳ�Ƶ�����

//==========================================================
//74LS377��ַ����
//==========================================================
//#define N4_377_BUS  XBYTE[0xEFFF]	//A15
//--------------------------------------
//D7-FEED-LM324-FEED/PROC_C -1 (PROC_C-ULN2004-PLC RELAY)
//D6-PASS_C-ULN2004-PASS -1 (Led Pass/PLC RELAY)
//D5-FAIL_C-ULN2004-FAIL -1 (Led Fail/PLC RELAY)
//D4-HVDCKZ-LM324-HV-RY0/DCNYKZ -1 (HV RELAY1/4053_C)
//D3-HVACKZ-ULN2004-HV-RY1 -1 (HV RELAY0)
//D2-HUILU-ULN2004-HUILUKZ -1
//D1-NY-ULN2004-NYKZ -1
//D0-JD-ULN2004-JDKZ -1
//--------------------------------------
//N19_574_Buf
//--------------------------------------
//#define HW_PLC_START_MASK	((u8)(ClrD7))
//#define HW_PLC_START_ON		((u8)(SetD7))
#define HW_BEEP_MASK		((u8)(ClrD0))
#define HW_BEEP_ON			((u8)(SetD0))

#define HW_LED_PASS_MASK	((u8)(ClrD1))
#define HW_LED_PASS_ON		((u8)(SetD1))



#define HW_LED_HV_MASK		((u8)(ClrD3))
#define HW_LED_HV_ON		((u8)(SetD3))

//#define HW_RELAY_HV1_MASK	((u8)(ClrD3))
//#define HW_RELAY_HV1_ON		((u8)(SetD3))

#define HW_RELAY_RET_MASK	((u8)(ClrD1))//������ʱ�򹦷����
#define HW_RELAY_RET_ON		((u8)(SetD1))

//#define HW_AMP_ACW_MASK		((u8)(ClrD1))
//#define HW_AMP_ACW_ON		((u8)(SetD1))

//#define HW_AMP_GND_MASK		((u8)(ClrD0))
//#define HW_AMP_GND_ON		((u8)(SetD0))

//==========================================================
//#define N5_377_BUS  XBYTE[0xBFFF]	//A14
//==========================================================
//D7-
//D6-FMQ-9013 -1
//D5-HIGH_LED-ULN2004-HVLED -1
//D4-NYCYKZ-LM324-NYCYQH-4053_B/A
//D3-LC4-ULN2004-LCKZ4-RRY4_900  -1
//D2-LC3-ULN2004-LCKZ3-RRY3_9k   -1
//D1-LC2-ULN2004-LCKZ2-RRY2_90k  -1
//D0-LC1-ULN2004-LCKZ1-RRY1_900k -1
//--------------------------------------
//N42_574_Buf
//--------------------------------------




//#define HW_SAMPLE_NYIR_MASK	((u8)(ClrD6))
//#define HW_SAMPLE_NYIR		((u8)(SetD6))

#define HW_SAMPLE_DC_MASK	((u8)(ClrD0))
#define HW_SAMPLE_DC_ON		((u8)(SetD0))

#define HW_LED_FAIL_MASK	((u8)(ClrD2))
#define HW_LED_FAIL_ON		((u8)(SetD2))

#define HW_RELAY_H_MASK	((u8)(ClrD5))
#define HW_RELAY_H 		((u8)(SetD5))

#define HW_RELAY_L_MASK	((u8)(ClrD6))
#define HW_RELAY_L 		((u8)(SetD6))

#define HW_RELAY_9K_MASK	((u8)(ClrD1))
#define HW_RELAY_9K 		((u8)(SetD1))


//==========================================================
//Ƶ��ֵ
enum FreqEnum
{	
	FREQ_50 ,
	FREQ_60 ,
	FREQ_400 ,
};

//==========================================================
//ϵͳʱ�ӽ���
#define TICKS_PER_SEC 100	//ϵͳʱ��ÿ���������100x10mS(T0)=1S
#define TICKS_PER_SEC_SOFTTIMER 100	//��ʱ��ʱ��ÿ���������100x10mS=1S

//��������
#define SYSTEM_CLOCK (11059200)//11.0592MHz
//#define SYSTEM_CLOCK (12000000)//12MHz

#define TIMER0_TICKS (u16)(65535-SYSTEM_CLOCK/12/100) //10mS(100Hz)��ʱֵ,12T
#define TH0_TICKS	(u8)(TIMER0_TICKS>>8)	//10ms�ж�
#define TL0_TICKS	(u8)(TIMER0_TICKS)		

//#define TIMER1TICKS (u16)(65535-SYSTEM_CLOCK/12/20) //50mS(20Hz)��ʱֵ,12T
//#define TH1_TICKS	(u8)(TIMER1TICKS>>8)	//50ms�ж�
//#define TL1_TICKS	(u8)(TIMER1TICKS)		
//
#define BAUD_RATE_9600 (9600)
#define BAUD_TICKS (u8)(256-SYSTEM_CLOCK/12/32/BAUD_RATE_9600) //12T

//#define TIMER2TICKS_20mS (u16)(65535-SYSTEM_CLOCK/12/50) //20mS(50Hz)��ʱֵ,12T
//#define TIMER2TICKS_20mS (u16)(65535-SYSTEM_CLOCK/12/25) //40mS(25Hz)��ʱֵ,12T
//#define TH2_TICKS_20mS	(u8)(TIMER2TICKS_20mS>>8)
//#define TL2_TICKS_20mS	(u8)(TIMER2TICKS_20mS)		

//#define TIMER2TICKS_1mS (u16)(65535-SYSTEM_CLOCK/12/1000) //1mS(1kHz)��ʱֵ,12T
//#define TH2_TICKS_1mS	(u8)(TIMER2TICKS_1mS>>8)
//#define TL2_TICKS_1mS	(u8)(TIMER2TICKS_1mS)		

#define BAUD_RATE_9600 (9600)
#define UART0_BAUD_9600 (u16)(65536-SYSTEM_CLOCK/32/BAUD_RATE_9600)//T2-12T
#define BAUD_9600_TICKS_H	(u8)(UART0_BAUD_9600>>8)		
#define BAUD_9600_TICKS_L	(u8)(UART0_BAUD_9600)		

//==========================================================
//��������
void Da_Out(u16 dat);//���ź�D/A���
void Arc_Out(u8 arc);//�绡�ȼ����

u16 Read_Ad_Ch0(void);//��ȡͨ��0��A/Dֵ
u16 Read_Ad_Ch1(void);//��ȡͨ��1��A/Dֵ

//void Range_Control(u8 dat);//���̿���

void Frequency_Control(u8 dat);//���Ƶ�ʿ���

void Amp_Output_On(void);//�����������������
void Amp_Output_Off(void);

void Dc_Output_On(void);//DC����Ͳ���
void Dc_Output_Off(void);

void Beep_On(void);//��������
void Beep_Off(void);//�ط�����

void Led_HV_On(void);//����ѹ��
void Led_HV_Off(void);//�ظ�ѹ��

void Led_Fail_On(void);//��������
void Led_Fail_Off(void);//�ر�����

void Led_Pass_On(void);//���ϸ��
void Led_Pass_Off(void);//�غϸ��


void Plc_Start_On(void);//��PLC����
void Plc_Start_Off(void);//��PLC����

//void Start_Timer0_Count(void);//����T0Ϊ16λ������
void Start_Timer0_10ms(void);//����T0Ϊ10ms��ʱ��
void Stop_Timer0(void);//�ر�T0

//void Start_Timer1_Count(void);//����T1Ϊ16λ������
//void Start_Timer1_50ms(void);//����T1Ϊ50ms��ʱ��
void Start_Timer1_Baud(void);//����T1Ϊ�����ʷ�����
void Stop_Timer1(void);//�ر�T1

//void Start_Timer2_Baud_9600(void);//����T2Ϊ�����ʷ�����
//void Start_Timer2_20ms(void);//����T2Ϊ20ms��ʱ��
//void Start_Timer2_1ms(void);//����T2Ϊ1ms��ʱ��
//void Stop_Timer2(void);//�ر�T2

//void ReadCpuId(u8 *buf);//��ȡCPU���к�

void Start_Uart(void);//���ڿ���
void Stop_Uart(void);//���ڹر�

void Cpu_Init(void);//��Ƭ����ʼ��

void Hardware_Init(void);//Ӳ����ʼ��

void ResetSys(void);//ϵͳ��λ


#endif
