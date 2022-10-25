/*  
 *   Игра «Pong» на светодиодной матрице 8x8 (проект с itopen.it)
*/
 
#include "LedControl.h"
 
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
 
LedControl lc = LedControl(12,11,10,1);
 
byte direction; // роза ветров, «0» - это север
int xball;
int yball;
int yball_prev;
byte xpad;
int ball_timer;
 

 
void setup() {
}
 
void loop() {
}