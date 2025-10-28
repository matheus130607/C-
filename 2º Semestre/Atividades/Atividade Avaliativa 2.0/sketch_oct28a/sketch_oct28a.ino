#include <Wire.h>
#include <LiquidCrystal.h>
#include <DHT.h>

// Define os pinos dos LEDs
const int led1pin = 7; // led Verde
const int led2pin = 8; // led Amarelo
const int led3pin = 9; // led Vermelho

// Define o sensor DHT
#define DHTPIN 13
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
float temperatura;

// Controle de tempo
const long intervaloDeLeitura = 2000;


void setup() {
  lcd.begin(16, 2);
  dht.begin();
  Serial.begin(9600);

  pinMode(led1pin, OUTPUT);
  pinMode(led2pin, OUTPUT);
  pinMode(led3pin, OUTPUT);

  lcd.setCursor(0, 0);
  lcd.print("Sistema Iniciado");
  delay(2000);
  lcd.clear();
}

void loop() {
    float temperatura = dht.readTemperature();

    if (isnan(temperatura)) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Erro na leitura");
      return;
    }
    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("temp:  ");
    lcd.setCursor(5,0);
    lcd.print(temperatura);
    lcd.setCursor(10,0);
    lcd.print("C");

    
    // Controle de LEDs
    if (temperatura <= 26) {
      digitalWrite(led1pin, HIGH);
      digitalWrite(led2pin, LOW);
      digitalWrite(led3pin, LOW);
    } else if (temperatura == 27) {
      digitalWrite(led1pin, LOW);
      digitalWrite(led2pin, HIGH);
      digitalWrite(led3pin, LOW);
    } else {
      digitalWrite(led1pin, LOW);
      digitalWrite(led2pin, LOW);
      digitalWrite(led3pin, HIGH);
    }

    Serial.print("Temperatura: ");
    Serial.print(temperatura);
    Serial.println(" °C");

    // Envia o valor puro para o Flask
    Serial.println(temperatura);
  }

