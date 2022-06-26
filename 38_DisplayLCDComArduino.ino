// Circuit: https://www.tinkercad.com/things/3C32Qn4AcQe-38-display-lcd-com-arduino

#include <LiquidCrystal.h>

// LiquidCrystal lcd(RS, E (enable), pinos de dados);
// LiquidCrystal lcd(RS, E, D4, D5, D6, D7);
LiquidCrystal lcd(6, 7, 8, 9, 10, 11);

void setup() {

  // lcd.begin(colunas, linhas);
  lcd.begin(16, 2);
  lcd.print("Bem vindo!");
}

void loop() {

}