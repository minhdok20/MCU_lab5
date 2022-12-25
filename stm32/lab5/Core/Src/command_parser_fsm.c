/*
 * command_parser_fsm.c
 *
 *  Created on: 25 Dec 2022
 *      Author: HP PV
 */


#include "command_parser_fsm.h"

void command_parser_fsm() {
	switch(command_parser_status) {
	case INIT_COMMAND:
		//if the received character is '!', jump to WAIT_COMMAND_END and start reading the command
		if(temp == '!') {
			command_parser_status = WAIT_COMMAND_END;
			index_command = 27;
		}
		break;
	case WAIT_COMMAND_END:
		switch(temp) {
		//if the received character is '#', return INIT_COMMAND status, end
		case '#':
			command_parser_status = INIT_COMMAND;
			command_flag = 1;
			break;
		//if the received character is '!', reset index_buffer in order to reread the command
		case '!':
			index_command = 27;
			break;
		//continue reading the command if not receive '!' or '#'
		default:
			buffer[index_command++] = temp;
			if(index_command == MAX_BUFFER_SIZE)
				index_command = 27;
			break;
		}
		break;
	default:
		break;
	}
}
