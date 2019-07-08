#include "ssd1306.h"
#include "I2c.h"
#include "font.h"
#include "localTime.h"

static const uint8_t addr = 0x3C;
//static const uint8_t addr = 0x3D;

static const uint8_t CommandTransmit = 0x00;
static const uint8_t DataTransmit = 0x40;

static const uint8_t followRamContent = 0xA4;
static const uint8_t ignoreRamContent = 0xA5;

static const uint8_t normalDisplay = 0xA6;
static const uint8_t inverseDisplay = 0xA7;

static const uint8_t displayOff = 0xAE;
static const uint8_t displayOn = 0xAF;

static uint8_t pageBuffer[129];

static void drawSymbol(const uint8_t *aSymPtr);
static void drawColumn(const uint8_t *aColPtr);

static void setContrast(uint8_t contrast)
{
	uint8_t buf[] = {CommandTransmit, contrast};

	sendBuffer(addr, buf, sizeof(buf) / sizeof(buf[0]));
}

static void entDispOn(uint8_t ramContent)
{
	uint8_t buf[] = {CommandTransmit, ramContent};

	sendBuffer(addr, buf, sizeof(buf) / sizeof(buf[0]));
}

static void normalInverseDisp(uint8_t normInvDisp)
{
	uint8_t buf[] = {CommandTransmit, normInvDisp};

	sendBuffer(addr, buf, sizeof(buf) / sizeof(buf[0]));
}

static void displayOnOff(uint8_t onOff)
{
	uint8_t buf[] = {CommandTransmit, onOff};

	sendBuffer(addr, buf, sizeof(buf) / sizeof(buf[0]));
}

static void sendCommand(uint8_t data)
{
    uint8_t buf[] = {CommandTransmit, data};
    sendBuffer(addr, buf, sizeof(buf) / sizeof(buf[0]));
}

static void sendDataBuffer(uint8_t *inBuf, uint8_t len)
{
    *inBuf = DataTransmit;
    sendBuffer(addr, inBuf, len);
}

static void drawSymbol(const uint8_t *aSymPtr)
{
    uint8_t cnt = 27;

    while (cnt --) {
        drawColumn(aSymPtr + 4 * cnt);
    }
}

static void drawColumn(const uint8_t *aColPtr)
{
    const uint8_t *colPtr = aColPtr;
    uint8_t col = 0;
    uint8_t colBuf[2];

    for (uint8_t i = 0; i < 4; i++) {
        col = (uint8_t)(col | ((*colPtr) & 0x01));
        col = (uint8_t)(col | (((*colPtr >> 1) & 0x01) << 2));
        col = (uint8_t)(col | (((*colPtr >> 2) & 0x01) << 4));
        col = (uint8_t)(col | (((*colPtr >> 3) & 0x01) << 6));
        colBuf[1] = col;
        sendDataBuffer(colBuf, 2);
        col = 0;

        col = (uint8_t)(col | ((*colPtr >> 4) & 0x01));
        col = (uint8_t)(col | (((*colPtr >> 5) & 0x01) << 2));
        col = (uint8_t)(col | (((*colPtr >> 6) & 0x01) << 4));
        col = (uint8_t)(col | (((*colPtr >> 7) & 0x01) << 6));
        colBuf[1] = col;
        sendDataBuffer(colBuf, 2);
        col = 0;

        colPtr++;
    }
}

static void clearScreen()
{
    sendCommand(0x21); //Set column address for vertical mode
    sendCommand(0x00); //Set start column for vertical mode
    sendCommand(0x7F); //Set end column for vertical mode

    for (uint32_t i = 0; i < 8 * 128; i ++) {
        uint8_t buf[] = {0, 0};
        sendDataBuffer(buf, 2);
    }
}

static void clearSymbol()
{
    sendCommand(0x22); //Set page address for vertical mode
    sendCommand(0x00); //Set start page for vertical mode
    sendCommand(0x07); //Set end page for vertical mode

    for (uint32_t i = 0; i < 8 * 28; i ++) {
        uint8_t buf[] = {0, 0};
        sendDataBuffer(buf, 2);
    }
}

void initDisplay(void)
{
    sendCommand(0xAE); //display off
    sendCommand(0x20); //Set Memory Addressing Mode
    sendCommand(0x01); //00,Horizontal Addressing Mode;01,Vertical Addressing Mode;10,Page Addressing Mode (RESET);11,Invalid

    sendCommand(0x22); //Set page address for vertical mode
    sendCommand(0x00); //Set start page for vertical mode
    sendCommand(0x07); //Set end page for vertical mode

    sendCommand(0x21); //Set column address for vertical mode
    sendCommand(0x1C); //Set start column for vertical mode
    sendCommand(0x3C); //Set end column for vertical mode

    sendCommand(0xC0); //Set COM Output Scan Direction
    sendCommand(0x40); //--set start line address
    sendCommand(0x81); //--set contrast control register
    sendCommand(0x7F);
    sendCommand(0xA1); //--set segment re-map 0 to 127
    sendCommand(0xA6); //--set normal display
    sendCommand(0xA8); //--set multiplex ratio(1 to 64)
    sendCommand(0x3F);
    sendCommand(0xA4); //0xa4,Output follows RAM content;0xa5,Output ignores RAM content
    sendCommand(0xD3); //-set display offset
    sendCommand(0x00);
    sendCommand(0xD5); //--set display clock divide ratio/oscillator frequency
    sendCommand(0xF0); 
    sendCommand(0xD9); //--set pre-charge period
    sendCommand(0x22); //
    sendCommand(0xDA); //--set com pins hardware configuration
    sendCommand(0x12);
    sendCommand(0xDB); //--set vcomh
    sendCommand(0x20); 
    sendCommand(0x8D); //--set DC-DC enable
    sendCommand(0x14);
    sendCommand(0xAF); //--turn on SSD1306 panel

    clearScreen();

    sendCommand(0x22); //Set page address for vertical mode
    sendCommand(0x00); //Set start page for vertical mode
    sendCommand(0x07); //Set end page for vertical mode

    sendCommand(0x21); //Set column address for vertical mode
    sendCommand(0x1C); //Set start column for vertical mode
    sendCommand(0x3C); //Set end column for vertical mode

    drawSymbol(getSymbol(0x34));

    uint8_t code = 0x30;

    while (1) {
        sendCommand(0x22); //Set page address for vertical mode
        sendCommand(0x00); //Set start page for vertical mode
        sendCommand(0x07); //Set end page for vertical mode

        sendCommand(0x21); //Set column address for vertical mode
        sendCommand(0x3D); //Set start column for vertical mode
        sendCommand(0x58); //Set end column for vertical mode

        drawSymbol(getSymbol(0x34));
        delayMs(5000);

        sendCommand(0x21); //Set column address for vertical mode
        sendCommand(0x3D); //Set start column for vertical mode
        sendCommand(0x58); //Set end column for vertical mode

        clearSymbol();
        ++code;
        if (code == 0x3A)
            code = 0x30;
    }


}
