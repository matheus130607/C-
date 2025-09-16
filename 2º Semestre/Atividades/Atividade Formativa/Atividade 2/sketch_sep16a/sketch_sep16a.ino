Atividade 1:


//Biblioteca do DTH
#include "DHT.h"
//armazena o valor flutuante de temperatura
float temperatura;
//porta usada e o tipo de sensor
DHT dht(3, DHT11);

void setup() {
Serial.begin(9600);// inicializando o monitor serial
dht.begin();// Inicializando o sensor
pinMode(13,OUTPUT);
pinMode(12,OUTPUT);
pinMode(11,OUTPUT); 
}

void loop() {
delay(2000);// Aguarda dois segundos entre as leituras
temperatura = dht.readTemperature();//Lê o valor da temperatura em C°

//Verificando se existe erro na leitura da temperatura
if (isnan(temperatura)) { Serial.println("ERRO NO SENSOR!");}

//Se tudo funcionar envia a temperatura para a serial
else {Serial.println(temperatura);}

if (temperatura <=24) {
  digitalWrite(13, HIGH);

} else if (temperatura  >=25 &&  temperatura <=30){
  digitalWrite(12,HIGH);

}  else if (temperatura >=31){
  digitalWrite(11,HIGH);

} else {
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
}
}

