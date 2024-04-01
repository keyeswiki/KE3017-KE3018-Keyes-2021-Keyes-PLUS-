//**********************************************************************************
/*
Keyes 2021入门学习套件 
Project 7
Active_buzzer 
http//www.keyestudio.com
*/
int buzzerPin = 8;
void setup ()
{
  pinMode (buzzerPin, OUTPUT);
}
void loop ()
{
  digitalWrite (buzzerPin, HIGH);
  delay (500);
  digitalWrite (buzzerPin, LOW);
  delay (500);
}
//**********************************************************************************
