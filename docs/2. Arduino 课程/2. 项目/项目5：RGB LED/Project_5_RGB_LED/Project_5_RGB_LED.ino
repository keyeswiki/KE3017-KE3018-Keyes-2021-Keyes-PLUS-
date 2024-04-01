//**********************************************************************************
/*
Keyes 2021入门学习套件 
Project 5
RGB LED
http//www.keyestudio.com
*/
int redpin = 11; //选择红色LED的引脚
int bluepin =9; // 选择蓝色LED的引脚
int greenpin =10;// 选择绿色LED的引脚
int val;
void setup() {
  pinMode(redpin, OUTPUT);
  pinMode(bluepin, OUTPUT);
  pinMode(greenpin, OUTPUT);
}
void loop() 
{
for(val=255; val>0; val--)
  {
   analogWrite(11, val);
   analogWrite(10, 255-val);
   analogWrite(9, 128-val);
   delay(1); 
  }
for(val=0; val<255; val++)
  {
   analogWrite(11, val);
   analogWrite(10, 255-val);
   analogWrite(9, 128-val);
   delay(1); 
  }
}
//**********************************************************************************
