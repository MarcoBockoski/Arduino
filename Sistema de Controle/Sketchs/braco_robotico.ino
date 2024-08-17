#include <Servo.h>

Servo s1, s2, s3, s4;
int p1 = A2, p2 =A3, p3 =A4, p4 = A5;
int v1 = 0, v2 = 0, v3 = 0, v4 = 0;

void setup() {
  Serial.begin(9600);
  s1.attach(11);
  s2.attach(9);
  s3.attach(5);
  s4.attach(3);
}

void loop() {
  v1 = analogRead(p1);
  v1 = map(v1, 0, 1023, 0, 180);
  Serial.println(v1);
  s1.write(v1);

  v2 = analogRead(p2);
  v2 = map(v2, 0, 1023, 0, 180);
  Serial.println(v2);
  s2.write(v2);

  v3 = analogRead(p3);
  v3 = map(v3, 0, 1023, 0, 180);
  Serial.println(v3);
  s3.write(v3);

  v4 = analogRead(p4);
  v4 = map(v4, 0, 1023, 0, 180);
  Serial.println(v4);
  s1.write(v4);
  delay(1);
}
