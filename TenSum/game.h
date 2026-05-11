void init_field(){
  //field is 13x5
  for (uint8_t x=0;x<13;x++){
    for (uint8_t y=0;y<5;y++){
      field[x][y]=random(1,10);
    }
  }
}

int8_t draw_field(uint8_t x_pos,uint8_t y_pos){
  Sprites::drawOverwrite(x_pos-5, y_pos, border, 0);
  Sprites::drawOverwrite(x_pos+105, y_pos, broder, 0);
  int8_t sum_of_cells=0;
  boolean take_this=false;
  int8_t x1=min(player_x,player_x2);
  int8_t x2=max(player_x,player_x2);
  int8_t y1=min(player_y,player_y2);
  int8_t y2=max(player_y,player_y2);
  if ((arduboy.justReleased(A_BUTTON))&&(player_cursor_score==10)){
    take_this=true;
    score+=(abs(x2-x1)+1)*(abs(y2-y1)+1);
    sound.tones(score_sfx);
  }
  for (uint8_t x=0;x<13;x++){
    for (uint8_t y=0;y<5;y++){
      rect(x_pos+x*8,y_pos+y*10,9,11);
      if (field[x][y]!=0){
        arduboy.setCursor(x_pos+x*8+2,y_pos+y*10+2);
        arduboy.print(field[x][y]);
      }
      if ((x>=x1) && (x<=x2) && (y>=y1) && (y<=y2) ){
        sum_of_cells+=field[x][y];
        if(take_this){
          field[x][y]=0;
        }
      }
    }
  }
  if ((round_timer_tick_cd%20>10)){
    rectfill(x_pos+cursor_x*8,y_pos+cursor_y*10,9,11);
  }
  if (player_set){
    rect(x_pos+x1*8+1,y_pos+y1*10+1,(x2-x1)*8+7,(y2-y1)*10+9);
  }
  return sum_of_cells;
}


//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// GAME
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
void initGame() {
  state=1;
  arduboy.initRandomSeed();
  init_field();
  round_timer=122;
  round_timer_tick_cd=ROUND_TIMER_TICK_SPEED;
}

void drawGame() {
  //draw game here
  player_cursor_score=draw_field(11,2);
  //draw player rect
  //display round time
  rect(1,55,126,6);
  rectfill(3,57,round_timer,2);
  arduboy.setCursor(62,55);
  arduboy.print(score);
  
  //printm(text,55);
}

void updateGame(){
  //Game logic here
  //round timer
  round_timer_tick_cd-=1;
  if (round_timer_tick_cd==0){
    round_timer-=1;
    round_timer_tick_cd=ROUND_TIMER_TICK_SPEED;
  }
  if(round_timer==0){
    initGameOver();
  }
  //controls
  if (arduboy.justPressed(A_BUTTON)){
    if (player_set==false){
      player_set=true;
      sound.tones(start_sfx);
      player_x=cursor_x;
      player_y=cursor_y;
    }
  }
  if (arduboy.pressed(A_BUTTON)){
      player_x2=cursor_x;
      player_y2=cursor_y;
  }
  if (arduboy.justReleased(A_BUTTON)){
    if (player_set==true){
      player_set=false;
    }
  }
  if((arduboy.justPressed(RIGHT_BUTTON))&&(cursor_x<12)){
      cursor_x+=1;
  }
  if((arduboy.justPressed(LEFT_BUTTON))&&(cursor_x>0)){
      cursor_x-=1;
  }
    if((arduboy.justPressed(DOWN_BUTTON))&&(cursor_y<4)){
      cursor_y+=1;
  }
  if((arduboy.justPressed(UP_BUTTON))&&(cursor_y>0)){
      cursor_y-=1;
  }
  
}


