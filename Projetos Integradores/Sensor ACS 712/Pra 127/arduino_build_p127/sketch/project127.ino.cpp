#include <Arduino.h>
#line 1 "C:\\Users\\Marco Antonio\\Documents\\Arduino\\project127\\project127.ino"
#include <LiquidCrystal.h>
#include <math.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int CT = A0;
double corrente;
double medido;
double energia;
double fonte = 127; 
double offsv = 2.5;
double sensi = 0.9995;
double ardvoltagem;

#line 14 "C:\\Users\\Marco Antonio\\Documents\\Arduino\\project127\\project127.ino"
void setup();
#line 19 "C:\\Users\\Marco Antonio\\Documents\\Arduino\\project127\\project127.ino"
void loop();
#line 32 "C:\\Users\\Marco Antonio\\Documents\\Arduino\\project127\\project127.ino"
void constantes();
#line 51 "C:\\Users\\Marco Antonio\\Documents\\Arduino\\project127\\project127.ino"
void calculaCorrente();
#line 59 "C:\\Users\\Marco Antonio\\Documents\\Arduino\\project127\\project127.ino"
void calculaEnergia();
#line 14 "C:\\Users\\Marco Antonio\\Documents\\Arduino\\project127\\project127.ino"
void setup() {
  lcd.begin(20, 4);
  constantes();
}

void loop() {
  calculaCorrente();
  lcd.setCursor(13,1);
  lcd.print(corrente);
  
  calculaEnergia();

  lcd.setCursor(7,3);
  lcd.print(energia);
  
  delay(1000);
}

void constantes(){
  
  lcd.setCursor(0,0);
  lcd.print("Voltagem: ");
  lcd.setCursor(13,0);
  lcd.print(fonte);
  lcd.setCursor(0,1);
  lcd.print("Corrente ef: ");
  lcd.setCursor(0,2);
  lcd.print("Energia: ");
  
  lcd.setCursor(19,0);
  lcd.print("V");
  lcd.setCursor(19,1);
  lcd.print("A");
  lcd.setCursor(14,3);
  lcd.print("e-7kWh");
}

void calculaCorrente(){
  
  medido = analogRead(CT);
  ardvoltagem = (medido*5.0)/1024.0;
  
  corrente = (10.0*(ardvoltagem - offsv)/sensi);
}

void calculaEnergia(){
  energia = abs(fonte*corrente*2.77);
}

