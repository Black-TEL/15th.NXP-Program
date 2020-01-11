#include "common.h"
#include "include.h"

void All_Init()
{
   
/*********************PWM模块初始化********************************************/
    FTM_PWM_init(FTM0, FTM_CH0,20000,0);        //电机PWM初始化
    FTM_PWM_init(FTM0, FTM_CH1,20000,0);        //电机PWM初始化
    FTM_PWM_init(FTM0, FTM_CH2,20000,0);        //电机PWM初始化
    FTM_PWM_init(FTM0, FTM_CH3,20000,0);        //电机PWM初始化
    
/*********************PID相关数据初始化****************************************/
    PID_DataInit();    
      
/*********************PIT中断初始化********************************************/    
    pit_init_ms(PIT0,1);
    set_vector_handler(PIT0_VECTORn ,PIT0_IRQHandler);
    enable_irq(PIT0_IRQn);
    
}

/*
 *限幅保护
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