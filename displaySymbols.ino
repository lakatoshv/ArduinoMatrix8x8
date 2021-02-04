/// <summary>
/// Display different symbols matrix 8x8.
/// </summary>
// <copyright file="displaySymbols.ino" company="lakatoshvv">
// Copyright (c) lakatoshvv. All rights reserved.
// </copyright>

#include <MaxMatrix.h>
#include <avr/pgmspace.h>


const PROGMEM unsigned char CH[] = {
  3, 8, B00000000, B00000000, B00000000, B00000000, B00000000, // space
};


const int DIN_PIN = 12;
const int CS_PIN = 10;    // 9, CS pin of MAX7219 module
const int CLK_PIN = 11;  // 10, CLK pin of MAX7219 module


const int maxInUse = 1;    //change this variable to set how many MAX7219's you'll use


MaxMatrix matrix(DIN_PIN, CS_PIN, CLK_PIN, maxInUse); // define module


byte buffer[10];


// active sentenses
char string1[] = " ABCDEFGHIJKLMNOPQRSTUVWXYZ ";

void setup(){
  matrix.init(); // module initialize
  matrix.setIntensity(0); // dot matix intensity 0-15
  Serial.begin(9600); // serial communication initialize
}


void loop(){
  byte c;
  // this is the code if you want to entering a message via serial console
  while (Serial.available() > 0){
    byte c = Serial.read();
    Serial.println(c, DEC);
    printCharWithShift(c, 100);
  }
  delay(100);
  matrix.shiftLeft(false, true);
  
  
  // 1st block - print the active sentences
  // comment this block when using the 2nd messages block 
 
  printStringWithShift(string1, 100);
}


void printCharWithShift(char c, int shift_speed){
  if (c < 32) return;
  c -= 32;
  memcpy_P(buffer, CH + 7*c, 7);
  matrix.writeSprite(maxInUse*8, 0, buffer);
  matrix.setColumn(maxInUse*8 + buffer[0], 0);
  
  for (int i=0; i<buffer[0]+1; i++) 
  {
    delay(shift_speed);
    matrix.shiftLeft(false, false);
  }
}


void printStringWithShift(char* s, int shift_speed){
  while (*s != 0){
    printCharWithShift(*s, shift_speed);
    s++;
  }
}


void printString(char* s)
{
  int col = 0;
  while (*s != 0)
  {
    if (*s < 32) continue;
    char c = *s - 32;
    memcpy_P(buffer, CH + 7*c, 7);
    matrix.writeSprite(col, 0, buffer);
    matrix.setColumn(col + buffer[0], 0);
    col += buffer[0] + 1;
    s++;
  }
}