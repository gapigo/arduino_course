// Circuit: https://www.tinkercad.com/things/kye022KmYFz-tarefa-2-contador-programado

#define BTN_SUB 0
#define BTN_ADD 1
#define SEG_A 2
#define SEG_B 3
#define SEG_C 4
#define SEG_D 5
#define SEG_E 6
#define SEG_F 7
#define SEG_G 8

#define DSP_D 9
#define DSP_U 10

#define BTN 11

#define LED 13

int espera = 0;
int contagem = 0;
bool ativo = false;
bool configurar = true;
int limite_contagem = 0;

int mapaDisplay[] = {
  B00111111, B00000110, B01011011, B01001111, 
  B01100110, B01101101, B01111101, B00000111, 
  B01111111, B01101111
  
};

void mostrarNumero(int numero) {
  int mapa = mapaDisplay[numero];
  int bitAtual = B00000001;
  
  /*
  B01100111   <= mapa
  B00000001 & <= bitAtual
  ---------
  B00000001 = 1 em decimal 
  
  B00000110
  B00000001 &
  ---------
  B00000000 = 0 em decimal 
  */
  
  for (int i = 0; i < 7; i++) {
    int acender = mapa & bitAtual;
    //digitalWrite(i + 2, HIGH);
    digitalWrite(i + 2, acender);
    bitAtual = bitAtual << 1;
  }
}

void mostrarDigitos(int dezena, int unidade) {
  digitalWrite(DSP_U, HIGH);
  digitalWrite(DSP_D, LOW);
  mostrarNumero(unidade);
  delay(100);
  
  digitalWrite(DSP_U, LOW);
  digitalWrite(DSP_D, HIGH);
  mostrarNumero(dezena);
  delay(100);
}

void setup() {
  pinMode(SEG_A, OUTPUT);
  pinMode(SEG_B, OUTPUT);
  pinMode(SEG_C, OUTPUT);
  pinMode(SEG_D, OUTPUT);
  pinMode(SEG_E, OUTPUT);
  pinMode(SEG_F, OUTPUT);
  pinMode(SEG_G, OUTPUT);
  pinMode(DSP_D, OUTPUT);
  pinMode(DSP_U, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(BTN, INPUT_PULLUP);
  pinMode(BTN_SUB, INPUT_PULLUP);
  pinMode(BTN_ADD, INPUT_PULLUP);
  Serial.begin(9600);
}

void contar() {
  if (espera == 5 && limite_contagem > contagem) {
    contagem++;
    espera = 0;
  }
  espera++;
  int numero = 12;
  int dez;
  int uni;
  dez = contagem / 10;
  uni = contagem % 10;
  mostrarDigitos(dez, uni);
}

void mostrarLimiteContagem() {
  int dez = limite_contagem / 10;
  int uni = limite_contagem % 10;
  mostrarDigitos(dez, uni);
}

void loop() {
  
  if ( digitalRead(BTN) == 0 ) {
	contagem = 0;
    ativo = !ativo;
    
    digitalWrite(DSP_U, LOW);
  	digitalWrite(DSP_D, LOW);
    // mostrarDigitos(0, 0);
    
    while( digitalRead(BTN) == 0 );
  }
  
  if ( digitalRead(BTN_SUB) == 0) {
	if (limite_contagem > 0) limite_contagem--;
    while( digitalRead(BTN_SUB));
  }
  
  if ( digitalRead(BTN_ADD) == 0) {
	if (limite_contagem < 99) limite_contagem++;
    while( digitalRead(BTN_ADD));
  }
  
  
  if (ativo) {
    contar();
    digitalWrite(LED, LOW);
    if (contagem >= limite_contagem) {
      ativo = !ativo;
      contagem = 0;
      limite_contagem = 0;
      digitalWrite(LED, HIGH);
    }
  }
  
  else {
    mostrarLimiteContagem();
  }
  
}
