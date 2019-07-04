#include "ssd1306.h"
#include "I2c.h"

static const uint8_t addr = 0x3C;
//uint8_t addr = 0x3D;

static const uint8_t CommandTransmit = 0x00;
static const uint8_t DataTransmit = 0x40;

static const uint8_t followRamContent = 0xA4;
static const uint8_t ignoreRamContent = 0xA5;

static const uint8_t normalDisplay = 0xA6;
static const uint8_t inverseDisplay = 0xA7;

static const uint8_t displayOff = 0xAE;
static const uint8_t displayOn = 0xAF;

static uint8_t pageBuffer[128];

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
	uint8_t control = DataTransmit;
    uint8_t *buf[] = {&control, inBuf};
    sendBuffer(addr, buf, len + 1);
}

void initDisplay(void)
{
    sendCommand(0xAE); //display off
    sendCommand(0x20); //Set Memory Addressing Mode
    sendCommand(0x02); //00,Horizontal Addressing Mode;01,Vertical Addressing Mode;10,Page Addressing Mode (RESET);11,Invalid
	sendCommand(0xB0); //Set Page Start Address for Page Addressing Mode,0-7
    sendCommand(0xC0); //Set COM Output Scan Direction
    sendCommand(0x0F); //---Set Lower nibble Column Start Address for Page addressing mode
    sendCommand(0x13); //---Set Higher nibble Column Start Address for Page addressing mode
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
//    sendCommand(0x8D); //--set DC-DC enable
//    sendCommand(0x14);
    sendCommand(0xAF); //--turn on SSD1306 panel

	for (uint8_t i=63; i < 128; i++) {
		pageBuffer[i] = 0xFF;
	}
	sendDataBuffer(pageBuffer, 65);
}
