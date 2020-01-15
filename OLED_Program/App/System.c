#include "common.h"
#include "include.h"

uint8 imgbuff[CAMERA_SIZE];                             //定义存储接收图像的数组
uint8 Img[CAMERA_W][CAMERA_H];                           //由于鹰眼摄像头是一字节8个像素，因而需要解压为 1字节1个像素，方便处理

void All_Init()
{
/*********************PID相关数据初始化****************************************/
    PID_DataInit();    
    
/*********************OLED初始化***********************************************/ 
    OLED_IIC_init();
    OLED_init();
    OLED_full();
    OLED_delay_ms(1000);
    OLED_clear();
    //display_init();
/*********************OLED参数界面初始化***************************************/
    OLED_Printf(3,2,Speed_PID.Kp);
    OLED_Printf(3,3,Speed_PID.Ki);
    OLED_Printf(3,4,Speed_PID.Kd);
    OLED_Printf(11,2,Turn_PID.Kp);
    OLED_Printf(11,3,Turn_PID.Ki);
    OLED_Printf(11,4,Turn_PID.Kd);
    
/*********************按键初始化***********************************************/
    gpio_init(key_Up, GPI, 1);
    gpio_init(key_Down, GPI, 1);
    gpio_init(key_Left, GPI, 1);
    gpio_init(key_Right, GPI, 1);
    gpio_init(key_Enter, GPI, 1);
    gpio_init(key_Exit, GPI, 1);

/*********************摄像头初始化*********************************************/
//    camera_init(imgbuff);                                   //摄像头初始化
//    set_vector_handler(PORTE_VECTORn ,PORTE_IRQHandler);    //设置LPTMR的中断复位函数为 PORTA_IRQHandler
//    set_vector_handler(DMA0_VECTORn ,DMA0_IRQHandler);      //设置LPTMR的中断复位函数为 PORTA_IRQHandler
    
/*********************PWM模块初始化********************************************/
//    FTM_PWM_init(FTM0, FTM_CH0,20000,0);        //电机PWM初始化
//    FTM_PWM_init(FTM0, FTM_CH1,20000,0);        //电机PWM初始化
//    FTM_PWM_init(FTM0, FTM_CH2,20000,0);        //电机PWM初始化
//    FTM_PWM_init(FTM0, FTM_CH3,20000,0);        //电机PWM初始化
      
/*********************PIT中断初始化********************************************/    
//    pit_init_ms(PIT0,1);
//    set_vector_handler(PIT0_VECTORn ,PIT0_IRQHandler);
//    enable_irq(PIT0_IRQn);
    
}

void img_extract(uint8 *dst, uint8 *src, uint32 srclen)         //二值化图像解压
{
    uint8 colour[2] = {0, 255}; //0 和 1 分别对应的颜色
    //注：山外的摄像头 100 表示 白色，25表示 黑色
    uint8 tmpsrc;
    while(srclen --)
    {
        tmpsrc = *src++;
        *dst++ = colour[ (tmpsrc >> 7 ) & 0x01 ];
        *dst++ = colour[ (tmpsrc >> 6 ) & 0x01 ];
        *dst++ = colour[ (tmpsrc >> 5 ) & 0x01 ];
        *dst++ = colour[ (tmpsrc >> 4 ) & 0x01 ];
        *dst++ = colour[ (tmpsrc >> 3 ) & 0x01 ];
        *dst++ = colour[ (tmpsrc >> 2 ) & 0x01 ];
        *dst++ = colour[ (tmpsrc >> 1 ) & 0x01 ];
        *dst++ = colour[ (tmpsrc >> 0 ) & 0x01 ];
    }
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