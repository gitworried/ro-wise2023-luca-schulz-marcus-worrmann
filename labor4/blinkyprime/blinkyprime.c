/**
 * @file main.c
 * @brief Entry point and SysTick handler for the application.
 */

#include "led.h"
#include "usart.h"

/**
 * @brief SysTick interrupt handler.
 * 
 * This function serves as the SysTick interrupt handler. It is called 
 * periodically based on the configured SysTick timer. In this implementation,
 * it toggles the state of the LED.
 */
void _systick(void)
{
    led_toggle();
}

/**
 * @brief Entry point of the application.
 * 
 * This function serves as the entry point of the application. It initializes
 * the USART communication and LED, and then enters an infinite loop where it
 * waits for interrupts. It periodically sends a message over USART.
 */
void _start()
{
    usart_init();
    led_init();

    while (1)
    {
        wfi();
        usart_puts("Blinkyprime\n");
    }
}