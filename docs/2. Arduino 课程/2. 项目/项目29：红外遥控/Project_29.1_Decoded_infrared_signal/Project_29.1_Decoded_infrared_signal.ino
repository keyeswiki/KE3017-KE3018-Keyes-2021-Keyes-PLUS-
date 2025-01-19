//**********************************************************************************
/*
Keyes 2021入门学习套件
Project 29.1
Decoded_infrared_signal
http//www.keyes-robot.com
*/
#include <IRremote.h>
int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;
void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // 开始接收信号
}
void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // 接收下一个值
  }
  delay(100);
}
//**********************************************************************************
