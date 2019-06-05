#include <AFMotor.h>
#include <Ultrasonic.h>

//Teste SMARS com sensor ultrasonico
//This sketch makes the robot move inside a delimitated Area (you can make a
//perimeter with insulating tape)

AF_DCMotor R_motor(1); // defines Right motor connector
AF_DCMotor L_motor(2); // defines Left motor connector

//Definições sensor ultrasonico
#define TRIGGER_PIN  9  //servo 01 signal
#define ECHO_PIN     10 //servo 02 signal
Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);

// declaração de variáveis

float distancia = 0;//distacia ao obstaculo

int vnormal = 125;
int vlenta = 85;

void setup() {
Serial.begin(9600); // sets up Serial library at 9600 bps
//changes the following values to make the robot drive as straight as possible

L_motor.setSpeed(vnormal); // sets L motor speed
R_motor.setSpeed(vnormal); // sets R motor speed - motor frente

R_motor.run(RELEASE); //turns L motor on
L_motor.run(RELEASE); //turns R motor on



}


void loop() {

  long microsec = ultrasonic.timing();
  distancia = ultrasonic.convert(microsec, Ultrasonic::CM);

if (distancia < 5){// se obstáculo a menos de 5 cm - pare - volte para tras - vire
  Serial.println("Obstaculo !!!");
  //pare os motores
  R_motor.run(RELEASE); 
  L_motor.run(RELEASE); 
  delay(500); //aguarde
  
  //meia volta
  L_motor.setSpeed(vlenta);
  R_motor.setSpeed(vlenta);
  L_motor.run(BACKWARD); //retorne lentamente
  R_motor.run(BACKWARD); //retorne lentamente por 500ms
  delay(500);
  L_motor.run(BACKWARD); //meia volta
  R_motor.run(FORWARD); //meia volta
  delay(800);

  //pare
  R_motor.run(RELEASE); 
  L_motor.run(RELEASE); 
  
  //ajuste velocidade
  L_motor.setSpeed(vnormal); 
  R_motor.setSpeed(vnormal); 
  }
  else { //se nada detectado - continue para frente
    L_motor.run(FORWARD); //moves motor L Backward
    R_motor.run(FORWARD); //moves motor L Backwar
  }
}
