#define ls A2
#define ledVerde 5
#define ledRojo 4
#define Button1 9

void setup() {
  Serial.begin(9600);
  pinMode(ls, INPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledRojo, OUTPUT);
  pinMode(Button1, INPUT);
  digitalWrite(Button1, HIGH);
  // Añadir Panel LCD
}

void loop() {
  if(!digitalRead(Button1)){
    int luzActual = analogRead(ls);
    Serial.print(luzActual);
    encender(ledRojo, 3, luzActual);
    encender(ledVerde, 2, luzActual);
    encender(ledRojo, 2, luzActual);
    encender(ledVerde, 1, luzActual);
    while(!digitalRead(Button1)){delay(10);}
  }
}

void encender(uint8_t led, uint8_t n, int luzActual){
    for(uint8_t i = 0; i<n; i++){
      while(analogRead(ls) > luzActual/3){}
      Serial.print(analogRead(ls));
      digitalWrite(led, HIGH);
      delay(2000);
      digitalWrite(led, LOW);
    }    
}
