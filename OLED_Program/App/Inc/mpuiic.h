#ifndef __MPUIIC_H
#define __MPUIIC_H	   		   
//MPU �ܽ�����
#define MPU_SCL_IO      PTB0
#define MPU_SDA_IO      PTB1

#define MPU_SCL         PTB0_OUT  
#define MPU_SDA         PTB1_OUT 
#define MPU_SDA_I       PTB1_IN 
//����SDA�������
#define MPU_SDA_OUT()   PTB1_DDR=1
#define MPU_SDA_IN()    PTB1_DDR=0


//IIC���в�������
void MPU_IIC_Delay(void);				//MPU IIC��ʱ����
void MPU_IIC_Init(void);                //��ʼ��IIC��IO��				 
void MPU_IIC_Start(void);				//����IIC��ʼ�ź�
void MPU_IIC_Stop(void);	  			//����IICֹͣ�ź�
void MPU_IIC_Send_Byte(uint8 txd);			//IIC����һ���ֽ�
uint8 MPU_IIC_Read_Byte(unsigned char ack);//IIC��ȡһ���ֽ�
uint8 MPU_IIC_Wait_Ack(void); 				//IIC�ȴ�ACK�ź�
void MPU_IIC_Ack(void);					//IIC����ACK�ź�
void MPU_IIC_NAck(void);				//IIC������ACK�ź�

void IMPU_IC_Write_One_Byte(uint8 daddr,uint8 addr,uint8 data);
uint8 MPU_IIC_Read_One_Byte(uint8 daddr,uint8 addr);	  
#endif
















