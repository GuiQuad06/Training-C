/*
 * crc.h
 *
 *  Created on: 2 sept. 2024
 *      Author: quad
 */

#ifndef CRC_H_
#define CRC_H_

#include <stdint.h>

void crc16_byte_process(int8_t byte);
int16_t crc16_ccitt(const char *str);

#endif // CRC_H_
