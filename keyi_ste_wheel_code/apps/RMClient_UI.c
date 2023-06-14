/**
 * @file RMClient_UI.c
 * @author Miraggio (w1159904119@gmail)
 * @brief 裁判系统客户端自定义UI
 * @version 0.1
 * @date 2021-04-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "can_control.h"
#include "RMClient_UI.h"
#define Light_Nums 8
#define INIT_NUMS 9
#define UPDATA_NUMS 7


void(*Dispaly_Init[])(void) = DISPLAY_INIT
void(*Display_Updata[])(void) = DISPLAY_UPDATA
RMClient_UI_t RMClient_UI = {&Dispaly_Init, &Display_Updata};

int8_t Updata_TimeWait;
int8_t InitShow_Flag;

/**
  * @brief  UI 显示
  * @param  None
  * @retval None
  */
void UserDefined_UI(void)
{
  // --- 需要实时更新的数据 --- //
  Updata_TimeWait++;

  if (Updata_TimeWait >= 2)
  {

    for(int i = 0 ; i < UPDATA_NUMS ; i++)
    {
      Display_Updata[i]();
    } 

    Updata_TimeWait = 0;
  }

  // --- 无需实时更新的数据 --- //
  if (Robot_Receive.chassismode  == CHAS_DisableMode || Robot_Receive.Write_Msg[7] == 1) //失能或按B刷新屏幕UI 
  {
    for (int i = 0; i < INIT_NUMS; i++)
    {
      Dispaly_Init[i]();
    }
  }

}
