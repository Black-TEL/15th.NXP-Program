#ifndef __MPUIIC_H
#define __MPUIIC_H	   		   
//MPU 管脚配置
#define MPU_SCL_IO      PTB0
#define MPU_SDA_IO      PTB1

#define MPU_SCL         PTB0_OUT  
#define MPU_SDA         PTB1_OUT 
#define MPU_SDA_I       PTB1_IN 
//定义SDA输入输出
#define MPU_SDA_OUT()   PTB1_DDR=1
#define MPU_SDA_IN()    PTB1_DDR=0


//IIC所有操作函数
void MPU_IIC_Delay(void);				//MPU IIC延时函数
void MPU_IIC_Init(void);                //初始化IIC的IO口				 
void MPU_IIC_Start(void);				//发送IIC开始信号
void MPU_IIC_Stop(void);	  			//发送IIC停止信号
void MPU_IIC_Send_Byte(uint8 txd);			//IIC发送一个字节
uint8 MPU_IIC_Read_Byte(unsigned char ack);//IIC读取一个字节
uint8 MPU_IIC_Wait_Ack(void); 				//IIC等待ACK信号
void MPU_IIC_Ack(void);					//IIC发送ACK信号
void MPU_IIC_NAck(void);				//IIC不发送ACK信号

void IMPU_IC_Write_One_Byte(uint8 daddr,uint8 addr,uint8 data);
uint8 MPU_IIC_Read_One_Byte(uint8 daddr,uint8 addr);	  
#endif
















