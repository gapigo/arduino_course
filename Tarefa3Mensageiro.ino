// Circuit: https://www.tinkercad.com/things/hDPyqsc6MCw-tarefa-3-mensageiro

#include <LiquidCrystal.h>
#define BTNEsq 2
#define BTNCim 3
#define BTNDir 4
#define BTNBai 5

// LiquidCrystal lcd(RS, E (enable), pinos de dados);
// LiquidCrystal lcd(RS, E, D4, D5, D6, D7);
LiquidCrystal lcd(6, 7, 8, 9, 10, 11);

int coluna = 0;
int linha = 0;
int caractere_atual;
char letras[32];

void setup() {
  pinMode(BTNEsq, INPUT_PULLUP);
  pinMode(BTNCim, INPUT_PULLUP);
  pinMode(BTNDir, INPUT_PULLUP);
  pinMode(BTNBai, INPUT_PULLUP);
  lcd.begin(16, 2);
  for (int i = 0; i < 32; i++) {
    letras[i] = 32;
  }
}

int getPosicaoAtual() {
  if (linha) return coluna + 15;
  return coluna;
}

char getCaractereAtual() {
  int index = getPosicaoAtual();
  return letras[index];
}

char setCaractereAtual(char caractere) {
  int index = getPosicaoAtual();
  letras[index] = caractere;
  return letras[index];
}

void loop() {
  if (!digitalRead(BTNEsq)) {
    if (coluna > 0) lcd.setCursor(--coluna, linha);
    else if (linha == 1) {
      lcd.setCursor(coluna = 15, --linha); 
      //coluna = 15;
    }
    //while(!digitalRead(BTNEsq));
  }
  
  if (!digitalRead(BTNCim)) {
    if (getCaractereAtual() == 32) 
      lcd.write(setCaractereAtual(65));
    else if (getCaractereAtual() < 90) 
      lcd.write(setCaractereAtual(getCaractereAtual()+1));
    lcd.setCursor(coluna, linha);
    //while(!digitalRead(BTNCim));
  }
  
  if (!digitalRead(BTNDir)) {
    if (coluna < 15) lcd.setCursor(++coluna, linha);
    else if (linha == 0) {
      lcd.setCursor(0, ++linha); 
      coluna = 0;
    }
    //while(!digitalRead(BTNDir));
  }
  
  if (!digitalRead(BTNBai)) {
    if (getCaractereAtual() == 65) 
      lcd.write(setCaractereAtual(32));
    else if (getCaractereAtual() != 32)
      lcd.write(setCaractereAtual(getCaractereAtual()-1));
    lcd.setCursor(coluna, linha);
    //while(!digitalRead(BTNBai));
  }
  lcd.blink();
  delay(200);
}
