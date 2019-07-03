/*
 * I2c.h
 *
 *  Created on: Jul 3, 2019
 *      Author: Arsenii Soitu
 */

#ifndef SRC_I2C_H_
#define SRC_I2C_H_

#include <libopencm3/stm32/i2c.h>

typedef struct {
	uint32_t periph;

	bool (*sendByte)(uint8_t addr, uint8_t data);
	bool (*sendBuffer)(uint8_t addr, void *buf, uint8_t len);
	bool (*transferData)(uint8_t addr, void *inBuf, uint8_t inLen, void *outBuf, uint8_t outLen);
}I2c;

typedef enum {
	I2c_CLK_FREQ_8_MHz,
	I2c_CLK_FREQ_16_MHz,
	I2c_CLK_FREQ_48_MHz
}I2cClkFrequency;

typedef enum {
	I2c_DATA_FREQ_10_kHz,
	I2c_DATA_FREQ_100_kHz,
	I2c_DATA_FREQ_400_kHz,
	I2c_DATA_FREQ_500_kHz,
	I2c_DATA_FREQ_1000_kHz
}I2cFrequency;

void i2cInit(I2c *aI2c, uint32_t periphNum, I2cClkFrequency ckFreq, I2cFrequency dataFreq);
bool sendByte(uint8_t addr, uint8_t data);
bool sendBuffer(uint8_t addr, void *buf, uint8_t len);
bool transferData(uint8_t addr, void *inBuf, uint8_t inLen, void *outBuf, uint8_t outLen);

#endif /* SRC_I2C_H_ */
