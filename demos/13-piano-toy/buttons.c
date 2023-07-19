
#include "buttons.h"

void init_buttons() {
    // Set buttons as input
    P2DIR &= ~(BIT0 | BIT1 | BIT2 | BIT3);
    // Enable pull-up resistors
    P2REN |= (BIT0 | BIT1 | BIT2 | BIT3);
    P2OUT |= (BIT0 | BIT1 | BIT2 | BIT3);
}

int button_P2_0_pressed() {
    return !(P2IN & BIT0);  // Return 1 if pressed
}

int button_P2_1_pressed() {
    return !(P2IN & BIT1);  // Return 1 if pressed
}

int button_P2_2_pressed() {
    return !(P2IN & BIT2);  // Return 1 if pressed
}

int button_P2_3_pressed() {
    return !(P2IN & BIT3);  // Return 1 if pressed
}
