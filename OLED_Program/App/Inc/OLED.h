#ifndef __OLED_H_
#define __OLED_H_
#include "common.h"
#include "include.h"
//MPU 管脚配置
#define OLED_SCL_IO      PTA15
#define OLED_SDA_IO      PTA16

#define OLED_SCL         PTA15_OUT  
#define OLED_SDA         PTA16_OUT 
#define OLED_SDA_I       PTA16_IN 
//定义SDA输入输出
#define OLED_IIC_SCL_0    gpio_set(OLED_SCL_IO, 0)      
#define OLED_IIC_SCL_1    gpio_set(OLED_SCL_IO, 1)     
#define OLED_IIC_SDA_0    gpio_set(OLED_SDA_IO, 0) 
#define OLED_IIC_SDA_1    gpio_set(OLED_SDA_IO, 1) 

extern unsigned char Printf[4][2][16][8];

//IIC所有操作函数
void OLED_IIC_init(void);
void OLED_delay_us(unsigned int _us_time);
void OLED_delay_ms(unsigned int _ms_time);
void OLED_IIC_write(unsigned char date);
void OLED_IIC_start();
void OLED_IIC_stop();
void OLED_send_cmd(unsigned char o_command);
void OLED_send_data(unsigned char o_data);
void Column_set(unsigned char column);
void Page_set(unsigned char page);
void OLED_clear(void);
void OLED_full(void);
void OLED_init(void);
void Picture_display(const unsigned char *ptr_pic);
void Picture_ReverseDisplay(const unsigned char *ptr_pic);
void OLED_Printf(int x,int y, float data);
void setPlace(int x, int y, int data);
void Choice_PID();
void Debug_setPlace(int x, int y, int data);
void Debug_OLED_Printf(int x,int y, float data);
void Debug_display_init();
void Change_PID_Init();
void Change_PID();
void Debue_Key();
void Change_PID_Exit();
void Choice_PID_Exit();

//extern const unsigned char  picture_tab[];
//extern const unsigned char  *point;
#endif