int pinoLed = 6
int pinoPot = A0;
int valor - 0;

void setup() {
  Serial.begin(9600);
  pinMode(pinoLed, OUTPUT);
}

void loop() {
  valor = analogRead(pinoPot);
  valor = map(valor, 0, 1023, 0, 255);
  Serial, println(valor);
  analogWrite(pinoLed, valor);
}
