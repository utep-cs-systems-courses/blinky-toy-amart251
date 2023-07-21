#ifndef TOY_CTRL
#define TOY_CTRL

// Controls which functions get called in adjustPWM file
#define RED_INCREASE 0
#define GREEN_INCREASE 1
#define RED_DECREASE 2
#define GREEN_DECREASE 3
#define BUZZER_MAX 0
#define BUZZER_INCREASE 1
#define BUZZER_DECREASE 2
#define BUZZER_ZERO 3

// PWM period constants
#define LED_PWM_PERIOD 10 // 10 WDT interrupts = PWM period of 40 ms
#define BUZZER_PWM_PERIOD 1000 // 1000 clock cycles = PWM period of 0.5 ms

volatile int dutyCycleRed;       // holds duty cycle of the red LED as an integer (0-10)
volatile int dutyCycleGreen;     // holds duty cycle of the green LED as an integer (0-10)
volatile double dutyCycleBuzzer; // holds duty cycle of the buzzer in decimal (0-1)
volatile int wdtCountRed;        // holds current count of WDT interrupts for red LED
volatile int wdtCountGreen;      // holds current count of WDT interrupts for green LED
volatile int currentInterrupt;   // holds current port 2 interrupt (buttons are bits 0-3)

void adjustRed(int direction);    // determines if red LED duty cycle gets increased or decreased
void adjustGreen(int direction);  // determines if green LED duty cycle gets increased or decreased
void adjustBuzzer(int direction); // determines how the buzzer duty cycle gets adjusted

#endif
