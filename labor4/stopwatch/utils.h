/**
 * @file
 * Utility functions for time conversion and string manipulation.
 */

#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>

/**
 * Converts a CVR value to milliseconds.
 *
 * This function calculates milliseconds based on the CVR and a multiplier
 * for half seconds.
 *
 * @param cvr The CVR value to convert.
 * @param halfs The number of half-second units to consider in the calculation.
 * @return The computed time in milliseconds.
 */
uint32_t cvr2ms(uint32_t cvr, uint32_t halfseconds);

/**
 * Converts an unsigned integer to a string.
 *
 * This function converts an unsigned integer into its decimal string representation.
 * The resulting string is stored in the provided buffer in reverse order.
 *
 * @param buf A pointer to the buffer where the string representation of the number will be stored.
 * @param val The unsigned integer to convert.
 * @return A pointer to the beginning of the string representation within the buffer.
 */
char *utoa(char *buf, uint32_t val);

/**
 * Formats a millisecond value into a string with the format "seconds.milliseconds".
 *
 * This function takes a millisecond count and converts it into a formatted string
 * showing seconds and milliseconds separated by a period.
 *
 * @param buf A pointer to the buffer where the formatted time will be stored.
 * @param buflen The length of the buffer.
 * @param ms The millisecond value to format.
 */
void format_ms(char *buf, int buflen, uint32_t ms);

#endif
