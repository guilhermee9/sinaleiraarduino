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

//MSG SAIDA
String msgBotao = "";

void setup()
{
  Serial.begin(9600); //inicia porta serial
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
  pinMode(totem_e_ramp, INPUT);

  //Estado inicial dos reles - desligados
  digitalWrite(sinal_verm_est, HIGH); //vermelho esq
  digitalWrite(sinal_verd_est, LOW); //verde esq
  digitalWrite(sinal_verm_ramp, HIGH); //vermelho dir
  digitalWrite(sinal_verd_ramp, LOW); //verde dir
}

void estadoInicial() {
  digitalWrite(sinal_verm_est, HIGH); //vermelho esq
  digitalWrite(sinal_verd_est, LOW); //verde esq
  digitalWrite(sinal_verm_ramp, HIGH); //vermelho dir
  digitalWrite(sinal_verd_ramp, LOW); //verde dir
}

void delayAuto() {
  if (alterado == 1) {
    Serial.println(msgBotao);
    msgBotao = "";
    delay(1000*2);
    estadoInicial();
    alterado = 0;
  }
}

void setRelay(int svm_est, int svd_est, int svm_ramp, int svd_ramp, int prox_est, int prox_ramp, int prox_e_ramp) {
  digitalWrite(sinal_verm_est, svm_est);
  digitalWrite(sinal_verd_est, svd_est);
  digitalWrite(sinal_verm_ramp, svm_ramp);
  digitalWrite(sinal_verd_ramp, svd_ramp);
  digitalWrite(prox_est, prox_est);
  digitalWrite(prox_ramp, prox_ramp);
  digitalWrite(prox_e_ramp, prox_e_ramp);
}


void loop()
{
  if (digitalRead(totem_ent) == 1) {
    alterado = 1;
    msgBotao = "Totem Entrada";
    setRelay(HIGH, LOW, HIGH, LOW, LOW, LOW, LOW);
    delayAuto();
  }else if (digitalRead(totem_ramp) == 1) {
    alterado = 1;
    msgBotao = "Totem Saída Rampa ";
    setRelay(HIGH,LOW,LOW,HIGH,LOW,LOW,LOW);
    delayAuto();
  }else if (digitalRead(totem_est) == 1) {
    alterado = 1;
    msgBotao = "Totem Saída Estacionamento";
    setRelay(LOW,HIGH,HIGH,LOW,LOW,LOW,LOW);
    delayAuto();
  }else if (digitalRead(totem_e_ramp) == 1) {
    alterado = 1;
    msgBotao = "Totem Saída Rampa";
    setRelay(HIGH,LOW,HIGH,LOW,LOW,LOW,LOW);
    delayAuto();
  }
}
