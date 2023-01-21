#include <LiquidCrystal_I2C.h>
#include <RTClib.h>
#include <Wire.h> //permet de discuter avec différents composants
#include <DHT.h>

//Initialisation du capteur infrarouges et de la led
#define OBS A1
#define LED 12
int avoid;

// Initialisation du module RTC
RTC_DS3231 rtc;

// Initialisation de l'écran LCD sur l'adresse 0x27
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Initialisation du capteur DHT22
DHT dht(2, DHT22);

byte degre[8] = {
0b01100,0b10010,0b10010,0b01100,0b00000,0b00000,0b00000,0b00000
};

//module qui permet de changer l'affichage de l'écran à des intervalles de temps
unsigned long mymillis;
boolean EC1 = true;
boolean EC2 = false;
boolean EC = false;

// Fonction setup, appelée une seule fois au démarrage
void setup () {
  // Initialisation du module RTC
  rtc.begin();
  
  // Vérification de l'alimentation de la RTC
  if (rtc.lostPower()) {
    // Si l'alimentation a été perdue, réglage de l'heure
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  // Initialisation de l'écran LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.createChar(1, degre);

  // Initialisation du détecteur d'obstacles et de la led
  pinMode(OBS, INPUT);
  pinMode(LED, OUTPUT);
}

// Fonction loop, appelée en boucle
void loop () {
  // Récupération de l'heure courante
  DateTime now = rtc.now();
  
  // Affichage de l'heure sur l'écran LCD
  printDateTime(now);
  
  //délais qui laisse le temps au capteur de récupéré la température et l'humidté
  delay(1000);

  temphum(); //appel de la fonction qui affiche température/humidité
  capteur(); //appel de la fonction qui allume led si détectée

}

//Fonction qui affiche la température et l'heure
void temphum(){
  // Récupération de l'humidité
  byte h = dht.readHumidity();
  // Récupération de la température
  byte t = dht.readTemperature();

  // Affichage de la température
  if (EC1 == true && EC == false) {
    lcd.setCursor(0,1);
    lcd.print("Temperature: ");
    lcd.print(t);
    lcd.print(char(1));
    
    // Mise à jour des variables pour éviter les répétitions
    EC = true;
    mymillis = millis();
  }
  
  // Affichage de l'humidité
  if (EC2 == true && EC == false) {
    lcd.setCursor(0,1);
    lcd.print(" Humidite: ");
    lcd.print(h);
    lcd.print("%   ");

    // Mise à jour des variables pour éviter les répétitions
    EC = true;
    mymillis = millis();
  }

  // Changement d'interface toutes les 3 secondes
  if (millis() - mymillis >= 3000) { 
    EC1 = !EC1;
    EC2 = !EC2;
    EC = false;
  }
}

//fonction qui affiche la date et l'heure
void printDateTime(DateTime dt) {
  char dateBuffer[] = "DD/MM/YYYY hh:mm";

  lcd.setCursor(0,0);
  lcd.print(dt.toString(dateBuffer));
}

//Fonction qui allume une led via le capteur infrarouges
void capteur(){
  avoid = digitalRead(OBS); //lecture de l'état du capteur
  if (avoid == HIGH) { digitalWrite(LED, LOW); } //led allumée
  else { digitalWrite(LED, HIGH); } //led éteinte
}
