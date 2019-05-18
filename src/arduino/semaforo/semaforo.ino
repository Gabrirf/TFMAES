#define green 13
#define yellow 12
#define red 11

void setup() {
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
}

void loop() {
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
  digitalWrite(red, HIGH);
  delay(2000);
  digitalWrite(red, LOW);
  digitalWrite(green, HIGH);
  delay(3000);
  digitalWrite(green, LOW);
  digitalWrite(yellow, HIGH);
  delay(500);
  for(int i=0; i<3;i++){
  digitalWrite(yellow, LOW);
  delay(100);
  digitalWrite(yellow, HIGH);
  delay(100);    
  }  
}
