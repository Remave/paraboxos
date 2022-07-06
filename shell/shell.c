
#include "shell.h"

#define PRINT_ASCIIART \
	kprint("  _____             _           _____ _____ \n"); \
	kprint(" |  _  |___ ___ ___| |_ ___ _ _|     |   __|\n"); \
	kprint(" |   __| .'|  _| .'| . | . |_'_|  |  |__   |\n"); \
	kprint(" |__|  |__,|_| |__,|___|___|_,_|_____|_____|\n")



static const int8_t SHELL_VERSION_MAJOR = 1;
static const int8_t SHELL_VERSION_MINOR = 1;

state_shell_t k_st_shell;
char* char_buffer = 0;

void load_shell()
{
	// state_shell.current_proc = 0;
	// state_shell.ptr_to_curproc = NULL;
	// state_shell.status = NULL; //NOPING
	INIT_VGA_COLOR;
	kprint("Wellcom to ParaboxOS v1.0 [Shell v1.1]\n");
	PRINT_ASCIIART;
	kprint("\n");
	kprint("type help for commands list, <command> -h for info a command.\n");
	set_color(BG_BLACK, FG_LIGHT_RED);
	kprint("root:");
	set_color(BG_BLACK, FG_WHITE);
	kprint(" /> ");
	// do {
	// 	kputchar(char_buffer);
	// 	kprint(char_buffer);
	// } while (char_buffer > 0);

}

void refresh_shell()
{

}

void parse_command(const char* cmd)
{

}

void execute_command(char* ptr_to_hd)
{

}
