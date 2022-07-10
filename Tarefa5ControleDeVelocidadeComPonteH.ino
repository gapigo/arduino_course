/* Enunciado
Para realizar esta tarefa copie o circuito disponível neste link, que é a mesma base da Tarefa de Controle de Direção. Será seu ponto de partida para realizar a programação e a adição dos componentes necessários para cumprir o objetivo proposto.

Perguntas dessa tarefa
Como foi visto aqui no curso, é possível realizar controles dispositivos que não necessariamente devem ter apenas os estados LIGADO e DESLIGADO. Isso é possível utilizando PWM para modular um pulso de onda quadrada para simular a intensidade luminosa ou controlar a velocidade angular de um motor.

Nesta tarefa você deve modificar o circuito sugerido adicionando 2 potenciômetros. Cada potenciômetro deve ser utilizado para controlar a velocidade de um dos motores ligados à ponte-h. Faça as mudanças necessárias no circuito caso necessite. Para testar mantenha os motores girando, não importa o sentido, e então ajuste suas velocidades com cada potenciômetro. Cada motor deve ter sua velocidade individual controlada pelo potenciômetro relacionado a ele. 
*/
#define EN1 9
#define IN1 3
#define IN2 4

#define EN2 5
#define IN3 6
#define IN4 7

void setup() {
  
  pinMode(EN1, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  
  pinMode(EN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  
  //digitalWrite(EN1, HIGH);
  //analogWrite(EN1, 128);
  //digitalWrite(EN2, HIGH);
  
  digitalWrite(IN2, HIGH);
  digitalWrite(IN4, HIGH);
    
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
  
}

void loop() {
  int pot1 = analogRead(A0);
  int pot2 = analogRead(A1);
  
  int vel1 = map(pot1, 0, 1023, 0, 255);
  int vel2 = map(pot2, 0, 1023, 0, 255);
  analogWrite(EN1, vel1);
  analogWrite(EN2, vel2);
}
