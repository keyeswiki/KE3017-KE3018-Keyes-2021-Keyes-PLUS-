//**********************************************************************************
/*
Keyes 2021入门学习套件
Project 24.1
Read_the_sound_sensor_analog_value
http//www.keyestudio.com
*/
int soundpin=A1;// 初始化声音传感器的模拟管脚A1
int val=0;// 初始化变量val的值为0
void setup()
{
Serial.begin(9600);// 波特率设置为9600
}
void loop()
{
val=analogRead(soundpin);// 读取传感器的模拟值并将其值赋给val
Serial.println(val);// 显示val的值
delay(1000);// 等待1秒
}
//**********************************************************************************
