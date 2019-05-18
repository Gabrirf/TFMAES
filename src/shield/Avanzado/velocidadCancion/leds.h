#define led1 7
#define led2 6
#define led3 5
#define led4 4

void initLeds(){
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void allOff(){
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);  
}

void allOn(){
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
}

void blinkAll(){
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  delay(100);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  delay(100);
}

void swLeds(int value){
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
      allOn();
      break;
  }
}
