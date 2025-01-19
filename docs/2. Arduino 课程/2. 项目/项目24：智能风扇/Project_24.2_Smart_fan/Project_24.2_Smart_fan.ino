//**********************************************************************************
/*
Keyes 2021入门学习套件
Project 24.2
Smart_fan
http//www.keyes-robot.com
*/
void setup() {
  Serial.begin(9600);
  pinMode(A3, OUTPUT);//数字口A3设置为输出
  pinMode(A2, OUTPUT);//数字口A2设置为输出
}
void loop() {
  int Soundvalue = analogRead(A1);  // 读取输入模拟值
  Serial.println(Soundvalue);
  if(Soundvalue>700)
  {
   // 当模拟值大于设定值时，启动电机 
   digitalWrite(A3,HIGH);
   digitalWrite(A2,LOW);
   for(int i=0;i<5;i++){
   delay(5000);                    // 等待5 s
   }
  }
  else{
   // 关闭电机
   digitalWrite(A3,LOW);
   digitalWrite(A2,LOW);
    }
}
//**********************************************************************************
