/**
 ******************************************************************************
 * @file    test_runner.c
 * @author
 * @brief
 ******************************************************************************
 */
#include "test_bsp.h"
#include "unity.h"

// Declare your test functions
void test_led_should_turn_on(void);
void test_led_should_turn_off(void);

void unit_test_runner(void) {
  // Initialize Unity
  UNITY_BEGIN();

  // Run the tests
  RUN_TEST(test_led_should_turn_on);
  RUN_TEST(test_led_should_turn_off);

  // Finish Unity and report
  UNITY_END();
}
