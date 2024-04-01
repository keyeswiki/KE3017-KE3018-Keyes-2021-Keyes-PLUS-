//*********************************************************************************
/*
Keyes 2021入门学习套件
Project 16
I2C 1602 LCD
http//www.keyestudio.com
*/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2); // 设置LCD地址为0x27 
void setup()
{
lcd.init(); // 初始化 lcd
lcd.init();
lcd.backlight();
}
void loop()
{
lcd.setCursor(2,0);
lcd.print("Hello, world!");
lcd.setCursor(2,1);
lcd.print("keyestudio!");
}
//*********************************************************************************
