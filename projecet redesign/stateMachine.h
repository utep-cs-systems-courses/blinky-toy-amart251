
#ifndef stateMachine_included
#define stateMachine_included

typedef enum {
    STATE1,
    STATE2,
    STATE3,
    STATE4
} ToyState;

extern ToyState current_state;

void transition_to_state1();
void transition_to_state2();
void transition_to_state3();
void transition_to_state4();

#endif // included
