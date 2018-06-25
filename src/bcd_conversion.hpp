/**
 * @file
 * @brief     These functions are used to convert between BCD and decimal.
 * @author    Jasper Smienk
 * @license   MIT License
 */

#ifndef BCD_CONVERSION_HPP
#define BCD_CONVERSION_HPP

#include "wrap-hwlib.hpp"
#include <cstdint>

/**
 * @brief Convert from decimal to BCD.
 *
 * This function is used to convert from a
 * decimal number to a Binary Coded Decimal number.
 *
 * @param[in]     dec    A decimal number.
 * @return A Binary Coded Decimal number.
 */
uint8_t decToBCD(uint8_t dec);

/**
 * @brief Convert from BCD to decimal.
 *
 * This function is used to convert from a
 * Binary Coded Decimal number to a decimal number.
 *
 * @param[in]     bcd    A BCD number.
 * @return A decimal number.
 */
uint8_t BCDToDec(uint8_t bcd);

#endif // BCD_CONVERSION_HPP
