//*********************************************************************************
/*
Keyes 2021入门学习套件
Project 19
Stepper_motor
http//www.keyestudio.com
*/
// 步进电机引脚
const int IN1_pin = 11;
const int IN2_pin = 10;
const int IN3_pin = 9;
const int IN4_pin = 8;
int val; 
void setup() {
Serial.begin(9600);
// 步进电机的Arduino引脚设置
pinMode(IN1_pin,OUTPUT);
pinMode(IN2_pin,OUTPUT);
pinMode(IN3_pin,OUTPUT);
pinMode(IN4_pin,OUTPUT);
}
void loop() {
int a = 1024;
int b = 1024;
val=Serial.read();
if(val=='A')
{
while(a--)
{
digitalWrite(IN1_pin, HIGH);
digitalWrite(IN2_pin, LOW);
digitalWrite(IN3_pin, LOW);
digitalWrite(IN4_pin, LOW);
delay(10);
digitalWrite(IN1_pin, LOW);
digitalWrite(IN2_pin, HIGH);
digitalWrite(IN3_pin, LOW);
digitalWrite(IN4_pin, LOW);
delay(10);
digitalWrite(IN1_pin, LOW);
digitalWrite(IN2_pin, LOW);
digitalWrite(IN3_pin, HIGH);
digitalWrite(IN4_pin, LOW);
delay(10);
digitalWrite(IN1_pin, LOW);
digitalWrite(IN2_pin, LOW);
digitalWrite(IN3_pin, LOW);
digitalWrite(IN4_pin, HIGH);
delay(10);
}
}
if(val=='C')
{
while(b--)
{
digitalWrite(IN4_pin, HIGH);
digitalWrite(IN3_pin, LOW);
digitalWrite(IN2_pin, LOW);
digitalWrite(IN1_pin, LOW);
delay(10);
digitalWrite(IN4_pin, LOW);
digitalWrite(IN3_pin, HIGH);
digitalWrite(IN2_pin, LOW);
digitalWrite(IN1_pin, LOW);
delay(10);
digitalWrite(IN4_pin, LOW);
digitalWrite(IN3_pin, LOW);
digitalWrite(IN2_pin, HIGH);
digitalWrite(IN1_pin, LOW);
delay(10);
digitalWrite(IN4_pin, LOW);
digitalWrite(IN3_pin, LOW);
digitalWrite(IN2_pin, LOW);
digitalWrite(IN1_pin, HIGH);
delay(10);
}
}
digitalWrite(IN4_pin, LOW);
digitalWrite(IN3_pin, LOW);
digitalWrite(IN2_pin, LOW);
digitalWrite(IN1_pin, LOW);
}
//*********************************************************************************
