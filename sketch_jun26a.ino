#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int sensorPin = A0;   
const int ledPin = 7;       
const int lightThreshold = 700; // 判斷白天/夜晚的分界值

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Night Light Ready");
  delay(1000);
}

void loop() {
  int lightLevel = analogRead(sensorPin); 
  Serial.println(lightLevel);

  // 顯示數值在 LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Light: ");
  lcd.print(lightLevel);

  lcd.setCursor(0, 1);
  if (lightLevel < lightThreshold) {
    lcd.print("Night: LED ON");
    digitalWrite(ledPin, HIGH);
  } else {
    lcd.print("Day: LED OFF");
    digitalWrite(ledPin, LOW);
  }

  delay(500);
}





