#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 =3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  int i;
  lcd.setCursor(3,0);
  lcd.print("ISE434");

  for(i = 0; i < 17; i++)
  {
    lcd.setCursor(i, 1);
    lcd.print(25 Derece");
    delay(1000);
    lcd.setCursor(i, 1);
    lcd.print(" ");
  }
}
