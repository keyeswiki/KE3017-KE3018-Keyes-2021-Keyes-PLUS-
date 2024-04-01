//**********************************************************************************
/*
Keyes 2021入门学习套件
Project 28.1
Read_the_temperature_and_humidity_values
http//www.keyestudio.com
*/
#include "DHT.h"
#define DHTPIN 11     // 连接DHT传感器的数字引脚
DHT dht(DHTPIN, DHT11);

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));

  dht.begin();
}

void loop() {
  // 在两次测量之间等待几秒钟.
  delay(2000);

  // 读取温度或湿度大约需要250毫秒!
  // 传感器读数也可能高达2秒“旧”(这是一个非常慢的传感器)
  float h = dht.readHumidity();
  // 读取温度为摄氏度(默认值)
  float t = dht.readTemperature();
  // 读取温度为华氏度 (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // 检查是否有读取失败并提前退出(再试一次).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // 计算华氏温度指数(默认值)
  float hif = dht.computeHeatIndex(f, h);
  // 以摄氏温度计算热指数 (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));
}
//**********************************************************************************
