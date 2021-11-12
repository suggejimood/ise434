int limit = 300;
int led = 9;
int sensor = A0;
int sensorValue = 0;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(sensor, INPUT);

  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(sensor);

  if(sensorValue < limit) {
    digitalWrite(led, HIGH);
  }
  else{
    digitalWrite(led, LOW);
  }

  Serial.print("Sensor value: ");
  Serial.println(sensorValue);

  delay(1000);
}
