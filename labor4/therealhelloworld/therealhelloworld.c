#include "usart.h"

void _start()
{
    usart_init();
    while (1)
    {
    usart_puts("hello world!\n");
    }
}