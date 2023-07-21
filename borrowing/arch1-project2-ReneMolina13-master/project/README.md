### Lab 2 - MSP430 Toy ###

The project consists of turning the MSP430 into a toy that uses its 2 LEDs, 4
buttons, and buzzer to make noise and make lights. At startup, both the red
and green LEDs are set to 50% duty cycle, as is the buzzer. The big picture
operation is as follows:

- Button 0 pressed: Red LED increases duty cycle by 10%, Buzzer set to maximum
duty cycle
- Button 1 pressed: Green LED increases duty cycle by 10%, Buzzer increases
duty cycle by 10%
- Button 2 pressed: Red LED decreases duty cycle by 10%, Buzzer decreases duty
cycle by 10%
- Button 3 pressed: Green LED decreases duty cycle by 10%, Buzzer set to
minimum duty cycle

###### The project is broken up into a handful of files described below: ######

- led.h: Contains macros for which bits belong to which LEDs, buttons, and
  buzzer
  
- initToy.h/initToy.c: Contains functions for initializing the peripherals
  used for the toy. Specifically the Clock System, LEDs/WDT, Input Buttons,
  and Buzzer/Timer A
  - Note that the PWM for both the LEDs and Buzzer are in Reset/Set mode: the
  output is high until the duty cycle is reached, where it drops to low until
  the next PWM period
  - Note that the PWM period for the LED is 1/3 ms while the PWM period for
  the buzzer is 1 1/3 ms
      - To accomodate this for the LEDs, the WDT is set for 32,000 interrupts/sec
  rather than the typical 250 (makes it so 10 interrupts is roughly 1/3 ms)
  
- adjustPWM.h/adjustPWM.c: Contains functions for adjusting the LED and Buzzer
  PWM duty cycles for the 8 ways described above in the section about the
  buttons
  
- toyCtrl.h/toyCtrl.c: Contains macros and variables regarding the PWM period
  and duty cycle for both LEDs and the buzzer. Also contains Watchdog Timer
  count variables that keep track of where we are in the PWM period. Finally,
  it contains functions that determine which PWM adjustment function to call
  in the adjustPWM file. The adjustBuzzer function is implemented in 2
  seperate files: buzzerAdjust-c.c and buzzerAdjust-s.s
  
- main.c: Contains the main function, the Port 2 and Watchdog Timer interrupt
  vectors, and the Port 2 interrupt handler.
  - The main function does nothing except initialize the peripherals then put
  the processor to sleep.
  - The Port 2 interrupt vector determines if the Port 2 interrupt was from
  one of the 4 buttons and if so, call the Port 2 interrupt handler.This function
  determines which button was pressed then call the appropriate functions in
  the toyCtrl files.
  - The Watchdog Timer interrupt vector controls the PWM for the LEDs. Since
  10 WDT interrupts equal roughly the LED PWM period of 1/3 ms, the duty cycle
  can easily be broken down to an integer betwen 0 and 10 with each integer
  representing 10% duty cycle. As noted above, the PWM is handled in reset/set
  mode

- buzzerAdjust-c.c/buzzerAdjust-s.s: Contains a switch statement determining
  which of the 4 functions adjusting the buzzer duty cycle get called. This
  function is implemented in both c and assembly
  
