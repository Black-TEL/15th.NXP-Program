#include "include.h"
#include "PID.h"

PID Speed_PID;
PID Turn_PID;

PID_iError* Speed_PID_iError;
PID_iError* Turn_PID_iError;

float PID_SpeedControl(float Point,float NowData_Laft,float NowData_Right,PID* K)
{
      float SpeedControl;
      
      Speed_PID_iError->iErrpr = Point - ((NowData_Laft + NowData_Right)/2);
      Speed_PID_iError->iErrpr = Speed_PID_iError->iErrpr * 0.8 + Speed_PID_iError->Last_iError * 0.2;
      Speed_PID_iError->Sum_iError += Speed_PID_iError->iErrpr; 
      
      Speed_PID_iError->Sum_iErro = range_protect((int)Speed_PID_iError->Sum_iErro,-100,100);
      
      SpeedControl = K->Kp * Speed_PID_iError->iErro + K->Ki * Speed_PID_iError->Sum_iError;
      
      Speed_PID_iError->Last_iError = Speed_PID_iError->iErrpr;
      
      return SpeedControl;
}

float PID_TurnCountrol(float NowData, float Point, PID* K)
{
      float TurnCountrol;
      
      Turn_PID_iError->iErrpr = Point - NowData;
      Turn_PID_iError->iError_iError = Turn_PID_iError->iErrpr - Turn_PID_iError->Last_iError;
      
      TurnCountrol = K->Kp * Turn_PID_iError->iErrpr + K->Kd * Turn_PID_iError->iError_iError;
      
      Turn_PID_iError->Last_iError = Turn_PID_iError->iErrpr;
      
      return TurnCountrol;
}

void PID_DataInit()
{
     Speed_PID.Kp = 0;
     Speed_PID.Ki = 0;
     Speed_PID.Kd = 0;
     
     Turn_PID.Kp = 0;
     Turn_PID.Ki = 0;
     Turn_PID.Kd = 0;
     
     Speed_PID_iError->iErrpr = 0;
     Speed_PID_iError->Last_iError = 0;
     Speed_PID_iError->Sum_iError = 0;
     Speed_PID_iError->iError_iError = 0;
     
     Turn_PID_iError->iErrpr = 0;
     Turn_PID_iError->Last_iError = 0;
     Turn_PID_iError->Sum_iError = 0;
     Turn_PID_iError->iError_iError = 0;
}