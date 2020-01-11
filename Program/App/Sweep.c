#include "include.h"
#include "Sweep.h"

int State;
int sweep_leave;
int position_flag;
int position_front,position_left,position_right;
int position_set_front;
int position_set_left;
int position_set_right;

void Sweep_Int()
{
     position_flag = 1;
     State = stop;
     sweep_leave = 0;
     distance1 = 100;
     distance2 = 100;
     distance3 = 100;
     //gpio_set(PTA2,0);     
     //MotorCountrol_Out(0, 0);
}

void Sweep_Start()
{
     //gpio_set(PTA2,1);     
     MotorCountrol_Out(5000, 2800);
    // Sweep_MotorCountrol_Out(120, 120);
}

void Sweep_Stop()
{
     //gpio_set(PTA2,0);     
     MotorCountrol_Out(0, 0);
}

void Sweep_Turn()
{
     //gpio_set(PTA2,1);     
     MotorCountrol_Out(16000, -14000);
     //MotorCountrol_Out(0, 4000);
     while(distance3 > 15 && State == turn)
     {
        return;
     }
     State = start;
}

void Sweep_Display()
{ 
  if(position_front < 40 && State != stop)
  {
    State = turn;
  }
//  if(State == turn && distance1 > 50)
//  {
//    State = start;
//  }
  if((position_front > (Set_long(sweep_leave) - 50)) && (position_front < (Set_long(sweep_leave) + 50)) && (position_left < (Set_long(sweep_leave) + 50)) && (position_left > (Set_long(sweep_leave) - 50)) && (position_right > (Set_long(sweep_leave) - 50)) && (position_right < (Set_long(sweep_leave) + 50)))
  {
    position_flag = 1;
    sweep_leave++;
  }
}

void Sweep_Position_GetDate()
{
  position_front = distance1;
  position_left = distance2;
  position_right = distance3;
}

void Sweep_Position_Date()
{
  position_set_front = distance1;
  position_set_left  = distance2;
  position_set_right = distance3;
}