int redPin = 8;
int greenPin = 9;
int bluePin = 10;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void showcolor(int red, int green, int blue){
  red = 255 - red;
  green = 255 - green;
  blue = 255 - blue;

  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

void loop() {
  //showcolor(0,0,0);
  for(int i=0; i<256; i+=10){
    for(int j=0; j<255; j+=10){
      for(int k=0; k<255; k+=10){
        showcolor(i, j, k);
        delay(1);
      }
    }
  }
}
