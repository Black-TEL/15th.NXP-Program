#include "common.h"
#include "MK60_gpio.h"
#include "mpuiic.h"
#include "MK60_conf.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEKս��STM32������V3
//MPU6050 IIC���� ����	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//��������:2015/1/17
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved									  
//////////////////////////////////////////////////////////////////////////////////

//MPU IIC ��ʱ����
void MPU_IIC_Delay(void)
{
    uint8 i = 100;
    
    while(i--)
    {
        ;
    }
}

//��ʼ��IIC
void MPU_IIC_Init(void)
{					     	
    gpio_init  (MPU_SCL_IO, GPO, 1); //��ʼ��SCL
    gpio_init  (MPU_SDA_IO, GPO, 1); //��ʼ��SDA
    
    port_init_NoALT(MPU_SCL_IO,ODO | PULLUP);
    port_init_NoALT(MPU_SDA_IO,ODO | PULLUP);
    
    
}
//����IIC��ʼ�ź�
void MPU_IIC_Start(void)
{
    MPU_SDA_OUT();     //sda�����
    MPU_SDA = 1;	  	  
    MPU_SCL = 1;
    MPU_IIC_Delay();
    MPU_SDA = 0;//START:when CLK is high,DATA change form high to low 
    MPU_IIC_Delay();
    MPU_SCL = 0;//ǯסI2C���ߣ�׼�����ͻ�������� 
}	  
//����IICֹͣ�ź�
void MPU_IIC_Stop(void)
{
    MPU_SDA_OUT();//sda�����
    MPU_SCL = 0;
    MPU_IIC_Delay();
    MPU_SDA = 0;//STOP:when CLK is high DATA change form low to high
    MPU_IIC_Delay();
    MPU_SCL = 1; 
    MPU_IIC_Delay();
    MPU_SDA = 1;//����I2C���߽����ź�
    MPU_IIC_Delay();							   	
}
//�ȴ�Ӧ���źŵ���
//����ֵ��1������Ӧ��ʧ��
//        0������Ӧ��ɹ�
uint8 MPU_IIC_Wait_Ack(void)
{
    uint8 ucErrTime=0;
    MPU_SCL=0;
    MPU_IIC_Delay();
    MPU_SDA = 1;
    MPU_IIC_Delay();	   
    MPU_SCL = 1;
    MPU_IIC_Delay();
    MPU_SDA_IN();
    MPU_IIC_Delay();
    while(MPU_SDA_I)
    {
        ucErrTime++;
        if(ucErrTime>250)
        {
            MPU_IIC_Stop();
            return 1;
        }
    }
    MPU_SDA_OUT(); 
    MPU_SCL = 0;//ʱ�����0 	   
    return 0;  
} 
//����ACKӦ��
void MPU_IIC_Ack(void)
{
    MPU_SCL = 0;
    MPU_SDA_OUT();
    MPU_SDA = 0;
    MPU_IIC_Delay();
    MPU_SCL = 1;
    MPU_IIC_Delay();
    MPU_SCL = 0;
}
//������ACKӦ��		    
void MPU_IIC_NAck(void)
{
    MPU_SCL = 0;
    MPU_SDA_OUT();;
    MPU_SDA = 1;
    MPU_IIC_Delay();
    MPU_SCL = 1;
    MPU_IIC_Delay();
    MPU_SCL = 0;
}					 				     
//IIC����һ���ֽ�
//���شӻ�����Ӧ��
//1����Ӧ��
//0����Ӧ��			  
void MPU_IIC_Send_Byte(uint8 txd)
{                        
    uint8 t;   
    MPU_SDA_OUT(); 	    
    MPU_SCL = 0;//����ʱ�ӿ�ʼ���ݴ���
    for(t=0;t<8;t++)
    {              
        if(txd&0x80)
            MPU_SDA = 1;
        else
            MPU_SDA = 0;
        txd<<=1;
        MPU_IIC_Delay();
        MPU_SCL = 1;
        MPU_IIC_Delay(); 
        MPU_SCL = 0;	
        MPU_IIC_Delay();
    }	
    MPU_SCL = 0;
} 	    
//��1���ֽڣ�ack=1ʱ������ACK��ack=0������nACK   
uint8 MPU_IIC_Read_Byte(unsigned char ack)
{
    unsigned char i,receive=0;
    MPU_SDA_IN();//SDA����Ϊ����
    for(i=0;i<8;i++ )
    {
        MPU_SCL = 0; 
        MPU_IIC_Delay();
        MPU_SCL = 1;
        receive<<=1;
        if(MPU_SDA_I)receive++;   
        MPU_IIC_Delay(); 
    }					 
    if (!ack)
        MPU_IIC_NAck();//����nACK
    else
        MPU_IIC_Ack(); //����ACK
    
    MPU_SCL = 0; 
    return receive;
}
