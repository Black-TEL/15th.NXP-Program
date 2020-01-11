#include "common.h"
#include "include.h"

void All_Init()
{
   
/*********************PWMģ���ʼ��********************************************/
    FTM_PWM_init(FTM0, FTM_CH0,20000,0);        //���PWM��ʼ��
    FTM_PWM_init(FTM0, FTM_CH1,20000,0);        //���PWM��ʼ��
    FTM_PWM_init(FTM0, FTM_CH2,20000,0);        //���PWM��ʼ��
    FTM_PWM_init(FTM0, FTM_CH3,20000,0);        //���PWM��ʼ��
    
/*********************PID������ݳ�ʼ��****************************************/
    PID_DataInit();    
      
/*********************PIT�жϳ�ʼ��********************************************/    
    pit_init_ms(PIT0,1);
    set_vector_handler(PIT0_VECTORn ,PIT0_IRQHandler);
    enable_irq(PIT0_IRQn);
    
}

/*
 *�޷�����
 */
int32 range_protect(int32 duty, int32 min, int32 max)
{
	if (duty >= max)
	{
		return max;
	}
	if (duty <= min)
	{
		return min;
	}
	else
	{
		return duty;
	}
}