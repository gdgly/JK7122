/**
  ******************************************************************************
  * @file GPIO/IOToggle/stm32f10x_it.c 
  * @author  MCD Application Team
  * @version  V3.0.0
  * @date  04/06/2009
  * @brief  Main Interrupt Service Routines.
  *         This file provides template for all exceptions handler and 
  *         peripherals interrupt service routine.
  ******************************************************************************
  * @copy
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2009 STMicroelectronics</center></h2>
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_it.h"	 
#include "stm32f10x_exti.h"
#include "stm32f10x_rcc.h"
#include "misc.h"
#include "pbdata.h"


void NMI_Handler(void)
{
}

void USART1_IRQHandler(void)
{
	u8 dat;
   if(USART_GetITStatus(USART1,USART_IT_RXNE)!=RESET)
   {
	   USART_ClearFlag(USART1, USART_FLAG_RXNE);
		if (!ComBuf.rec.end)//����û����
		{
			SetRecTimeOut(REC_TIME_OUT);//���ý��ճ�ʱ����
			dat=USART_ReceiveData(USART1);
			if (dat==(u8)(UART_REC_BEGIN))//֡ͷ
			{
				if(ComBuf.rec.ptr!=0) //���ֽ�
				{
					ComBuf.rec.ptr=0;//���½��� 
				}
				else
				{
					ComBuf.rec.buf[ComBuf.rec.ptr++]=dat;
				}
			}
			else if (dat==(u8)(UART_REC_END))//֡β
			{
				ComBuf.rec.buf[ComBuf.rec.ptr++]=dat;
				ComBuf.rec.end=TRUE;//���ս���
				ComBuf.rec.len=ComBuf.rec.ptr;//��������ݳ���
				ComBuf.rec.ptr=0;//ָ���������¿�ʼ�µ�һ֡����
				ComBuf.rec.TimeOut=0;//���ճ�ʱ����
			}
			else
			{
				if (ComBuf.rec.ptr>=REC_LEN_MAX)//������֡����
				{
					ComBuf.rec.ptr=0;//���½���
				}
				else
				{
					ComBuf.rec.buf[ComBuf.rec.ptr++]=dat;
				}
			}
		}	
        
   }
   if(USART_GetITStatus(USART1,USART_IT_ORE)!=RESET)
   {
	   USART_ClearFlag(USART1, USART_FLAG_ORE);
	   dat=USART_ReceiveData(USART1);
   
   }
}


/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval : None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval : None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval : None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval : None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval : None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval : None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSV_Handler exception.
  * @param  None
  * @retval : None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval : None
  */
void SysTick_Handler(void)
{
}

void TIM3_IRQHandler(void)
{
	static u8 num=0;
	u8 i;
	TIM_ClearITPendingBit(TIM3,TIM_IT_Update);
	//if(disp_time<99999)
	
	
//	else
//		disp_time=0;
	Key_Scan();
	//ʱ������
	if(SystemStatus==SYS_STATUS_TEST)
	{
		num++;
		if(num>9)//10mSʱ��
		{
			num=0;
			F_100ms=TRUE;//100ms��ʱ��־
			Test_value.Test_Time++;
			disp_time++;
			Test_Time++;
			//Voltage++;
		}
	}
	else
	{
		if(num!=0)
			num=0;
	}	
	for (i=0;i<MAXTSOFTTIMER;i++)
	{
		if (SoftTimer[i])
			SoftTimer[i]--;
		
	}
	if(F_Fail==0)
		Beep_Work();
	

}
/****************************************************************************
* ��    �ƣ�void EXTI9_5_IRQHandler(void)
* ��    �ܣ�EXTI9-5�жϴ�������
* ��ڲ�������
* ���ڲ�������
* ˵    ����
* ���÷������� 
****************************************************************************/
void EXTI9_5_IRQHandler(void)
{
}

/****************************************************************************
* ��    �ƣ�void EXTI1_IRQHandler(void)
* ��    �ܣ�EXTI2�жϴ�������
* ��ڲ�������
* ���ڲ�������
* ˵    ����
* ���÷������� 
****************************************************************************/
void EXTI0_IRQHandler(void)
{
	//delay_ms(1);//����
	 	 //�绡
	if(GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_0)==0)
	{
		SetSystemMessage(MSG_ARC);
	
	}
	EXTI_ClearITPendingBit(EXTI_Line0); //���LINE0�ϵ��жϱ�־λ  
}
 
//�ⲿ�ж�2�������
void EXTI1_IRQHandler(void)
{
	delay_ms(1);//����
	if(GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_1)==0)//�����ж�
	{
	
		SetSystemMessage(MSG_OVER);
	}
		 
	EXTI_ClearITPendingBit(EXTI_Line1);  //���LINE2�ϵ��жϱ�־λ  
}


/**************************************************************************
* ��    �ƣ�void EXTI2_IRQHandler(void)
* ��    �ܣ�EXTI2�жϴ�������
* ��ڲ�������
* ���ڲ�������
* ˵    ����
* ���÷������� 
****************************************************************************/
void EXTI2_IRQHandler(void)//��������
{
	delay_ms(1);
	if(GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_2)==0)
	{
		if(GetSystemStatus()==SYS_STATUS_IDLE)
		{
			SetSystemStatus(SYS_STATUS_START);//��������״̬
			run_stemp=0;//�ӵ�һ����ʼ
		
		}
	}
	EXTI_ClearITPendingBit(EXTI_Line2);
}

/****************************************************************************
* ��    �ƣ�void EXTI3_IRQHandler(void)
* ��    �ܣ�EXTI3�жϴ�������
* ��ڲ�������
* ���ڲ�������
* ˵    ����
* ���÷������� 
****************************************************************************/
void EXTI3_IRQHandler(void)//��λ����
{
	delay_ms(1);
	if(GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_3)==0)
	{
		if(GetSystemStatus()==SYS_STATUS_TEST)//������ͣ����
		{
			SetSystemStatus(SYS_STATUS_IDLE);
		
		}
		else
	   SetSystemStatus(SYS_STATUS_IDLE);
	}
	EXTI_ClearITPendingBit(EXTI_Line3);
}
