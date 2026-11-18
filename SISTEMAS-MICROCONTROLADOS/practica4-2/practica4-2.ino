int led =3;
int potenciometro =A0;
float senal;
int brillo;


void setup() {
  pinMode(led, OUTPUT);
  pinMode(potenciometro,INPUT);

}

void loop() {
 senal=analogRead(potenciometro);
 brillo=map(senal, 0, 1023, 0 , 255);
 analogWrite(led, brillo);

}
