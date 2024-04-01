//**********************************************************************************
/*
Keyes 2021入门学习套件
Project 29.2
Infrared_remote_control
http//www.keyestudio.com
*/
#include <IRremote.h>
int IR_Recv = 11;   //红外接收器引脚11
int bluePin = 10;
int greenPin = 9;
int yellowPin = 8;
IRrecv irrecv(IR_Recv);
decode_results results;
void setup(){
  Serial.begin(9600);  //开始串行通信
  irrecv.enableIRIn(); // 开始接收
  pinMode(bluePin, OUTPUT);      // 设置数字引脚为输出
  pinMode(greenPin, OUTPUT);      // 设置数字引脚为输出
  pinMode(yellowPin, OUTPUT);      // 设置数字引脚为输出 
}
 void loop(){
  //解码红外信号输入
  if (irrecv.decode(&results)){
    long int decCode = results.value;
    Serial.println(results.value,HEX);
    //切换case 以使用所选的远程控制按钮
    switch (results.value){
      case  0x00FF6897: //当你按1键时
        digitalWrite(bluePin, HIGH);
        break;   
      case  0x00FF30CF: //当你按4键时
        digitalWrite(bluePin, LOW);   
        break;
       case 0x00FF9867: //当你按2键时
        digitalWrite(greenPin, HIGH);
        break;           
       case 0x00FF18E7: //当你按5键时
        digitalWrite(greenPin, LOW);
        break;       
       case 0x00FFB04F: //当你按3键时
        digitalWrite(yellowPin, HIGH);
        break;       
       case 0x00FF7A85: //当你按6键时
        digitalWrite(yellowPin, LOW);
        break;
    }
    irrecv.resume(); // 从你按下的按钮接收下一个值
  }
  delay(10);
}
//**********************************************************************************
