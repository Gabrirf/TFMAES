#include "musical_notes.h"
#include "RichShieldTM1637.h"

// Buzzer
#define buzzer 3
// Botones
#define Button1 9
#define Button2 8
// Pantalla
#define CLK 10//CLK of the TM1637 IC connect to D10 of OPEN-SMART UNO R3
#define DIO 11//DIO of the TM1637 IC connect to D11 of OPEN-SMART UNO R3
TM1637 disp(CLK,DIO);

int cont = 1;

void setup() {
  Serial.begin(9600);
  // Buzzer
  pinMode(buzzer, OUTPUT);
  // Botones
  pinMode(Button1, INPUT);
  digitalWrite(Button1, HIGH);
  pinMode(Button2, INPUT);
  digitalWrite(Button2, HIGH);
  // Pantalla
  disp.init();//The initialization of the display
  disp.display(cont);//display counter number
}

void loop() {
  if(!digitalRead(Button1)){
    cont++;
    while(!digitalRead(Button1)){delay(10);}
  }
  if(!digitalRead(Button2)){
      //playTone(100*cont,500);
      selectSong(cont);
    while(!digitalRead(Button2)){delay(10);}
  }
  if(cont > 10){
    cont = 1;
  }
  disp.display(cont);
}

void playTone(long frequency, long millisecond) {
    if(frequency > 0){
      // Transformacion para el bucle
      long delayValue = 1000000 / frequency / 2; 
      long numCycles = frequency * millisecond / 1000;
      // Bucle para estimular el buzzer a la frecuencia deseada
      for (long i = 0; i < numCycles; i++) {
          digitalWrite(buzzer, HIGH); 
          delayMicroseconds(delayValue);
          digitalWrite(buzzer, LOW);
          delayMicroseconds(delayValue);
      }
    }
    else delay(millisecond);
 }

 void selectSong(int num){
  switch(num){
    case 1:
      squeak();
      break;
    case 2:
      catcall();
      break;
    case 3:
      ohhh();
      break;
    case 4:
      laugh();
      break;
    case 5:
      closeEncounters();
      break;
    case 6:
      laugh2();
      break;
    case 7:
      waka();
      break;
    case 8:
      r2D2();
      break;
    case 9:
      ariel();
      break;
    default:
      disp.display(8888);
      delay(1000);
  }
}

void scale() 
{    
          playTone(note_C7,500); //C: play the note C for 500ms 
          playTone(note_D7,500); //D 
          playTone(note_E7,500); //E 
          playTone(note_F7,500); //F 
          playTone(note_G7,500); //G 
          playTone(note_A7,500); //A 
          playTone(note_B7,500); //B 
          playTone(note_C8,500); //C 
}  

void r2D2(){
          playTone(note_A7,100); //A 
          playTone(note_G7,100); //G 
          playTone(note_E7,100); //E 
          playTone(note_C7,100); //C
          playTone(note_D7,100); //D 
          playTone(note_B7,100); //B 
          playTone(note_F7,100); //F 
          playTone(note_C8,100); //C 
          playTone(note_A7,100); //A 
          playTone(note_G7,100); //G 
          playTone(note_E7,100); //E 
          playTone(note_C7,100); //C
          playTone(note_D7,100); //D 
          playTone(note_B7,100); //B 
          playTone(note_F7,100); //F 
          playTone(note_C8,100); //C 
}

void closeEncounters() {
          playTone(note_Bb5,300); //B b
          delay(50);
          playTone(note_C6,300); //C
          delay(50);
          playTone(note_Ab5,300); //A b
          delay(50);
          playTone(note_Ab4,300); //A b
          delay(50);
          playTone(note_Eb5,500); //E b   
          delay(500);     
          
          playTone(note_Bb4,300); //B b
          delay(100);
          playTone(note_C5,300); //C
          delay(100);
          playTone(note_Ab4,300); //A b
          delay(100);
          playTone(note_Ab3,300); //A b
          delay(100);
          playTone(note_Eb4,500); //E b   
          delay(500);  
          
          playTone(note_Bb3,300); //B b
          delay(200);
          playTone(note_C4,300); //C
          delay(200);
          playTone(note_Ab3,300); //A b
          delay(500);
          playTone(note_Ab2,300); //A b
          delay(550);
          playTone(note_Eb3,500); //E b      
}

void ariel() {

          playTone(note_C6,300); //C
          delay(50);
          playTone(note_D6,300); //D
          delay(50);
          playTone(note_Eb6,600); //D#
          delay(250);
          
          playTone(note_D6,300); //D
          delay(50);
          playTone(note_Eb6,300); //D#
          delay(50);
          playTone(note_F6,600); //F
          delay(250);
          
          playTone(note_C6,300); //C
          delay(50);
          playTone(note_D6,300); //D
          delay(50);
          playTone(note_Eb6,500); //D#
          delay(50);          
          playTone(note_D6,300); //D
          delay(50);
          playTone(note_Eb6,300); //D#
          delay(50);             
          playTone(note_D6,300); //D
          delay(50);
          playTone(note_Eb6,300); //D#
          delay(50);
          playTone(note_F6,600); //F
          delay(50); 

}
 

void laugh2() {
          playTone(note_C6,200); //C
          playTone(note_E6,200); //E  
          playTone(note_G6,200); //G 
          playTone(note_C7,200); //C 
          playTone(note_C6,200); //C
          delay(50);
          playTone(note_C6,200); //C
          playTone(note_E6,200); //E  
          playTone(note_G6,200); //G 
          playTone(note_C7,200); //C 
          playTone(note_C6,200); //C
          delay(50);
          playTone(note_C6,50); //C
          delay(50);
          playTone(note_C6,50); //C
          delay(50);
          playTone(note_C6,50); //C
          delay(50);
          playTone(note_C6,50); //C
          delay(50);
          playTone(note_C6,50); //C
          delay(50);
          playTone(note_C6,50); //C
          delay(50);
          playTone(note_C6,50); //C
          

          
}
  
void squeak() {
  for (int i=100; i<5000; i=i*1.45) {
    playTone(i,60);
  }
  delay(10);
  for (int i=100; i<6000; i=i*1.5) {
    playTone(i,20);
  }
}

void waka() {
  for (int i=1000; i<3000; i=i*1.05) {
    playTone(i,10);
  }
  delay(100);
  for (int i=2000; i>1000; i=i*.95) {
    playTone(i,10);
  }
    for (int i=1000; i<3000; i=i*1.05) {
    playTone(i,10);
  }
  delay(100);
  for (int i=2000; i>1000; i=i*.95) {
    playTone(i,10);
  }
    for (int i=1000; i<3000; i=i*1.05) {
    playTone(i,10);
  }
  delay(100);
  for (int i=2000; i>1000; i=i*.95) {
    playTone(i,10);
  }
    for (int i=1000; i<3000; i=i*1.05) {
    playTone(i,10);
  }
  delay(100);
  for (int i=2000; i>1000; i=i*.95) {
    playTone(i,10);
  }
}

void catcall() {
  for (int i=1000; i<5000; i=i*1.05) {
    playTone(i,10);
  }
 delay(300);
 
  for (int i=1000; i<3000; i=i*1.03) {
    playTone(i,10);
  }
  for (int i=3000; i>1000; i=i*.97) {
    playTone(i,10);
  }
}

void ohhh() {
  for (int i=1000; i<2000; i=i*1.02) {
    playTone(i,10);
  }
  for (int i=2000; i>1000; i=i*.98) {
    playTone(i,10);
  }
}

void uhoh() {
  for (int i=1000; i<1244; i=i*1.01) {
    playTone(i,30);
  }
  delay(200);
  for (int i=1244; i>1108; i=i*.99) {
    playTone(i,30);
  }
}

void laugh() {
  for (int i=1000; i<2000; i=i*1.10) {
    playTone(i,10);
  }
  delay(50);
  for (int i=1000; i>500; i=i*.90) {
    playTone(i,10);
  }
  delay(50);
  for (int i=1000; i<2000; i=i*1.10) {
    playTone(i,10);
  }
  delay(50);
  for (int i=1000; i>500; i=i*.90) {
    playTone(i,10);
  }
  delay(50);
    for (int i=1000; i<2000; i=i*1.10) {
    playTone(i,10);
  }
  delay(50);
  for (int i=1000; i>500; i=i*.90) {
    playTone(i,10);
  }
  delay(50);
    for (int i=1000; i<2000; i=i*1.10) {
    playTone(i,10);
  }
  delay(50);
  for (int i=1000; i>500; i=i*.90) {
    playTone(i,10);
  }
  delay(50);
}
