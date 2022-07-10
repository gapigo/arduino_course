#define BUZ 3
#define BTN1 A1
#define BTN2 A2
#define BTN3 A3

void setup() {
  pinMode(BUZ, OUTPUT);
  pinMode(BTN1, INPUT);
  pinMode(BTN2, INPUT);
  pinMode(BTN3, INPUT);

  digitalWrite(BUZ, LOW);
  delay(1000);
  digitalWrite(BUZ, HIGH);
}

void loop() {

    if ( digitalRead(BTN1) == 0 ) {
      analogWrite(BUZ, 0);
      delay(1000);
      analogWrite(BUZ, 255);
    }
    
    if ( digitalRead(BTN2) == 0 ) {
      analogWrite(BUZ, 100);
      delay(1000);
      analogWrite(BUZ, 255);
    }
    
    if ( digitalRead(BTN3) == 0 ) {
      analogWrite(BUZ, 200);
      delay(1000);
      analogWrite(BUZ, 255);
    }
}