#include "ssd1306.h"
#include "I2c.h"
#include "font.h"
#include "localTime.h"

#define CMD_MEM_MODE 0x20
#define CMD_HOR_VER_CMNS 0x21
#define CMD_HOR_VER_PAGES 0x22
#define CMD_CNTRST 0x81

enum MemoryMode {
	Horizontal = 0x00,
	Vertical = 0x01,
	Page = 0x02
};

static const uint8_t addr = 0x3C;
//static const uint8_t addr = 0x3D;
static const uint8_t CommandTransmit = 0x00;
static const uint8_t DataTransmit = 0x40;

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

static void setMemoryMode(enum MemoryMode memMode)
{
	sendCommand(CMD_MEM_MODE);
	sendCommand(memMode);
}

static void pageStart(uint8_t page)
{
	sendCommand(start & 0x07 | 0xB0);
}

static void pageStartColumn(uint8_t col)
{
	sendCommand(col & 0x0F);
	sendCommand(col >> 4 & 0x0F | 0x10);
}

static void horVerColums(uint8_t start, uint8_t end)
{
	sendCommand(CMD_HOR_VER_CMNS);
	sendCommand(start);
	sendCommand(end);
}

static void horVerPages(uint8_t start, uint8_t end)
{
	sendCommand(CMD_HOR_VER_PAGES);
	sendCommand(start);
	sendCommand(end);
}


static void stuffInit()
{
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
}

static void setContrast(uint8_t contrast)
{
	sendCommand(CMD_CNTRST);
	sendCommand(contrast);
}

void initDisplay(void)
{
    sendCommand(0xAE); //display off
	setMemoryMode(Vertical);
	horVerPages(0x00, 0x07);
	horVerColums(0x00, 0x7F);
	stuffInit();
    sendCommand(0xAF); //--display on

    drawSymbol(getSymbol(0x34));
}
