#include <libopencm3/stm32/rcc.h>
#include <libopencm3/cm3/nvic.h>
#include <libopencm3/cm3/systick.h>
#include "SEGGER_RTT_Conf.h"
#include "SEGGER_RTT.h"
#include "localTime.h"
#include "stdio.h"

static uint64_t time;
static char buffer[100];

void sys_tick_handler(void)
{
    ++time;
//    if ((time % 1000) == 0) {
//        SEGGER_RTT_printf(0, "Time: %d\n", time);
        sprintf(buffer, "Time: %d\n", (int)time);
        SEGGER_RTT_WriteString(0, buffer);
  //  }
}


void systickMsSetup()
{
    systick_counter_disable();
    systick_set_clocksource(STK_CSR_CLKSOURCE_AHB); //STK_CSR_CLKSOURCE_AHB
    STK_CVR = 0;
	time = 0;

    systick_set_reload(rcc_ahb_frequency / 1000);
    systick_counter_enable();
    systick_interrupt_enable();
}

void delayMs(uint32_t ms)
{
    uint64_t localTime = time;
    while ((time - localTime) < ms) {

    }
}
