/*
 * crc.h
 *
 *  Created on: 2 sept. 2024
 *      Author: quad
 */

#ifndef CRC_H_
#define CRC_H_

#include <stdint.h>

uint16_t crc16_byte_process(uint8_t byte);
uint16_t crc16_ccitt(const char *str);

#endif // CRC_H_
