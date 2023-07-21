#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"


// SONGS

// Scarborough fair   1/2 note                  1/4 note
int song1 [14] = {6810, 6810, 6810, 6810, 0, 6810, 6810, 0, 0, 4545, 0, 4545, 4545, 6067};

// BTS - DNA
int song2 [52] = {3607, 0, 4049, 0, 0, 0, 3607, 0, 0, 0, 0, 0, 2407, 0, 2272, 0, 2024, 2272, 2407, 0, 0, 0, 0, 0, 0, 3607, 0, 4049, 0,0,0, 3607, 0,0,0,0,0, 2407, 0, 2272, 0, 2024, 0, 2272, 0};

// middle C scale up
int song3 [9] = {7644, 0, 6810, 0, 6067, 0, 5726, 0, 5102};


void song_advance();


void state_advance()
{
  if (sw_state) {
    song_advance();
   
  }
  led_update();
}

char prev_state = 0;
int i = 0;
void song_advance()	       
{
  if (prev_state != sw_state) i = 0;

  prev_state = sw_state;
  
  switch (sw_state) {

  case 1:
    if (i >= sizeof(song1))  i = 0;
    buzzer_set_period(song1[i]);
    i++;
    break;

  case 2:
    if (i >= sizeof(song2))  i = 0;
    buzzer_set_period(song2[i]);
    i++;
    break;
  case 3:
    if (i >= sizeof(song3))  i = 0;
    buzzer_set_period(song3[i]);
    i++;
    break;

  case 4:
    buzzer_turn_off();
    break;

  default:
    sw_state = 1;
    break;
  }
}

