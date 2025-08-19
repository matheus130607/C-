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
    }
}