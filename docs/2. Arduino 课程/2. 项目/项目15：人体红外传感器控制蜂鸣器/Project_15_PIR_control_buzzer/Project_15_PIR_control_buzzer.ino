//*********************************************************************************
/*
Keyes 2021入门学习套件 
Project 15
PIR_control_buzzer
http//www.keyes-robot.com
*/

int buzzerpin = 8;  // 蜂鸣器引脚
int pirPin = 3;     // 人体红外传感器引脚 
int pirStat = 0;   // 人体红外传感器状态 
void setup() {
 pinMode(buzzerpin, OUTPUT);     
 pinMode(pirPin, INPUT);     
 Serial.begin(9600);
}
void loop()
{
 pirStat = digitalRead(pirPin); 
 if (pirStat == HIGH)
 {            // 如果检测到人体或动物运动时
   digitalWrite(buzzerpin, HIGH);  // 蜂鸣器鸣叫
   Serial.println("Hey I got you!!!");
 } 
 else {
   digitalWrite(buzzerpin, LOW); // 如果未检测到人体或动物运动时，关闭蜂鸣器
 }
}
//*********************************************************************************
