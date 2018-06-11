#define CONFIG_SERIAL_BAUD_RATE             9600

/* these has input for gates IC but output from atmega328 */
#define CONFIG_INPUT_PINA                   11
#define CONFIG_INPUT_PINB                   12
#define CONFIG_INPUT_PINC                   13

/* configs chars from menu input */
#define CONFIG_KEY_1                        '1'
#define CONFIG_KEY_2                        '2'
#define CONFIG_KEY_3                        '3'

#ifdef CONFIG_PORTUGUES
    #define CONFIG_OUTPUT_TEXT                  "MUDA PARA"
#else
    #define CONFIG_OUTPUT_TEXT                  "TOGGLE TO"
#endif