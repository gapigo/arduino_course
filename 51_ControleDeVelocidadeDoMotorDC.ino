#define MOTOR 3

void setup() {
  pinMode(MOTOR, OUTPUT);
  pinMode(A0, INPUT);

}

void loop() {
  int pot = analogRead(A0);
  int vel = map(pot, 0, 1023, 0, 255);
  analogWrite(MOTOR, vel);

}