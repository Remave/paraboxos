#ifndef _VGA_TEXT_H
#define _VGA_TEXT_H

#include "stdint.h"
#include "stddef.h"
#include "colors.h"

#define COLS 80
#define ROWS 25
#define SIZE_SCRN COLS*ROWS

#define EMPTY_CHAR (VGACHAR){NULL, NULL}
#define INSERT_CHAR(c) (VGACHAR){c, cur_color}

#define CURPOS_INC cur_pos++
#define CURPOS_DEC cur_pos--

// #define CURPOS_CHAR (cur_pos)
// #define CURPOS_COLR (cur_pos+1)

#define RESET_CURPOS cur_pos=0
#define SET_CURPOS(col, row) cur_pos=col*ROWS+row

#define INIT_VGA_COLOR set_color(BG_BLACK, FG_WHITE);

struct k_cur { uint8_t _char, _color; } __attribute__((packed));

typedef struct k_cur VGACHAR;

extern uint8_t* stack_top[];

static struct k_cur *vid_ptr = (VGACHAR*)0xb8000; //pointer to video mem text

static int32_t cur_pos = 0;
static int32_t cur_color = 0;

static void set_color(uint8_t bg, uint8_t fg);

static void _set_pos_newline(void);

static void clr(void);

static void kprint(const char*);

static void write_to_vmem(VGACHAR chr); //write data to video mem by struct

void set_color(uint8_t bg, uint8_t fg)
{
	cur_color=(bg|fg);
}

void _set_pos_newline()
{
	int16_t curlen = (cur_pos % (COLS));
	cur_pos+=COLS-curlen;
}

void clr()
{
	int16_t i = 0;
	set_color(BG_BLACK, FG_WHITE);
	while (i < SIZE_SCRN) {
		write_to_vmem(EMPTY_CHAR);
		i++;
	}
	RESET_CURPOS;
}

void kprint(const char* str)
{
	int16_t i = 0;
	//set_color(BG_BLACK, FG_WHITE);
	while (str[i] != 0) {
		if (str[i] == '\n') _set_pos_newline();
		//if (str[i] == '\r') _set_pos_newline();
		else
			write_to_vmem(INSERT_CHAR(str[i]));
		i++;
	}
}

void write_to_vmem(VGACHAR chr)
{
	vid_ptr[CURPOS_INC] = chr;
}

//implementation



#endif