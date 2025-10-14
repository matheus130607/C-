//Define os pinos para os LEDs
const int led1pin = 7; // led Verde
const int led2pin = 8; // led Vermelho

void setup() {
  //Inicia a comunicação serial com a mesma velocidade do Python
  Serial.begin(9600);

  //Define os pinos LEDs como saída
  pinMode(led1pin, OUTPUT);
  pinMode(led2pin, OUTPUT);
}

void loop() {
 //Verifica se há algum dados disponivel para ser lidp na porta serial
 if (Serial.available() > 0) {
  //Lê o caractere recebido
  char command = Serial.read();

  //Executa a ação baseada no comando
  switch (command) {
    case 'A':
    digitalWrite(led1pin, HIGH); //Liga o LED 1
    break;
    case 'a':
    digitalWrite(led1pin, LOW); //Desliga o LED 1
    break;
    case 'B':
    digitalWrite(led2pin, HIGH); //Liga o LED 2
    break;
    case 'b':
    digitalWrite(led2pin, LOW); //Desliga o LED 2
    break;
  }
 }
}
