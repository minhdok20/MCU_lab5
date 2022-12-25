/*
 * uart_communication_fsm.c
 *
 *  Created on: 25 Dec 2022
 *      Author: HP PV
 */


#include "uart_communication_fsm.h"

void uart_communication_fsm() {
	switch(uart_communication_status) {
	case WAIT:
		if(command_flag == 1) {
			command_flag = 0;
			if(buffer[27] == 'R' && buffer[28] == 'S' && buffer[29] == 'T') {
				HAL_ADC_Start(&hadc1);
				ADC_value = HAL_ADC_GetValue(&hadc1);
				HAL_ADC_Stop(&hadc1);
				HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "\r\n"), 1000);
				uart_communication_status = SEND_ADC_VALUE;
				setTimer2(3000);
			}
			else {
				if(buffer[27] == 'O' && buffer[28] == 'K') {
					HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "\r\n"), 1000);
					clearTimer2();
				}
			}
		}

		if(timer2_flag == 1) {
			uart_communication_status = SEND_ADC_VALUE;
			setTimer2(3000);
		}
		break;
	case SEND_ADC_VALUE:
		HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "!ADC=%lu#\r\n", ADC_value), 1000);
		uart_communication_status = WAIT;
		break;
	default:
		break;
	}
}
