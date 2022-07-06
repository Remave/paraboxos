#ifndef _STDIO
#define _STDIO

#include "stddef.h"
#include "stdint.h"
#include "hal_io.h"

//void wait_for_kinput

static void kputchar(uint8_t* out);

void kputchar(uint8_t* out)
{
	*out = inb(PORT_PS2_RW);
}

#endif