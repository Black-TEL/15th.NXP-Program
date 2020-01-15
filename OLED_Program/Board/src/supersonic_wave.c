#include "supersonic_wave.h"

//uint32 distance0;
uint32 distance1;
uint32 distance2;
uint32 distance3;

//uint32 distance_for0()
//{
//     uint32 timevar;
//     uint32 dis;
//     gpio_set(TRIG0,1);                  //产生触发脉冲
//     pit_delay_us(PIT3,20);             
//     gpio_set(TRIG0,0);                  //产生一个20us的高电平脉冲
//           
//     while(gpio_get(ECHG0) == 0);        //等待电平变高，低电平一直等待
//     pit_time_start(PIT3);               //开始计时
//     while(gpio_get(ECHG0) == 1)         //等待电平变低，高电平一直等待 
//     {
//        timevar = pit_time_get_us(PIT3);
//        if(timevar>6300)
//        {
//          break;
//        }
//     }
//    //zhangaiwu_Flag = pit_time_get_us(PIT3);
//     dis = timevar*340/20000;
//     timevar=0;
// 
//     return dis;
//}
uint32 distance_for()
{
     uint32 timevar;
     uint32 dis;
     gpio_set(TRIG1,1);                  //产生触发脉冲
     pit_delay_us(PIT3,20);             
     gpio_set(TRIG1,0);                 //产生一个20us的高电平脉冲
           
     while(gpio_get(ECHG1) == 0);        //等待电平变高，低电平一直等待
     pit_time_start(PIT3);               //开始计时
     while(gpio_get(ECHG1) == 1)         //等待电平变低，高电平一直等待 
     {
        timevar = pit_time_get_us(PIT3);
        if(timevar>25000)
        {
          break;
        }
     }
    //zhangaiwu_Flag = pit_time_get_us(PIT3);
     dis = timevar*340/20000;
     timevar=0;
 
     return dis;
}

uint32 distance_left()
{
     uint32 timevar;
     uint32 dis;
     gpio_set(TRIG2,1);               //产生触发脉冲
     pit_delay_us(PIT3,20);       
     gpio_set(TRIG2,0);           //产生一个20us的高电平脉冲
        
        
     while(gpio_get (ECHG2) == 0);             //等待电平变高，低电平一直等待
     pit_time_start(PIT3); //开始计时
     while(gpio_get(ECHG2) == 1)//等待电平变低，高电平一直等待 
     {
        timevar = pit_time_get_us(PIT3);
        if(timevar>25000)
        {
          break;
        }
     }
    //zhangaiwu_Flag = pit_time_get_us(PIT3);
     dis = timevar*340/20000;
     timevar=0;
 
     return dis;
}
uint32 distance_right()
{
     uint32 timevar;
     uint32 dis;
     gpio_set(TRIG3,1);               //产生触发脉冲
     pit_delay_us(PIT3,20);       
     gpio_set(TRIG3,0);           //产生一个20us的高电平脉冲
        
        
     while(gpio_get (ECHG3) == 0);             //等待电平变高，低电平一直等待
     pit_time_start(PIT3); //开始计时
     while(gpio_get(ECHG3) == 1)//等待电平变低，高电平一直等待 
     {
        timevar = pit_time_get_us(PIT3);
        if(timevar>25000)
        {
          break;
        }
     }
    //zhangaiwu_Flag = pit_time_get_us(PIT3);
     dis = timevar*340/20000;
     timevar=0;
 
     return dis;
}