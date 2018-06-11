/**
 * put code for initialize Arduino UNO here
 **/

#include <Arduino.h>
#include <cd400_pinout.h>

#ifndef UNO_CONFIG_H_
#define UNO_CONFIG_H_

#ifdef CONFIG_UNO

cd400_pinout cd400_pinout_data;

extern void board_config ()
{
    /* for use with cd407be 3 in or gate */
    cd400_pinout_data.pin_g = 13;
    cd400_pinout_data.pin_h = 12;
    cd400_pinout_data.pin_i = 11;

    /* for use with cd4069 1 in not gate  */
    cd400_pinout_data.pin_c = 13;

    /* for use with cd4081be 2 in and gate */
    cd400_pinout_data.pin_a = 13;
    cd400_pinout_data.pin_b = 12;
}

#endif

#endif