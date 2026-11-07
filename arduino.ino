#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
const float R1 = 330.0; 
const float R2 = 330.0; 

const float Voltage = 5.0; 
const float multiMeter = 1.00; 

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Arduino");
  lcd.setCursor(0,1); 
  lcd.print("Voltmeter"); 
  delay(2000); 
  lcd.clear(); 

  lcd.setCursor(0,0); 
  lcd.print("DC Voltmeter");
}

void loop() {
  int read = analogRead(A0); 
  float vA = read * Voltage/ 1023.0; 
  float V_input = vA * (R1 + R2) / R1; 
  V_input = V_input * multiMeter; 

  lcd.setCursor(0,1); 
  lcd.print("V = "); 
  lcd.print(V_input, 2); 
  lcd.print("V  "); 
  
  delay(500); 
}
