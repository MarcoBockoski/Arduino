#include <Servo.h>

Servo servo;
int pinoBotao = 2;
int valor = 0;

void setup() {
  Serial.begin(9600);
  pinMode(pinoBotao, INPUT);
  servo.attach(3);
}

void loop() {
  valor = digitalRead(pinoBotao);
  if(valor == 1){
    servo.write(180);
  }else{
    servo.write(0);
  }
  Serial.println(valor);
  //delay(1000);
}
