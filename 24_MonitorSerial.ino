//Circuit: https://www.tinkercad.com/things/jG3vHOgUyJ1-24-monitor-serial

int contagem = 0;

void setup() {
  Serial.begin(9600);
  
  Serial.println("Ola mundo");
  
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH);
  Serial.println("Aceso");
  delay(1000);
  
  digitalWrite(13, LOW);
  Serial.println("Apagado");
  delay(1000);
  
  Serial.println(contagem);
  contagem++;
}
