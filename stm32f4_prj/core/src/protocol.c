/**
 ******************************************************************************
 * @file    protocol.c
 * @author
 * @brief
 ******************************************************************************
 */
#include "protocol.h"
#include "usart.h"

extern UART_HandleTypeDef huart2;

// Initialize protocol
void protocol_init(void) {
  MX_USART2_UART_Init();
  return;
}

// Receive command
prot_ret_t protocol_receive_cmd(uint8_t *data, uint16_t *data_len) {

  uint8_t *ptr = data;
  uint16_t data_received;

  data_received = 0;
  while (1) {
    // Receive one byte at a time (blocking)
    if (HAL_UART_Receive(&huart2, ptr, 1, HAL_MAX_DELAY) != HAL_OK) {
      return PROT_RET_NOK;
    }

    if (*ptr == '\r' || *ptr == '\n') {
      *ptr = '\0';
      *data_len = data_received;
      return PROT_RET_OK; // Finish command reception
    }
    ptr++;
    data_received++;

    if (data_received >= PROTOCOL_MAX_BUFFER_SIZE) {
      *ptr = '\0';
      *data_len = data_received;
      return PROT_RET_NOK;
    }
  }
}

// Send reply
prot_ret_t protocol_send_reply(uint8_t *data, uint16_t data_len) {

  if (HAL_UART_Transmit(&huart2, (uint8_t *)data, data_len, HAL_MAX_DELAY) !=
      HAL_OK) {
    return PROT_RET_NOK;
  }
  return PROT_RET_OK;
}
