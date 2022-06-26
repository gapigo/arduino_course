//Circuit: https://www.tinkercad.com/things/e4p41wjEU4A-23-sinaleira-com-leds

#define ESPERA	500

int ledVermelho = 8;
int ledAmarelo = 7;

void setup() {
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
}

void loop() {
  digitalWrite(ledVermelho, HIGH);
  digitalWrite(ledAmarelo, LOW);
  delay(ESPERA);
  
  digitalWrite(ledVermelho, LOW);
  digitalWrite(ledAmarelo, HIGH);
  delay(ESPERA);
}