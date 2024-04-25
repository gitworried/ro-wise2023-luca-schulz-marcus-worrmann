/**
 * @file blinky.h
 * @brief Header file for blinky implementation
 */

#ifndef BLINKY_H
#define BLINKY_H

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

/**;
 * @brief Retrieves the current value of the system tick counter.
 * 
 * This function returns a pointer to the system tick counter register (STK_VAL).
 * The system tick counter is used for time delays in the system.
 * 
 * @return A constant pointer to volatile uint32_t representing the address of the system tick value register.
 */
volatile uint32_t *const stk_value();

/**
 * @brief Checks if the button is pressed.
 * 
 * This function reads the input data register and checks the status of the button connected to bit 3.
 * A logical NOT operation is applied to invert the mask bit and check the button status.
 * 
 * @return int Returns 1 if the button is pressed, otherwise returns 0.
 */
int button();

/**
 * @brief Enables the system tick counter.
 * 
 * This function sets the least significant bit of the STK_CNTRL register to 1,
 * which starts the system tick counter.
 */
void clock_on();

/**
 * @brief Disables the system tick counter.
 * 
 * This function clears the least significant bit of the STK_CNTRL register,
 * effectively stopping the system tick counter.
 */
void clock_off();

/**
 * @brief Toggles the state of the system tick counter.
 * 
 * This function checks the current state of the system tick counter and toggles it.
 * If the counter is on, it is turned off, and if it is off, it is turned on.
 * Additional actions are performed if the counter is turned off including setting the LED and resetting the register.
 */
void clock_toggle();


/**
 * @brief Enters the processor into wait-for-interrupt mode.
 * 
 * This function executes the WFI (Wait For Interrupt) assembly instruction,
 * which causes the processor to stop executing instructions and conserve power
 * until an interrupt is received.
 */
void wfi();
#endif /* BLINKY_H */
