// Efeito "Carro Fantástico" (KITT): Simular a famosa luz do carro da série
// de TV. Uma luz "corre" de um lado para o outro em uma barra de LEDs.

int leds[4] = {13, 12, 11, 10};

void setup() {
  
  for(int i = 0; i < 4; i++){
    pinMode(leds[i], OUTPUT);
  }
  
}

void loop() {
 for(int j = 0; j < 4; j++) {
  digitalWrite(leds[j], HIGH);
  delay(100);
  digitalWrite(leds[j], LOW);
  delay(100);
 }
 for(int j = 4;j > 0; j--) {
  digitalWrite(leds[j], HIGH);
  delay(100);
  digitalWrite(leds[j], LOW);
  delay(100);
 }
 
}