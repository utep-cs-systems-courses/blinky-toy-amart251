#ifndef INIT_TOY
#define INIT_TOY

void initToy(void);     // initialize the toy
void initClocks(void);  // initialize the msp430 clock system
void initLEDs(void);    // initialize LEDs and WDT for PWM
void initButtons(void); // initialize buttons for input
void initBuzzer(void);  // initialize buzzer and Timer A for PWM

#endif
