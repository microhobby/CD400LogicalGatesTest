
/**
 * Common struct to record pin out configuration from CD400 CI series
 * Author: Matheus Castello
 * E-mail: matheus@castello.eng.br
 * Date: 10/06/2018
 **/

#ifndef CD400_PINOUT_H_
#define CD400_PINOUT_H_

/* DIP 14 */
struct cd400_pinout {
    unsigned int pin_a;
    unsigned int pin_b;
    unsigned int pin_c;
    unsigned int pin_d;
    unsigned int pin_e;
    unsigned int pin_f;
    unsigned int pin_g;
    unsigned int pin_h;
    unsigned int pin_i;
    unsigned int pin_j;
    unsigned int pin_k;
    unsigned int pin_l;
};

#endif