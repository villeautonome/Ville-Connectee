int lampadaire = 2;
int sensorValue;
float sensorValue_f;
float ValeurLum;

void setup() {
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  digitalWrite(2,LOW);
}

void loop() {
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
