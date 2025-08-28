/**
 ******************************************************************************
 * @file    protocol.c
 * @author
 * @brief
 ******************************************************************************
 */
#include "protocol.h"
#include "usart.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static uint8_t data_buffer[PROTOCOL_MAX_BUFFER_SIZE];
extern UART_HandleTypeDef huart2;

static const char STATUS_OK[] = "OK\n";
static const char STATUS_ERROR[] = "ERROR\n";

// Initialize protocol
prot_ret_t protocol_init(void) {
  MX_USART2_UART_Init();
  return PROT_RET_OK;
}

// Receive Command
prot_ret_t protocol_receive_command(prot_data_t *data) {
  uint8_t *data_ptr = data_buffer;
  uint16_t data_received = 0;

  // Initialize empty structure
  data->cmd_type = 0x0000;
  data->data_len = 0;
  data->data[0] = '\0';
  data->status = PROT_STATUS_EMPTY;

  // Receive until newline or buffer full
  do {
    if (HAL_UART_Receive(&huart2, data_ptr, 1, HAL_MAX_DELAY) != HAL_OK) {
      return PROT_RET_NOK;
    }

    if ((*data_ptr == '\r') || (*data_ptr == '\n')) {
      break;
    }

    data_ptr++;
    data_received++;

    if (data_received >= PROTOCOL_MAX_BUFFER_SIZE) {
      return PROT_RET_NOK; // Overflow
    }
  } while (1);

  *data_ptr = '\0';

  // Parse command
  if (data_received < 4) {
    return PROT_RET_NOK; // Invalid frame
  }

  // Extract command type (first 4 hex chars)
  char cmd_str[5] = {0};
  memcpy(cmd_str, data_buffer, 4);
  data->cmd_type = (uint16_t)strtol(cmd_str, NULL, 16);

  // Check if additional data present
  if (data_received > 5) {
    // Skip space
    uint16_t payload_len = data_received - 5;
    memcpy(data->data, &data_buffer[5], payload_len);
    data->data[payload_len] = '\0';
    data->data_len = payload_len;
  }

  data->status = PROT_STATUS_OK;
  return PROT_RET_OK;
}

// Send Response
prot_ret_t protocol_send_response(prot_data_t *data) {
  if (data->data_len > 0) {
    if (HAL_UART_Transmit(&huart2, data->data, data->data_len, HAL_MAX_DELAY) !=
        HAL_OK) {
      return PROT_RET_NOK;
    }

    // Send space
    if (HAL_UART_Transmit(&huart2, (uint8_t *)" ", 1, HAL_MAX_DELAY) !=
        HAL_OK) {
      return PROT_RET_NOK;
    }
  }

  // Send status
  const char *status_str =
      (data->status == PROT_STATUS_OK) ? STATUS_OK : STATUS_ERROR;
  if (HAL_UART_Transmit(&huart2, (uint8_t *)status_str, strlen(status_str),
                        HAL_MAX_DELAY) != HAL_OK) {
    return PROT_RET_NOK;
  }

  return PROT_RET_OK;
}

// Set status
prot_ret_t protocol_set_status(prot_status_t status, prot_data_t *data) {
  if (!data)
    return PROT_RET_NOK;
  data->status = status;
  return PROT_RET_OK;
}
