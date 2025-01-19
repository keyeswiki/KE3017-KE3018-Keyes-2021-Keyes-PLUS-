//**********************************************************************************
/*
Keyes 2021入门学习套件
Project 30.1
Read_the_thermistor_analog_value
http//www.keyes-robot.com
*/
#include<math.h>

const float voltagePower=5.0;
const float Rs=4.7;//采样电阻为4.7千欧
const int B=3950;
const double T1=273.15+25;//常温
const double R1=10;//常温对应的阻值，注意单位是千欧
void setup() {
  Serial.begin(9600);
}
void loop() { 
  //获得A1处的电压值
  double digitalValue=analogRead(1);
  double voltageValue=(digitalValue/1023)*5;
  Serial.print("Current voltage value=");
  Serial.println(voltageValue);
  
  //通过分压比获得热敏电阻的阻值
  double Rt=((voltagePower-voltageValue)*Rs)/voltageValue;
  Serial.print("Current registor value=");
  Serial.println(Rt);
 
  //换算得到温度值
  Serial.print("Current temperature value=");
  Serial.println(((T1*B)/(B+T1*log(Rt/R1)))-273.15);//
  Serial.println();
    
  //每3秒输出，更改此处修改频率
  delay(3000); 
}
//**********************************************************************************
