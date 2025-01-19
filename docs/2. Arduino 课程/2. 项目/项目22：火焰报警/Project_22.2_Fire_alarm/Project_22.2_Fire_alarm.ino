//**********************************************************************************
/*
Keyes 2021入门学习套件
Project 22.2
Fire_alarm
http//www.keyes-robot.com
*/
const int red = 11;
const int green = 10;
const int blue= 9;
const int buzzer = 12;
const int flamepin = A1;
const int thereshold = 30;
void setup() {
  // 将设置代码放在这里，运行一次:
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(flamepin, INPUT);
 
}
void setColor(int redValue, int greenValue, int blueValue)
 {
analogWrite(red, redValue);
analogWrite(blue, blueValue);
analogWrite(green, greenValue);
}
 
void loop() {
  // 把主代码放在这里，重复运行:
  int flamesenseval = analogRead(flamepin);
  Serial.println(flamesenseval);
  if (flamesenseval >= thereshold) {
    setColor(255, 0, 0); //红色
    tone(buzzer, 1000);
    delay(10);
  }
  else
  {
    setColor(0, 255, 0); // 绿色
    noTone(buzzer);
  }
}
//**********************************************************************************
