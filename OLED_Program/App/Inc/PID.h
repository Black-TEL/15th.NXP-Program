#ifndef __PID_H__
#define __PID_H__
#include "common.h"
#include "include.h"

extern PID Speed_PID;
extern PID Turn_PID;

extern PID_iError* Speed_PID_iError;
extern PID_iError* Turn_PID_iError;

extern float PID_SpeedControl(float Point,float NowData_Laft,float NowData_Right,PID* K);
extern float PID_TurnCountrol(float NowData, float Point, PID* K);
extern void PID_DataInit();

#endif