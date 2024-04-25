/**
 * @file usart.h
 * @brief USART driver for USART2 peripheral.
 */
#ifndef USART_H
#define USART_H

#include <stdint.h>

/**
 * @brief Sends a single character to the default USART transmitter in blocking mode.
 *
 * @param c specifies the character to be sent
 */
void usart_putc(uint8_t c);

/**
 * @brief a null-terminated string to the default USART transmitter in blocking mode.
 * This function sends each character of the string until the null-terminator is encountered.
 *
 * @param str points to the string to be sent
 */
void usart_puts(const char *str);

/**
 * @brief a 32-bit unsigned integer as hexadecimal characters to the USART transmitter.
 * This function converts a 32-bit unsigned integer into its hexadecimal string representation
 * and sends it character by character to the USART.
 *
 * @param val the 32-bit unsigned integer to be sent as hexadecimal
 */
void usart_putx(uint32_t val);

/**
 * @brief initilise USART2 as given in the task
 * 
 */
void usart_init();
#endif 