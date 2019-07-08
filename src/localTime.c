#include <libopencm3/stm32/rcc.h>
#include <libopencm3/cm3/nvic.h>
#include <libopencm3/cm3/systick.h>
#include "localTime.h"

static uint64_t time;

void sys_tick_handler(void)
{
    ++time;
}


void systickMsSetup()
{
    systick_counter_disable();
    systick_set_clocksource(STK_CSR_CLKSOURCE_AHB_DIV_8); //STK_CSR_CLKSOURCE_AHB
    STK_CVR = 0;
	time = 0;

    systick_set_reload(rcc_ahb_frequency / 8 / 1000);
    systick_counter_enable();
    systick_interrupt_enable();
}

void delayMs(uint32_t ms)
{
    uint64_t localTime = time;
    while ((time - localTime) < ms) {

    }
}
