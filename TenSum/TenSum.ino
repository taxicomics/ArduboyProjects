#include <Arduboy2.h>
#include <ArduboyTones.h>
Arduboy2 arduboy;
ArduboyTones sound(arduboy.audio.enabled);
BeepPin1 beep;
const uint16_t score_sfx[] PROGMEM = {
  NOTE_F4H, 29,  NOTE_REST, 2,  NOTE_D4H, 34,  NOTE_REST, 2,
  NOTE_D4H, 36,  NOTE_REST, 2,  NOTE_F4H, 32,
  TONES_END
};
const uint16_t start_sfx[] PROGMEM = {
  NOTE_E4H, 22,  NOTE_REST, 2,  NOTE_E4H, 25,
  TONES_END
};

#include "SETTINGS.h"
#include "image.h"
#include "helpers.h"
//basic vars
uint8_t state=0;
uint8_t round_timer=12;
uint8_t round_timer_tick_cd=12;
uint8_t player_x=0;
uint8_t player_y=0;
uint8_t player_x2=1;
uint8_t player_y2=1;
boolean player_set=false;
uint8_t player_cursor_score=0;
uint8_t cursor_x=0;
uint8_t cursor_y=0;
int8_t score=0;
int8_t highscore=0;
uint8_t blink_counter=0;


int field[13][5];

#include "game_over.h"
#include "game.h"
#include "menu.h"

void setup() {
  arduboy.begin();
  arduboy.setFrameRate(FRAMERATE);
  arduboy.audio.on();
  EEPROM.get(eeAddress, highscore);
}

void loop() {
  if (!arduboy.nextFrame()) return;
  blink_counter=(blink_counter+1)%255;
  arduboy.pollButtons();
  arduboy.clear();

 switch(state){
    case 0:
      drawMainMenu();
      updateMainMenu();
      break;
    case 1:
      drawGame();
      updateGame();
      break;
    case 2:
      drawGameOver();
      updateGameOver();
      break;
 }

  arduboy.display();
}


