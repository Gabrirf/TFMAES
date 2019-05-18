#define led1 7
#define led2 6
#define led3 5
#define led4 4

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop() {
  for(int i=1;i<255; i++){
    analogWrite(led1,i);
    analogWrite(led2,i);
    analogWrite(led3,i);
    analogWrite(led4,i);
    delay(10);
  }
  for(int i=255;i>0; i--){
    analogWrite(led1,i);
    analogWrite(led2,i);
    analogWrite(led3,i);
    analogWrite(led4,i);
    delay(10);
  }
}
