double Light (int RawADC0){
  double Vout = RawADC0*.0048828125;
  int lux = 500 / (10*((5-Vout)/Vout));

  //int lux = (2500/Vout-500) / 10;

  return lux;
}

void setup() {
  Serial.print(9600);
}

void loop() {
  Serial.print("LDR: ");
  Serial.println(int(analogRead(A0)));
  Serial.print("LUX: ");
  Serial.println(int(Light(analogRead(A0))));

  delay(1000);
}
