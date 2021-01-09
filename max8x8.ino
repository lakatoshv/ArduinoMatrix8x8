/// <summary>
/// Use matrix 8x8.
/// </summary>
// <copyright file="max8x8.ino" company="lakatoshvv">
// Copyright (c) lakatoshvv. All rights reserved.
// </copyright>

#include "LedControl.h"
#include "binary.h"

const int DIN_PIN = 12;
const int CLK_PIN = 11;
const int CS_PIN = 10;

LedControl lc=LedControl(DIN_PIN, CLK_PIN, CS_PIN,1);

void setup() {
  lc.shutdown(0,false);
  lc.setIntensity(0,8);
  lc.clearDisplay(0);  
}

void loop(){
  lc.setRow(0,0,B11111111);
  lc.setRow(0,1,B11111111);
  lc.setRow(0,2,B11111111);
  lc.setRow(0,3,B11111111);
  lc.setRow(0,4,B11111111);
  lc.setRow(0,5,B11111111);
  lc.setRow(0,6,B11111111);
  lc.setRow(0,7,B11111111);
  
  delay(1000);
  lc.clearDisplay(0);  
  delay(1000);
}