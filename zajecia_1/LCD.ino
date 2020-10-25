#include <LiquidCrystal.h>
LiquidCrystal lcd(10, 9, 8 , 7, 6, 5);

void setup() {
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Mechatronic");
  lcd.setCursor(0,1);
  lcd.print("Design");
  

}

void loop() {
  // put your main code here, to run repeatedly:

}
