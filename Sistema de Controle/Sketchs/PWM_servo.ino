#include <Servo.h>

Servo servo;
int pinoPot = A0;
int valor = 0;

void setup() {
  Serial.begin(9600);
  servo.attach(6);
}

void loop() {
  valor = analogRead(pinoPot);
  valor = map(valor, 0, 1023, 0 , 180);
  Serial.println(valor);
  servo.write(valor);
  delay(15);
}
