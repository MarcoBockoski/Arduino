#include <Wire.h>
#include <Adafruit_INA219.h>
#include <LiquidCrystal.h>



LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //Declaração do LCD (Padrão)
Adafruit_INA219 ina219 (0x40); //Declaração do Sensor, já que tem só um, seu endereço pode ser diferente
float energia = 0;
float vCarga = 0;
float vResistorS = 0;
float vDivisor = 0;
float corrente = 0;

void setup() {
  Serial.begin(9600);
  //while (!Serial) 
  //{ 
  //  delay(1); //Enquanto não for plugado o USB, não roda
  //} 
  //Serial.println("Relou");

  if (! ina219.begin()) 
  { 
    Serial.println("Falha ao encontrar o INA219"); 
    while (1) { 
      delay(10);
      } //Loop sem fim, pra resetar arduino
  } 
  
  lcd.begin(16, 2);
  constantes();
  Serial.println("Mede corrente e energia com INA219"); 
  ina219.setCalibration_16V_400mA(); 
  //ina219.setCalibration_32V_1A();
}

void loop() {
  vResistorS = ina219.getShuntVoltage_mV(); // Tensão em shunt
  vDivisor = ina219.getBusVoltage_V(); //Tensão no divisor
  corrente = ina219.getCurrent_mA(); // Corrente em miliamperes
  vCarga = vDivisor + (vResistorS / 1000); //Conta para tensão na carga, específico de fábrica
  energia = corrente*vCarga; //Conta de energia
  printSerial();
  printLCD();
  delay(1000);
}

void constantes(){
  
  lcd.setCursor(0,0);
  lcd.print("Corrente: ");
 
  lcd.setCursor(0,1);
  lcd.print("Energia: ");
  
  lcd.setCursor(14,0);
  lcd.print("mA");
  
  lcd.setCursor(14,1);
  lcd.print("mJ");
}

void printSerial(){
  Serial.print("Tensão de Entrada: "); 
  Serial.print(vDivisor); 
  Serial.println(" V");
  Serial.print("Tensão no shunt: "); 
  Serial.print(vResistorS); 
  Serial.println(" mV"); 
  Serial.print("Tensão da Carga: "); 
  Serial.print(vCarga); 
  Serial.println(" V"); 
  Serial.print("Corrente: "); 
  Serial.print(corrente); 
  Serial.println(" mA"); 
  Serial.print("Energia: "); 
  Serial.print(energia); 
  Serial.println(" mJ"); 
}

void printLCD(){
  lcd.setCursor(9,0);
  lcd.print(corrente);

  lcd.setCursor(9,1);
  lcd.print(energia);
}
