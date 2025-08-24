/**
 ******************************************************************************
 * @file    bsp.h
 * @author
 * @brief   Header for bsp.c module
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */

#ifndef BSP_H
#define BSP_H

#include "stm32f4xx_hal.h"

// LED pin/port for your board (Nucleo/Discovery boards often use PG13 or PD12)
#define LED_GPIO_PORT GPIOD // change to your board's LED port
#define LED_PIN GPIO_PIN_12 // change to your board's LED pin

// Initialize board peripherals (clocks, GPIO, etc.)
void BSP_Init(void);

// LED control
void BSP_LedOn(void);
void BSP_LedOff(void);
void BSP_LedToggle(void);

#endif // BSP_H
