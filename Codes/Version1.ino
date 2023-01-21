//Code écrit par Célia Roess

#include <NewPing.h>
#include <Adafruit_NeoPixel.h>
#include <LiquidCrystal_I2C.h>

//initialisation pour le lampadaire
int lampadaire = 2;
int sensorValue;
float sensorValue_f;
float ValeurLum;

//initialisation des constantes pour la place n°1
const int trig1 = 9;
const int echo1 = 8;
float distance1 = 0;
unsigned int lecture_echo1 = 0;
float lecture_echo_f1 = 0;
boolean place1 = false;
NewPing sonar1(trig1,echo1,100);

//initialisation des constantes pour la place n°2
const int trig2 = 12;
const int echo2 = 11;
float distance2 = 0;
unsigned int lecture_echo2 = 0;
float lecture_echo_f2 = 0;
boolean place2 = false;
NewPing sonar2(trig2,echo2,100);

const int placestotales = 2;
int placesdisponibles = placestotales;

//initialisation des LEDs
Adafruit_NeoPixel LED = Adafruit_NeoPixel(placestotales, 6, NEO_GRB + NEO_KHZ800);

//initialisation de l'écran
LiquidCrystal_I2C lcd(0x27, 16, 2);



void setup() {
  Serial.begin(9600);
  LED.begin();

  //initialisation lampadaire
  pinMode(2,OUTPUT);
  digitalWrite(2,LOW);

  //initialisation pour la place n°1
  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);
  //pinMode(vert1, OUTPUT);
  //pinMode(rouge1, OUTPUT);

  //initialisation pour la place n°2
  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);
  //pinMode(vert2, OUTPUT);
  //pinMode(rouge2, OUTPUT);

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

void fonclamp() {
  sensorValue = analogRead(A0); //lecture de la valeur numérique
  sensorValue_f = sensorValue;
  ValeurLum = (sensorValue_f*5)/1023;

  Serial.println(ValeurLum);
  
  if (ValeurLum > 4) {
    digitalWrite(lampadaire,LOW);
  }
  else {
    digitalWrite(lampadaire,HIGH);
  }
}

void foncplace1() {
  digitalWrite(trig1, HIGH); // génération de l'impulsion Trig de 10 µs
  delayMicroseconds(10);
  digitalWrite(trig1, LOW);
  lecture_echo1 = pulseIn(echo1, HIGH); // lecture de la durée de Echo en µs  
  
  lecture_echo_f1=lecture_echo1;
  distance1=(lecture_echo_f1/1000)*17;

  //distance1 = sonar1.ping_cm();

  if (distance1 < 8 and distance1 != 0) {
    //digitalWrite(vert1, HIGH);
    //digitalWrite(rouge1, LOW);
    place1 = true;
  }
  else {
    //digitalWrite(vert1,LOW);
    //digitalWrite(rouge1,HIGH);
    place1 = false;
  }
}

void foncplace2() {
  digitalWrite(trig2, HIGH); // génération de l'impulsion Trig de 10 µs
  delayMicroseconds(10);
  digitalWrite(trig2, LOW);
  lecture_echo2 = pulseIn(echo2, HIGH); // lecture de la durée de Echo en µs  
  
  lecture_echo_f2=lecture_echo2;
  distance2=(lecture_echo_f2/1000)*17;

  //distance2 = sonar2.ping_cm();

  if (distance2 < 8 and distance2 != 0) {
    //digitalWrite(vert2, HIGH);
    //digitalWrite(rouge2, LOW);
    place2 = true;
  }
  else {
    //digitalWrite(vert2,LOW);
    //digitalWrite(rouge2,HIGH);
    place2 = false;
  }
}


void foncplacesdisponibles() {
  boolean place[placestotales] {0};
  place[0] = place1;
  place[1] = place2;

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
  fonclamp();
  foncplace1();
  foncplace2();
  foncplacesdisponibles();
  foncLED();

  lcd.setCursor(0,0);
  lcd.print("Nombre de places");
  lcd.setCursor(7,1);
  lcd.print(placesdisponibles);
}
