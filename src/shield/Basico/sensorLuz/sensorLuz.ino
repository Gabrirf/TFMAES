#define lightSensor A2

void setup() {
  Serial.begin(9600);
  pinMode(lightSensor, INPUT);
}

void loop() {
  int sensor = analogRead(lightSensor);
  float R = (float) (1023-sensor) * 10 / sensor; // KOhm
  float lux = 325 * pow(R, -1.4); // Luz
  Serial.print("Valor del sensor: ");
  Serial.println(sensor,1);
  Serial.print("Valor de la resistencia: ");
  Serial.print(R,1);
  Serial.println(" KOhm");
  Serial.print("Valor de luz: ");
  Serial.print(lux,1);
  Serial.println(" lux");
  delay(3000);
}
