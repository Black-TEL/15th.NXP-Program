#ifndef __SWEEP_H__
#define __SWEEP_H__
#include "common.h"
#include "include.h"

#define Set_long(n) n*30

extern int State;
extern int position_front,position_left,position_right;
extern int position_flag;
extern int sweep_leave;
extern int position_set_front;
extern int position_set_left;
extern int position_set_right;

extern void Sweep_Int();
extern void Sweep_Start();
extern void Sweep_Stop();
extern void Sweep_Turn();
extern void Sweep_Display();
extern void Sweep_Position_Date();
extern void Sweep_Position_GetDate();

#endif