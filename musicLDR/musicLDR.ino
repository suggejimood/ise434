int sensorReading;
int thisPitch;

void setup() {
  Serial.begin(9600);

}

void loop() {
  sensorReading = analogRead(A0);
  Serial.println(sensorReading);

  thisPitch = map(sensorReading, 400, 1000, 120, 1500);

  tone(9, thisPitch, 10);

  delay(10);
}
