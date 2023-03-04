#include <Adafruit_NeoPixel.h>

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
Adafruit_NeoPixel LED = Adafruit_NeoPixel(placestotales, 2, NEO_GRB + NEO_KHZ800);

//initialisation de la matrice de led

int DIN_pin = 6; // déclaration de la broche de données
int CS_pin = 5; // déclaration de la broche de sélection de circuit
int CLK_pin = 7; // déclaration de la broche d'horloge

// Définition de matrices pour l'affichage de chiffres
int C1[8] = {0x00, 0x80, 0x84, 0xFE, 0x80, 0x80, 0x00, 0x00}; //afficher le chiffre 1
int C2[8] = {0x00, 0x84, 0xC2, 0xA2, 0x92, 0x8C, 0x00, 0x00}; //afficher le chiffre 2
int C3[8] = {0x00, 0x42, 0x82, 0x8A, 0x96, 0x62, 0x00, 0x00}; //afficher le chiffre 3
int C4[8] = {0x00, 0x30, 0x28, 0x24, 0xFE, 0x20, 0x00, 0x00}; //afficher le chiffre 4


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

  pinMode(CS_pin, OUTPUT);
  pinMode(DIN_pin, OUTPUT);
  pinMode(CLK_pin, OUTPUT);
  delay(50);
  init_MAX7219();
  clear_matrix();
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

// Fonction pour écrire un octet de données sur la matrice LED
void write_pix(int data){
  digitalWrite(CS_pin, LOW); // sélection du circuit MAX7219
  for (int i = 0; i < 8; i++){
      digitalWrite(CLK_pin, LOW); // mettre l'horloge à basse fréquence
      digitalWrite(DIN_pin, data & 0x80); // écriture de la donnée dans la broche de données en masquant les bits non utilisés
      data = data << 1; // décalage des bits vers la gauche pour traiter les bits suivants
      digitalWrite(CLK_pin, HIGH); // mise à haute fréquence de l'horloge
  }
}

// Fonction pour écrire une ligne de données sur la matrice LED
void write_line(int adress, int data){
  digitalWrite(CS_pin, LOW); // sélection du circuit MAX7219
  write_pix(adress); // envoi de l'adresse de la ligne à écrire
  write_pix(data); // envoi des données à écrire sur la ligne
  digitalWrite(CS_pin, HIGH); // désélection du circuit MAX7219
}

// Fonction pour écrire un tableau de données sur la matrice LED
void write_matrix(int *tab){
  for (int i = 0; i < 8; i++) write_line(i + 1, tab[i]); // écriture de chaque ligne du tableau
}

// Fonction d'initialisation du circuit MAX7219
void init_MAX7219(void){
  write_line(0x09, 0x00); // décoding BCD
  write_line(0X0A, 0x01); // réglage de la luminosité
  write_line(0X0B, 0x07); // activation de l'affichage des 8 LEDs
  write_line(0X0C, 0x01); // mode normal du circuit MAX7219
  write_line(0X0F, 0x00); // réinitialisation du circuit MAX7219
}

// Fonction pour effacer la matrice LED
void clear_matrix(void){
  const int clean[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  write_matrix(clean);
}

// fonction pour convertir un entier en octet qui représente l'état d'une LED sur la matrice LED
int intToHex(int x) {
  switch (x)
  {
  case 0: return 0x01; break; //LED sur la première case
  case 1: return 0x02; break; //LED sur la 2ème case
  case 2: return 0x04; break; //LED sur la 3ème case
  case 3: return 0x08; break; //LED sur la 4ème case
  case 4: return 0x10; break; //LED sur la 5ème case
  case 5: return 0x20; break; //LED sur la 6ème case
  case 6: return 0x40; break; //LED sur la 7ème case
  case 7: return 0x80; break; //LED sur la 8ème case
  }
}

void complet(){
  int full[8] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}; //allume toutes les led de la matrice
  write_matrix(full);
  delay(500);
  clear_matrix();
  delay(500);
}

void loop() {
  foncplace1();
  foncplace2();
  foncplace3();
  foncplace4();
  foncplacesdisponibles();
  foncLED();

  if (placesdisponibles==0){
    complet();
  }
  if (placesdisponibles==1){
    write_matrix(C1);
  }
  if (placesdisponibles==2){
    write_matrix(C2);
  }
  if (placesdisponibles==3){
    write_matrix(C3);
  }
  if (placesdisponibles==4){
    write_matrix(C4);
  }
}
