#include "include.h"
#include "PID.h"

PID Speed_PID;
PID Turn_PID;

PID_iError* Speed_PID_iError;
PID_iError* Turn_PID_iError;

float PID_SpeedControl(float Point,float NowData_Laft,float NowData_Right,PID* K)
{
      float SpeedControl;
      
      Speed_PID_iError->iError = Point - ((NowData_Laft + NowData_Right)/2);
      Speed_PID_iError->iError = Speed_PID_iError->iError * 0.8 + Speed_PID_iError->Last_iError * 0.2;
      Speed_PID_iError->Sum_iError += Speed_PID_iError->iError; 
      
      Speed_PID_iError->Sum_iError = range_protect((int)Speed_PID_iError->Sum_iError,-100,100);
      
      SpeedControl = K->Kp * Speed_PID_iError->iError + K->Ki * Speed_PID_iError->Sum_iError;
      
      Speed_PID_iError->Last_iError = Speed_PID_iError->iError;
      
      return SpeedControl;
}

float PID_TurnCountrol(float NowData, float Point, PID* K)
{
      float TurnCountrol;
      
      Turn_PID_iError->iError = Point - NowData;
      Turn_PID_iError->iError_iError = Turn_PID_iError->iError - Turn_PID_iError->Last_iError;
      
      TurnCountrol = K->Kp * Turn_PID_iError->iError + K->Kd * Turn_PID_iError->iError_iError;
      
      Turn_PID_iError->Last_iError = Turn_PID_iError->iError;
      
      return TurnCountrol;
}

void PID_DataInit()
{
     Speed_PID.Kp = 1;
     Speed_PID.Ki = 2;
     Speed_PID.Kd = 3;
     
     Turn_PID.Kp = 12;
     Turn_PID.Ki = 101;
     Turn_PID.Kd = 200;
     
//     Speed_PID_iError->iError = 0;
//     Speed_PID_iError->Last_iError = 0;
//     Speed_PID_iError->Sum_iError = 0;
//     Speed_PID_iError->iError_iError = 0;
//     
//     Turn_PID_iError->iError = 0;
//     Turn_PID_iError->Last_iError = 0;
//     Turn_PID_iError->Sum_iError = 0;
//     Turn_PID_iError->iError_iError = 0;
}