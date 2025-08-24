/**
 ******************************************************************************
 * @file    Templates_LL/Src/main.c
 * @author  MCD Application Team
 * @brief   Main program body through the LL API
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2017 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "bsp.h"
#include "protocol.h"
#include <stdio.h>

#ifdef UNIT_TEST
#include "test_runner.h"
#endif

/** @addtogroup STM32F4xx_LL_Examples
 * @{
 */

/** @addtogroup Templates_LL
 * @{
 */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);

/* Private functions ---------------------------------------------------------*/

static uint8_t cmd_data[PROTOCOL_MAX_BUFFER_SIZE];
static uint8_t reply_data[PROTOCOL_MAX_BUFFER_SIZE];
static uint16_t cmd_data_len;
static uint16_t reply_data_len;

/**
 * @brief  Main program
 * @param  None
 * @retval None
 */
int main(void) {
  HAL_Init();

  /* Configure the system clock to 168 MHz */
  SystemClock_Config();

  // Ensure HAL_RCC_GetPCLK1Freq() returns the correct clock for baud
  // calculation.
  SystemCoreClockUpdate();

  protocol_init();

  BSP_Init();

  // uint32_t pclk1 = HAL_RCC_GetPCLK1Freq();
  // uint32_t sysclk = HAL_RCC_GetSysClockFreq();
  // printf("PCLK1: %lu Hz, SYSCLK: %lu Hz\n", pclk1, sysclk);

#ifdef UNIT_TEST
  unit_test_runner();
#endif

  /* Infinite loop */
  while (1) {
    if (protocol_receive_cmd(cmd_data, &cmd_data_len) == PROT_RET_OK) {
      // process_command(cmd_data, cmd_data_len, reply_data, &reply_data_len);

      reply_data_len = 0;
      protocol_send_reply(reply_data, reply_data_len);
      protocol_send_reply((uint8_t *)"OK\r\n", 4);
    } else {
      protocol_send_reply((uint8_t *)"ERROR\r\n", 7);
    }
  }
}

/* ==============   BOARD SPECIFIC CONFIGURATION CODE BEGIN    ============== */

/**
 * @brief  System Clock Configuration
 *         The system Clock is configured as follow :
 *            System Clock source            = PLL (HSE)
 *            SYSCLK(Hz)                     = 168000000
 *            HCLK(Hz)                       = 168000000
 *            AHB Prescaler                  = 1
 *            APB1 Prescaler                 = 4
 *            APB2 Prescaler                 = 2
 *            HSE Frequency(Hz)              = 8000000
 *            PLL_M                          = 8
 *            PLL_N                          = 336
 *            PLL_P                          = 2
 *            VDD(V)                         = 3.3
 *            Main regulator output voltage  = Scale1 mode
 *            Flash Latency(WS)              = 5
 * @param  None
 * @retval None
 */
void SystemClock_Config(void) {
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  // Configure HSE and PLL
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  HAL_RCC_OscConfig(&RCC_OscInitStruct);

  // Select PLL as system clock source
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK |
                                RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5);
}

/* ==============   BOARD SPECIFIC CONFIGURATION CODE END      ============== */

#ifdef USE_FULL_ASSERT

/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t *file, uint32_t line) {
  /* User can add his own implementation to report the file name and line
     number, ex: printf("Wrong parameters value: file %s on line %d", file,
     line) */

  /* Infinite loop */
  while (1) {
  }
}
#endif
