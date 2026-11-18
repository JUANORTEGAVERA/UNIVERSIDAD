
int motor = 6;
int pulsador1 = 3;
int pulsador2 = 4;
int pulsacion1;
int pulsacion2;
int velocidad = 0;

void setup() {
  pinMode(motor, OUTPUT);
  pinMode(pulsador1, INPUT_PULLUP);
  pinMode(pulsador2, INPUT_PULLUP);
}

void loop() {

  pulsacion1 = digitalRead(pulsador1);
  pulsacion2 = digitalRead(pulsador2);

  if (pulsacion1 == LOW) {
    velocidad = velocidad + 25;

    if (velocidad > 255) {
      velocidad = 255;
    }

    delay(200);
  }

  if (pulsacion2 == LOW) {
    velocidad = velocidad - 25;

    if (velocidad < 0) {
      velocidad = 0;
    }

    delay(200);
  }

  analogWrite(motor, velocidad);
}
