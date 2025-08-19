// 9. LED RGB - Mistura de Cores: Usar um único LED RGB (que na verdade
// são três LEDs - vermelho, verde e azul - em um só) para criar qualquer
// cor do espectro, variando a intensidade de cada uma das três cores
// básicas com PWM.


void setup() {
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  setColor(0, 0, 0);
}

void loop() {
  setColor(255, 0, 0); delay(500); 
  setColor(0, 255, 0); delay(500); 
  setColor(0, 0, 255); delay(500); 
}

void setColor(uint8_t r, uint8_t g, uint8_t b) {
  analogWrite(9, r);
  analogWrite(10, g);
  analogWrite(11, b);
}