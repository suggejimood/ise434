#include<Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3f,16,2);

const int MPU=0x68;
int led = 8; 
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
int16_t RcX, RcY, RcZ, vector, angle, largestVector;

void setup(){
  lcd.begin();
  pinMode(led, OUTPUT);

  for(int i=0; i<3; i++){
    for(int i = 0; i < 4; i++){
    if(i==0)
    {
      lcd.setCursor(0,0); // İkinci satırın başlangıç noktası
      lcd.print("Test Machine");
      lcd.setCursor(0,1); // İkinci satırın başlangıç noktası
      lcd.print("Loading   ");
    }
    else if(i==1){
      lcd.setCursor(0,0); // İkinci satırın başlangıç noktası
      lcd.print("Test Machine");
      lcd.setCursor(0,1); // İkinci satırın başlangıç noktası
      lcd.print("Loading.  ");
    }
    else if(i==2){
      lcd.setCursor(0,0); // İkinci satırın başlangıç noktası
      lcd.print("Test Machine");
      lcd.setCursor(0,1); // İkinci satırın başlangıç noktası
      lcd.print("Loading.. ");
    }
    else if(i==3){
      lcd.setCursor(0,0); // İkinci satırın başlangıç noktası
      lcd.print("Test Machine");
      lcd.setCursor(0,1); // İkinci satırın başlangıç noktası
      lcd.print("Loading...");
    }
    delay(500);
  }
  }
  
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B); 
  Wire.write(0);    
  Wire.endTransmission(true);
  Serial.begin(9600);
}
void loop(){
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);  
  Wire.endTransmission(false);
  Wire.requestFrom(MPU,12,true);  
  AcX=Wire.read()<<8|Wire.read();    
  AcY=Wire.read()<<8|Wire.read();  
  AcZ=Wire.read()<<8|Wire.read();  
  GyX=Wire.read()<<8|Wire.read();  
  GyY=Wire.read()<<8|Wire.read();  
  GyZ=Wire.read()<<8|Wire.read();
  
  Serial.println("-------Accelerometer-------");
  RcX = AcX * AcX;
  RcY = AcY * AcY;
  RcZ = AcZ * AcZ;

  vector = RcX + RcY + RcZ;
  vector = sqrt(vector);
  
  lcd.setCursor(0,1); // İkinci satırın başlangıç noktası
  lcd.print("Vector: ");
  lcd.setCursor(7,1); // İkinci satırın başlangıç noktası
  lcd.print(vector);
  
  Serial.print("Vector: "); Serial.println(vector);
  Serial.println("---------------------------");

  Serial.println("-------Angle-------");
  angle = map(AcX, -16300, 16300, 0, 180);

  Serial.println(angle);

  lcd.setCursor(0,0); // İlk satırın başlangıç noktası
  lcd.print("Angle: ");
  lcd.setCursor(6,0); // İkinci satırın başlangıç noktası
  lcd.print(angle);
  
  if(angle < 145 && angle > 135){
    digitalWrite(led, HIGH);
  }
  else{
    digitalWrite(led, LOW);
  }
  Serial.println("-------------------");
  
  Serial.println("------Gyroscope-------");
  Serial.print("X = "); Serial.print(AcX);
  Serial.print(" | Y = "); Serial.print(AcY);
  Serial.print(" | Z = "); Serial.println(AcZ);
  Serial.println("---------------------");
  delay(1000);

  lcd.clear();
}
