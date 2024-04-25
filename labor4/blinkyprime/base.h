/**
 * @file defines.h
 * @brief Definitions of bitmasks and base registers for RCC, GPIO, USART, and SysTick.
 */

#ifndef DEFINES_H
#define DEFINES_H

// Bitmasks

// RCC
#define RCC_AHB2ENR_GPIOA_EN (1)         /**< RCC AHB2 peripheral clock enable register for GPIOA. */
#define RCC_AHB1ENR_USART2_EN (1 << 17)  /**< RCC AHB1 peripheral clock enable register for USART2. */
#define RCC_AHB2ENR_PB (1 << 1)          /**< RCC AHB2 peripheral clock enable register for Port B. */

// GPIO
#define GPIOA_MODER_MODE2_PA2_AFM (0b10 << 4)       /**< GPIOA pin 2 alternate function mode. */
#define GPIOA_MODER_MODE15_PA15_AFM (0b10 << 30)    /**< GPIOA pin 15 alternate function mode. */
#define GPIO2_AFRL_AFSEL2 (0b0111 << 8)            /**< GPIO alternate function selection for pin 2. */
#define GPIOA_AFLH_AFSEL15 (0b0111 << 28)          /**< GPIO alternate function selection for pin 15. */
#define GPIO_MODER_LD3 (1 << 6)                    /**< GPIO pin mode register for LD3 LED. */
#define GPIO_PB3_HIGH (1 << 3)                     /**< GPIO pin output data register for PB3. */

// USART
#define USART_ISR_TXE (1 << 7)         /**< USART transmit data register empty flag. */
#define USART_ISR_TC (1 << 6)          /**< USART transmission complete flag. */
#define USART_CR1_UE (1)               /**< USART enable bit. */
#define USART_CR1_TE (1 << 3)          /**< USART transmitter enable bit. */

// Sys
#define STK_INIT (0b111)    /**< SysTick control and status register INIT bit value. */
#define STK_1HZ 0x1E8480    /**< SysTick reload value for 1Hz. */

// Base Register
#define RCC_BASE 0x40021000     /**< Base address of RCC registers. */
#define GPIOA_BASE 0x48000000    /**< Base address of GPIO Port A registers. */
#define GPIOB_BASE 0x48000400    /**< Base address of GPIO Port B registers. */
#define STK_BASE 0xE000E010      /**< Base address of SysTick registers. */
#define USART2_BASE 0x40004400   /**< Base address of USART2 registers. */

#endif /* DEFINES_H */
