
const int BTN_INT = 2;   // Aumentar velocidad
const int BTN_POLL = 4;  // Disminuir velocidad
const int motor = 9;

volatile int cntInt = 0;
int velocidad = 0;

int estadoAnterior = HIGH;

void ISR_boton() {
  cntInt++;
}

void setup() {
  pinMode(BTN_INT, INPUT_PULLUP);
  pinMode(BTN_POLL, INPUT_PULLUP);
  pinMode(motor, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(BTN_INT), ISR_boton, FALLING);

  Serial.begin(9600);
}

void loop() {

  // Botón con interrupción: aumentar velocidad
  if (cntInt > 0) {
    noInterrupts();
    cntInt--;
    interrupts();

    velocidad = velocidad + 25;

    if (velocidad > 255) {
      velocidad = 255;
    }
  }

  // Botón con polling: disminuir velocidad
  int estadoActual = digitalRead(BTN_POLL);

  if (estadoActual == LOW && estadoAnterior == HIGH) {
    velocidad = velocidad - 25;

    if (velocidad < 0) {
      velocidad = 0;
    }
  }

  estadoAnterior = estadoActual;

  analogWrite(motor, velocidad);

  Serial.print("Velocidad: ");
  Serial.println(velocidad);

  delay(100);
}
