/**
 ******************************************************************************
 * @file    usart.c
 * @author
 * @brief   USART
 ******************************************************************************
 * @attention
 *
 ******************************************************************************
 */
#include "stm32f4xx_hal.h"

UART_HandleTypeDef huart2;

void MX_USART2_UART_Init(void) {
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_USART2_CLK_ENABLE();

  GPIO_InitTypeDef gpio = {0};
  gpio.Pin = GPIO_PIN_2 | GPIO_PIN_3; // PA2=TX, PA3=RX
  gpio.Mode = GPIO_MODE_AF_PP;
  gpio.Pull = GPIO_PULLUP;
  gpio.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  gpio.Alternate = GPIO_AF7_USART2;
  HAL_GPIO_Init(GPIOA, &gpio);

  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;

  HAL_UART_Init(&huart2);
}
