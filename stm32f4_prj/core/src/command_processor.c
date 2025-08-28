/**
 ******************************************************************************
 * @file    command_processor.c
 * @author
 * @brief
 ******************************************************************************
 */

#include "command_processor.h"
#include "bsp.h"
#include "stm32f4xx_hal.h"
#include <stdio.h>
#include <string.h>

#ifdef UNIT_TEST
#include "test_runner.h"
#endif

// Type definition for handlers
typedef prot_ret_t (*command_handler_t)(prot_data_t *data);

typedef struct {
  uint16_t cmd_type;
  command_handler_t handler;
} command_entry_t;

// ---------------- Example Handlers ----------------

// Command 0x0001: Echo
static prot_ret_t handle_echo(prot_data_t *data) {
  char temp[PROTOCOL_MAX_BUFFER_SIZE];
  int len = snprintf(temp, sizeof(temp), "Echo: %s", data->data);

  if (len < 0 || len >= PROTOCOL_MAX_BUFFER_SIZE) {
    protocol_set_status(PROT_STATUS_ERROR, data);
    return PROT_RET_NOK;
  }

  memcpy(data->data, temp, len + 1); // +1 to copy null terminator
  data->data_len = len;
  protocol_set_status(PROT_STATUS_OK, data);
  return PROT_RET_OK;
}

// Command 0x0002: Toggle LED
static prot_ret_t handle_led_toggle(prot_data_t *data) {
  BSP_LedToggle();
  protocol_set_status(PROT_STATUS_OK, data);
  return PROT_RET_OK;
}

// Command 0x0003: Unit Test
static prot_ret_t unit_test(prot_data_t *data) {
  (void)data; // suppress unused warning

#ifdef UNIT_TEST
  unit_test_runner();
#else
  printf("Not UNIT_TEST defined.\n");
#endif

  return PROT_RET_OK;
}

// --------------------------------------------------

// Command table
static const command_entry_t command_table[] = {
    {0x0001, handle_echo},
    {0x0002, handle_led_toggle},
    {0x0003, unit_test},
};

#define COMMAND_TABLE_SIZE (sizeof(command_table) / sizeof(command_table[0]))

// Init function (not much to do here yet)
prot_ret_t command_processor_init(void) { return PROT_RET_OK; }

// Dispatcher
prot_ret_t command_processor_execute(prot_data_t *data) {
  for (size_t i = 0; i < COMMAND_TABLE_SIZE; i++) {
    if (data->cmd_type == command_table[i].cmd_type) {
      return command_table[i].handler(data);
    }
  }

  // Unknown command
  data->data_len = snprintf((char *)data->data, PROTOCOL_MAX_BUFFER_SIZE,
                            "Unknown cmd: %04X", data->cmd_type);
  protocol_set_status(PROT_STATUS_ERROR, data);
  return PROT_RET_NOK;
}
