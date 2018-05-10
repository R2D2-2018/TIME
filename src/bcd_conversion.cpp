/**
 * @file
 * @brief     These functions are used to convert between BCD and decimal.
 * @author    Jasper Smienk
 * @license   MIT License
 */

#include "bcd_conversion.hpp"

uint8_t decToBCD(uint8_t dec) {
    return (dec / 10 * 16) + (dec % 10);
}

uint8_t BCDToDec(uint8_t bcd) {
    return (bcd / 16 * 10) + (bcd % 16);
}
