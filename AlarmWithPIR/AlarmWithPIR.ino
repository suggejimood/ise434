int alarmpin = 2;
int ledpin = 9;
int buzzerpin = 3;
int pirstate = 0;

void setup() {
  pinMode(alarmpin, INPUT);
  pinMode(ledpin, OUTPUT);
  Serial.begin(9600);
  Serial.println("PIR ALARM");
}

void loop() {
  if(digitalRead(alarmpin) == HIGH)
  {
    digitalWrite(ledpin, HIGH);
    tone(buzzerpin, 500, 20);
    if(pirstate == 0)
    {
      Serial.println("Motion Detected!");
      pirstate = 1;
    }
  }

  else{
    digitalWrite(ledpin, LOW);
    if(pirstate == 1)
    {
      Serial.println("Motion Ended");
      pirstate = 0;
    }
  }

  delay(20);
}
