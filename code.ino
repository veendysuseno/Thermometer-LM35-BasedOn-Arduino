/*
    Program Thermometer LM35 Based On Arduino Uno
*/
#include <LiquidCrystal.h>  //Pendeklarasian Library

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  // Pemilihan Pin dan pendeklarasian variabel
const int inPin = 0;

void setup() { //Pengaturan Pin dan Variabel
    lcd.begin(16, 2);
}

void loop() { //Perulangan Program
    int value = analogRead(inPin);  //Pembacaan Sensor
    lcd.setCursor(0, 1);
    float millivolts = (value / 1024.0) * 5000;  //Konversi Suhu
    float celsius = millivolts / 10;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(celsius); //Penampilan Suhu
    lcd.print("C");
    lcd.setCursor(0, 1);
    lcd.print((celsius * 9) / 5 + 32);
    lcd.print("F");
    delay(1000);
}