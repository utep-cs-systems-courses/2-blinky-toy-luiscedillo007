#include <msp430.h>
#include "led.h"

void led_init() 
{
    P1DIR |= LEDS;                          // bits attached to leds are output
    P1OUT &= ~LEDS;                         /* leds initially off */
}

void led_update(unsigned char led_val) 
{
    P1OUT &= (0xff^LEDS) | led_val;        // clear bit for off leds
    P1OUT |= led_val;                      // set bit for on leds 
} 
