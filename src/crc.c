/*
 * crc.c
 *
 *  Created on: 2 sep. 2024
 *      Author: quad
 */

#include "crc.h"

// Register structure for the CRC16 processing
typedef union {
    int value;
    struct {
        int8_t head;
        int16_t crc;
        int8_t tail;
    } part;
} crc_register_t; 

static crc_register_t crc_register;

const int CRC_INIT = 0xFFFF;
const int CRC_POLYNOMIAL = 0x1021;

void crc16_byte_process(int8_t byte)
{
    int bit_remaining = 8;
    // Load the payload
    crc_register.part.tail = byte;

    do
    {
        // Left shift one bit
        crc_register.value <<= 1;

        // Test the LSBit of the Head part
        if (crc_register.part.head & 0x1)
        {
            crc_register.part.crc ^= CRC_POLYNOMIAL;
        }
    } while (--bit_remaining);
}

int16_t crc16_ccitt(const char *str)
{
    // Initialize the remainder part of the CRC Register
    crc_register.part.crc = CRC_INIT;

    while(*str != '\0')
    {
        crc16_byte_process(*str);
        str++;
    }

    // Why ??
    crc16_byte_process(0x00);
    crc16_byte_process(0x00);

    return crc_register.part.crc;
}

