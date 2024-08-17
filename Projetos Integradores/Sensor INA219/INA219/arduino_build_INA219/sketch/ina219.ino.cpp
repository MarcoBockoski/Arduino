#include <Arduino.h>
#line 1 "C:\\Users\\Marco Antonio\\Documents\\Arduino\\ina219\\ina219.ino"
#include <Wire.h>
#include <Adafruit_INA219.h>
#include <LiquidCrystal.h>



LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //Declaração do LCD (Padrão)
Adafruit_INA219 ina219_0 (0x40); //Declaração do Sensor, já que tem só um, seu endereço pode ser diferente
float energia = 0;
float vCarga = 0;
float vResistorS = 0;
float vDivisor = 0;
float corrente = 0;

#line 15 "C:\\Users\\Marco Antonio\\Documents\\Arduino\\ina219\\ina219.ino"
void setup();
#line 35 "C:\\Users\\Marco Antonio\\Documents\\Arduino\\ina219\\ina219.ino"
void loop();
#line 46 "C:\\Users\\Marco Antonio\\Documents\\Arduino\\ina219\\ina219.ino"
void constantes();
#line 61 "C:\\Users\\Marco Antonio\\Documents\\Arduino\\ina219\\ina219.ino"
void printSerial();
#line 79 "C:\\Users\\Marco Antonio\\Documents\\Arduino\\ina219\\ina219.ino"
void printLCD();
#line 15 "C:\\Users\\Marco Antonio\\Documents\\Arduino\\ina219\\ina219.ino"
void setup() {
  Serial.begin(9600);
  //while (!Serial) 
  //{ 
  //  delay(1); //Enquanto não for plugado o USB, não roda
  //} 
  //Serial.println("Relou");

  if (! ina219_0.begin()) 
  { 
    Serial.println("Falha ao encontrar o INA219"); 
    while (1) { 
      delay(10);
      } //Loop sem fim, pra resetar arduino
  } 
  
  lcd.begin(16, 2);
  Serial.println("Mede corrente e energia com INA219"); 
}

void loop() {
  vResistorS = ina219_0.getShuntVoltage_mV(); // Tensão em shunt
  vDivisor = ina219_0.getBusVoltage_V(); //Tensão no divisor
  corrente = ina219_0.getCurrent_mA(); // Corrente
  vCarga = vDivisor + (vResistorS / 1000); //Conta para tensão na carga, específico de fábrica
  energia = (corrente*vCarga)/3600; //Conta de energia, considerando 1s = 1/3600h 
  printSerial();
  printLCD();
  delay(1000);
}

void constantes(){
  
  lcd.setCursor(0,0);
  lcd.print("Corrente: ");
 
  lcd.setCursor(0,1);
  lcd.print("Energia: ");
  
  lcd.setCursor(15,0);
  lcd.print("A");
  
  lcd.setCursor(9,1);
  //lcd.print("e-7kWh");
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
  Serial.println(" A"); 
  Serial.print("Energia: "); 
  Serial.print(energia); 
  Serial.println(" e-7kWh"); 
}

void printLCD(){
  lcd.setCursor(11,0);
  lcd.print(corrente);

  lcd.setCursor(10,1);
  lcd.print(energia);
}

