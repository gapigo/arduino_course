#define LED1 10
#define LED2 11
#define LED3 12
#define LED4 13

int vel;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  
  pinMode(A0, INPUT);

  Serial.begin(9600);
}

void loop() {
  vel = analogRead(A0);
  Serial.println(vel);

  digitalWrite(LED1, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED4, HIGH);
  delay(vel);
  
  digitalWrite(LED2, LOW);
  digitalWrite(LED4, LOW);
  digitalWrite(LED1, HIGH);
  digitalWrite(LED3, HIGH);
  delay(vel);
}