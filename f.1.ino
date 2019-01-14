//entrada
int totem_e_ramp = 2;
int totem_ent = 3;
int totem_ramp = 4;
int totem_est = 5;

//corte leitoras
int prox_est = 6;
int prox_ramp = 7;
int prox_ent = 8;
int prox_e_ramp = 9;

//saida
int sinal_verm_est = 10;
int sinal_verd_est = 11;
int sinal_verm_ramp = 12;
int sinal_verd_ramp = 13;

//Controle de entrada em funçoes
int alterado = 0;

  
void setup()
{
  Serial.begin(9600); //porta serial
  //Define pinos para o rele como saida
  pinMode(sinal_verm_est, OUTPUT); 
  pinMode(sinal_verd_est, OUTPUT);
  pinMode(sinal_verm_ramp, OUTPUT);
  pinMode(sinal_verd_ramp, OUTPUT);
  //Corte leitoras
  pinMode(prox_est, OUTPUT); 
  pinMode(prox_ramp, OUTPUT);
  pinMode(prox_ent, OUTPUT);
  pinMode(prox_e_ramp, OUTPUT);
  //Define pinos dos botoes como entrada
  pinMode(totem_ent, INPUT); 
  pinMode(totem_ramp, INPUT);
  pinMode(totem_est, INPUT);
 // pinMode(totem_e_ramp, INPUT);
  
  //Estado inicial dos reles - desligados
  digitalWrite(sinal_verm_est, HIGH); //vermelho esq
  digitalWrite(sinal_verd_est, LOW); //verde esq
  digitalWrite(sinal_verm_ramp, HIGH); //vermelho dir
  digitalWrite(sinal_verd_ramp, LOW); //verde dir
  

}

void estadoInicial(){
    digitalWrite(sinal_verm_est, HIGH); //vermelho esq
    digitalWrite(sinal_verd_est, LOW); //verde esq
    digitalWrite(sinal_verm_ramp, HIGH); //vermelho dir
    digitalWrite(sinal_verd_ramp, LOW); //verde dir
}

void delayAuto(){
  if(alterado == 1){
    delay(1000*2);
    alterado = 0;
  }
}
 

void loop()
{

  while(digitalRead(totem_ent) == 0)
  {
    alterado = 1;
    digitalWrite(sinal_verm_est, HIGH);
    digitalWrite(sinal_verd_est, LOW);
    digitalWrite(sinal_verm_ramp, HIGH);
    digitalWrite(sinal_verd_ramp, LOW);
    digitalWrite(prox_est, LOW);
    digitalWrite(prox_ramp, LOW);
    digitalWrite(prox_e_ramp, LOW);
    Serial.print("TOTEM ENTRADA ACIONADO");
  }

  delayAuto();
  estadoInicial();

  while(digitalRead(totem_ramp) == 0)
  {
    alterado = 1;
    digitalWrite(sinal_verm_est, HIGH);
    digitalWrite(sinal_verd_est, LOW);
    digitalWrite(sinal_verm_ramp, LOW);
    digitalWrite(sinal_verd_ramp, HIGH);
    digitalWrite(prox_est, LOW);
    digitalWrite(prox_ent, LOW);
    digitalWrite(prox_e_ramp, LOW);
    Serial.print("TOTEM RAMPA ACIONADO");
  }

  delayAuto();
  estadoInicial();

  while(digitalRead(totem_est) == 0)
  {
    alterado = 1;
    digitalWrite(sinal_verm_est, LOW);
    digitalWrite(sinal_verd_est, HIGH);
    digitalWrite(sinal_verm_ramp, HIGH);
    digitalWrite(sinal_verd_ramp, LOW);
    digitalWrite(prox_ent, LOW);
    digitalWrite(prox_ramp, LOW);
    digitalWrite(prox_e_ramp, LOW);
    Serial.print("TOTEM ESTACIONAMENTO ACIONADO");
    
  }
  
  /*
   
   while(digitalRead(totem_e_ramp) == 0)
  {
    alterado = 1;
    digitalWrite(sinal_verm_est, HIGH);
    digitalWrite(sinal_verd_est, LOW);
    digitalWrite(sinal_verm_ramp, HIGH);
    digitalWrite(sinal_verd_ramp, LOW);
    digitalWrite(prox_est, LOW);
    digitalWrite(prox_ramp, LOW);
    digitalWrite(prox_ent, LOW);
  }

  delayAuto();
  estadoInicial();
*/
  
}
