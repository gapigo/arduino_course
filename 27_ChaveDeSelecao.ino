// Circuito: https://www.tinkercad.com/things/fx1jkvr9ss9-27-chave-de-selecao

#define LED_VD 8
#define LED_VM 7

#define SW_D 3
#define SW_E 2

int ledSelecionado;
void setup() {
	pinMode(LED_VM, OUTPUT);
  	pinMode(LED_VD, OUTPUT);
  
    pinMode(SW_D, INPUT);
    pinMode(SW_E, INPUT);
}

void loop() {
  if ( digitalRead(SW_D) ) {
    ledSelecionado = LED_VD;
  }
  if ( digitalRead(SW_E) ) {
    ledSelecionado = LED_VM;
  }
  
  digitalWrite(ledSelecionado, HIGH);
  delay(500);
  
  digitalWrite(ledSelecionado, LOW);
  delay(500);
}