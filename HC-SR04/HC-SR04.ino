#define echoPin 7
#define trigPin 8
#define LEDPin 13

int maximumRange = 400;
int minimumRange = 2;
long duration, distance;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LEDPin, OUTPUT);

}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);

  distance = duration / 29 / 2;

  if(distance >= maximumRange || distance <= minimumRange)
  {
    Serial.println("-1");
    digitalWrite(LEDPin, HIGH);
  }
  else{
    Serial.println(distance);
    digitalWrite(LEDPin, LOW);
  }
  delay(1000);
}
