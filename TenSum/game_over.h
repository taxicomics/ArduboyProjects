//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// GAME OVER
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
void initGameOver() {
  state=2;
  if(score>highscore){
    highscore=score;
  }
  EEPROM.put(eeAddress, highscore);
}

void drawGameOver() {
  //draw gameover here
  Sprites::drawOverwrite(1,1, GameOverScreen, 0);
    if (blink_counter>50){
    Sprites::drawOverwrite(113,51,B_button_spr,0);
  }
  printm("Your Score was:",35);
  arduboy.setCursor(64,45);
  arduboy.print(score);
  //  printm("press B to go back",55);
}

void updateGameOver(){
  if(arduboy.pressed(B_BUTTON)){
    state=0;
    score=0;
  }
}