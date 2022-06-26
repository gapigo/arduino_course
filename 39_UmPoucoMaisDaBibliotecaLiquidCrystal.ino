// Circuit: https://www.tinkercad.com/things/kh3D5UYXFU1-39-um-pouco-mais-da-biblioteca-liquidcrystal

#include <LiquidCrystal.h>

// LiquidCrystal lcd(RS, E (enable), pinos de dados);
// LiquidCrystal lcd(RS, E, D4, D5, D6, D7);
LiquidCrystal lcd(6, 7, 8, 9, 10, 11);

void setup() {

  // lcd.begin(colunas, linhas);
  lcd.begin(16, 2);
  lcd.print("Bem vindo ao");
  
  // lcd.setCursor(coluna, linha);
  lcd.setCursor(0, 1);
  lcd.print("curso de Arduino");
  
  delay(2000);
  // Limpa o display
  lcd.clear();
  
  //lcd.write(caractere);
  lcd.write('R');
  delay(200);
  lcd.write('T');
  delay(200);
  lcd.write('S');
  
  lcd.print(65); // escreve "65" na tela
  lcd.write(65); // escreve 'A' na tela (converte para ASCII)
  
  delay(2000);
  
  lcd.clear();
  lcd.print("Bem vindo ao curso de Arduino");
}

void loop() {
  delay(2000);
  for (int i = 0; i < 13; i++) {
    delay(200);
  	lcd.scrollDisplayLeft();
  }
  delay(2000);
  for (int i = 0; i < 13; i++) {
    delay(200);
  	lcd.scrollDisplayRight();
  }
}
