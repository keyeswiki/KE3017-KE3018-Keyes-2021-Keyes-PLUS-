//**********************************************************************************
/*
Keyes 2021入门学习套件
Project 22.1
Read_the_flame_sensor_analog_value
http//www.keyes-robot.com
*/
int flamepin=A1;// 初始化模拟管脚A1
int val=0;// 定义val，初始值赋为0
void setup()
{
Serial.begin(9600);// 波特率设置为9600
}
void loop()
{
val=analogRead(flamepin);// 读取模拟引脚A1的模拟值，并将其值赋给val
Serial.println(val);// 显示val值
}
//**********************************************************************************
