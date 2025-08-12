void setup() {

pinMode(13, OUTPUT);//Luz Verde
pinMode(12, OUTPUT);// Luz Amarela
pinMode(11, OUTPUT);// Luz Vermelha
}

void loop() {// Deixa em loop 

  digitalWrite (13, HIGH);// Ascende a luz verde
  delay(2000);// Mantem ela ligada
  digitalWrite (13, LOW);// Desliga a luz
  delay(1);// Mantem ela desligada

  digitalWrite (12, HIGH);// Ascende a luz Amarela
  delay(1500);// Mantem ela ligada
  digitalWrite (12, LOW);// Desliga a luz
  delay(1);// Mantem ela desligada

   digitalWrite (11, HIGH);// Ascende a luz Vermelha
  delay(750);// Mantem ela desligada
  digitalWrite (11, LOW);//Desliga a luz
  delay(1);// Mantem ela desligada

}
