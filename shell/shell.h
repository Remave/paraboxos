#ifndef _SHELL_H
#define _SHELL_H

#include "../include/stdint.h"
#include "../include/string.h"
#include "../include/stdio.h"
#include "../include/vga_text.h"

typedef struct
{
	uint32_t current_proc;
	int8_t   status;
	uint8_t* ptr_to_curproc;
	char*    input_chars;
	char*    curcmd;
	char**   args;
} __attribute__((packed)) state_shell_t;

//init and load shell
void load_shell(void);

void refresh_shell(void);

void parse_command(const char* cmd);

void execute_command(char* ptr_to_hd);

#endif