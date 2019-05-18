#include "cancion.h"
#include "leds.h"

#define knob A0
#define Button1 9

void setup() {
  pinMode(knob, INPUT);
  pinMode(Button1, INPUT);
  digitalWrite(Button1, HIGH);
  initLeds();
}

void loop() {
  if(!digitalRead(Button1)){
    while(!digitalRead(Button1)){delay(10);}
  
    for (int i=0;i<203;i++){
      int value = analogRead(knob);
      swLeds(value);
      songspeed = map(value, 0, 1023, 50, 1);
      int wait = duration[i] * songspeed;
      tone(buzzer,notes[i],wait);          //tone(pin,frequency,duration)
      delay(wait);
    }
  }
}
