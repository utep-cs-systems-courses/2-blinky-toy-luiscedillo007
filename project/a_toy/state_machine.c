#include <msp430.h>
#include "state_machine.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

void state_init() 
{
    led_update(0);
}

unsigned char get_state()
{
    if (switch_state_down & SW1)     // bit corresponding to switch -> switch is pressed
    {
        return 1;
    } 
    else if (switch_state_down & SW2) 
    {
        return 2;
    } 
    else if (switch_state_down & SW3) 
    {
        return 3;
    } 
    else if (switch_state_down & SW4) 
    {
        return 4;
    }
}

void state() 
{
    unsigned char this_state = get_state();
    unsigned char led_val = 0;

    switch (this_state) 
    {
        case 1:
            led_val = LED_RED;
            break;
        case 2:
            led_val = LED_GREEN;
            break;
        case 3:
            led_val = LED_RED | LED_GREEN;
            break;
        case 4:
            led_val = 0;
            buzzer_set_period(2000);
            break;
    }

    led_update(led_val);
}
