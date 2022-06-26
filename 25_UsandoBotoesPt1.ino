// Circuito: https://www.tinkercad.com/things/4iOhp9v7Ges-25-usando-botoes-parte-1/editel

#define LED 7
#define BTN 2

int btnEstado;

void setup() {
	pinMode(LED, OUTPUT);
  	pinMode(BTN, INPUT);
}

void loop() {
	btnEstado = digitalRead(BTN);
  	if (btnEstado == 1) {
    	digitalWrite(LED, HIGH);
    } else {
      	digitalWrite(LED, LOW);
    }
}
