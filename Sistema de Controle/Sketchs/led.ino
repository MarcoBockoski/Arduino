int pinoLED = 13;

void setup() {
  Serial.begin(9600);
  pinMode(pinoLED, OUTPUT);
}

void loop() {
  digitalWrite(pinoLED, HIGH);
  delay(100);
  digitalWrite(pinoLED, LOW);
  delay(100);
}
