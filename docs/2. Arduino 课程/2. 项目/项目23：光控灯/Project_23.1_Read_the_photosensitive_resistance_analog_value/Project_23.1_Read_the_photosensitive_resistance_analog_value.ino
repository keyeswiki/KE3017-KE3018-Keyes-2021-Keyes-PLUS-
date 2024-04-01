//**********************************************************************************
/*
Keyes 2021入门学习套件
Project 23.1
Read_the_photosensitive_resistance_analog_value
http//www.keyestudio.com
*/
int photocellpin=A0;// 初始化连接光敏电阻的模拟管脚A0
int val=0;// 初始化变量val的值为0
void setup()
{
Serial.begin(9600);// 波特率设置为9600
}
void loop()
{
val=analogRead(photocellpin);// 读取传感器的值并将其值赋给val
Serial.println(val);// 显示val的值
delay(200);// 等待0.2秒
}
//**********************************************************************************
