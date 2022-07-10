int duty = 0;
int dutyMax = 100;
  

void setup() {
  pinMode(2, OUTPUT);
  pinMode(A0, INPUT);
}

void loop() {
  int pot = analogRead(A0);
  duty = map(pot, 0, 1023, 0, dutyMax);
  
  digitalWrite(2, HIGH);
  delay(duty);
  digitalWrite(2, LOW);
  delay(dutyMax - duty);
}