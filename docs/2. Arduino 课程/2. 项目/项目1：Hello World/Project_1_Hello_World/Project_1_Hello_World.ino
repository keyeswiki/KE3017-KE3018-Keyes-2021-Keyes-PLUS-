//*************************************************************************************
/*
Keyes 2021入门学习套件
Project 1
Hello World
http//www.keyes-robot.com
*/
char val;//定义变量val.
void setup()
{
Serial.begin(9600);// 设置波特率为9600. 
}
void loop()
{
  if (Serial.available() > 0) {
    val=Serial.read();// 读取指令或字符从PC到Arduino，并赋值给val.
    if(val=='R')// 确定接收的指令或字符是否为“R”.
    {  // if it’s “R”,    
     Serial.println("Hello World!");// 显示“Hello World !”字符串.
    }
  }
}
//*************************************************************************************
