
#include "buttons.h"
#include "leds.h"
#include "sound.h"
#include "stateMachine.h"

int main() {
    // Initializations
    init_buttons();
    init_leds();
    init_speaker();
    
    // Main loop
    while (1) {
        if (button_P2_0_pressed()) {
            transition_to_state1();
        } else if (button_P2_1_pressed()) {
            transition_to_state2();
        } else if (button_P2_2_pressed()) {
            transition_to_state3();
        } else if (button_P2_3_pressed()) {
            transition_to_state4();
        }
    }
    
    return 0;
}
