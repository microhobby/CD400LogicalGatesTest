#include <Arduino.h>
#include <gates_test_defconfig.h>
#include <board_configs.h>
#include <cd4069ube.h>
#include <cd4075be.h>
#include <cd4081be.h>

/* Global vars */
unsigned int pin_a_state = LOW;
unsigned int pin_b_state = LOW;
unsigned int pin_c_state = LOW;
char menu1[50];
char menu2[50];
char menu3[50];
char menu4[50];

void setup()
{
    Serial.begin( CONFIG_SERIAL_BAUD_RATE );

    /* drivers board configs */
    board_config();

    /* pin config */
    pinMode(CONFIG_INPUT_PINA, OUTPUT);
    pinMode(CONFIG_INPUT_PINB, OUTPUT);
    pinMode(CONFIG_INPUT_PINC, OUTPUT);
}

void displayCILogic() 
{
    /* do the logic */
    cd4069ube_simulate_output_pin_i(&cd4069_pinout_data);
    cd4081be_simulate_output_pin_i(&cd4081_pinout_data);
    cd4075be_simulate_output_pin_l(&cd4075_pinout_data);

    /* mount ouput reutilizing menu buffers */
    sprintf(menu1, "CD4069UBE : NOT %d = %d\n", 
        cd4069_pinout_data.pin_c, cd4069_pinout_data.pin_i);
    sprintf(menu2, "CD4081BE : %d AND %d = %d\n", 
        cd4081_pinout_data.pin_a, cd4081_pinout_data.pin_b, 
            cd4081_pinout_data.pin_i);
    sprintf(menu3, "CD4075BE : %d OR %d OR %d = %d\n", 
        cd4075_pinout_data.pin_g, cd4075_pinout_data.pin_h, 
            cd4075_pinout_data.pin_i, cd4075_pinout_data.pin_l);

    /* set to serial output */
    Serial.println( "-----------------------------" );
    Serial.print( menu1 );
    Serial.print( menu2 );
    Serial.print( menu3 );
    Serial.println( "-----------------------------" );
}

void displayMenu()
{
    /* check states */
    sprintf(menu1, "1) PIN:%d %s %d\n", 
        CONFIG_INPUT_PINA, CONFIG_OUTPUT_TEXT, (pin_a_state ^ 1));
    sprintf(menu2, "2) PIN:%d %s %d\n", 
        CONFIG_INPUT_PINB, CONFIG_OUTPUT_TEXT, (pin_b_state ^ 1));
    sprintf(menu3, "3) PIN:%d %s %d\n", 
        CONFIG_INPUT_PINC, CONFIG_OUTPUT_TEXT, (pin_c_state ^ 1));
        
    /* draw a menu on the serial port */
    Serial.println( "SIMULATE ICs" );
    Serial.println( "-----------------------------" );
    Serial.println( "MENU:" );
    Serial.print( menu1 );
    Serial.print( menu2 );
    Serial.print( menu3 );
    Serial.println( "-----------------------------" );
    Serial.print( "?" );
}

byte checkKeyboardInput() 
{
    byte ret;

    while( !Serial.available() );
    ret = Serial.read();
    Serial.flush();
    Serial.println( (char)ret );

    return ret;
}

void loop() 
{
    byte choice;
    boolean isValidInput;
    displayCILogic();
    displayMenu();

    do {
        choice = checkKeyboardInput();

        switch (choice) {
            case CONFIG_KEY_1:
                pin_a_state ^= 1;
                digitalWrite(CONFIG_INPUT_PINA, pin_a_state);
                break;
            case CONFIG_KEY_2:
                pin_b_state ^= 1;
                digitalWrite(CONFIG_INPUT_PINB, pin_b_state);
                break;
            case CONFIG_KEY_3:
                pin_c_state ^= 1;
                digitalWrite(CONFIG_INPUT_PINC, pin_c_state);
                break;
            default:
                isValidInput = false;
                break;
        }

    } while(isValidInput);

}