void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);// vermelho
  pinMode(8, OUTPUT);// amarelo
  pinMode(11, OUTPUT);// verde
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000);
  digitalWrite(8, HIGH);
  delay(500);
  digitalWrite(8, LOW);
  delay(500);
  digitalWrite(11,HIGH);
  delay(1000);
  digitalWrite(11, LOW);
  delay(1000);
}
