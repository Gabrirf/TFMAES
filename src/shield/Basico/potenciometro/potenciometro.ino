#define knob A0

void setup() {
  Serial.begin(9600);
  pinMode(knob, INPUT);
}

void loop() {
  int value = analogRead(knob);
  Serial.print(value);
}
