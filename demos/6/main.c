/*  Copyright (c) 2013, laborer (laborer@126.com)
 *  Licensed under the BSD 2-Clause License.
 */


#include "common.h"
#include "uart.h"
#include "print.h"
#include "timer.h"
#include <stdlib.h>


void welcome(void)
{
    uart_baudrate();
    uart_init();
    UARTSTR("c51drv\n");
}

/* Send an unsigned int */
void _uart_putulong(unsigned long i)
{
    unsigned char __idata       buf[10];
    unsigned char               j;
    
    ulong2bcd(i, buf);
    for (j = 0; j < 9 && buf[j] == 0; j++);
    for (; j < 10; j++) {
        UARTCHAR('0' + buf[j]);
    }
}

void main(void) {
    /* unsigned char __code *p; */
    /* unsigned char i; */
    unsigned long t;
    unsigned char __idata buf[10];

    welcome();

    uart_getchar();

    /* for (p = 0; p < 8 * 1024; p++) { */
    /*     UARTCHAR(*p); */
    /*     DELAY_US(3423); */
    /* } */

    /* _uart_putulong(12345L); */
    /* UARTCHAR('\n'); */
    /* _uart_putulong(12312424L); */
    /* UARTCHAR('\n'); */
    /* _uart_putulong(4294967295L); */
    /* UARTCHAR('\n'); */
    /* _uart_putulong(3932154463L); */
    /* UARTCHAR('\n'); */


    delay_ms(1000);

    TIMER0_INIT32();
    TIMER0_START();

    t = TIMER0_GET32();
    ulong2bcd(393215L, buf);
    t = TIMER0_GET32() - t;
    _uart_putulong(t);
    UARTCHAR('\n');

    delay_ms(1000);

    t = TIMER0_GET32();
    ulong2bcd(3932159463UL, buf);
    t = TIMER0_GET32() - t;
    _uart_putulong(t);
    UARTCHAR('\n');

    delay_ms(1000);

    t = TIMER0_GET32();
    _ultoa(393215L, buf, 10);
    t = TIMER0_GET32() - t;
    _uart_putulong(t);
    UARTCHAR('\n');

    delay_ms(1000);

    t = TIMER0_GET32();
    _ultoa(3932159463UL, buf, 10);
    t = TIMER0_GET32() - t;
    _uart_putulong(t);
    UARTCHAR('\n');

    while (1);
}