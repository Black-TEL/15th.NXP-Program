#include "supersonic_wave.h"

//uint32 distance0;
uint32 distance1;
uint32 distance2;
uint32 distance3;

//uint32 distance_for0()
//{
//     uint32 timevar;
//     uint32 dis;
//     gpio_set(TRIG0,1);                  //������������
//     pit_delay_us(PIT3,20);             
//     gpio_set(TRIG0,0);                  //����һ��20us�ĸߵ�ƽ����
//           
//     while(gpio_get(ECHG0) == 0);        //�ȴ���ƽ��ߣ��͵�ƽһֱ�ȴ�
//     pit_time_start(PIT3);               //��ʼ��ʱ
//     while(gpio_get(ECHG0) == 1)         //�ȴ���ƽ��ͣ��ߵ�ƽһֱ�ȴ� 
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
     gpio_set(TRIG1,1);                  //������������
     pit_delay_us(PIT3,20);             
     gpio_set(TRIG1,0);                 //����һ��20us�ĸߵ�ƽ����
           
     while(gpio_get(ECHG1) == 0);        //�ȴ���ƽ��ߣ��͵�ƽһֱ�ȴ�
     pit_time_start(PIT3);               //��ʼ��ʱ
     while(gpio_get(ECHG1) == 1)         //�ȴ���ƽ��ͣ��ߵ�ƽһֱ�ȴ� 
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
     gpio_set(TRIG2,1);               //������������
     pit_delay_us(PIT3,20);       
     gpio_set(TRIG2,0);           //����һ��20us�ĸߵ�ƽ����
        
        
     while(gpio_get (ECHG2) == 0);             //�ȴ���ƽ��ߣ��͵�ƽһֱ�ȴ�
     pit_time_start(PIT3); //��ʼ��ʱ
     while(gpio_get(ECHG2) == 1)//�ȴ���ƽ��ͣ��ߵ�ƽһֱ�ȴ� 
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
     gpio_set(TRIG3,1);               //������������
     pit_delay_us(PIT3,20);       
     gpio_set(TRIG3,0);           //����һ��20us�ĸߵ�ƽ����
        
        
     while(gpio_get (ECHG3) == 0);             //�ȴ���ƽ��ߣ��͵�ƽһֱ�ȴ�
     pit_time_start(PIT3); //��ʼ��ʱ
     while(gpio_get(ECHG3) == 1)//�ȴ���ƽ��ͣ��ߵ�ƽһֱ�ȴ� 
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