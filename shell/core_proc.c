#define _CORE_PROC_ALLOCER_C

#include "../include/stdint.h"
#include "../include/string.h"
#include "../include/hal_io.h"

//4Mb max size allocdte for process
#define ALLOC_MODE_SIZE 4194303

/*
	kernel
	|                  |
	structure of process
	|                  |
	+------------------+ max
	| || Stack         |
	| \/               |
	+- - - - - - - - - + 4KG stack size
	|       free       |
	+- - - - - - - - - +
	| /\               |
	| || Heap          |
	+------------------+  } 3MB max
	|                  |
	|  DATA            |
	|                  |
	+------------------+
	|                  |
	|  CODE            |
	|                  |
	+------------------+ 0
	|                  |
*/

//processes allocer
uint32_t* alloc_proc(uint32_t sp)
{
	
}