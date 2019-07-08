#ifndef SRC_FONT_H
#define SRC_FONT_H

#include <inttypes.h>

extern const uint8_t SSD130632x28[];

const uint8_t *getSymbol(uint8_t code);

#endif // FONT_H
