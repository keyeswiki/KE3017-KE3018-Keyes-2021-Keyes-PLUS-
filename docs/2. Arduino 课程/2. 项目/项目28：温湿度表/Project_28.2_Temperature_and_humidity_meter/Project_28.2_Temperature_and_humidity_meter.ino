//**********************************************************************************
/*
Keyes 2021入门学习套件
Project 28.2
Temperature_and_humidity_meter
http//www.keyestudio.com
*/
#include "DHT.h"
#define DHTPIN 11     // 连接DHT传感器的数字引脚
DHT dht(DHTPIN, DHT11);
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);  // 将LCD地址设置为0x27，以16个字符和2行显示

void setup() {
  lcd.init();                      // 初始化LCD
  lcd.init();
  // 向LCD打印一条消息.
  lcd.backlight();

  dht.begin();
}

void loop() {
  lcd.setCursor(0,0);
  lcd.print("Humidity: ");
  lcd.print((const int)dht.readHumidity());
  lcd.setCursor(0,1);
  lcd.print("Temperature: ");
  lcd.print((const int)dht.readTemperature());
  delay(200);
}
//**********************************************************************************
