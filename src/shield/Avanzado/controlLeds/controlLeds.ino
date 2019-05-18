#include "leds.h"

#define knob A0

void setup() {
  // Potenciometro
  pinMode(knob, INPUT);
  // Leds
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop() {
 int value = analogRead(knob);

 switch(value){
  case 0 ... 300:
    allOff();
    break;
  case 301 ... 420:
    allOff();
    digitalWrite(led1, HIGH);
    break;
  case 421 ... 560:
    allOff();
    digitalWrite(led2, HIGH);
    break;
  case 561 ... 700:
    allOff();
    digitalWrite(led3, HIGH);
    break;
  case 701 ... 800:
    allOff();
    digitalWrite(led4, HIGH);
    break; 
  case 801 ... 1023:
    blinkAll();
    break;
 }
}
