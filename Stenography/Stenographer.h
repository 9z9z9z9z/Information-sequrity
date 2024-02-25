#ifndef STENOGRAPHY_STENOGRAPHER_H
#define STENOGRAPHY_STENOGRAPHER_H

#include <cstdint>
#include <string>
#include "Structs.h"


class Stenographer {
public:
    static void extract_byte_from_pixel(const RGBQUAD *pixel, uint8_t *extracted_byte);
    static void hide_byte_into_pixel(RGBQUAD *pixel, uint8_t extracted_byte);
};


#endif //STENOGRAPHY_STENOGRAPHER_H
