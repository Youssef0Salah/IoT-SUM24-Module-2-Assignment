#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int irSensorPin = A5;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("IR Sensor Readings");
  delay(2000);
  lcd.clear();
}

void loop() {
  int irSensorValue = analogRead(irSensorPin);
  float distance = map(irSensorValue, 0, 4095, 1, 25);

  if (irSensorValue == 0 || irSensorValue == 4095) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("No input detected");
    lcd.setCursor(0, 1);
    lcd.print("Please connect");
    Serial.println("No input detected, please connect the sensor.");
  } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("IR Value: ");
    lcd.print(irSensorValue);
    lcd.setCursor(0, 1);
    lcd.print("Distance: ");
    lcd.print(distance);
    lcd.print(" mm");

    Serial.print("IR Sensor Value: ");
    Serial.print(irSensorValue);
    Serial.print(" | Distance: ");
    Serial.print(distance);
    Serial.println(" mm");
  }

  delay(500);
}
