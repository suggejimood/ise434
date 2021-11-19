int alarmpin = 6;
int ledpin = 9;
int buzzerpin = 3;
int statuschange = 1;

void setup() {
  pinMode(alarmpin, INPUT);
  pinMode(ledpin, OUTPUT);
  Serial.begin(9600);
  Serial.println("DOOR ALARM");
}

void loop() {
  if(digitalRead(alarmpin) == HIGH)
  {
    digitalWrite(ledpin, LOW);
    if(statuschange == 0)
    {
      Serial.println("Your door is closed");
      statuschange = 1;
    }
  }

  else{
    digitalWrite(ledpin, HIGH);
    tone(buzzerpin, 500, 20);
    if(statuschange == 1){
      Serial.println("Your door is open");
      statuschange = 0;
    }
  }

  delay(20);
}
