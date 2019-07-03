#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/i2c.h>

void rccSetup(void);
void gpioSetup(void);

int main()
{
    rccSetup();
    gpioSetup();

    while (1);
}

void rccSetup(void)
{
    rcc_clock_setup_in_hse_8mhz_out_48mhz();
    rcc_periph_clock_enable(RCC_I2C1);
}

void gpioSetup()
{
    rcc_periph_clock_enable(RCC_GPIOB);
    gpio_mode_setup(GPIOB, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO6);
    gpio_mode_setup(GPIOB, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO7);
}

