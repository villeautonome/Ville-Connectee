#include <Adafruit_NeoPixel.h>
#include <LiquidCrystal_I2C.h>

//constantes pour le capteur 1
const int capteur1 = 8;
boolean place1 = false;

//constantes pour le capteur 2
const int capteur2 = 9;
boolean place2 = false;

//constantes pour le capteur 3
const int capteur3 = 10;
boolean place3 = false;

//constantes pour le capteur 4
const int capteur4 = 11;
boolean place4 = false;

const int placestotales = 4;
int placesdisponibles = placestotales;

//initialisation des LEDs
Adafruit_NeoPixel LED = Adafruit_NeoPixel(placestotales, 6, NEO_GRB + NEO_KHZ800);

//initialisation de l'écran
LiquidCrystal_I2C lcd(0x26, 16, 2);

void setup() {
  pinMode(capteur1, INPUT);
  pinMode(capteur2, INPUT);
  pinMode(capteur3, INPUT);
  pinMode(capteur4, INPUT);

  LED.begin();
  
  Serial.begin(9600);

  //vérification du fonctionnement des LEDs
  for(int i = 0; i < 8; i++ ) {LED.setPixelColor(i, 223, 0, 0);}
  LED.show(); //on affiche la couleur rouge
  delay(1000);
  for(int i = 0; i < 8; i++ ) {LED.setPixelColor(i, 0, 223, 0);}
  LED.show(); //on affiche la couleur verte
  delay(1000);
  for(int i = 0; i < 8; i++ ) {LED.setPixelColor(i, 0, 0, 223);}
  LED.show(); //on affiche la couleur bleue
  delay(1000);

  //initialisation de l'écran
  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void foncplace1() {
  if (digitalRead(capteur1) == HIGH) {
    place1 = false;
  }
  else {
    place1 = true;
  }
}

void foncplace2() {
  if (digitalRead(capteur2) == HIGH) {
    place2 = false;
  }
  else {
    place2 = true;
  }
}

void foncplace3() {
  if (digitalRead(capteur3) == HIGH) {
    place3 = false;
  }
  else {
    place3 = true;
  }
}

void foncplace4() {
  if (digitalRead(capteur4) == HIGH) {
    place4 = false;
  }
  else {
    place4 = true;
  }
}

void foncplacesdisponibles() {
  boolean place[placestotales] {0};
  place[0] = place1;
  place[1] = place2;
  place[2] = place3;
  place[3] = place4;

  placesdisponibles = placestotales;
  for (int i=0; i<placestotales; i++) {
    if (place[i] == true) {
      placesdisponibles -= 1;
    }
  }
}

void foncLED() {
  boolean place[placestotales] {0};
  place[0] = place1;
  place[1] = place2;
  place[2] = place3;
  place[3] = place4;
  
  for (int i=0; i<placestotales; i++){
    if (place[i] == true) {
      LED.setPixelColor(i, 223, 0, 0);
      }
    LED.show();
    
    if (place[i] == false) {
      LED.setPixelColor(i, 0, 223, 0);
      }
    LED.show();
  }
}

void loop() {
  foncplace1();
  foncplace2();
  foncplace3();
  foncplace4();
  foncplacesdisponibles();
  foncLED();

  /**
  Serial.print("Nombre de places disponibles : ");
  Serial.println(placesdisponibles);
  **/

  lcd.setCursor(0,0);
  lcd.print("Nombre de places");
  lcd.setCursor(7,1);
  lcd.print(placesdisponibles);
}
