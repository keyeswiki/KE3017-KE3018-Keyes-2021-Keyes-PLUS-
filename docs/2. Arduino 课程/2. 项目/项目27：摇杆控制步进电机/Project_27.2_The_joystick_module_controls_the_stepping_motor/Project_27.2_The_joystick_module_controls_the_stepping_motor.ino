//**********************************************************************************
/*
Keyes 2021入门学习套件
Project 27.2
The_joystick_module_controls_the_stepping_motor 
http//www.keyestudio.com
*/
const int X_pin = 0; // 模拟引脚A0连接到X输出
const int Y_pin = 1; // 模拟引脚A1连接到Y输出
int SW_pin = 3;
int X_Rotate;
int Y_Rotate;
// 步进电机引脚
const int IN1_pin = 11;
const int IN2_pin = 10;
const int IN3_pin = 9;
const int IN4_pin = 8;
void setup() {
// 摇杆的Arduino引脚设置
pinMode(SW_pin, INPUT);
digitalWrite(SW_pin, HIGH);
// 步进电机的Arduino引脚设置
pinMode(IN1_pin,OUTPUT);
pinMode(IN2_pin,OUTPUT);
pinMode(IN3_pin,OUTPUT);
pinMode(IN4_pin,OUTPUT);
}
void loop() {
X_Rotate = analogRead(X_pin);
Y_Rotate = analogRead(Y_pin);
if (Y_Rotate < 500) {
digitalWrite(IN1_pin, HIGH);
digitalWrite(IN2_pin, LOW);
digitalWrite(IN3_pin, LOW);
digitalWrite(IN4_pin, LOW);
delay((Y_Rotate/2)+2);
digitalWrite(IN1_pin, LOW);
digitalWrite(IN2_pin, HIGH);
digitalWrite(IN3_pin, LOW);
digitalWrite(IN4_pin, LOW);
delay((Y_Rotate/2)+2);
digitalWrite(IN1_pin, LOW);
digitalWrite(IN2_pin, LOW);
digitalWrite(IN3_pin, HIGH);
digitalWrite(IN4_pin, LOW);
delay((Y_Rotate/2)+2);
digitalWrite(IN1_pin, LOW);
digitalWrite(IN2_pin, LOW);
digitalWrite(IN3_pin, LOW);
digitalWrite(IN4_pin, HIGH);
delay((Y_Rotate/2)+2);
}
else if (Y_Rotate > 550){
digitalWrite(IN4_pin, HIGH);
digitalWrite(IN3_pin, LOW);
digitalWrite(IN2_pin, LOW);
digitalWrite(IN1_pin, LOW);
delay((1028-Y_Rotate)/2);
digitalWrite(IN4_pin, LOW);
digitalWrite(IN3_pin, HIGH);
digitalWrite(IN2_pin, LOW);
digitalWrite(IN1_pin, LOW);
delay((1028-Y_Rotate)/2);
digitalWrite(IN4_pin, LOW);
digitalWrite(IN3_pin, LOW);
digitalWrite(IN2_pin, HIGH);
digitalWrite(IN1_pin, LOW);
delay((1028-Y_Rotate)/2);
digitalWrite(IN4_pin, LOW);
digitalWrite(IN3_pin, LOW);
digitalWrite(IN2_pin, LOW);
digitalWrite(IN1_pin, HIGH);
delay((1028-Y_Rotate)/2);
}
else if (Y_Rotate > 500 && Y_Rotate < 550) {
digitalWrite(IN4_pin, LOW);
digitalWrite(IN3_pin, LOW);
digitalWrite(IN2_pin, LOW);
digitalWrite(IN1_pin, LOW);
}}
//**********************************************************************************
