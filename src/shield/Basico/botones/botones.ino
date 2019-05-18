#define Button1 9
#define Button2 8

void setup() {
  Serial.begin(9600);
  pinMode(Button1, INPUT);
  digitalWrite(Button1, HIGH);
  pinMode(Button2, INPUT);
  digitalWrite(Button2, HIGH);
}

void loop() {
  if(!digitalRead(Button1)){
    Serial.print("Hola");
    while(!digitalRead(Button1)){delay(10);}
  }
}
