#define EN1 2
#define IN1 3
#define IN2 4

#define EN2 5
#define IN3 6
#define IN4 7

void setup()
{
  pinMode(EN1, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  
  pinMode(EN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  digitalWrite(EN1, HIGH);
  digitalWrite(EN2, LOW);
  
  /* 
     IN1 | IN2    | MOTOR
     HIGH  LOW		HORARIO
     LOW   HIGH		ANTI-HORARIO
     LOW   LOW		IRRELEVANTE
     HIGH  HIGH		IRRELEVANTE
  */
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  
  delay(2000);
  
  digitalWrite(EN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  
  delay(2000);
  digitalWrite(EN1, LOW);
  digitalWrite(EN2, LOW);
}

void loop()
{
  
}
