#include <LiquidCrystal_I2C.h>
#include <RTClib.h>
#include <Wire.h>
#include <DHT.h>

RTC_DS3231 rtc;
LiquidCrystal_I2C lcd(0x27, 16, 2);

DHT dht(2, DHT22);

byte degre[8] = {
0b01100,0b10010,0b10010,0b01100,0b00000,0b00000,0b00000,0b00000
};

void setup () {
  rtc.begin();
  
  if (rtc.lostPower()) {
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.createChar(1, degre);
}

void loop () {
  DateTime now = rtc.now();
  printDateTime(now);
  delay(1000);
  byte h = dht.readHumidity();
  byte t = dht.readTemperature();

  lcd.setCursor(0,1);
  lcd.print("Temperature: ");
  lcd.print(t);
  lcd.print(char(1));
}

void printDateTime(DateTime dt) {
  char dateBuffer[] = "DD/MM/YYYY hh:mm";

  lcd.setCursor(0, 0);
  lcd.print(dt.toString(dateBuffer));
}
