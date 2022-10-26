/*  
 *   Игра «Pong» на светодиодной матрице 8x8 (проект с itopen.it)
*/
 
#include "LedControl.h"
#include "Timer.h"
 
#define POTPIN A5 // потенциометр
#define PADSIZE 3
#define BALL_DELAY 200
#define GAME_DELAY 10
#define BOUNCE_VERTICAL 1
#define BOUNCE_HORIZONTAL -1
#define NEW_GAME_ANIMATION_SPEED 50
#define HIT_NONE 0
#define HIT_CENTER 1
#define HIT_LEFT 2
#define HIT_RIGHT 3
 
//#define DEBUG 1
 
byte sad[] = {
B00000000,
B01000100,
B00010000,
B00010000,
B00000000,
B00111000,
B01000100,
B00000000
};
 
Timer timer;
 
LedControl lc = LedControl(12,11,10,1);
 
byte direction; // роза ветров, «0» - это север
int xball;
int yball;
int yball_prev;
byte xpad;
int ball_timer;
 
void newGame() {
    lc.clearDisplay(0);
    // начальная позиция:
    xball = random(1, 7);
    yball = 1;
    direction = random(3, 6); // идем на юг
    setSprite(smile);
    delay(1500);
    lc.clearDisplay(0);
}
 
void setup() {
  // в начале MAX72xx находится в режиме сбережения энергии;
  // нужно его «разбудить»: 
  pinMode(POTPIN, INPUT);
 
  lc.shutdown(0,false);
  // выставляем яркость на среднюю величину:
  lc.setIntensity(0, 8);
  // очищаем дисплей:
  lc.clearDisplay(0);
  randomSeed(analogRead(0));
#ifdef DEBUG
  Serial.begin(9600);
  Serial.println("Pong");
#endif
  newGame();
  ball_timer = timer.every(BALL_DELAY, moveBall);
}
 
void loop() {
    timer.update();
    delay(GAME_DELAY);
}