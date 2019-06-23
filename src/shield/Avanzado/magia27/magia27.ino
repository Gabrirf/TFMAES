#include "RichShieldTM1637.h"

#define Button1 9
#define Button2 8

// Pantalla
#define CLK 10
#define DIO 11
TM1637 disp(CLK,DIO);

#define ls A2
#define ledVerde 5
#define ledRojo 4

int luzActual;

void setup() {
  Serial.begin(9600);
  pinMode(Button1, INPUT);
  digitalWrite(Button1, HIGH);
  pinMode(Button2, INPUT);
  digitalWrite(Button2, HIGH);

  pinMode(ls, INPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledRojo, OUTPUT);
  disp.init();
  disp.display(0);
}

void loop() {
  luzActual = analogRead(ls);
  int posicion = 0;
  boolean siguiente = false;
  int cont = 0;
  for(int i=0;i<3;i++){
    while(!siguiente){
      if(!digitalRead(Button1)){
        disp.display(++cont);
        posicion += pow(3, i);
        while(!digitalRead(Button1)){delay(10);}
      }
      if(!digitalRead(Button2)){
        siguiente = true;
        while(!digitalRead(Button2)){delay(10);}
      }
    }
    siguiente = false;
    cont = 0;
    disp.display(cont);
  }
  Serial.println(posicion);
  disp.display(cont);    
  encender(ledRojo, posicion);
  encender(ledVerde, 1);
}

void encender(uint8_t led, uint8_t n){
    for(uint8_t i = 0; i<n; i++){
      while(analogRead(ls) > luzActual/3){}
      Serial.print(analogRead(ls));
      digitalWrite(led, HIGH);
      delay(2000);
      digitalWrite(led, LOW);
    }    
}
