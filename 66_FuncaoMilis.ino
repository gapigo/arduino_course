#define LED1 2
#define LED2 3
#define LED3 5

int led1Estado = 0;
int led2Estado = 0;
int led3Estado = 0;

int led1TempoAnterior = 0;
int led2TempoAnterior = 0;

int estadoBtn = 0;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(4, INPUT_PULLUP);
  
  Serial.begin(9600);
}

void loop() {
  /*
  digitalWrite(LED1, HIGH);
  delay(1000);
  digitalWrite(LED1, LOW);
  delay(1000);
  
  // 2 segundos depois...
  */
  
  /*
  Serial.println(millis());
  delay(1000);
  */
  
  if (millis() - led1TempoAnterior >= 250) {
    led1TempoAnterior = millis();
    led1Estado = !led1Estado;
    digitalWrite(LED1, led1Estado);
  }
  
  if (millis() - led2TempoAnterior >= 1000) {
    led2TempoAnterior = millis();
    led2Estado = !led2Estado;
    digitalWrite(LED2, led2Estado);
  }
  
  if (digitalRead(4) != estadoBtn && estadoBtn == 1) {
    led3Estado = !led3Estado;
    digitalWrite(LED3, led3Estado);
  }
  estadoBtn = digitalRead(4);
  delay(1);
}