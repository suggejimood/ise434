float sicaklik;
float analoggerilim;

void setup() {
  Serial.begin(9600);
}

void loop() {
  analoggerilim = analogRead(A1);
  analoggerilim = (analoggerilim/1023)*5000;
  sicaklik = analoggerilim /10,0;
  Serial.print("Temperature is: ");
  Serial.print(" Celcius");

  delay(1000);
}
