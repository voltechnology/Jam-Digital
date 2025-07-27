#include <Wire.h>
#include <RTClib.h>
#include <LiquidCrystal_I2C.h>

RTC_DS3231 rtc;
LiquidCrystal_I2C lcd(0x27, 16, 2); 

void setup() {
  Wire.begin();
  rtc.begin();
  lcd.init(); 
  lcd.backlight(); // Aktifkan backlight

  rtc.adjust(DateTime(F(_DATE), F(TIME_)));
  // rtc.adjust(DateTime(2025, 5, 7, 15, 0, 0)); // Manual

  lcd.setCursor(0, 0);
  lcd.print("Waktu:");
}

void loop() {
  DateTime now = rtc.now();

  // Menampilkan Waktu 
  lcd.setCursor(7, 0);
  if (now.hour() < 10) lcd.print("0");
  lcd.print(now.hour());
  lcd.print(":");
  if (now.minute() < 10) lcd.print("0");
  lcd.print(now.minute());
  lcd.print(":");
  if (now.second() < 10) lcd.print("0");
  lcd.print(now.second());

  // Tampilkan Tanggal 
  lcd.setCursor(0, 1);
  if (now.day() < 10) lcd.print("0");
  lcd.print(now.day());
  lcd.print("/");
  if (now.month() < 10) lcd.print("0");
  lcd.print(now.month());
  lcd.print("/");
  lcd.print(now.year());

  delay(1000);
}