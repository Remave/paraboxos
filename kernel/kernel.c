/*
	ParaboxOS KERNEL 32bit
	Copyright 2022 
*/
//#include "../include/stdint.h"
//#include "../include/string.h"
//#include "../include/io.h"
//#include "../shell/core_proc.c"
//#include "../fs/pbfs.c"
#include "../shell/shell.h"

#define INC2(a) a+=2
#define INC4(a) a+=4

#define DEC2(a) a-=2
#define DEC4(a) a-=4

#define _NOP asm("NOP")

//char *vid_ptr = (char*)0xb8000; //pointer to video mem text

//int32_t cur_pos = 0;

// typedef struct 
// {
// 	//packaged
// 	uint8_t t;
// } k_pb_objectical;

void noping(uint32_t cycle)
{
	while (cycle--) _NOP;
}

void kmain(void)
{
	clr();
	noping(100); //wait :|
	//kprint("Kernel initialization\n");


	noping(100); //wait :|
	clr();	
	load_shell();
	// while (1) {
		
		
	//  	_NOP;
	// }
}