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

typedef enum { PROT_RET_OK = 0, PROT_RET_NOK = 1 } prot_ret_t;

// Initialize protocol
void protocol_init(void);

// Receive command
prot_ret_t protocol_receive_cmd(uint8_t *data, uint16_t *data_len);

// Send reply
prot_ret_t protocol_send_reply(uint8_t *data, uint16_t data_len);

#endif // PROTOCOL_H
