#include "pbdata.h"
#include "keyboard.h"
//==========================================================
//ȫ�ֱ���
Key_TypeDef Keyboard;//����ṹ��

static u8 LastKeyVal;//�ϴμ�ֵ
static u8 LastKeyTicks;//��������
static u8 ContinueKeyTicks;//������������



void Keyboard_Init(void)
{
	
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_10MHz;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_14|GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
//	GPIO_SetBits(GPIOB,GPIO_Pin_14);
//	GPIO_SetBits(GPIOB,GPIO_Pin_15);
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_12|GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPD;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
	Keyboard.value=KEY_NONE;//��ֵΪ��
	Keyboard.state=FALSE;	//������Ч
	Keyboard.continuance=FALSE;//����������Ч
	
	LastKeyVal=KEY_NONE ;//�ϴμ�ֵ
	LastKeyTicks=0;//��������
	ContinueKeyTicks=0;//������������
	GPIO_ResetBits(GPIOB,GPIO_Pin_14);
	GPIO_ResetBits(GPIOB,GPIO_Pin_15);
}

//==========================================================
//�������ƣ�Key_Identiry
//�������ܣ�����ʶ��
//��ڲ�������
//���ڲ�����U8 ��ֵ
//�������ڣ�2014.09.25 
//�޸����ڣ�2014.09.29 14:45
//��ע˵�������������źţ�0��Ч
//==========================================================
u8 Key_Identiry(void)
{
	
	u8 key;
//	if((GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_3)==0)&&(GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_2)==0))
//	{
//		key=KEY_RESET;
//	}
//	else if(GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_3)==0)
//	{
//		key=KEY_RESET;
//	}
//	else if(GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_2)==0)
//	{
//		key=KEY_START;
//	}
//	
//	else
	if((GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12)==0)||(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_13)==0))
	{
		GPIO_SetBits(GPIOB,GPIO_Pin_14);
		if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12)==0&&GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_13)==0)
		{
			key=KEY_LEFT;
		}else
		
		if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12)==0)
		{
			key=KEY_UP;
		}
		else if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_13)==0)
		{
		
			key=KEY_SET;
//			if()
//				key=KEY_LEFT;
			
		}
		else
		{
		
			GPIO_ResetBits(GPIOB,GPIO_Pin_14);
			GPIO_SetBits(GPIOB,GPIO_Pin_15);
			if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12)==0)
			{
				key=KEY_ENTER;
			}
			else if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_13)==0)
			{
			
				key=KEY_DOWN;
			}
			else
			{
			
				key=KEY_NONE;
			}
		
		}
	
	}
	else 
		key=KEY_NONE;

	GPIO_ResetBits(GPIOB,GPIO_Pin_14);
	GPIO_ResetBits(GPIOB,GPIO_Pin_15);
	return (key);
}
//==========================================================
//�������ƣ�Key_Init
//�������ܣ������ṹ���ʼ��
//��ڲ�������
//���ڲ�������
//�������ڣ�2014.09.29
//�޸����ڣ�2014.09.29 10:49
//��ע˵������
//==========================================================
void Key_Init(void)
{
	Keyboard.value=KEY_NONE;//��ֵΪ��
	Keyboard.state=FALSE;	//������Ч
	Keyboard.continuance=FALSE;//����������Ч
	
	LastKeyVal=KEY_NONE;//�ϴμ�ֵ
	LastKeyTicks=0;//��������
	ContinueKeyTicks=0;//������������
}

//==========================================================
//�������ƣ�Key_Read
//�������ܣ���ȡ����
//��ڲ�������
//���ڲ�������
//�������ڣ�2014.09.29
//�޸����ڣ�2014.09.29 10:50
//��ע˵������
//==========================================================
u8 Key_Read(void)
{
	if (Keyboard.state)	//�м�����
	{
		Keyboard.state=FALSE;
		//Beep_One();	//��������һ��
		return (Keyboard.value);
	}
	//��ֱ�Ӵ����Դ��ͨ�ð���
	return (KEY_NONE);	
}

//==========================================================
//�������ƣ�Key_Read_WithTimeOut
//�������ܣ�����ʽ��ȡ����
//��ڲ�����ticks:�ȴ�������(50ms����)
//���ڲ���������ֵ
//�������ڣ�2014.09.29
//�޸����ڣ�2014.09.29 10:56
//��ע˵����ֱ��������Ӧ����ʱ��
//==========================================================
u8 Key_Read_WithTimeOut(u8 ticks)
{
//	if (ticks)//��ʱ�ȴ�����
//		{
			SetSoftTimer(KEYBOARD_SOFTTIMER,ticks);//���ð�����ʱ����(����ʱ������,50ms����)
				
			while ((!GetSoftTimerOut(KEYBOARD_SOFTTIMER))&&(!Keyboard.state)) //��ʱδ�������ް�������
				{
//					RunOnKeyFree();//�ڰ����ȴ������д�������ҵ��
				}
//		}
//	else//���޵ȴ�����
//		{
//			while (!Keyboard.state) 
//				{
//					RunOnKeyFree();//�ڰ����ȴ������д�������ҵ��
//				}			
//		}
	return Key_Read();//��������
}
//==========================================================
//�������ƣ�Key_Scan
//�������ܣ�����ɨ��
//��ڲ�������
//���ڲ�������
//�������ڣ�2014.09.28 
//�޸����ڣ�2014.09.28 11:01
//��ע˵������10mS�жϵ���
//==========================================================
void Key_Scan(void)
{
	u8 keyval;
	
	keyval = Key_Identiry();//����ʶ�𣬷��ؼ�ֵ

	//��������ʶ��
	if (keyval==KEY_NONE)//�޼�
	{
		if (LastKeyVal)	//�ϴ��м����̰����б�
		{
			if ( (LastKeyTicks>SHORTKEYCOUNT) && (LastKeyTicks<LONGKEYCOUNT) )
			{
				Keyboard.value=LastKeyVal;	//��ֵ
				Keyboard.state=TRUE;		//�а���
			}
		}
		LastKeyVal=KEY_NONE;
		LastKeyTicks=0;
		Keyboard.continuance=FALSE; //��������	
	}
	else	//�м�
	{
		if (LastKeyVal==keyval)//�ϴΰ����ͱ��ΰ�����ͬ
		{
			if (LastKeyTicks<LONGKEYCOUNT+1)//������������100x10mS
				LastKeyTicks++;
			
			if (LastKeyTicks==LONGKEYCOUNT)//���ڳ�����������
			{
				ContinueKeyTicks=0;//������������
				keyval|=LONG_PRESS;	//������
				Keyboard.value=keyval;	//��ֵ
				Keyboard.state=TRUE;	//�а���
//				Keyboard.continuance=FALSE; //��������
				Keyboard.continuance=TRUE; //��������
			}
			else if (LastKeyTicks>LONGKEYCOUNT)//���ڳ�����������
			{
				if(HW_KEYBOARD_CONTINUE_SUPPORT)//����������Ч�б�
				{
					keyval|=LONG_PRESS;	//������
					Keyboard.value=keyval;//��ֵ
//					Keyboard.state=TRUE;//�а���
					Keyboard.continuance=TRUE; //��������
					ContinueKeyTicks++;
					if(ContinueKeyTicks>CONTINUEKEYCOUNT)//��������������
					{
						ContinueKeyTicks=0;//������������
						if(Keyboard.state==FALSE)//�����Ѷ�ȡ
							Keyboard.state=TRUE;//�а���
					}
				}
			}					
		}
		else//�ϴΰ����ͱ��ΰ�����ͬ
		{
			if(LastKeyVal == 0x68 && keyval == 0x67)
			{
				SetSystemStatus(SYS_STATUS_IDLE);//����
				Beep_Off();
			}
			LastKeyVal=keyval;
			LastKeyTicks=0;
			
		}
	}
}

