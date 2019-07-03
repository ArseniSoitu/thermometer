#include "I2c.h"

I2c *I2cMaster;

static void setI2c8MHzDataFreq(I2cFrequency dataFreq);
static void setI2c16MHzDataFreq(I2cFrequency dataFreq);
static void setI2c48MHzDataFreq(I2cFrequency dataFreq);

void i2cInit(I2c *aI2c, uint32_t periphNum, I2cClkFrequency ckFreq, I2cFrequency dataFreq)
{
	I2cMaster = aI2c;
	aI2c->periph = periphNum;
	aI2c->sendByte = sendByte;
	aI2c->sendBuffer = sendBuffer;
	aI2c->transferData = transferData;

	i2c_peripheral_disable(I2cMaster->periph);

	i2c_set_7bit_addr_mode(I2cMaster->periph);
	i2c_enable_analog_filter(I2cMaster->periph);
	switch (ckFreq) {
		case I2c_CLK_FREQ_8_MHz:
			setI2c8MHzDataFreq(dataFreq);
			break;
		case I2c_CLK_FREQ_16_MHz:
			setI2c16MHzDataFreq(dataFreq);
			break;
		case I2c_CLK_FREQ_48_MHz:
			setI2c48MHzDataFreq(dataFreq);
			break;
		default:
			while (1);
	}
	i2c_peripheral_enable(I2cMaster->periph);
}

bool sendByte(uint8_t addr, uint8_t data)
{
	i2c_transfer7(I2cMaster->periph, addr, &data, 1, NULL, 0);

	return true;
}

bool sendBuffer(uint8_t addr, void *buf, uint8_t len)
{
	i2c_transfer7(I2cMaster->periph, addr, buf, len, NULL, 0);

	return true;
}

bool transferData(uint8_t addr, void *inBuf, uint8_t inLen, void *outBuf, uint8_t outLen)
{
	i2c_transfer7(I2cMaster->periph, addr, inBuf, inLen, outBuf, outLen);

	return true;
}

static void setI2c8MHzDataFreq(I2cFrequency dataFreq)
{
	switch (dataFreq) {
		case I2c_DATA_FREQ_10_kHz:
			i2c_set_prescaler(I2cMaster->periph, 1);
			i2c_set_scl_low_period(I2cMaster->periph, 0xC7);
			i2c_set_scl_high_period(I2cMaster->periph, 0xC3);
			i2c_set_data_hold_time(I2cMaster->periph, 0x02);
			i2c_set_data_setup_time(I2cMaster->periph, 0x04);
			break;
		case I2c_DATA_FREQ_100_kHz:
			i2c_set_prescaler(I2cMaster->periph, 1);
			i2c_set_scl_low_period(I2cMaster->periph, 0x13);
			i2c_set_scl_high_period(I2cMaster->periph, 0x0F);
			i2c_set_data_hold_time(I2cMaster->periph, 0x02);
			i2c_set_data_setup_time(I2cMaster->periph, 0x04);
			break;
		case I2c_DATA_FREQ_400_kHz:
			i2c_set_prescaler(I2cMaster->periph, 0);
			i2c_set_scl_low_period(I2cMaster->periph, 0x09);
			i2c_set_scl_high_period(I2cMaster->periph, 0x03);
			i2c_set_data_hold_time(I2cMaster->periph, 0x01);
			i2c_set_data_setup_time(I2cMaster->periph, 0x03);
			break;
		case I2c_DATA_FREQ_500_kHz:
			i2c_set_prescaler(I2cMaster->periph, 0);
			i2c_set_scl_low_period(I2cMaster->periph, 0x06);
			i2c_set_scl_high_period(I2cMaster->periph, 0x03);
			i2c_set_data_hold_time(I2cMaster->periph, 0x00);
			i2c_set_data_setup_time(I2cMaster->periph, 0x01);
			break;
		default:
			while(1);
	}
}

static void setI2c16MHzDataFreq(I2cFrequency dataFreq)
{
	switch (dataFreq) {
		case I2c_DATA_FREQ_10_kHz:
			i2c_set_prescaler(I2cMaster->periph, 3);
			i2c_set_scl_low_period(I2cMaster->periph, 0xC7);
			i2c_set_scl_high_period(I2cMaster->periph, 0xC3);
			i2c_set_data_hold_time(I2cMaster->periph, 0x02);
			i2c_set_data_setup_time(I2cMaster->periph, 0x04);
			break;
		case I2c_DATA_FREQ_100_kHz:
			i2c_set_prescaler(I2cMaster->periph, 3);
			i2c_set_scl_low_period(I2cMaster->periph, 0x13);
			i2c_set_scl_high_period(I2cMaster->periph, 0x0F);
			i2c_set_data_hold_time(I2cMaster->periph, 0x02);
			i2c_set_data_setup_time(I2cMaster->periph, 0x04);
			break;
		case I2c_DATA_FREQ_400_kHz:
			i2c_set_prescaler(I2cMaster->periph, 1);
			i2c_set_scl_low_period(I2cMaster->periph, 0x09);
			i2c_set_scl_high_period(I2cMaster->periph, 0x03);
			i2c_set_data_hold_time(I2cMaster->periph, 0x02);
			i2c_set_data_setup_time(I2cMaster->periph, 0x03);
			break;
		case I2c_DATA_FREQ_1000_kHz:
			i2c_set_prescaler(I2cMaster->periph, 0);
			i2c_set_scl_low_period(I2cMaster->periph, 0x04);
			i2c_set_scl_high_period(I2cMaster->periph, 0x02);
			i2c_set_data_hold_time(I2cMaster->periph, 0x00);
			i2c_set_data_setup_time(I2cMaster->periph, 0x02);
			break;
		default:
			while(1);
	}
}

static void setI2c48MHzDataFreq(I2cFrequency dataFreq)
{
	switch (dataFreq) {
		case I2c_DATA_FREQ_10_kHz:
			i2c_set_prescaler(I2cMaster->periph, 11);
			i2c_set_scl_low_period(I2cMaster->periph, 0xC7);
			i2c_set_scl_high_period(I2cMaster->periph, 0xC3);
			i2c_set_data_hold_time(I2cMaster->periph, 0x02);
			i2c_set_data_setup_time(I2cMaster->periph, 0x04);
			break;
		case I2c_DATA_FREQ_100_kHz:
			i2c_set_prescaler(I2cMaster->periph, 11);
			i2c_set_scl_low_period(I2cMaster->periph, 0x13);
			i2c_set_scl_high_period(I2cMaster->periph, 0x0F);
			i2c_set_data_hold_time(I2cMaster->periph, 0x02);
			i2c_set_data_setup_time(I2cMaster->periph, 0x04);
			break;
		case I2c_DATA_FREQ_400_kHz:
			i2c_set_prescaler(I2cMaster->periph, 5);
			i2c_set_scl_low_period(I2cMaster->periph, 0x09);
			i2c_set_scl_high_period(I2cMaster->periph, 0x03);
			i2c_set_data_hold_time(I2cMaster->periph, 0x03);
			i2c_set_data_setup_time(I2cMaster->periph, 0x03);
			break;
		case I2c_DATA_FREQ_1000_kHz:
			i2c_set_prescaler(I2cMaster->periph, 5);
			i2c_set_scl_low_period(I2cMaster->periph, 0x03);
			i2c_set_scl_high_period(I2cMaster->periph, 0x01);
			i2c_set_data_hold_time(I2cMaster->periph, 0x00);
			i2c_set_data_setup_time(I2cMaster->periph, 0x01);
			break;
		default:
			while(1);
	}
}
