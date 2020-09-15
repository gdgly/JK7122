//==========================================================
//�ļ����ƣ�Lcd2002.h
//����������ͨ��2002�ַ�Һ������ͷ�ļ�
//�ļ��汾��Ver1.0
//�������ڣ�2014.09.28
//�޸����ڣ�2014.09.28 16:38
//�ļ����ߣ�
//�ļ���ע����
//ע�������
//==========================================================
#ifndef __Lcd2002_h__
#define __Lcd2002_h__

//==========================================================
//LCD2002��ַ����
////9820A
#define LCD_RS PEout(2)  //RS
#define LCD_WR PEout(3)  //RW
#define LCD_E PEout(4)  //E
#define GPIO_WriteHigh(GPIOx,a) GPIOx->BSRR=(((uint8_t)(uint8_t)~(a))<<24)|(((uint32_t)(uint8_t)(a))<<8)
#define GPIO_WriteLow(GPIOx,a) GPIOx->BSRR=(((uint32_t)(uint8_t)~(a))<<16)|((uint32_t)(uint8_t)(a))
////sbit	LCD_DI = P2^7;//Һ�������������
////sbit	LCD_RW = P2^6;//Һ����д����
////sbit	LCD_EN = P2^5;//Һ��EN����(�����أ�1��Ч)
//#define LCD_CMD_WR_BUS  XBYTE[0x3FFF]
//#define LCD_CMD_RD_BUS  XBYTE[0x7FFF]
//#define LCD_DAT_WR_BUS  XBYTE[0xBFFF]
//#define LCD_DAT_RD_BUS  XBYTE[0xFFFF]

//9850
//#define LCD_CMD_WR_BUS  XBYTE[0xC0FF]
//#define LCD_CMD_RD_BUS  XBYTE[0xC8FF]
//#define LCD_DAT_WR_BUS  XBYTE[0xE000]
//#define LCD_DAT_RD_BUS  XBYTE[0xE8FF]
#define Bank1_LCD_C        ((u32)0x6C000000)
#define Bank1_LCD_D        ((u32)0x6C000002)

#define LCD_RAM           *(__IO uint8_t *)(Bank1_LCD_D)
#define LCD_REG           *(__IO uint8_t *)(Bank1_LCD_C)

//==========================================================
//LCD��������
#define LCD_CMD_XSFW	(u8)(0x30)	//��ʾ��λ����
#define LCD_CMD_DYHDZ	(u8)(0x80)	//��һ����ʾ��ַ
#define LCD_CMD_DEHDZ	(u8)(0xC0)	//�ڶ�����ʾ��ַ
#define LCD_CMD_DDDZ	(u8)(0x80)	//DDRAM��ַ����(D7=1):[D6-D0Ϊ��ַ,��7λ��ַд��AC��,���Ĳ������Դ�]
#define LCD_CMD_GGDZ	(u8)(0x40)	//GGRAM��ַ����(D6=1):[D5-D0Ϊ��ַ,�û��Զ����ַ����ַ���ַ]
#define LCD_CMD_GZFS	(u8)(0x38)	//������ʽ����(D5=1):[DL=D4=1:8λ���߿��(0Ϊ4λ);N=D3=2:������ʾ(0Ϊһ��);F=D2=0:5X7����(0Ϊ5X11)]
#define LCD_CMD_HMGD	(u8)(0x18)	//�������������(D4=1):[S/C=D3=1:�������(0Ϊ������);R/L=D2=1:�ҹ���(0�����)]
#define LCD_CMD_XSZT	(u8)(0x0C)	//��ʾ״̬����(D3=1):[D=D2=1:��ʾ��(0Ϊ��);C=D1=0:��겻��ʾ(1��ʾ),B=D0=0:��˸�ر�(1����)]
#define LCD_CMD_SRFS	(u8)(0x06)	//���뷽ʽ����(D2=1):[I/D=D1=1:AC���ݵ�ַָ���Զ���1(0Ϊ����),S=D0=1:���������/����ƶ�(0Ϊ��ֹ)]
#define LCD_CMD_DZQL	(u8)(0x02)	//���ݵ�ַָ����������(D1=1)
#define LCD_CMD_XSQP	(u8)(0x01)	//��ʾ��������(D0=1)

//==========================================================
//��������
#define LCDADDR_X_LIMIT ((u8)(16-1))//�е�ַ��ֵ(20��)
#define LCDADDR_Y_LIMIT ((u8)(2-1))//�е�ַ��ֵ(2��)
#define LCDADDR_MAX 	((u8)(16*2))//���һ����ʾ���ַ�����(40��)

//LCD����ṹ�嶨��
typedef struct 
{
	u8 x;	//������
	u8 y;	//������
}LcdAddr_TypeDef;

//==========================================================
//ȫ�ֱ���
extern LcdAddr_TypeDef LcdAddr;//LCD��ַ�ṹ��

//==========================================================
//�����б�
//u8 Lcd_ReadStatus(void);//��LCD״̬��
void Lcd_ReadBF(void);//��ȡҺ����״̬λֱ��BF��־��Ч(��200�κ��Զ��˳�)
void Lcd_WriteCmd(u8);//д����
void Lcd_WriteData(u8);//д����
//u8 Lcd_ReadData(void);//����ǰ��ַ������
void Lcd_SetAddr(void);//LCD����LcdAdr����
// void Lcd_WriteDataAt(u8 dat);//��ַLcdAdrд����
//u8 Lcd_ReadDataAt(void);//��ַLcdAdr������
void Lcd_Clr(void);//ȫ������
void Lcd_Init(void);//Һ����ʼ��
void Lcd_AddrUpdate(void);//LCD����LcdAdr����


#endif
