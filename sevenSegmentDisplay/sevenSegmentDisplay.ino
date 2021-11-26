void setup() {
  pinMode(2, OUTPUT); // "A" segment
  pinMode(3, OUTPUT); // "B" segment
  pinMode(4, OUTPUT); // "C" segment
  pinMode(5, OUTPUT); // "D" segment
  pinMode(6, OUTPUT); // "E" segment
  pinMode(7, OUTPUT); // "F" segment
  pinMode(8, OUTPUT); // "G" segment
  pinMode(9, OUTPUT); // "DP" segment
}

void loop() {
  // To write "0"
  digitalWrite(2, 0);
  digitalWrite(3, 0);
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(6, 0);
  digitalWrite(7, 0);
  digitalWrite(8, 1);
  digitalWrite(9, 1);
  delay(1000);

  // To write "1"
  digitalWrite(2, 1);
  digitalWrite(3, 0);
  digitalWrite(4, 0);
  digitalWrite(5, 1);
  digitalWrite(6, 1);
  digitalWrite(7, 1);
  digitalWrite(8, 1);
  digitalWrite(9, 1);
  delay(1000);

}
