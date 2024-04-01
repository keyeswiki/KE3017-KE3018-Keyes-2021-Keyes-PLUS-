//**********************************************************************************
/*
Keyes 2021入门学习套件 
Project 9
74HC595N_control_7_LEDS
http//www.keyestudio.com
*/
int data = 4;// 将74hc5954引脚设置为数据输入引脚SI 
int clock = 6;// 将74hc595的6引脚设置为时钟引脚SCK
int latch = 5;// 将74hc595的引脚5设置为输出锁存器RCK
int ledState = 0;
const int ON = HIGH;
const int OFF = LOW;
void setup()
{
pinMode(data, OUTPUT);
pinMode(clock, OUTPUT);
pinMode(latch, OUTPUT);
}
void loop()
{
for(int i = 0; i < 256; i++)
{
updateLEDs(i);
delay(500);
}
}
void updateLEDs(int value)
{
digitalWrite(latch, LOW);//
shiftOut(data, clock, MSBFIRST, ~value);// 串行数据输出，高电平优先
digitalWrite(latch, HIGH);// 锁存器
}
//**********************************************************************************
