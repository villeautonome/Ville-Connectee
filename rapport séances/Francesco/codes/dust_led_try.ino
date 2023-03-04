#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

int pin = 8;
unsigned long duration;
unsigned long starttime;
unsigned long sampletime_ms = 30000;
unsigned long lowpulseoccupancy = 0;
float ratio = 0;
float concentration = 0;
float maxcon = 0;

void setup() {
 Serial.begin(9600);
 pinMode(8,INPUT);
 starttime = millis();
 lcd.begin(16, 2);

 lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Hello, world!");
}
void loop() {
 duration = pulseIn(pin, LOW);
 lowpulseoccupancy = lowpulseoccupancy+duration;
 if ((millis()-starttime) > sampletime_ms)
 {
 ratio = lowpulseoccupancy/(sampletime_ms*10.0); // Integer percentage 0=>100
 concentration = 1.1*pow(ratio,3)-3.8*pow(ratio,2)+520*ratio+0.62;
 if (concentration > maxcon){ maxcon = concentration;}
 lcd.setCursor(0, 0);
 lcd.print("now: ");
 lcd.setCursor(5, 0);
 lcd.print(concentration);
 
 lcd.setCursor(0, 1);
 lcd.print("max: ");
 lcd.setCursor(5, 1);
 lcd.print(maxcon);

 Serial.print(" concentration: ");
 Serial.print(concentration);
 Serial.println(" pcs/0.01cf");
 Serial.print(" max concentration: ");
 Serial.print(maxcon);
 Serial.println(" pcs/0.01cf");
 lowpulseoccupancy = 0;
 starttime = millis();
 }
}
