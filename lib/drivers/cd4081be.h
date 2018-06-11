
/**
 * CD4081BE 2 Input AND Gate
 * Author: Matheus Castello
 * E-mail: matheus@castello.eng.br
 * Date: 10/06/2018
 **/

/*****************************************
 * Pinout configuration with outputs
 * 
 *             A -  o  - VCC 
 *             B -     - H
 *     A . B = I -     - G
 *     C . D = J -     - L = G . H
 *             C -     - K = E . F
 *             D -     - F
 *           GND -     - E
 * 
 *****************************************/

#ifndef CD4081BE_H_
#define CD4081BE_H_

struct cd4081be_simulated_data {
    unsigned int input_1;
    unsigned int input_2;
    unsigned int output;
};

cd4081be_simulated_data cd4081be_read_pin_state_simulate (unsigned int input1,
    unsigned int input2)
{
    cd4081be_simulated_data out;

    out.input_1 = digitalRead(input1);
    out.input_2 = digitalRead(input2);
    /* simulate the IC result */
    out.output = out.input_1 && out.input_2;

    return out;
}

cd4081be_simulated_data cd4081be_simulate_output_pin_i (cd400_pinout* pin_data)
{
    cd4081be_simulated_data out = cd4081be_read_pin_state_simulate(
            pin_data->pin_a, pin_data->pin_b);
    pin_data->pin_i = out.output;

    return out;
}

#endif