// Circuito: https://www.tinkercad.com/things/dqPla3ox6bf-iniciar-tarefa-1-mini-semaforo

int ledVermelho = 11;
int ledAmarelo = 12;
int ledVerde = 13;

void setup() {
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
}

void loop() {
  // Manter acesso led verde
  digitalWrite(ledVerde, HIGH);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVermelho, LOW);
  delay(5000);
  
  // Manter acesso led amarelo
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAmarelo, HIGH);
  digitalWrite(ledVermelho, LOW);
  delay(2000);
  
  // Manter acesso led vermelho
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVermelho, HIGH);
  delay(5000);
}

