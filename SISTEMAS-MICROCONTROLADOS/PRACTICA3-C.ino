const int pinLM35 = A1;
void setup() {
  Serial.begin(9600);
}
void loop() {
  long suma = 0;
  for (int i = 0; i < 10; i++) {
    suma += analogRead(pinLM35);
    delay(10);
  }
  float promedioADC = suma / 10.0;
  float voltaje = (promedioADC / 1023.0) * 5.0;
  float temperatura = voltaje / 0.01;

  Serial.print("ADC promedio: ");
  Serial.print(promedioADC);
  Serial.print(" | T: ");
  Serial.print(temperatura);
  Serial.println(" °C");

  delay(1000);
}
