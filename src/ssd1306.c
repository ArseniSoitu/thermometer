#include "ssd1306.h"
#include "I2c.h"

uint8_t addr = 0x3C;
//uint8_t addr = 0x3D;

uint8_t CommandTransmit = 0x80;
uint8_t DataTransmit = 0x40;

uint8_t followRamContent = 0xA4;
uint8_t ignoreRamContent = 0xA5;

uint8_t normalDisplay = 0xA6;
uint8_t inverseDisplay = 0xA7;

uint8_t displayOff = 0xAE;
uint8_t displayOn = 0xAF;

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
