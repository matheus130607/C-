// Controle de Brilho (PWM): Usar um pino com capacidade PWM (Pulse
// Width Modulation) para controlar a intensidade do brilho de um LED,
// fazendo-o ir do mais fraco ao mais forte gradualmente.


int pinoPotenciometro = A0;
int pinoLED = 13;

void setup() {

  pinMode(pinoLED, OUTPUT);

}

 

void loop() {

  int leitura = analogRead(pinoPotenciometro);
  int brilho = map(leitura, 0, 1023, 0, 255);
  analogWrite(pinoLED, brilho);
  delay(10);

}