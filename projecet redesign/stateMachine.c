
#include "stateMachine.h"
#include "leds.h"
#include "sound.h"

ToyState current_state = STATE1;  // Initialize with STATE1

void transition_to_state1() {
    current_state = STATE1;
    set_LED_dim();
    play_sound1();
}

void transition_to_state2() {
    current_state = STATE2;
    set_LED_medium();
    play_sound2();
}

void transition_to_state3() {
    current_state = STATE3;
    set_LED_bright();
    play_sound3();
}

void transition_to_state4() {
    current_state = STATE4;
    set_LED_very_bright();
    play_sound4();
}
