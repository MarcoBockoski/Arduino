int valor = 0

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("Digite um numero:");
  valor = Serial.read(;
  Serial.print("O numero digitado foi ");
  Serial.write(valor);
  Serial.println();
  delay(5000);
}
