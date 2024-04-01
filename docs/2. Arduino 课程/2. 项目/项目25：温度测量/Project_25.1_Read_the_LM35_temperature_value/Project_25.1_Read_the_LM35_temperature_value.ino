//**********************************************************************************
/*
Keyes 2021入门学习套件
Project 25.1
Read_the_LM35_temperature_value
http//www.keyestudio.com
*/
#define sensorPin A1
void setup()
{
   Serial.begin(9600);
}
void loop()
{
  long reading = analogRead(sensorPin);
  float voltage = reading * 5.0;
  voltage /= 1024.0;
  float temperatureC = (500 * reading) /1024 ;
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
  Serial.print(voltage); Serial.print(" volts  -  ");
  Serial.print(temperatureC); Serial.print(" degrees C  -  ");
  Serial.print(temperatureF); Serial.println(" degrees F");
  delay(100);
}
//**********************************************************************************
