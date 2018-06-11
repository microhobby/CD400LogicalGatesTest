/**
 * CD4069UBE 1 Input inverter not gate
 * Author: Matheus Castello
 * E-mail: matheus@castello.eng.br
 * Date: 10/06/2018
 **/

/*****************************************
 * Pinout configuration with outputs
 * 
 *             A -  o  - VCC 
 *     NOT A = G -     - F
 *             B -     - L = NOT F
 *     NOT B = H -     - E
 *             C -     - K = NOT E
 *     NOT C = I -     - D
 *           GND -     - J = NOT D
 * 
 *****************************************/

#include <cd400_pinout.h>

#ifndef CD4069UBE_H_
#define CD4069UBE_H_

/* read pin output state and then simulate IC */
unsigned int cd4069ube_simulate_output_pin_g (cd400_pinout* pin_data)
{
    unsigned int pinState = digitalRead(pin_data->pin_a);
    pin_data->pin_g = pinState ^ 1;
    return pin_data->pin_g;
}

unsigned int cd4069ube_simulate_output_pin_h (cd400_pinout* pin_data)
{
    unsigned int pinState = digitalRead(pin_data->pin_b);
    pin_data->pin_h = pinState ^ 1;
    return pin_data->pin_h;
}

unsigned int cd4069ube_simulate_output_pin_i (cd400_pinout* pin_data)
{
    unsigned int pinState = digitalRead(pin_data->pin_c);
    pin_data->pin_i = pinState ^ 1;
    return pin_data->pin_i;
}

unsigned int cd4069ube_simulate_output_pin_j (cd400_pinout* pin_data)
{
    unsigned int pinState = digitalRead(pin_data->pin_d);
    pin_data->pin_j = pinState ^ 1;
    return pin_data->pin_j;
}

unsigned int cd4069ube_simulate_output_pin_k (cd400_pinout* pin_data)
{
    unsigned int pinState = digitalRead(pin_data->pin_e);
    pin_data->pin_k = pinState ^ 1;
    return pin_data->pin_k;
}

unsigned int cd4069ube_simulate_output_pin_l (cd400_pinout* pin_data)
{
    unsigned int pinState = digitalRead(pin_data->pin_f);
    pin_data->pin_l = pinState ^ 1;
    return pin_data->pin_l;
}

#endif