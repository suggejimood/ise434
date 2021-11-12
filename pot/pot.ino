int led = 10;
int pot = A0;
int potValue;
float voltage = 0;

void setup() {
   Serial.begin(9600);
   pinMode(led, 10);
}

void loop() {
  potValue = analogRead(pot);
  potValue = map(potValue, 0, 1023, 0, 255);
  analogWrite(led, potValue);

  voltage = (potValue / 1023.0) * 5.0;
  Serial.print("sensor Value: ");
  Serial.println(potValue);
  Serial.print("Voltage Value: ");
  Serial.println(voltage);

  delay(1000);
}
