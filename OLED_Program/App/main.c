/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2013,山外科技
 *     All rights reserved.
 *     技术讨论：山外初学论坛 http://www.vcan123.com
 *
 *     除注明出处外，以下所有内容版权均属山外科技所有，未经允许，不得用于商业用途，
 *     修改内容时必须保留山外科技的版权声明。
 *
 * @file       main.c
 * @brief      山外K60 平台主程序
 * @author     山外科技                     10
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
//      camera_get_img();                                        //摄像头获取图像
//      img_extract(Img, imgbuff,CAMERA_SIZE);          //解压图像
      Debue_Key();
      Picture_display(&Printf[0][0][0][0]);
//      OLED_delay_ms(3000);

//      Picture_ReverseDisplay(&k[0][0][0][0]);
//      OLED_delay_ms(3000);
   
    }
}