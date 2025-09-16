int pinoPIR = 7;     // Pino do sensor PIR
int pinoLED = 8;     // Pino do LED
int estadoPIR = 0;   // Estado atual do sensor
int contador = 0;    // Contador de pessoas

void setup() {
  pinMode(pinoPIR, INPUT);
  pinMode(pinoLED, OUTPUT);
  Serial.begin(9600);
  Serial.println("Sistema iniciado...");
}

void loop() {
  estadoPIR = digitalRead(pinoPIR);

  if (estadoPIR == HIGH) { // Se detectar movimento
    digitalWrite(pinoLED, HIGH); // Liga o LED
    delay(1000);
    digitalWrite(pinoLED, LOW);
    contador++;
    Serial.print("Pessoa detectada! Contagem: ");
    Serial.println(contador);

    delay(1000); // Espera para não contar a mesma pessoa várias vezes
  } else {
    digitalWrite(pinoLED, LOW); // Desliga o LED se não houver movimento
  }
}
