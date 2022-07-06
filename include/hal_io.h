#ifndef _IO_H
#define _IO_H

#include "stdint.h"
#include "stddef.h"

#define PORT_PS2_RW 0x60

static void outb(uint16_t port, uint8_t data);
static void outw(uint16_t port, uint16_t data);
static void outl(uint16_t port, uint32_t data);

static uint8_t  inb(uint16_t port);
static uint16_t inw(uint16_t port);
static uint32_t inl(uint16_t port);

void outb(uint16_t port, uint8_t data)
{
	asm volatile("outb %0, %1" : : "a"(data), "Nd"(port));
	return;
}

void outw(uint16_t port, uint16_t data)
{
	asm volatile("outw %w0, %1" : : "a" (data), "id" (port) );
}

void outl(uint16_t port, uint32_t data)
{
	asm volatile("outl %%eax, %%dx" :: "d" (port), "a" (data));
}

uint8_t inb(uint16_t port)
{
	uint8_t res;
	asm volatile("inb %1, %0" : "=a"(res) : "Nd"(port));
	return res;
}

uint16_t inw(uint16_t port)
{
   uint16_t ret;
   asm volatile("inw %1, %0" : "=a" (ret) : "dN" (port));
   return ret;
}

uint32_t inl(uint16_t port)
{
   uint32_t ret;
   asm volatile("inl %1, %0" : "=a" (ret) : "dN" (port));
   return ret;
}

#endif