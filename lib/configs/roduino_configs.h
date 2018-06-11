/**
 * put code for initialize Roduino here
 **/

#include <Arduino.h>
#include <cd400_pinout.h>

#ifndef RODUINO_CONFIG_H_
#define RODUINO_CONFIG_H_

#ifdef CONFIG_RODUINO

cd400_pinout cd4069_pinout_data;
cd400_pinout cd4075_pinout_data;
cd400_pinout cd4081_pinout_data;

extern void board_config ()
{
    /* for use with cd407be 3 in or gate */
    cd4075_pinout_data.pin_g = CONFIG_INPUT_PINC;
    cd4075_pinout_data.pin_h = CONFIG_INPUT_PINB;
    cd4075_pinout_data.pin_i = CONFIG_INPUT_PINA;

    /* for use with cd4069 1 in not gate  */
    cd4069_pinout_data.pin_c = CONFIG_INPUT_PINC;

    /* for use with cd4081be 2 in and gate */
    cd4081_pinout_data.pin_a = CONFIG_INPUT_PINC;
    cd4081_pinout_data.pin_b = CONFIG_INPUT_PINB;
}

#endif

#endif