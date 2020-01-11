#include "include.h"
#include "Control.h"

void MotorControl(int Power)
{
     if(Power>=0)
      {
        FTM_PWM_Duty(FTM0, FTM_CH0, Power);
        FTM_PWM_Duty(FTM0, FTM_CH1, 0);
        FTM_PWM_Duty(FTM0, FTM_CH2, Power);
        FTM_PWM_Duty(FTM0, FTM_CH3, 0);
      }
      else
      {
        FTM_PWM_Duty(FTM0, FTM_CH0, 0);
        FTM_PWM_Duty(FTM0, FTM_CH1, -Power);
        FTM_PWM_Duty(FTM0, FTM_CH2, 0);
        FTM_PWM_Duty(FTM0, FTM_CH3, -Power);
      }
}
void Sweep_MotorCountrol_Out(int Power_Out_Left, int Power_Out_Right)
{
    FTM_PWM_Duty(FTM0, FTM_CH4, Power_Out_Left);
    FTM_PWM_Duty(FTM0, FTM_CH5, Power_Out_Right);
}
        
void MotorCountrol_Out(int Power_Out_Left, int Power_Out_Right)
{
/********************左轮电机输出**********************************************/  
     if(Power_Out_Left>=0)
     {
        FTM_PWM_Duty(FTM0, FTM_CH0, Power_Out_Left);
        FTM_PWM_Duty(FTM0, FTM_CH1, 0);
     }
     else
     {
        FTM_PWM_Duty(FTM0, FTM_CH0, 0);
        FTM_PWM_Duty(FTM0, FTM_CH1, -Power_Out_Left);        
     }
     
/********************右轮电机输出**********************************************/   
     if(Power_Out_Right>=0)
     {
        FTM_PWM_Duty(FTM0, FTM_CH2, Power_Out_Right);
        FTM_PWM_Duty(FTM0, FTM_CH3, 0);
     }
     else
     {
        FTM_PWM_Duty(FTM0, FTM_CH2, 0);
        FTM_PWM_Duty(FTM0, FTM_CH3, -Power_Out_Right);
     }
}