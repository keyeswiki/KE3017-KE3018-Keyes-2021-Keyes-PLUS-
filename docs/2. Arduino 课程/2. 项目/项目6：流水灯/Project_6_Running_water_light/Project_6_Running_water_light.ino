//**********************************************************************************
/*
Keyes 2021入门学习套件 
Project 6
Running_water_light
http//www.keyestudio.com
*/
int BASE = 2 ;// 第一个LED的I/O引脚
int NUM = 5; // LED 数量
void setup()
{
   for (int i = BASE; i < BASE + NUM; i ++) 
   {
     pinMode(i, OUTPUT);   // 设置I/O引脚为输出
   }
}
void loop()
{
   for (int i = BASE; i < BASE + NUM; i ++) 
   {
     digitalWrite(i, LOW); // 设I/O引脚为低电平，依次熄灭led灯。
     delay(200); // 延时
   }
   for (int i = BASE; i < BASE + NUM; i ++) 
   {
     digitalWrite(i, HIGH);   // 设置I/O引脚为高，依次点亮led灯
     delay(200);  // 延时
   }  
}
//**********************************************************************************
