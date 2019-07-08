#include "font.h"

static const uint8_t symCodeOffset = 0x30;

const uint8_t SSD130632x28[] = {
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0xFF,0xFF,0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x0F,0x00,0x00,0xF0,0x07,0x00,0x00,0xE0,0x07,0x00,0x00,0xE0,0x07,0x00,0x00,0xE0,0x07,0x00,0x00,0xE0,0x07,0x00,0x00,0xE0,0x07,0x00,0x00,0xE0,0x07,0x00,0x00,0xE0,0x07,0x00,0x00,0xE0,0x07,0x00,0x00,0xE0,0x07,0x00,0x00,0xE0,0x07,0x00,0x00,0xE0,0x07,0x00,0x00,0xE0,0x07,0x00,0x00,0xE0,0x07,0x00,0x00,0xE0,0x07,0x00,0x00,0xE0,0x07,0x00,0x00,0xE0,0x0F,0x00,0x00,0xF0,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0xFF,0xFF,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // Code for char num 48
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0xFF,0xFF,0x7F,0xFF,0xFF,0xFF,0xFF,0xFE,0xFF,0xFF,0x7F,0x00,0x00,0x00,0x1C,0x00,0x00,0x00,0x0C,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // Code for char num 49
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0xFF,0x7F,0x07,0x80,0xFF,0xFF,0x07,0x80,0xFF,0xFF,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0xFF,0xFF,0x03,0xE0,0xFF,0xFF,0x03,0xE0,0xFE,0xFF,0x01,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // Code for char num 50
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0x7F,0xFF,0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x07,0xC0,0x01,0xE0,0x07,0xC0,0x01,0xE0,0x07,0xC0,0x01,0xE0,0x07,0xC0,0x01,0xE0,0x07,0xC0,0x01,0xE0,0x07,0xC0,0x01,0xE0,0x07,0xC0,0x01,0xE0,0x07,0xC0,0x01,0xE0,0x07,0xC0,0x01,0xE0,0x07,0xC0,0x01,0xE0,0x07,0xC0,0x01,0xE0,0x07,0xC0,0x01,0xE0,0x07,0xC0,0x01,0xE0,0x07,0xC0,0x01,0xE0,0x07,0xC0,0x01,0xE0,0x07,0xC0,0x01,0xE0,0x07,0xC0,0x01,0xE0,0x07,0xC0,0x01,0xE0,0x07,0xC0,0x01,0xE0,0x07,0xC0,0x01,0xE0,0x02,0x80,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // Code for char num 51
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0xFF,0xFF,0x7F,0xFF,0xFF,0xFF,0xFF,0xFE,0xFF,0xFF,0x7F,0x00,0x80,0x03,0x00,0x00,0x80,0x03,0x00,0x00,0x80,0x03,0x00,0x00,0x80,0x03,0x00,0x00,0x80,0x03,0x00,0x00,0x80,0x03,0x00,0x00,0x80,0x03,0x00,0x00,0x80,0x03,0x00,0x00,0x80,0x03,0x00,0x00,0x80,0x03,0x00,0x00,0x80,0x03,0x00,0x00,0x80,0x03,0x00,0x00,0x80,0x03,0x00,0x00,0x80,0x03,0x00,0x00,0x80,0x03,0x00,0x00,0x80,0x03,0x00,0x00,0x80,0x03,0x00,0x00,0x80,0x03,0x00,0x00,0x80,0xFF,0x7F,0x00,0x80,0xFF,0xFF,0x00,0x00,0xFF,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // Code for char num 52
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0xFF,0x00,0x40,0xFF,0xFF,0x01,0xE0,0xFF,0xFF,0x01,0xE0,0x07,0xC0,0x01,0xE0,0x07,0xC0,0x01,0xE0,0x07,0xC0,0x01,0xE0,0x07,0xC0,0x01,0xE0,0x07,0xC0,0x01,0xE0,0x07,0xC0,0x01,0xE0,0x07,0xC0,0x01,0xE0,0x07,0xC0,0x01,0xE0,0x07,0xC0,0x01,0xE0,0x07,0xC0,0x01,0xE0,0x07,0xC0,0x01,0xE0,0x07,0xC0,0x01,0xE0,0x07,0xC0,0x01,0xE0,0x07,0xC0,0x01,0xE0,0x07,0xC0,0x01,0xE0,0x07,0xC0,0x01,0xE0,0x07,0xC0,0x01,0xE0,0x07,0xC0,0x01,0xE0,0x07,0xC0,0xFF,0xFF,0x07,0xC0,0xFF,0xFF,0x02,0x80,0xFF,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // Code for char num 53
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0xFF,0x01,0x40,0xFF,0xFF,0x03,0xE0,0xFF,0xFF,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0xFF,0xFF,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // Code for char num 54
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0xFF,0xFF,0x7F,0xFF,0xFF,0xFF,0xFF,0xFE,0xFF,0xFF,0xFF,0x00,0x00,0x00,0xE0,0x00,0x00,0x00,0xE0,0x00,0x00,0x00,0xE0,0x00,0x00,0x00,0xE0,0x00,0x00,0x00,0xE0,0x00,0x00,0x00,0xE0,0x00,0x00,0x00,0xE0,0x00,0x00,0x00,0xE0,0x00,0x00,0x00,0xE0,0x00,0x00,0x00,0xE0,0x00,0x00,0x00,0xE0,0x00,0x00,0x00,0xE0,0x00,0x00,0x00,0xE0,0x00,0x00,0x00,0xE0,0x00,0x00,0x00,0xE0,0x00,0x00,0x00,0xE0,0x00,0x00,0x00,0xE0,0x00,0x00,0x00,0xE0,0x00,0x00,0x00,0xE0,0x00,0x00,0x00,0xE0,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // Code for char num 55
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0xFF,0xFE,0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0xFF,0xFE,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // Code for char num 56
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0xFF,0xFF,0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0x03,0xE0,0x07,0x80,0xFF,0xFF,0x07,0x80,0xFF,0xFF,0x02,0x00,0xFF,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 // Code for char num 57
         };

const uint8_t *getSymbol(uint8_t code)
{
    return &SSD130632x28[(code - 0x30) * 112];
}