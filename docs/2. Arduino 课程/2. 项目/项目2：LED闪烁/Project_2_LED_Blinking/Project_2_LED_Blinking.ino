//*************************************************************************************
/*
Keyes 2021入门学习套件
Project 2
LED_Blinking 
http//www.keyestudio.com
*/
int ledPin = 10; // 定义数字引脚10.
void setup()
{
pinMode(ledPin, OUTPUT);// 定义led引脚为输出.
}
void loop()
{
digitalWrite(ledPin, HIGH); // 点亮LED.
delay(1000); // 等待1秒.
digitalWrite(ledPin, LOW); // 熄灭LED.
delay(1000); // 等待1秒
}
//*************************************************************************************
