//*********************************************************************************
/*
Keyes 2021入门学习套件
Project 18
Steering_gear_rotating
http//www.keyes-robot.com
*/
#include <Servo.h>
Servo myservo;// 定义舵机名
void setup()
{
myservo.attach(9);// 选择舵机引脚(9)
}
void loop()
{
myservo.write(0);// 设置电机的旋转角度
delay(500);
myservo.write(45);// 设置电机的旋转角度
delay(500);
myservo.write(90);// 设置电机的旋转角度
delay(500);
myservo.write(135);// 设置电机的旋转角度
delay(500);
myservo.write(180);// 设置电机的旋转角度
delay(500);
}
//*********************************************************************************
