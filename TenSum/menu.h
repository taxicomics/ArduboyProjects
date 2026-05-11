//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// MAIN MENU
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
void drawMainMenu() {
  //draw main here
  //rect(1,1,126,62);
  //printm("TenSum",20);
  //printm("press A to play",30);
  Sprites::drawOverwrite(0, 0, MenuScreen,0);
  if((highscore>0)&&(blink_counter>128)){
      printm("Highscore:",10);
      arduboy.setCursor(55,20);
      arduboy.print(highscore);
    }
  else{
     Sprites::drawOverwrite(14, 10, title_spr,0);
  }
  
  if (blink_counter%100>50){
    Sprites::drawOverwrite(113,51,A_button_spr,0);
  }
}

void updateMainMenu() {
  if (arduboy.pressed(A_BUTTON)){
      initGame();
  }
}