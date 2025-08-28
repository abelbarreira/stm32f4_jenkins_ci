/**
 ******************************************************************************
 * @file    protocol.h
 * @author
 * @brief
 ******************************************************************************
 */

#ifndef PROTOCOL_H
#define PROTOCOL_H

#include "stm32f4xx_hal.h"

#define PROTOCOL_MAX_BUFFER_SIZE 64

/// @brief Protocol Status
typedef enum {
  PROT_STATUS_OK = 0,
  PROT_STATUS_ERROR = 1,
  PROT_STATUS_EMPTY = 2
} prot_status_t;

/// @brief Protocol Data
typedef struct {
  uint16_t cmd_type;
  uint8_t data[PROTOCOL_MAX_BUFFER_SIZE];
  uint16_t data_len;
  prot_status_t status;
} prot_data_t;

/// @brief Protocol Returning values
typedef enum { PROT_RET_OK = 0, PROT_RET_NOK = 1 } prot_ret_t;

// Initialize protocol
prot_ret_t protocol_init(void);

// Receive Command
prot_ret_t protocol_receive_command(prot_data_t *data);

// Send Response
prot_ret_t protocol_send_response(prot_data_t *data);

// Set status
prot_ret_t protocol_set_status(prot_status_t status, prot_data_t *data);

#endif // PROTOCOL_H
