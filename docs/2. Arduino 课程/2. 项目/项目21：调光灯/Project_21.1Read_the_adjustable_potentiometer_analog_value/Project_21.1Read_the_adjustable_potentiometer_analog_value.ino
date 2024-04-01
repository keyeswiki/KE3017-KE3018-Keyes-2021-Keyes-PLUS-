//**********************************************************************************
/*
Keyes 2021入门学习套件
Project 21.1
Read_the_adjustable_potentiometer_analog_value
http//www.keyestudio.com
*/
int potpin=A1;//初始化可调电位器的模拟引脚A1
int val=0;// 定义val,初始值赋为0
void setup()
{
Serial.begin(9600);// 波特率设置为9600
}
void loop()
{
val=analogRead(potpin);// 读取模拟引脚A1的模拟值，并将其赋值给val 
Serial.println(val);// 显示val的值
}
//**********************************************************************************
