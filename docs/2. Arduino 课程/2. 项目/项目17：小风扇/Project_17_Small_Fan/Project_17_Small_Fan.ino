//**********************************************************************************
/*
Keyes 2021入门学习套件
Project 17
Small_Fan
http//www.keyestudio.com
*/
void setup(){
  pinMode(A3, OUTPUT);//数字口A3设置为输出
  pinMode(A2, OUTPUT);//数字口A2设置为输出
}
void loop(){
//设置风扇逆时针转3000毫秒
  digitalWrite(A3,LOW);
  digitalWrite(A2,HIGH);
  delay(3000);
//设置风扇停止转动1000毫秒
  digitalWrite(A3,LOW);
  digitalWrite(A2,LOW);
  delay(1000);
//设置风扇顺时针转3000毫秒
  digitalWrite(A3,HIGH);
  digitalWrite(A2,LOW);
  delay(3000);
}
//********************************************************************************
