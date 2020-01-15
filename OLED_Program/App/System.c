#include "common.h"
#include "include.h"

uint8 imgbuff[CAMERA_SIZE];                             //����洢����ͼ�������
uint8 Img[CAMERA_W][CAMERA_H];                           //����ӥ������ͷ��һ�ֽ�8�����أ������Ҫ��ѹΪ 1�ֽ�1�����أ����㴦��

void All_Init()
{
/*********************PID������ݳ�ʼ��****************************************/
    PID_DataInit();    
    
/*********************OLED��ʼ��***********************************************/ 
    OLED_IIC_init();
    OLED_init();
    OLED_full();
    OLED_delay_ms(1000);
    OLED_clear();
    //display_init();
/*********************OLED���������ʼ��***************************************/
    OLED_Printf(3,2,Speed_PID.Kp);
    OLED_Printf(3,3,Speed_PID.Ki);
    OLED_Printf(3,4,Speed_PID.Kd);
    OLED_Printf(11,2,Turn_PID.Kp);
    OLED_Printf(11,3,Turn_PID.Ki);
    OLED_Printf(11,4,Turn_PID.Kd);
    
/*********************������ʼ��***********************************************/
    gpio_init(key_Up, GPI, 1);
    gpio_init(key_Down, GPI, 1);
    gpio_init(key_Left, GPI, 1);
    gpio_init(key_Right, GPI, 1);
    gpio_init(key_Enter, GPI, 1);
    gpio_init(key_Exit, GPI, 1);

/*********************����ͷ��ʼ��*********************************************/
//    camera_init(imgbuff);                                   //����ͷ��ʼ��
//    set_vector_handler(PORTE_VECTORn ,PORTE_IRQHandler);    //����LPTMR���жϸ�λ����Ϊ PORTA_IRQHandler
//    set_vector_handler(DMA0_VECTORn ,DMA0_IRQHandler);      //����LPTMR���жϸ�λ����Ϊ PORTA_IRQHandler
    
/*********************PWMģ���ʼ��********************************************/
//    FTM_PWM_init(FTM0, FTM_CH0,20000,0);        //���PWM��ʼ��
//    FTM_PWM_init(FTM0, FTM_CH1,20000,0);        //���PWM��ʼ��
//    FTM_PWM_init(FTM0, FTM_CH2,20000,0);        //���PWM��ʼ��
//    FTM_PWM_init(FTM0, FTM_CH3,20000,0);        //���PWM��ʼ��
      
/*********************PIT�жϳ�ʼ��********************************************/    
//    pit_init_ms(PIT0,1);
//    set_vector_handler(PIT0_VECTORn ,PIT0_IRQHandler);
//    enable_irq(PIT0_IRQn);
    
}

void img_extract(uint8 *dst, uint8 *src, uint32 srclen)         //��ֵ��ͼ���ѹ
{
    uint8 colour[2] = {0, 255}; //0 �� 1 �ֱ��Ӧ����ɫ
    //ע��ɽ�������ͷ 100 ��ʾ ��ɫ��25��ʾ ��ɫ
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
 *�޷�����
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