#define BOTON_PIN 2

void setup() {
    Serial.begin(9600);  // Iniciar comunicación serial
    pinMode(BOTON_PIN, INPUT);
    Serial.println("Práctica 1 - Microcontroladores");
}

void loop() {
    int estado = digitalRead(BOTON_PIN);

    if (estado == 1) {
        Serial.println("Estado del botón: ENCENDIDO");
    } else {
        Serial.println("Estado del botón: APAGADO");
    }

    delay(500);
}