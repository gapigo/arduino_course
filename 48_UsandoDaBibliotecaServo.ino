#include <Servo.h>

Servo servo2;

void setup() {
  // Pino, ajuste1, ajuste2 (para não ficar torto os angulos)
  servo2.attach(2, 500, 2600);
  pinMode(A0, INPUT);
  
  servo2.write(0);
  delay(1000);
  
  servo2.write(90);
  delay(1000);
  
  servo2.write(180);
  delay(1000);

}

void loop() {
  int pot = analogRead(A0);
  // map(param a ser convertido, a0, a1, b0, b1)
  int angulo = map(pot, 0, 1023, 0, 180);
  servo2.write(angulo);
  delay(1000);
}
