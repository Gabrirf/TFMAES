#define buzzer 3

void setup() {
  pinMode(buzzer, OUTPUT);
  playTone(440, 500);
}

void loop() {
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
