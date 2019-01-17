#include "timer.h"
#include "usart.h"
#include "dali.h"



void TIM2_Init(u16 arr,u16 psc)
{
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

	TIM_TimeBaseStructure.TIM_Period = arr;
	TIM_TimeBaseStructure.TIM_Prescaler =psc;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

	TIM_ITConfig(TIM2,TIM_IT_Update ,ENABLE);

	TIM_Cmd(TIM2, ENABLE);
}

void TIM2_IRQHandler(void)
{
	static u8 tick = 0;

	if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)
	{
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);

		if(tick < 96)
		{
			tick ++;

			if(tick >= 96)					//Լ10ms
			{
				tick = 0;

				Usart1ReciveFrameEnd();		//���USART1�Ƿ�������һ֡����
				Usart3ReciveFrameEnd();		//���USART3�Ƿ�������һ֡����
				Usart4ReciveFrameEnd();		//���UART4�Ƿ�������һ֡����
				Usart5ReciveFrameEnd();		//���UART5�Ƿ�������һ֡����
			}
		}

		if(dali_get_flag()==RECEIVING_DATA)
		{
			dali_receive_tick();
		}
		else if(dali_get_flag()==SENDING_DATA)
		{
			dali_send_tick();
		}
	}
}






