#define LED 3
#define LED2 5


void setup() {
  pinMode(LED, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(A0, INPUT);
}

void loop() {
  int pot = analogRead(A0);
  int intensidade = map(pot, 0, 1023, 0, 255);
  
  analogWrite(LED, intensidade);
  
  for (int i = 0; i <= 255; i += 5) {
    analogWrite(LED2, i);
    delay(30);
  }
  
  for (int i = 255; i >= 0; i -= 5) {
    analogWrite(LED2, i);
    delay(30);
  }
}