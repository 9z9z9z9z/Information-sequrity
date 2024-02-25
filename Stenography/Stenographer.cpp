//
// Created by rolya on 24.02.2024.
//

#include "Stenographer.h"

void Stenographer::hide_byte_into_pixel(RGBQUAD *pixel, uint8_t hide_byte) {
    pixel->rgbBlue &= (0xFC);
    pixel->rgbBlue |= (hide_byte >> 6) & 0x3;
    pixel->rgbGreen &= (0xFC);
    pixel->rgbGreen |= (hide_byte >> 4) & 0x3;
    pixel->rgbRed &= (0xFC);
    pixel->rgbRed |= (hide_byte >> 2) & 0x3;
    pixel->rgbReserved &= (0xFC);
    pixel->rgbReserved |= (hide_byte) & 0x3;
}

void Stenographer::extract_byte_from_pixel(const RGBQUAD *pixel, uint8_t *extracted_byte) {
    *extracted_byte = 0;
    *extracted_byte |= (pixel->rgbBlue & 0x3) << 6;
    *extracted_byte |= (pixel->rgbGreen & 0x3) << 4;
    *extracted_byte |= (pixel->rgbRed & 0x3) << 2;
    *extracted_byte |= (pixel->rgbReserved & 0x3);
}



