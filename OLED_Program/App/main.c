/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2013,ɽ��Ƽ�
 *     All rights reserved.
 *     �������ۣ�ɽ���ѧ��̳ http://www.vcan123.com
 *
 *     ��ע�������⣬�����������ݰ�Ȩ����ɽ��Ƽ����У�δ����������������ҵ��;��
 *     �޸�����ʱ���뱣��ɽ��Ƽ��İ�Ȩ������
 *
 * @file       main.c
 * @brief      ɽ��K60 ƽ̨������
 * @author     ɽ��Ƽ�                     10
 * @version    v5.0
 * @date       2013-08-28
 */

#include "common.h"
#include "include.h"
#include "math.h"
   
void main()
{
    All_Init();
    while(1)
    {
//      camera_get_img();                                        //����ͷ��ȡͼ��
//      img_extract(Img, imgbuff,CAMERA_SIZE);          //��ѹͼ��
      Debue_Key();
      Picture_display(&Printf[0][0][0][0]);
//      OLED_delay_ms(3000);

//      Picture_ReverseDisplay(&k[0][0][0][0]);
//      OLED_delay_ms(3000);
   
    }
}