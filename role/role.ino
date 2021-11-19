int role = 8;

void setup() {
  pinMode(role, OUTPUT);
}

void loop() {
  digitalWrite(role, HIGH);
  delay(3000);
  digitalWrite(role, LOW);
  delay(3000);
}
