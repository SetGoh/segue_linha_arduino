/*DECLARAÇÃO DE VARIAVEIS*/
#define MotorA_sentido1 2
#define MotorA_sentido2 3
#define MotorB_sentido1 4
#define MotorB_sentido2 7
#define MotorA_PWM 5  
#define MotorB_PWM 6
 
#define veloc0 0
#define veloc1 60
#define veloc2 180
 
#define Sensor_direita A0
#define Sensor_esquerda A5
 
bool direita, esquerda;

void setup() {
  Serial.begin(9600);
  pinMode(MotorA_sentido1, OUTPUT);
  pinMode(MotorA_sentido2, OUTPUT);
  pinMode(MotorB_sentido1, OUTPUT);
  pinMode(MotorB_sentido2, OUTPUT);
  pinMode(MotorA_PWM, OUTPUT);
  pinMode(MotorB_PWM, OUTPUT);
  pinMode(Sensor_direita, INPUT);
  pinMode(Sensor_esquerda, INPUT);
  
}
 
void loop()
{
  //Define o sentido de rotação dos motores
  digitalWrite(MotorA_sentido1, LOW);
  digitalWrite(MotorA_sentido2, HIGH);
  digitalWrite(MotorB_sentido1, HIGH);
  digitalWrite(MotorB_sentido2, LOW);
  
  //Leituras dos Sensores
  direita = digitalRead(Sensor_direita);
  esquerda = digitalRead(Sensor_esquerda);
  Serial.print(direita);
  Serial.print(" || ");
  Serial.println(esquerda);
 
  //Rodando os motores dependendo das leituras
  if(direita == false && esquerda == false)
  {
  analogWrite(MotorA_PWM, veloc1);
  analogWrite(MotorB_PWM, veloc1);
  }
  if(direita == false && esquerda == true)
  {
  analogWrite(MotorA_PWM, veloc2);
  analogWrite(MotorB_PWM, veloc0);
  }
  if(direita == true && esquerda == false)
  {
  analogWrite(MotorA_PWM, veloc0);
  analogWrite(MotorB_PWM, veloc2);
  }
  if(direita == true && esquerda == true)
  {
  analogWrite(MotorA_PWM, veloc0);
  analogWrite(MotorB_PWM, veloc0);
  }
}
