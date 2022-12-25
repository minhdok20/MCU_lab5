/*
 * global.h
 *
 *  Created on: 25 Dec 2022
 *      Author: HP PV
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"

//Setup time cycle
extern int TICK;

//Status command parser
extern int command_parser_status;
#define INIT_COMMAND		0
#define	WAIT_COMMAND_END	1

//Status UART communication
extern int uart_communication_status;
#define WAIT			11
#define SEND_ADC_VALUE	12

//String to display on the console
extern char str[50];

//ADC Value
extern uint32_t ADC_value;

#define MAX_BUFFER_SIZE 30
extern uint8_t temp;

extern uint8_t buffer[MAX_BUFFER_SIZE];
extern uint8_t index_buffer;
extern uint8_t buffer_flag;

extern uint8_t index_command;
extern uint8_t command_flag;

extern ADC_HandleTypeDef hadc1;
extern UART_HandleTypeDef huart2;

#endif /* INC_GLOBAL_H_ */
