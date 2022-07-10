#define EN1 2
#define IN1 3
#define IN2 4

#define EN2 5
#define IN3 6
#define IN4 7

#define BTN_DWN 8
#define BTN_LFT 9
#define BTN_MID 10
#define BTN_RHT 11
#define BTN_TOP 12

void setup() {
  
  pinMode(EN1, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  
  pinMode(EN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  pinMode(BTN_DWN, INPUT_PULLUP);
  pinMode(BTN_LFT, INPUT_PULLUP);
  pinMode(BTN_MID, INPUT_PULLUP);
  pinMode(BTN_RHT, INPUT_PULLUP);
  pinMode(BTN_TOP, INPUT_PULLUP);
    
  digitalWrite(EN1, LOW);
  digitalWrite(EN2, LOW);
    
  /*
  	IN1 | IN2  | MOTOR1
    HIGH  LOW    HORARIO
    LOW   HIGH   ANTI-HORARIO
    LOW   LOW    IRRELEVANTE
    HIGH  HIGH   IRRELEVANTE
    
  	IN3 | IN4  | MOTOR2
    HIGH  LOW    ANTI-HORARIO
    LOW   HIGH   HORARIO
    LOW   LOW    IRRELEVANTE
    HIGH  HIGH   IRRELEVANTE
  */
  
  pinMode(A0, INPUT);
  Serial.begin(9600);
  
}

void motorEsquerdo(int acao) {
  if (!acao) {
    digitalWrite(EN1, LOW);
    return;
  }
  digitalWrite(EN1, HIGH);
  
  if (acao > 0) {
    digitalWrite(IN1, HIGH);
  	digitalWrite(IN2, LOW);
    return;
  }
  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
}

void motorDireito(int acao) {
  if (!acao) {
    digitalWrite(EN2, LOW);
    return;
  }
  digitalWrite(EN2, HIGH);
  
  if (acao > 0) {
    
    digitalWrite(IN3, LOW);
  	digitalWrite(IN4, HIGH);
    return;
  }
  
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void loop() {
  if (!digitalRead(BTN_TOP)){
    motorEsquerdo(1);
    motorDireito(1);
    
    while(!digitalRead(BTN_TOP));
  }
  
  if (!digitalRead(BTN_DWN)){
    motorEsquerdo(-1);
    motorDireito(-1);
    
    while(!digitalRead(BTN_DWN));
  }
  
  if (!digitalRead(BTN_LFT)){
    motorEsquerdo(1);
    motorDireito(-1);
    
    while(!digitalRead(BTN_LFT));
  }
  
  if (!digitalRead(BTN_RHT)){
    motorEsquerdo(-1);
    motorDireito(1);
    
    while(!digitalRead(BTN_RHT));
  }
  
  if (!digitalRead(BTN_MID)){
    motorEsquerdo(0);
    motorDireito(0);
    
    while(!digitalRead(BTN_MID));
  }
}
