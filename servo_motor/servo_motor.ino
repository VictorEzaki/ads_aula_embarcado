#include <Servo.h>

const int potVelocidade = A0; 
const int potAngulo     = A1; 

Servo servo_motor;

int posAtual = 90;   
int direcao = 1;     

void setup() {
  servo_motor.attach(9);
  servo_motor.write(posAtual);
}

void loop() {
  
  int leituraAng = analogRead(potAngulo);
  int limiteSuperior = map(leituraAng, 0, 1023, 95, 170); 
  int limiteInferior = 180 - limiteSuperior;                
  
  int leituraVel = analogRead(potVelocidade);
  int tempoPasso = map(leituraVel, 0, 1023, 2, 40);
  
  posAtual += direcao;
  servo_motor.write(posAtual);
  
  if (posAtual >= limiteSuperior) {
    posAtual = limiteSuperior;
    direcao = -1; 
  } 
  else if (posAtual <= limiteInferior) {
    posAtual = limiteInferior;
    direcao = 1;  
  }
  
  delay(tempoPasso);
}