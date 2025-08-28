/**
 ******************************************************************************
 * @file    command_processor.h
 * @author
 * @brief
 ******************************************************************************
 */
#ifndef COMMAND_PROCESSOR_H
#define COMMAND_PROCESSOR_H

#include "protocol.h"

// Initialize command processor (e.g., setup table if needed)
prot_ret_t command_processor_init(void);

// Process a received command
prot_ret_t command_processor_execute(prot_data_t *data);

#endif // COMMAND_PROCESSOR_H
