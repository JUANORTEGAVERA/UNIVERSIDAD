#include <TimerOne.h>   // instalar librería TimerOne

volatile bool flag = false;
const int LED = 8;

void ISR_timer() {
  flag = true;       // solo marca la bandera
}

void setup() {
  pinMode(LED, OUTPUT);
  Timer1.initialize(1000000);   // 1 segundo (1,000,000 µs)
  Timer1.attachInterrupt(ISR_timer);
}

void loop() {
  if (flag) {
    flag = false;
    digitalWrite(LED, !digitalRead(LED));
  }
  // aquí puede ejecutarse otra tarea sin bloqueo
}
