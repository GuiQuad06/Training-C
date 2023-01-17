/*
 * byte_manip.h
 *
 *  Created on: 7 mar. 2020
 *      Author: quad
 */

#ifndef BYTE_MANIP_H_
#define BYTE_MANIP_H_

#include <stdint.h>

int check_parity(uint8_t byte);
uint8_t xor_checksum_32b(uint32_t reg, unsigned int size);
uint8_t xor_checksum(char* string, unsigned int size);

#endif /* BYTE_MANIP_H_ */
