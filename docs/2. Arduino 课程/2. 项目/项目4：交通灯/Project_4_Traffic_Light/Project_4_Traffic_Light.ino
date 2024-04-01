//*********************************************************************************
/*
Keyes 2021入门学习套件 
Project 4
Traffic_Light
http//www.keyestudio.com
*/
int redled =10; // 初始化数字管脚10.
int yellowled =7; // 初始化数字管脚7.
int greenled =4; // 初始化数字管脚4.
void setup()
{
pinMode(redled, OUTPUT);// 将红色LED引脚设置为“output”
pinMode(yellowled, OUTPUT); // 将黄色LED引脚设置为“output”
pinMode(greenled, OUTPUT); // 将蓝色LED的引脚设置为“output”
}
void loop()
{
digitalWrite(greenled, HIGH);// 点亮绿色LED
delay(5000);// 延时5秒
digitalWrite(greenled, LOW); // 熄灭绿色LED
for(int i=0;i<3;i++)// 闪烁3次
{
delay(500);// 延时0.5秒
digitalWrite(yellowled, HIGH);//点亮黄色LED
delay(500);// 延时0.5秒
digitalWrite(yellowled, LOW);// 熄灭黄色LED
} 
delay(500);// 延时0.5秒
digitalWrite(redled, HIGH);// 点亮红色LED
delay(5000);// 延时5秒
digitalWrite(redled, LOW);// 熄灭红色LED
}
//*********************************************************************************
