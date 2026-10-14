// Práctica 1: Parpadeo de LED
// Nombre: ____Juan Ortega Y Astrid Cabrera________________
// Fecha: ______13/10/2026_________________

#define LED_PIN 13
void setup() {
    pinMode(LED_PIN, OUTPUT);  // Configurar pin como salida
}

void loop() {
    digitalWrite(LED_PIN, HIGH);  // Encender LED
    delay(250);                  // Esperar 1 segundo
       digitalWrite(LED_PIN, LOW);   // Apagar LED
    delay(100);  
}
