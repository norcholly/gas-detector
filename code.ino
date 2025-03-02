#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define sensor A0 // Gas Sensor Analog Pin
#define redLed 7 // Red LED Digital Pin
#define greenLed 4 // Green LED Digital Pin
#define buzzer 2 // Buzzer Digital Pin

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  lcd.begin(16,2);
  lcd.backlight();

  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int value = analogRead(sensor);
  Serial.println(value);
  if(value>350 && value<500) {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    digitalWrite(buzzer, HIGH);

    lcd.setCursor(0,0);
    lcd.print("GAS LEAK!");
    lcd.setCursor(0,1);
    lcd.print("BE CAREFUL!");

    delay(1000);

    lcd.clear();

    digitalWrite(redLed, LOW);
    digitalWrite(buzzer, LOW);
    delay(1000);
  } else if(value>500) {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    digitalWrite(buzzer, HIGH);

    lcd.setCursor(0,0);
    lcd.print("DANGER! LEAVE");
    lcd.setCursor(0,1);
    lcd.print("THE AREA!");

    delay(300);

    lcd.clear();
    
    digitalWrite(redLed, LOW);
    digitalWrite(buzzer, LOW);
    delay(300);
  } else {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    digitalWrite(buzzer, LOW);
  }
}
