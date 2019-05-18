#include <Wire.h>

#include "RichShieldTM1637.h"
#include "RichShieldIRremote.h"
#include "RichShieldPassiveBuzzer.h"
#include "musical_notes.h"

#define PassiveBuzzerPin 3
PassiveBuzzer buz(PassiveBuzzerPin);


#define RECV_PIN 2
IRrecv IR(RECV_PIN);

#define CLK 10
#define DIO 11
TM1637 disp(CLK,DIO);

unsigned char num = 0;
int nota = 0;
void setup()
{
  disp.init();
  IR.enableIRIn();
}


void loop()
{
  if (IR.decode()) {//If a valid key code is detected

    if(IR.isReleased())//If it is not the repeat code for long press
    {
      switch(IR.keycode)
      {
        case KEY_ZERO:  num = 0;nota = note_C4 ;break;
        case KEY_ONE:   num = 1;nota = note_Db4;break;
        case KEY_TWO:   num = 2;nota = note_D4 ;break;
        case KEY_THREE: num = 3;nota = note_Eb4;break;
        case KEY_FOUR:  num = 4;nota = note_E4 ;break;
        case KEY_FIVE:  num = 5;nota = note_F4 ;break;
        case KEY_SIX:   num = 6;nota = note_Gb4;break;
        case KEY_SEVEN: num = 7;nota = note_G4 ;break;
        case KEY_EIGHT: num = 8;nota = note_Ab4;break;
        case KEY_NINE:  num = 9;nota = note_A4 ;break;
        case KEY_PLUS:  num = num+1;nota = note_Bb4;break;
        case KEY_MINUS: num = num-1;nota = note_B4 ;break;
        case KEY_C: num = 10;nota = note_C5 ;break;
        default: break;
      }
      disp.display(num);
      buz.playTone(nota,200);
      //delay(100);   //buzzer beep for 100ms
    }else{
      buz.playTone(nota,200);
    }
    IR.resume(); // Receive the next value
  }
}


/*********************************************************************************************************
The end of file
*********************************************************************************************************/
