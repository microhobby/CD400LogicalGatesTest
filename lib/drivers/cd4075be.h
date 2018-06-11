
/**
 * CD4075BE 3 Input OR Gate
 * Author: Matheus Castello
 * E-mail: matheus@castello.eng.br
 * Date: 10/06/2018
 **/

/*****************************************
 * Pinout configuration with outputs
 * 
 *             A -  o  - VCC 
 *             B -     - G
 *             D -     - H
 *             E -     - I
 *             F -     - L = G + H + I
 * D + E + F = K -     - J = A + B + C
 *           GND -     - C
 * 
 *****************************************/

#include <cd400_pinout.h>

#ifndef CD4075BE_H_
#define CD4075BE_H_

struct cd4075be_simulated_data {
    unsigned int input_1;
    unsigned int input_2;
    unsigned int input_3;
    unsigned int output;
};

cd4075be_simulated_data cd4075be_read_pin_state_simulate (unsigned int input1,
    unsigned int input2, unsigned int input3)
{
    cd4075be_simulated_data out;

    out.input_1 = digitalRead(input1);
    out.input_2 = digitalRead(input2);
    out.input_3 = digitalRead(input3);
    /* simulate the IC result */
    out.output = out.input_1 || out.input_2 || out.input_3;

    return out;
}

cd4075be_simulated_data cd4075be_simulate_output_pin_k (cd400_pinout* pin_data)
{
    cd4075be_simulated_data out = cd4075be_read_pin_state_simulate(
            pin_data->pin_d, pin_data->pin_e, pin_data->pin_f);
    pin_data->pin_k = out.output;

    return out;
}

cd4075be_simulated_data cd4075be_simulate_output_pin_j (cd400_pinout* pin_data)
{
    cd4075be_simulated_data out = cd4075be_read_pin_state_simulate(
            pin_data->pin_a, pin_data->pin_b, pin_data->pin_c);
    pin_data->pin_j = out.output;

    return out;
}

cd4075be_simulated_data cd4075be_simulate_output_pin_l (cd400_pinout* pin_data)
{
    cd4075be_simulated_data out = cd4075be_read_pin_state_simulate(
            pin_data->pin_g, pin_data->pin_h, pin_data->pin_i);
    pin_data->pin_l = out.output;

    return out;
}

#endif