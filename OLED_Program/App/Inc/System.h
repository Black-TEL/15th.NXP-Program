#ifndef __SYSTEM_H__
#define __SYSTEM_H__
#include "common.h"
#include "include.h"

extern uint8 imgbuff[CAMERA_SIZE];                             //����洢����ͼ�������
extern uint8 Img[CAMERA_W][CAMERA_H];                           //����ӥ������ͷ��һ�ֽ�8�����أ������Ҫ��ѹΪ 1�ֽ�1�����أ����㴦��

void All_Init();                                            //��ʼ������ģ��

extern int32 range_protect(int32 duty, int32 min, int32 max);

#endif