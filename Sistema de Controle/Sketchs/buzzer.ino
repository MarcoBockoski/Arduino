int buzzer = 9;
int botao = 7;
int val = 0;

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(botao, INPUT);
}

void loop() {
  val = digitalRead(botao);
  if(val == 1){
    digitalWrite(buzzer, HIGH);
    delayMicroseconds(10);
    digitalWrite(buzzer, LOW);
    delayMicroseconds(100);
  }
}
