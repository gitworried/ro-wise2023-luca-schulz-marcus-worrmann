/**
 * @file led.h
 * @brief Header file for led implementation
 */

#ifndef LED_H
#define LED_H

#include <stdint.h>
/**
 * @file led.h
 * @brief Header file for controlling an LED on STM32L432KC
 * 
 * This file contains function prototypes for controlling an LED on STM32L432KC.
 */

/**
 * @brief Initialize GPIO PortB and configure the LED pin as output
 * 
 * This function initializes the GPIO PortB and configures the pin connected to the LED
 * as an output pin.
 */

/**
 * @brief Sets the specified bits in a register while clearing other bits.
 *
 * This function sets the specified bits in a register while clearing other bits
 * according to the provided bitmask and not_bitmask.
 *
 * @param reg Pointer to the register.
 * @param bitmask The bitmask specifying which bits to set.
 * @param not_bitmask The bitmask specifying which bits to clear.
 */
void set_register(volatile uint32_t *reg, int bitmask, int not_bitmask);

/**
 * @brief Initializes the LED and system components.
 *
 * This function initializes the LED and system components by configuring
 * the necessary registers.
 */
void led_init();

/**
 * @brief Set the state of the LED
 * 
 * @param value The value to set (0 for off, 1 for on)
 */
void led_set(int value);

/**
 * @brief Toggle the state of the LED
 */
void led_toggle(void);

/**
 * @brief Enters the processor into wait-for-interrupt mode.
 * 
 * This function executes the WFI (Wait For Interrupt) assembly instruction,
 * which causes the processor to stop executing instructions and conserve power
 * until an interrupt is received.
 */
void wfi();
#endif /* LED_H */
