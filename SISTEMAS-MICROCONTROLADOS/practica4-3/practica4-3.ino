const int MOTOR = 6;    // pin PWM
const int POT = A0;

void setup() {
  pinMode(MOTOR, OUTPUT);
}

void loop() {
  int lectura = analogRead(POT);
  int velocidad = map(lectura, 0, 1023, 0, 255);
  analogWrite(MOTOR, velocidad);
  delay(50);
}
