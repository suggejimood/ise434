int led = 10;
int sensor = A0;
int sensorValue = 0;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(sensor, INPUT);

  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(sensor);
  sensorValue = map(sensorValue, 0, 300, 255, 0);
  analogWrite(led, sensorValue);

  Serial.print("Sensor value: ");
  Serial.println(sensorValue);

  delay(1000);
}
