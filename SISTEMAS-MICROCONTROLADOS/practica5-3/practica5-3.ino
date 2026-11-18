
const int BTN_INT = 2;   // interrupción
const int BTN_POLL = 4;  // polling
const int LED_INT = 8;
const int LED_POLL = 9;

volatile int cntInt = 0;
int cntPoll = 0;

void ISR_boton() { cntInt++; }

void setup() {
  pinMode(BTN_INT, INPUT_PULLUP);
  pinMode(BTN_POLL, INPUT_PULLUP);
  pinMode(LED_INT, OUTPUT);
  pinMode(LED_POLL, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(BTN_INT), ISR_boton, FALLING);
  Serial.begin(9600);
}

void loop() {
  // Polling: solo detecta si el botón está presionado en este instante
  if (digitalRead(BTN_POLL) == LOW) {
    cntPoll++;
    digitalWrite(LED_POLL, HIGH);
    delay(200);   
    digitalWrite(LED_POLL, LOW);
  }

  digitalWrite(LED_INT, cntInt % 2);
  Serial.print("INT: "); Serial.print(cntInt);
  Serial.print("  POLL: "); Serial.println(cntPoll);
  delay(100);
}
