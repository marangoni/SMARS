/************************************************ 
Franzino Smars - Teste anda pra frente 
Franzino Smars - alinhamento frente e trás
Autor: Luiz C M Oliveira - 05.06.2019
 
***************************************************************/

#include <Wire.h>
#include <AFMotor.h>  //biblioteca para controle motores - Adafruit Shield

// Seleciona porta em que os motores estão ligados M1, M2, M3 or M4. Neste caso, M1 and M

AF_DCMotor L_motor(2); // motor esquerdo M2
AF_DCMotor R_motor(1); // motor direito M1

int vd = 50; //velocidade direita
int ve = 45; //velocidade esquerda

int tempo_frente = 3000;
int tempo_tras = 3000;
int tempo_parado = 1000;

void setup() {
//Ajusta velocidades
      R_motor.setSpeed(vd);
      L_motor.setSpeed(ve);

      for (int i=0;i<8;i++){ //repete 8x
            L_motor.run(FORWARD);   // Para frente
            R_motor.run(FORWARD);   // Para frente
            delay(tempo_frente);
            L_motor.run(RELEASE);   // Desliga motor esquerdo
            R_motor.run(RELEASE);   // Desliga motor direito
            delay(tempo_parado);
            L_motor.run(BACKWARD);   // Para frente
            R_motor.run(BACKWARD);   // Para frente
            delay(tempo_tras);
            L_motor.run(RELEASE);   // Desliga motor esquerdo
            R_motor.run(RELEASE);   // Desliga motor direito
            delay(tempo_parado);
      }
 
}

void loop() {
  
      
      
  }
