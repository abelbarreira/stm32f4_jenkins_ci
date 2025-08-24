/**
 ******************************************************************************
 * @file    bsp.c
 * @author
 * @brief   BSP
 ******************************************************************************
 * @attention
 *
 ******************************************************************************
 */
#include "bsp.h"

void BSP_Init(void) {
  // Enable clock for GPIOD
  __HAL_RCC_GPIOD_CLK_ENABLE();

  // Configure PD12 as output
  GPIO_InitTypeDef gpio = {0};
  gpio.Pin = LED_PIN;
  gpio.Mode = GPIO_MODE_OUTPUT_PP;
  gpio.Pull = GPIO_NOPULL;
  gpio.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED_GPIO_PORT, &gpio);
}

void BSP_LedOn(void) {
  HAL_GPIO_WritePin(LED_GPIO_PORT, LED_PIN, GPIO_PIN_SET);
}

void BSP_LedOff(void) {
  HAL_GPIO_WritePin(LED_GPIO_PORT, LED_PIN, GPIO_PIN_RESET);
}

void BSP_LedToggle(void) { HAL_GPIO_TogglePin(LED_GPIO_PORT, LED_PIN); }
