/**
 ******************************************************************************
 * @file    test_bsp.c
 * @author
 * @brief
 ******************************************************************************
 */
#include "bsp.h"
#include "stm32f4xx_hal.h"
#include "unity.h"

void setUp(void) {
  BSP_Init(); // called before each test
}

void tearDown(void) {
  // nothing for now
}

void test_led_should_turn_on(void) {
  BSP_LedOn();
  TEST_ASSERT_EQUAL(GPIO_PIN_SET, HAL_GPIO_ReadPin(LED_GPIO_PORT, LED_PIN));
}

void test_led_should_turn_off(void) {
  BSP_LedOff();
  TEST_ASSERT_EQUAL(GPIO_PIN_RESET, HAL_GPIO_ReadPin(LED_GPIO_PORT, LED_PIN));
}
