#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd1(0x27, 16, 2); // << Address 1
LiquidCrystal_I2C lcd2(0x26, 16, 2); // << Address 2

void setup()
{
  lcd1.init();
  lcd2.init();

  lcd1.backlight();
  lcd2.backlight();

  lcd1.setCursor(0, 0);
  lcd1.print("Hello World");
  lcd1.setCursor(0, 1);
  lcd1.print("Display 1");

  lcd2.setCursor(0, 0);
  lcd2.print("Hello World");
  lcd2.setCursor(0, 1);
  lcd2.print("Display 2");

}


void loop()
{
}
// ------- ©Electronics Project Hub -----------//
