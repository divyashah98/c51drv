/*  Copyright (c) 2013, laborer (laborer@126.com)
 *  Licensed under the BSD 2-Clause License.
 */


#ifndef __UART_H
#define __UART_H


#define UART_SMOD       1
#define UART_BAUD       4800


#if defined SDCC || defined __SDCC
void uart_interrupt(void) __interrupt SI0_VECTOR __using 1;
#endif


char uart_rcready();
char uart_txready();
void uart_putchar(unsigned char c);
unsigned char uart_getchar(void);
void uart_baudrate(void);
char uart_baudrate_auto(void);
void uart_init(void);


#endif /* __UART_H */
