#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/i2c.h>
#include "I2c.h"
#include "ssd1306.h"
#include "localTime.h"

void rccSetup(void);
void gpioSetup(void);

int main()
{
	I2c i2cPeriph;
    rccSetup();
    systickSetup();
    gpioSetup();
    i2cInit(&i2cPeriph, I2C1, I2c_CLK_FREQ_48_MHz, I2c_DATA_FREQ_400_kHz);
    initDisplay();

    while (1) {
    }
}

void rccSetup(void)
{
    rcc_clock_setup_in_hse_8mhz_out_48mhz();
    RCC_CFGR3 |= RCC_CFGR3_I2C1SW;
    rcc_periph_clock_enable(RCC_I2C1);
}

void gpioSetup()
{
    rcc_periph_clock_enable(RCC_GPIOB);
    gpio_mode_setup(GPIOB, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO6);
    gpio_set_output_options(GPIOB, GPIO_OTYPE_OD, GPIO_OSPEED_50MHZ, GPIO6); //SCL
    gpio_set_af(GPIOB, GPIO_AF1, GPIO6);
    gpio_mode_setup(GPIOB, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO7);
    gpio_set_output_options(GPIOB, GPIO_OTYPE_OD, GPIO_OSPEED_50MHZ, GPIO7); //SDA
    gpio_set_af(GPIOB, GPIO_AF1, GPIO7);
}

