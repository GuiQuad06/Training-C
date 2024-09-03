/*
 * crc.c
 *
 *  Created on: 2 sep. 2024
 *      Author: quad
 */

#include "crc.h"

// Register structure for the CRC16 processing
typedef union
{
    uint32_t value;

    struct __attribute__((packed))
    {
        uint8_t tail;
        uint16_t crc;
        uint8_t head;
    } part;
} crc16_ccitt_register_t;

static crc16_ccitt_register_t crc_register;

const uint16_t CRC_INIT       = 0xFFFF;
const uint16_t CRC_POLYNOMIAL = 0x1021;

uint16_t crc16_byte_process(uint8_t byte)
{
    uint8_t bit_remaining  = 8;
    // Load the payload
    crc_register.part.tail = byte;

    do
    {
        // Left shift one bit
        crc_register.value <<= 1;

        // Test the LSBit of the Head part
        if (crc_register.part.head & 0x01)
        {
            crc_register.part.crc ^= CRC_POLYNOMIAL;
        }
    } while (--bit_remaining);

    return crc_register.part.crc;
}

uint16_t crc16_ccitt(const char *str)
{
    // Initialize the remainder part of the CRC Register
    crc_register.part.crc = CRC_INIT;

    while (*str != '\0')
    {
        (void) crc16_byte_process((uint8_t) *str);
        str++;
    }

    // CRC16-CCITT final processing (0x0000)
    crc16_byte_process(0x00);
    crc16_byte_process(0x00);

    return crc_register.part.crc;
}
