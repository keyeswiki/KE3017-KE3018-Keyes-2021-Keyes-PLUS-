//**********************************************************************************
/*
Keyes 2021入门学习套件
Project 23.2
Light_lamp
http//www.keyestudio.com
*/
int photocellpin=A0;// 初始化连接光敏电阻的模拟管脚A0
int ledpin=11;// 初始化数字管脚11
int val=0;// 初始化变量val的值为0
void setup()
{
pinMode(ledpin,OUTPUT);// 设置数字引脚11为“输出”
Serial.begin(9600);// 波特率设置为9600
}
void loop()
{
val=analogRead(photocellpin);//读取传感器的模拟值并将其值赋给val
Serial.println(val);//显示val的值
analogWrite(ledpin,val/4);//设置亮度(最大值255)
delay(10);// 等待0.01秒
}
//**********************************************************************************
