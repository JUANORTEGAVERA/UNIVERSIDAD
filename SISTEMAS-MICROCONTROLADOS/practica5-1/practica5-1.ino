const int BOTON = 2;        // INT0
const int LED = 8;

volatile int contador = 0;  // variable compartida con la ISR

void ISR_boton() {
  contador++;               // solo incrementa, muy corto
}

void setup() {
  pinMode(BOTON, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(BOTON), ISR_boton, FALLING);
  Serial.begin(9600);
}

void loop() {
  // El programa principal sigue ejecutándose sin bloquearse
  digitalWrite(LED, !digitalRead(LED));
  Serial.print("Pulsaciones: ");
  Serial.println(contador);
  delay(500);               // el LED parpadea cada 500 ms
}
