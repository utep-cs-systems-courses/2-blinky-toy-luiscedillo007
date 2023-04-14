#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "state_machine.h"
#include "libTimer.h"
#include "buzzer.h"

void main() 
{
    configureClocks();
    switch_init();
    buzzer_init();
    led_init();
    state_init();

    enableWDTInterrupts();
    or_sr(0x18);
}
