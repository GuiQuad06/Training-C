/*
 * byte_manip.c
 *
 *  Created on: 7 mar. 2020
 *      Author: quad
 */

#include "byte_manip.h"

int check_parity(uint8_t byte)
{
    int i, acc = 0;

    for(i = 0 ; i < 8 ; i++) {
        acc += ((byte>>i & 0x01) ? 1 : 0);
    }
    return acc;
}

uint8_t xor_checksum_32b(uint32_t reg, unsigned int size)
{
    int i;
    uint8_t cs = (uint8_t)(reg & 0x000000FF);

    for(i = 0; i < size ; i++) {
        reg = reg >> 8;
        cs ^= (uint8_t)(reg & 0x000000FF);
    }
    return cs;
}

uint8_t xor_checksum(char* string, unsigned int size)
{
    int i;
    uint8_t tmp;
    uint8_t cs = (uint8_t)(string[size-1]);

    for(i = size-2; i >= 0 ; i--) {
        tmp = (uint8_t)string[i] ;
        cs ^= tmp;
    }
    return cs;
}

// Rajouter : Fonctions set & clear de bits
