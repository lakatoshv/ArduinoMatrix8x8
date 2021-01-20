
//Arduino Uno 8x8 LED matrix "cursor" w/ joystick

#include "LedControl.h"
LedControl lc=LedControl(12,11,10,1);
unsigned long delaytime=200;

// Variables:
// left/right joystick pin
const int hPin = A0;
// up/down joystick pin
const int vPin = A1;
// left/right joystick reading
int hVal;
// up/down joystick reading
int vVal;
// x-axis position
int xPos;
// y-axis position
int yPos;
// matrix column value
int xMax;
// matrix row value
int yMax;
// xMax from last loop
int xLast;
// yMax from last loop
int yLast;


void setup() {
  
  lc.shutdown(0,false);
  lc.setIntensity(0,8);
  // debug led for start of setup
  lc.setLed(0,0,0,1);
  delay(delaytime);
  lc.clearDisplay(0);
  
  pinMode(hPin,INPUT);
  pinMode(vPin,INPUT);
  
  Serial.begin(9600);
  Serial.println("[setup]");
  
  xPos = 0;
  yPos = 0;
}

void loop() {
  
  hVal = analogRead(hPin);
  vVal = analogRead(vPin);
  
  Serial.print("Horizontal: ");
  Serial.print(hVal);
  Serial.print("  Vertical: ");
  Serial.println(vVal);
  
  if(hVal >= 768){
    xPos = xPos + 128;
  }
  else if(hVal <= 256){
    xPos = xPos - 128;
  }
  else{}
 
  Serial.print(" X: ");
  Serial.print(xPos);
  Serial.print(" ");
  
  if(vVal >= 768){
    yPos = yPos + 128;
  }
  else if(vVal <= 256){
    yPos = yPos - 128;
  }
  else{}
  
  Serial.print(" Y: ");
  Serial.print(yPos);
  Serial.print(" ");
  
  if(xPos >=1024){
    xPos = 0;
  }
 
  if(yPos >=1024) {
    yPos = 0;
  }
  
  if(xPos <0){
    xPos = 1024;
  }
  
  if(yPos <0) {
    yPos = 1024;
  }
  
  // convert the 1024 value to 0-7 for matrix ( done here instead of when adding value to xPos because it would of went too fast
  yMax = yPos/128;

///////////////////////////////////////////////////////////////////////////////////  

  Serial.print(" xMax: ");
  Serial.print(xMax);
  Serial.print(" yMax: ");
  Serial.print(yMax);
 
  lc.setLed(0,xMax,yMax,1);
  
  if(xLast != xMax || yLast != yMax){ 
      lc.setLed(0,xLast,yLast,0);
  }
  
  xLast = xMax;
  yLast = yMax;
  delay(250);
}
