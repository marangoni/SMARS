/************************************************ 
Franzino Smars - Teste anda pra frente 
Franzino Smars - alinhamento frente e trás
Autor: Luiz C M Oliveira - 31.05.2019

Teclas: 
I - Start - Inicia o teste
P - Stop - Para o teste
U - UP - Aumenta a velocidade em 1
D - DOWN - Diminiui a velocidade em 1
R - RIGHT - Seleciona Roda direita
L - LEFT - Seleciona Roda esquerda
V - velocidade - Ajusta a velocidade

Como calibrar:
 1) Identificar as rodas - Olhando de frente para o sensor ultrasonico - Esquerda (L) e Direita (D)
 2) Ligar o Arduino/Franzino no PC
 3) Carregar este programa - Ferramentas -> Porta (selecionar) Ferramentas -> Placa -> Arduino/Genuino UNO
 4) Exibir o monitor serial - Ctrl + Shift + M ou Lupa do lado superior direito da tela

 5) Iniciar o teste - teclar I - Duas rodas devem girar para frente - velocidade 50
 6) Selecionar a roda direita - teclar R
 7) Aumentar - U ou diminuir a velocidade - D - até que o carrinho ande em linha reta.
 8) Anote os valores mostrados no monitor serial - velocidade Direita e velocidade Esquerda
 
***************************************************************/

#include <Wire.h>
#include <AFMotor.h>  //biblioteca para controle motores - Adafruit Shield

// Seleciona porta em que os motores estão ligados M1, M2, M3 or M4. Neste caso, M1 and M

AF_DCMotor L_motor(2); // motor esquerdo M2
AF_DCMotor R_motor(1); // motor direito M1

int vd = 50; //velocidade direita
int ve = 35; //velocidade esquerda

unsigned long tempo_i = 0;  //variaveis para controle de temporização
unsigned long tempo_f = 0;

int teste = 0;
char tecla;

String line1    ="-------------------------------------------";
String message1 =" SMARS - Franzino - Teste - Linha reta";
String message2 =" Teclas:";
String message3 =" I,i - Inicia o teste";
String message4 =" S,s - Para o teste";
String message5 =" F,f - Anda para frente";
String message6 =" T,t - Anda para trás";
//String message7 =" R,r - Seleciona roda direita";
//String message8 =" L,l - Seleciona roda esquerda";
//String message9 =" V,v - Ajusta a velocidade";
String message10="Velocidade Direita:  ";
String message11="Velocidade Esquerda: ";
String message12="Pressione I para iniciar o teste...";
String message13="Teste em andamento";
String message14="Teste finalizado";
String message15="Para frente em linha reta.";
String message16="Para trás em linha reta";
String message17="Este é o motor esquerdo";

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // espera a conexão da porta serial.
  }
  //Instruções no monitor serial
  Serial.println(line1);
  Serial.println(message1);
  Serial.println(message2);
  Serial.println(message3);
  Serial.println(message4);
  Serial.println(message5);
  Serial.println(line1);
  Serial.println(message12);
}

void loop() {
 
  if (Serial.available()) {
    // read the most recent byte (which will be from 0 to 255):
    tecla = Serial.read();
  }

  if (tecla == 'i'){
      Serial.println("Comando: i");
      teste = 1; 
      tecla ="";
      Serial.println(message13);
      Serial.println(message15);      
  }
  
  if (tecla == 's'){
      Serial.println("Comando: s - Para o teste");
      teste = 0;
      tecla ="";
      Serial.println(message14);
      Serial.print(message10);
      Serial.println(vd);
      Serial.print(message11);
      Serial.println(ve); 
       L_motor.run(RELEASE);   // Desliga motor esquerdo
       R_motor.run(RELEASE);   // Desliga motor direito
  }

  if (teste == 1){
    if (tecla == 'f'){
      Serial.println("Comando: f - Para frente");
      L_motor.run(FORWARD);   // Para frente
      R_motor.run(FORWARD);   // Para frente
      tecla ="";    
    }
  if (tecla == 't'){
      Serial.println("Comando: t - Para trás");
      L_motor.run(BACKWARD);   // Para frente
      R_motor.run(BACKWARD);   // Para frente
       
  }
  if (tecla == 'r'){
        Serial.println("Comando: r");
        tecla ="";    
  }
  if (tecla == 'l'){
      Serial.println("Comando: l");
      tecla ="";    
  }
  if (tecla == 'v'){
      Serial.println("Comando: v");
      tecla ="";    
    }
  }
  
  tempo_f = millis();
  if (tempo_f - tempo_i > 5000){//escreve a velocidade na tela a cada 5s
    Serial.print(message10);
    Serial.println(vd);
    Serial.print(message11);
    Serial.println(ve);
    tempo_i = tempo_f;
  }
  
  //Movimenta motores
  R_motor.setSpeed(vd);
  L_motor.setSpeed(ve);
  
}
