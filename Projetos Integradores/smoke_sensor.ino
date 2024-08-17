// C++ code

int redLed = 12; //Led vermelho é conectado ao terminal 12 do arduíno
int greenLed = 11; //Led verde é conectado ao terminal 11 do arduíno
int buzzer = 10; //O alarme sonoro é conectado ao terminal 10 do arduíno
int smokeA0 = A5; //Sensor de fumaça é conectado ao terminal A5 do arduíno| A0 é o nome do terminal do sensor

int sensorThres = 400; //Atribui o valor de 400(ppm à uma variável sensorThres | sensorThres(hold) = Valor limite do sensor, passando disso, é acusado presença de fumaça

void setup() { //Função para definir se os terminais são entradas ou saídas 
  pinMode(redLed, OUTPUT); //12 é um terminal de saída
  pinMode(greenLed, OUTPUT); //11 é um terminal de saída
  pinMode(buzzer, OUTPUT); //10 é um terminal de saída
  pinMode(smokeA0, INPUT); //A5 é um terminal de entrada
  Serial.begin(9600); //Comando para comunicação com um computador, usado para printar mensagens captadas pelo arduíno e printar no monitor do pece
}
     //A5 é o pino de entrada, conforme os valores lidos pelo MQ-2(Sensor de fumaça), os LEDS vermelho e verde ligarão ou não, assim como o alarme sonoro
void loop() {
  int analogSensor = analogRead(smokeA0); //Declara uma variável chamada analog sensor, atribuindo seu valor como o valor captado pelo sensor

  Serial.print("Pin A0: ");
  Serial.println(analogSensor); //Disponibiliza no monitor o valor lido pelo sensor de concentração de gás em ppm
  //Usa estruturas de fluxo de controle if e else
  if (analogSensor > sensorThres) //No caso do valor lido pelo sensor extrapolar o limite de concentração de 400ppm de gás na atmosfera(Se 40% da atmosfera for fumaça/GLP/Butano/Metano)...
  {
    digitalWrite(redLed, HIGH); //Led vermelho liga
    digitalWrite(greenLed, LOW); //led verde desliga
    tone(buzzer, 1000, 200); //Aciona o alarme sonoro, na frequência de 1kHz, no tempo de 200ms
  }
  else //Pelo contrário...
  {
    digitalWrite(redLed, LOW); //Led vermelho desliga
    digitalWrite(greenLed, HIGH); //Led verde liga
    noTone(buzzer); //Alarme Sonoro fica mudo
  }
  delay(100); //De 100 em 100ms, o arduíno executa o processo de leitura em ppm e analisa se o valor lido pelo sensor extrapola o limite
}
