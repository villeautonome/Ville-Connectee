int DIN_pin = 11; // déclaration de la broche de données
int CS_pin = 10; // déclaration de la broche de sélection de circuit
int CLK_pin = 12; // déclaration de la broche d'horloge

// Définition de matrices pour l'affichage de chiffres
int C1[8] = {0x00, 0x10, 0x30, 0x10, 0x10, 0x10, 0x10, 0x7C}; //afficher le chiffre 1
int C2[8] = {0x00, 0x38, 0x44, 0x04, 0x08, 0x10, 0x20, 0x7C}; //afficher le chiffre 2
int C3[8] = {0x00, 0x7C, 0x08, 0x10, 0x08, 0x04, 0x44, 0x38}; //afficher le chiffre 3
int C4[8] = {0x00, 0x08, 0x18, 0x28, 0x48, 0x7C, 0x08, 0x08}; //afficher le chiffre 4

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

void setup(){
  pinMode(CS_pin, OUTPUT);
  pinMode(DIN_pin, OUTPUT);
  pinMode(CLK_pin, OUTPUT);
  delay(50);
  init_MAX7219();
  clear_matrix();
}

void loop(){
  write_matrix(C1);
  delay(1000);
  write_matrix(C2);
  delay(1000);
  write_matrix(C3);
  delay(1000);
  write_matrix(C4);
  delay(1000);
}
