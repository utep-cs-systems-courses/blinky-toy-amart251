#ifndef ADJUST_PWM
#define ADJUST_PWM

void increaseRed(void);    // increases duty cycle of red LED by 10%
void increaseGreen(void);  // increases duty cycle of green LED by 10%
void decreaseRed(void);    // decreases duty cycle of red LED by 10%
void decreaseGreen(void);  // increases duty cycle of green LED by 10%
void buzzerMax(void);      // sets buzzer duty cycle to 100%
void buzzerIncrease(void); // increases buzzer duty cycle by 10%
void buzzerZero(void);     // sets buzzer duty cycle to 0%
void buzzerDecrease(void); // decreases buzzer duty cycle by 10%

#endif
