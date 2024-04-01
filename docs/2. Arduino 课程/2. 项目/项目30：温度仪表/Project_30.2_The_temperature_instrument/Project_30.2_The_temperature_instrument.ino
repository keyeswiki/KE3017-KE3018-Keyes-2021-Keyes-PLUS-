//**********************************************************************************
/*
Keyes 2021入门学习套件
Project 30.2
The_temperature_instrument
http//www.keyestudio.com
*/
#include <math.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);  // 设置LCD地址为0x27, 16个字符，2行显示
const float voltagePower=5.0;
const float Rs_val=4.7;//采样电阻为4.7千欧
const int B=3950;
const double T1=273.15+25;//常温
const double R1=10;//常温对应的阻值，注意单位是千欧
void setup(){
Serial.begin(9600);
lcd.init();                      // 初始化 lcd
// 打印消息到LCD.
lcd.backlight();

lcd.clear();
lcd.setCursor(0, 0);
lcd.print("C v v=");
}

void loop(){
//获得A1处的电压值
double digitalValue=analogRead(1);
double voltageValue=(digitalValue/1023)*5;
  
//通过分压比获得热敏电阻的阻值
double Rt=((voltagePower-voltageValue)*Rs_val)/voltageValue;

//换算得到温度值
const float t=((T1*B)/(B+T1*log(Rt/R1)))-273.15;

if(t>-100.0) //如果温度大于-100℃时，串口监视器显示电压值,通过分压比获得热敏电阻的阻值,温度值和LCD显示电压值和温度值
{
Serial.print("Current voltage value=");
Serial.println(voltageValue);
Serial.print("Current registor value=");
Serial.println(Rt);
Serial.print("Current temperature value=");
Serial.println(t);
Serial.println("  ");
lcd.setCursor(7, 0);
lcd.print(voltageValue);
lcd.setCursor(13, 0);
lcd.print("V");
lcd.setCursor(0, 1);
lcd.print("C t v=");
lcd.setCursor(7, 1);
lcd.print(t);
lcd.setCursor(13, 1);
lcd.print("C");
lcd.print("  ");
}
else
{
Serial.println("Error! check sensor!");
}
delay(500);
}
//**********************************************************************************
