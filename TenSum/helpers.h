//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// HELPERS
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
void print(String text,int x, int y){
  arduboy.setCursor(x, y);
  arduboy.println(text);
}

void rect(int x,int y, int xs, int ys){
  arduboy.drawRect(x, y, xs, ys, WHITE);
}

void rectfill(int x,int y, int xs, int ys){
  arduboy.fillRect(x, y, xs, ys, WHITE);
}

void circ(int x,int y,int r){
  arduboy.drawCircle(x,y,r, WHITE);
}

void circfill(int x,int y,int r){
  arduboy.fillCircle(x,y,r, WHITE);
}

void printm(String text,int y){
  int half_length=text.length()*6;
  arduboy.setCursor(64-half_length/2, y);
  arduboy.println(text);
}

void spr(const uint8_t *bitmap,int x, int y){
  Sprites::drawPlusMask(x, y, bitmap, 0);
}

void playTone(uint16_t count, uint8_t frames)
{
  beep.tone(count, frames);
}

int distance(int x1,int y1, int x2, int y2){
  return abs(x1-x2)+abs(y1-y2);
}




