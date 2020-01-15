#ifndef	_SUPERSONIC_WAVE_H_
#define _SUPERSONIC_WAVE_H_
#include "include.h"

//#define TRIG0 PTC7
//#define ECHG0 PTC9

#define TRIG1 PTC7
#define ECHG1 PTC9

#define TRIG2 PTB2
#define ECHG2 PTB3

#define TRIG3 PTD7
#define ECHG3 PTD6

//æ‡¿Î
//extern uint32 distance0;
extern uint32 distance1;
extern uint32 distance2;
extern uint32 distance3;

extern uint32 distance_for();  //«∞”“
extern uint32 distance_left();  //◊Û
extern uint32 distance_right(); //”“

#endif