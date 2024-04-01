//**********************************************************************************
/*
Keyes 2021入门学习套件
Project 21.2
Dimming_light
http//www.keyestudio.com
*/
int potpin=A1;// 初始化可调电位器的模拟引脚A1
int ledpin=11;// 初始化数字引脚11
int val=0;// 定义val,初始值赋为0
void setup()
{
pinMode(ledpin,OUTPUT);// 设置数字引脚为“输出”
Serial.begin(9600);// 波特率设置为9600
}
void loop()
{
val=analogRead(potpin);// 读取模拟引脚A1的模拟值，并将其赋值给val 
analogWrite(ledpin,val/4);
Serial.println(val);// 显示val的值
}
//**********************************************************************************
