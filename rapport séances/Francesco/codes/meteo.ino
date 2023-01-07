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

unsigned long mymillis;
boolean EC1 = true;
boolean EC2 = false;
boolean EC = false;

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

  if (EC1 == true && EC == false) {
    lcd.setCursor(0,1);
    lcd.print("Temperature: ");
    lcd.print(t);
    lcd.print(char(1));
    
    EC = true;
    mymillis = millis();
  }
  
  if (EC2 == true && EC == false) {
    lcd.setCursor(0,1);
    lcd.print(" Humidite: ");
    lcd.print(h);
    lcd.print("%   ");

    EC = true;
    mymillis = millis();
  }

  //changement d'interface toutes les 3 secondes
  if (millis() - mymillis >= 3000) { 
    EC1 = !EC1;
    EC2 = !EC2;
    EC = false;
  }

}

void printDateTime(DateTime dt) {
  char dateBuffer[] = "DD/MM/YYYY hh:mm";

  lcd.setCursor(0,0);
  lcd.print(dt.toString(dateBuffer));
}
